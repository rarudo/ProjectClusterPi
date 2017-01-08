//
// Created by user on 16/10/26.
//

#include "Ipaddreses.h"

//接続処理
Ipaddreses::Ipaddreses(string ip,string toIp,string rtp,string nsIp,int port,vector<string> latitudeRoute,vector<string> longitudeRoute) {
    this->ip = ip;
    this->toIp = toIp;
    this->rtp = rtp;
    this->nsIp = nsIp;
    this->port = port;
    this->latitudeRoute = latitudeRoute;
    this->longitudeRoute = longitudeRoute;
    mscw = new MySQLConnWrapper();
    mscw->connect();
    mscw->switchDb("clusterpi");
    setTimestamp();
    int id = insertDbIpInfo();
    insertDbLocation(id);
}
void Ipaddreses::setTimestamp() {
    mscw->execute("select now()");
    while(mscw->fetch()){
        this->datetime= mscw->print("now()");
    }

}

/**
 *
 * @return インサートしたidを返す
 */
int Ipaddreses::insertDbIpInfo() {
    string tbName = "ip_infomation";
    string portStr = to_string(port);
    string insertPrefix = "insert into "+tbName;
    string insertColumn = "ip_address_from,time,ip_address_to,rtp,nameserver_ip,port,is_checked";
    string insertValue = '"'+ip+"\",\""+datetime+"\",\""+toIp+"\",\""+rtp+"\",\""+nsIp+"\","+portStr+","+"\"0\"";
    string insert = insertPrefix + " (" + insertColumn + ") " + "values ("+insertValue+")";
    //cout << insert << endl;
    mscw->execute(insert);
    mscw->execute(" SELECT LAST_INSERT_ID()");
    mscw->fetch();
    string idStr = mscw->print("LAST_INSERT_ID()");
    int id = atoi(idStr.c_str());
    return id;
}

void Ipaddreses::insertDbLocation(int id) {
    string tbName = "location_route";
    string insertPrefix = "insert into "+tbName;
    string insertColum = "id,location";
    string insertValue = to_string(id)+',' + '"';
    string latitudeTemp,longitudeTemp;
    for(int i =0; i < latitudeRoute.size(); i++){
        latitudeTemp = latitudeRoute[i];
        longitudeTemp = longitudeRoute[i];
        insertValue += latitudeTemp+'/'+longitudeTemp;
        if(i+1 < latitudeRoute.size()){
            insertValue += ',';
        }
    }
    insertValue += '"';
    string insert = insertPrefix + " (" + insertColum + ") " + "values ("+insertValue+")";
    //cout<<insert<<endl;
    mscw->execute(insert);
}

