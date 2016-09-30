//
// Created by User on 2016/09/19.
//
#include "ipInfo.h"
ipInfo::ipInfo(string ss) {
    this->ipAddr = ss;
}

string ipInfo::getIpAddress(){
    return this->ipAddr;
}

vector<string> ipInfo::getCountryRoute(){
    string _ip = this->ipAddr;
    /**
     * getRouteとgetCountryを組み合わせて
     * どの国（地域）を辿ってきたかを返す
     */
    vector<string> route;
    route.push_back("Chiba");
    route.push_back("Tokyo");
    route.push_back("China");
    return route;
}

string ipInfo::getCountry(){
    /**
     * ipパケットの経路から国を推測する処理
     *          or
     * DNSを与えているネームサーバから国を推測
     */
    return "US";
}

vector<string> ipInfo::getIpRoute(){
    string _ip = this->ipAddr;
    vector<string> result;
    command cmd;
    vector<string> resultTmp = cmd.analyzeCommandMulti("sudo traceroute -I -w 0.2 -q 1 -n "+_ip,"(\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3})\\s");
    //tracerouteの結果か宛先ipを除外する
    for(auto n:resultTmp){
        if(n != _ip){
            result.push_back(n);
        }
    }
    return result;
}
