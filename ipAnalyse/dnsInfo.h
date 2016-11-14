//
// Created by user on 16/09/26.
//

#ifndef PROJECTPI_DNSINFO_H
#define PROJECTPI_DNSINFO_H
#include <string>
#include "../command.h"
#include <regex>
using namespace std;

class dnsInfo {
public:
    dnsInfo();
    void setIpAddr(string ipAddress);
    void init();
    void fetchDnsInfo();
    string getRtp();
    string getNameServerName();
    string getNameServerIp();
private:
    string ipAddr;
    string dnsName;
    string nameServerName;
    string nameServerIp;
};

#endif //PROJECTPI_DNSINFO_H
