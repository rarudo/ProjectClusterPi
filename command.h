//
// Created by user on 16/09/23.
//

#ifndef PROJECTPI_COMMAND_H
#define PROJECTPI_COMMAND_H
#include<string>
#include <iostream>
#include <regex>

using namespace std;

class command {
public:
    void doCommand(string str);
    string getResult();
    string analyzeCommand(string commandStr,string re);
private:
};


#endif //PROJECTPI_COMMAND_H
