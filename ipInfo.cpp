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

/**
 * nslookupコマンドから必要な値を抜き取る
 * @return DNS名を返す
 */
string ipInfo::getDns(){
    string _ip = this->ipAddr;
    command cmd = command();
    cmd.doCommand("nslookup "+_ip);
    //正規表現の結果が入る
    smatch match;
    //正規表現パターン
    std::regex re( "name = (.*)" ) ;
    //検索する対象はコマンドの実行結果
    std::string text= cmd.getResult();
    //コマンド結果から必要な値を正規表現で抽出
    int result =regex_search(text,match,re);
    if(result) {
        //配列の最後の要素（正規表現の結果）を返す
        return match[match.size()-1];
    }else{
        return "";
    }
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
    route.push_back("10,10,123,1");
    route.push_back("192,2,14,2");
    route.push_back("220,12,14,234");
    route.push_back("168,22,194,232");
    return route;
}
