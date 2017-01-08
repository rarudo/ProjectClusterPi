//
// Created by user on 16/11/14.
//

#ifndef PROJECTPI_TASKQUE_H
#define PROJECTPI_TASKQUE_H


#include "MySQLConnWrapper.h"
#include <arpa/inet.h>
#include <vector>
#include <cstdlib>
#include <cstring>

class TaskQue {
public:
    TaskQue();
    int fetch();
    string getIpAddr();
    string getTime();

private:
    int nowOperator = 0;
    int listSize;
    void fetchQue();
    void insertChecked(string id);
    vector<string> ipList;
    vector<string> timeList;
    MySQLConnWrapper *mscw;
    string ipIntToStr(string ipInt);
};


#endif //PROJECTPI_TASKQUE_H
