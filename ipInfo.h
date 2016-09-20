//
// Created by User on 2016/09/19.
//

#ifndef PROJECTPI_IPINFO_H
#define PROJECTPI_IPINFO_H
#include<string>
#include <vector>
using namespace std;

class ipInfo {
public:

    ipInfo(string ss);

    string getDns();
    vector<string> getRoute();
    string getCountry();
    string getNameServer();
    string getIpAddress();
    vector<string> getCountryRoute();
private:
    string ipAddr;

};


#endif //PROJECTPI_IPINFO_H
