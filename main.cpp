#include <iostream>
#include "ipAnalyse/ipInfo.h"
#include "ipAnalyse/dnsInfo.h"
#include "mySql/Ipaddreses.h"
#include "mySql/TaskQue.h"

void doMain(string ipAddr){
    //string ipAddr = "63.240.178.216";
    dnsInfo *dns;
    ipInfo *ip;
    ip = new ipInfo(ipAddr);
    dns = new dnsInfo();
    dns->setIpAddr(ipAddr);
    cout << "ip Address " << endl;
    cout << "     "+ip->getIpAddress() << endl;
    cout << "RTP"<< endl;
    cout << "     "+dns->getRtp() << endl;
    cout << "Name Server Name"<< endl;
    cout << "     "+dns->getNameServerName() << endl;
    cout << "Name Server Ip"<< endl;
    cout << "     "+dns->getNameServerIp() << endl;
    cout << "ip Route"<< endl;
    for(auto n: ip->getIpRoute()){
        cout <<"     "+ n <<endl;
    }
    cout << "Relay Countrys" << endl;
    for(auto n: ip->getCountryRoute()){
        cout <<"     "+ n <<endl;
    }

    cout << "Relay Cities" << endl;
    for(auto n: ip->getCityRoute()){
        cout <<"     "+ n <<endl;
    }

    cout << "Relay Latitude" << endl;
    for(auto n: ip->getLatitudeRoute()){
        cout <<"     "+ n <<endl;
    }

    cout << "Relay Longitude" << endl;
    for(auto n: ip->getLongitudeRoute()){
        cout <<"     "+ n <<endl;
    }


    Ipaddreses *ipSql;
    ipSql = new Ipaddreses(ip->getIpAddress()
            ,"10.10.10.10"
            ,dns->getRtp()
            ,dns->getNameServerIp()
            ,80
            ,ip->getLatitudeRoute()
            ,ip->getLongitudeRoute()
    );


}

int main() {
    TaskQue *tq;
    tq = new TaskQue();
   while(tq->fetch()){
       string ipAddr = tq->getIpAddr();
       doMain(ipAddr);
    }
   return 0;
}

