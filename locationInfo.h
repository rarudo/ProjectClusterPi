//
// Created by user on 16/10/01.
//

#ifndef PROJECTPI_LOCATIONINFO_H
#define PROJECTPI_LOCATIONINFO_H

#include <maxminddb.h>
#include <cstring>
#include <string>
using namespace std;
class locationInfo {
public:
    void fetchLocation();
    void setIpAddr(string _ip);
    string getCity();
    string getCountry();


private:
    void init();
    string city;
    string country;
    string ip;
};
string getMMDBresult(MMDB_entry_data_s entry_data);
#endif //PROJECTPI_LOCATIONINFO_H
