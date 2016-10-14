#include <iostream>
#include <string>
#include "ipAnalyse/ipInfo.h"
#include "ipAnalyse/dnsInfo.h"
#include "Port.h"
#include "mySql/MySQLConnWrapper.h"

int main() {
    dnsInfo *dns;
    ipInfo *ip;
    string ipAddr = "216.58.197.238";
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

//    MySQLConnWrapper *mscw = new MySQLConnWrapper();
//    mscw->connect();
//    mscw->switchDb("clusterpi");
//    mscw->execute("");
/*
    cout << "Send Country"<< endl;
    cout << "     "+ip->getCountry() << endl;


*/
    delete ip;
    delete dns;
    return 0;
}