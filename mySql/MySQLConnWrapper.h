//
// Created by user on 16/10/03.
//

#ifndef PROJECTPI_MYSQLCONN_WRAPPER_H
#define PROJECTPI_MYSQLCONN_WRAPPER_H
#include "mysql_connection.h"

#include "mysql_driver.h"
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/driver.h>
#include <cppconn/exception.h>
#include <cppconn/resultset.h>
#include <cppconn/statement.h>
#include <cppconn/prepared_statement.h>
#include <fstream>

using namespace std;

class MySQLConnWrapper  {

public:

    /* Your MySQL server settings */
    MySQLConnWrapper();
    void loadSqlSettings();

    ~MySQLConnWrapper();
    void manageException(sql::SQLException& e);
    void connect();
    void switchDb(const string& db_name);
    void prepare(const string& query);
    void setInt(const int& num, const int& data);
    void setString(const int& num, const string& data);
    void execute(const string& query = "");
    bool fetch();
    string print(const string& field);
    string print(const int& index);

private:

    string host;
    string user;
    string password;
    sql::Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt;
    sql::PreparedStatement* prep_stmt;
    sql::ResultSet* res;

};


#endif //PROJECTPI_MYSQLCONN_WRAPPER_H
