//
// Created by user on 16/09/26.
//

#include "dnsInfo.h"

dnsInfo::dnsInfo(){

}

void dnsInfo::setIpAddr(string ipAddress) {
    init();
    this->ipAddr = ipAddress;
    //DNS関係の情報を取得
    fetchDnsInfo();
}
//グローバル変数の初期化処理
void dnsInfo::init(){
    this->dnsName = "";
    this->nameServerName = "";
    this->nameServerIp = "";
}

/**
 * nslookupコマンドから必要な値を抜き取る
 * グローバル変数に代入する
 *
 */
void dnsInfo::fetchDnsInfo() {
    string _ip = this->ipAddr;
    string rtp,nameServerName,nameServerIp;
    command cmd = command();
    rtp = cmd.analyzeCommand("dig -x "+_ip ,"ANSWER SECTION[\\s\\S]*PTR\\s*(.*)");
    nameServerName = cmd.analyzeCommand("dig -x "+_ip+" NS" ,"SOA\\s*(.*?)\\s");
    nameServerIp = cmd.analyzeCommand("dig "+nameServerName,"ANSWER SECTION[\\s\\S]*(?:IN)\\s*A\\s(.*)");
    this->dnsName = rtp;
    this->nameServerName = nameServerName;
    this->nameServerIp = nameServerIp;
}

//逆引きの名前
string dnsInfo::getRtp() {
    return this->dnsName;
}

//ネームサーバー
string dnsInfo::getNameServerName(){
    return this->nameServerName;
}
string dnsInfo::getNameServerIp(){
    return this->nameServerIp;
}
