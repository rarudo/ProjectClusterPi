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

string ipInfo::getDns(){
    string _ip = this->ipAddr;
    /**
     * 処理
     * Linux上ならnslookupでDNSを取得
     *
     */
    return "google.com";
}

vector<string> ipInfo::getCountryRoute(){
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

string ipInfo::getNameServer(){
    /**
     * nslookup等のコマンドでネームサーバーを取得する
     */
    return "dns.Nameservers.com";
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
    route.push_back("192,2,14,2");
    route.push_back("220,12,14,234");
    route.push_back("168,22,194,232");
    return route;
}
