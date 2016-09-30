//
// Created by User on 2016/09/19.
//

#ifndef PROJECTPI_IPINFO_H
#define PROJECTPI_IPINFO_H
#include<string>
#include <vector>
#include <fstream>
#include <iostream>
#include <regex>
#include "command.h"
using namespace std;

class ipInfo {
public:

    ipInfo(string ss);

    vector<string> getIpRoute();
    string getCountry();
    string getIpAddress();
    vector<string> getCountryRoute();
private:
    //コマンドを実行したことを記録
    bool didGetDns;
    string dns;
    string ipAddr;
};


#endif //PROJECTPI_IPINFO_H
