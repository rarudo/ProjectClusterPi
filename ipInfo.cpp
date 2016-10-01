//
// Created by User on 2016/09/19.
//
#include "ipInfo.h"


ipInfo::ipInfo(string ss) {
    this->ipAddr = ss;
    fetchIpRoute();
    fetchRoute();
}
vector<string> ipInfo::getCountryRoute() {
    return this->countryRoute;
}

vector<string> ipInfo::getCityRoute() {
    return this->cityRoute;
}

string ipInfo::getIpAddress(){
    return this->ipAddr;
}

vector<string> ipInfo::getIpRoute() {
    return this->ipRoute;
}

/**
 * ipの経路から国と地域の経路を取得
 */
void ipInfo::fetchRoute() {
    vector<string> resultCountry, resultCity;
    locationInfo li;
    //ipRouteで取得したipアドレスすべてを調べる
    for(auto ipAddr :this->getIpRoute()){
        li.setIpAddr(ipAddr);
        //国の情報を取得
        string preResultCountry = (li.getCountry());
        string preResultCity = (li.getCity());

        if(preResultCountry.size() > 0){
            resultCountry.push_back(preResultCountry);
        }else{
            //resultCountry.push_back("Unknown");
        }
        if(preResultCity.size() > 0){
            resultCity.push_back(preResultCity);
        }else{
            //resultCity.push_back("Unknown");
        }
    }
    this->countryRoute = resultCountry;
    this->cityRoute = resultCity;
}

/**
 * ipの経路を取得
 */
void ipInfo::fetchIpRoute(){
    string _ip = this->ipAddr;
    vector<string> result;
    command cmd;
    vector<string> resultTmp = cmd.analyzeCommandMulti("sudo traceroute -I -w 0.2 -q 1 -n "+_ip,"(\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}).*ms");
    this->ipRoute = resultTmp;
}



