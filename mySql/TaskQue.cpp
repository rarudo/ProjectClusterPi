//
// Created by user on 16/11/14.
//

#include "TaskQue.h"

TaskQue::TaskQue() {
    mscw = new MySQLConnWrapper();
    mscw->connect();
    mscw->switchDb("clusterpi");
    fetchQue();
}



void TaskQue::fetchQue() {
    mscw->execute("select * from data where is_check = 0 limit 50");
    while(mscw->fetch()){
        string ipStrTmp = mscw->print("ip_address");
        string id = mscw->print("id");
        string time = mscw->print("date_time");
        //is_checkに１を代入
        insertChecked(id);
        //192.168.みたいなアドレスをstringで取得
        try {
            //ipをunit32_tへ
            string ipAddr = ipIntToStr(ipStrTmp);
            //ipアドレスをlistに追加
            ipList.push_back(ipAddr);
            //datatimeをlistに追加
            timeList.push_back(time);
        }catch (char *strError){
            cout << strError << endl;
        }

    }
    this->listSize = (int) ipList.size();
}

//unit32_t型のipをstring型になおす
string TaskQue::ipIntToStr(string ipStr) {
    uint32_t u32ip = (uint32_t) stoull(ipStr.c_str());
    char src[32];
    //return string(src);
    //cout << "u32="+ipStr << endl;
    struct in_addr ipAddr;
    ipAddr.s_addr = u32ip;
    memcpy(src,inet_ntoa(ipAddr),32);
    string resultIpStr= inet_ntoa(ipAddr);
    //cout << "ConvertedString="+resultIpStr << endl;
    //cout << "ConvertedStringSatuma="+string(src)<< endl;
    return resultIpStr;
}

/**
 * Mysqlのテーブるのis_checkコラムに1を代入する
 */
void TaskQue::insertChecked(string id) {
    mscw->execute("update data set is_check = 1 where id ="+id);
}

int TaskQue::fetch() {
    if(listSize > nowOperator + 1) {
        this->nowOperator++;
        return 1;
    }
    return 0;
}

string TaskQue::getIpAddr() {
    cout << "getIpAddr"+ipList[nowOperator] << endl;
    return ipList[nowOperator];
}

string TaskQue::getTime() {
    return timeList[nowOperator];
}




