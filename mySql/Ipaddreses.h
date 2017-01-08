//
// Created by user on 16/10/26.
//

#ifndef PROJECTPI_IPADDRESES_H
#define PROJECTPI_IPADDRESES_H

#include "MySQLConnWrapper.h"
#include <vector>

class Ipaddreses {
public:
    Ipaddreses(string ip,string toIp,string rtp,string nsIp,int port,vector<string> latitudeRoute,vector<string> longitude);

private:
    string ip;
    string toIp;
    string rtp;
    string nsIp;
    vector<string> latitudeRoute;
    vector<string> longitudeRoute;

    MySQLConnWrapper *mscw;
    string datetime;
    int port;
    void setTimestamp();
    int insertDbIpInfo();
    void insertDbLocation(int id);
};


#endif //PROJECTPI_IPADDRESES_H
