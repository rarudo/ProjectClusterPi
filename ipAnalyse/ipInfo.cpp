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

vector<string> ipInfo::getLatitudeRoute() {
    return this->latitudeRoute;
}

vector<string> ipInfo::getLongitudeRoute() {
    return this->longitudeRoute;
}


/**
 * ipの経路から国と地域の経路を取得
 */
void ipInfo::fetchRoute() {
    vector<string> resultCountry, resultCity, resultLatitude, resultLongitude;
    locationInfo li;
    //ipRouteで取得したipアドレスすべてを調べる
    for(auto ipAddr :this->getIpRoute()){
        li.setIpAddr(ipAddr);
        //国の情報を取得
        if(li.getCountry().size() > 0)
            resultCountry.push_back(li.getCountry());
        //地域の情報を取得
        if(li.getCity().size() > 0)
            resultCountry.push_back(li.getCity());
        //緯度の情報を取得
        if(li.getLatitude().size() > 0)
            resultLatitude.push_back(li.getLatitude());
        //経度の情報を取得
        if(li.getLongitude().size() > 0)
            resultLongitude.push_back(li.getLongitude());
    }
    this->countryRoute = resultCountry;
    this->cityRoute = resultCity;
    this->latitudeRoute = resultLatitude;
    this->longitudeRoute= resultLongitude;

}

/**
 * ipの経路を取得
 */
void ipInfo::fetchIpRoute(){
    string _ip = this->ipAddr;
    command cmd;
    vector<string> resultTmp = cmd.analyzeCommandMulti("sudo traceroute -I -w 0.2 -q 1 -n "+_ip,"(\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}).*ms");
    this->ipRoute = resultTmp;
}




