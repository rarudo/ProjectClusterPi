#include <iostream>
#include "ipInfo.h"

int main() {
    ipInfo *ip;
    ip = new ipInfo("216.58.197.184 ");
//    system("ping -c 2 google.com > tmp");


    cout << "ip Address " << endl;
    cout << "     "+ip->getIpAddress() << endl;
    cout << "DNS Name"<< endl;
    cout << "     "+ip->getDns() << endl;

/*
    cout << "ip Route"<< endl;
    for(auto n: ip->getRoute()){
        cout <<"     "+ n <<endl;
    }

    cout << "Send Country"<< endl;
    cout << "     "+ip->getCountry() << endl;

    cout << "Send Name Server"<< endl;
    cout << "     "+ip->getNameServer() << endl;

    cout << "Relay Countrys" << endl;
    for(auto n: ip->getCountryRoute()){
        cout <<"     "+ n <<endl;
    }
*/
    return 0;
}