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
    /**
     * getRouteとgetCountryを組み合わせて
     * どの国（地域）を辿ってきたかを返す
     */
    command cmd;
    string result = cmd.analyzeCommand("sudo traceroute -I "+_ip,"(.*)");
    cout << result endl;
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

vector<string> ipInfo::getRoute(){
    string _ip = this->ipAddr;
    /**
     * 処理
     * Linux上ならtracerouteでIPパケットの到達経路を取得
     *格納例
     * vectorの最初が自分に一番近いルーターのアドレス
     * 最後の配列が相手のipアドレス
     */
    vector<string> route;
    return route;
}
