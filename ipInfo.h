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
#include <error.h>
#include <stdlib.h>
#include "locationInfo.h"

using namespace std;

class ipInfo {
public:

    ipInfo(string ss);
    vector<string> getIpRoute();
    string getIpAddress();
    vector<string> getCountryRoute();
    vector<string> getCityRoute();
private:
    string ipAddr;
    vector<string> ipRoute;
    vector<string> countryRoute;
    vector<string> cityRoute;
    void fetchIpRoute();
    void fetchRoute();
};
#endif //PROJECTPI_IPINFO_H
