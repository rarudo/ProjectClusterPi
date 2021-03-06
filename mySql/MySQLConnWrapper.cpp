//
// Created by user on 16/10/03.
//

/**
 * from https://github.com/eduardocasas/MySQL-Connector-Cpp-Wrapper-Class/blob/master/
 */


#include "MySQLConnWrapper.h"

using namespace std;
MySQLConnWrapper::MySQLConnWrapper()
{
    loadSqlSettings();


}
void MySQLConnWrapper::loadSqlSettings() {
    string fname = ".secret";
    ifstream *ifs = new ifstream(fname);
    string str;
    string hostname;
    string port;

    //読み込み失敗時
    if (ifs->fail()) {
        cerr << "設定ファイルの読み込み失敗" << endl;
        //設定ファイル書き込み
        std::ofstream ofs;
        ofs.open(fname, std::ios::app);
        ofs << "hostname:localhost" << endl;
        ofs << "port:10000" << endl;
        ofs << "user:your user" << endl;
        ofs << "password:your password" << endl;
        ifs = new ifstream(fname);
    }
    //ファイル読み込み
    while (getline(*ifs, str)) {
        string value = str.substr(str.find(':') + 1);
        string key = str.substr(0, str.find(':'));
        //switch文に文字列は使えない?
        if (key == "hostname")
            hostname = value;
        else if (key == "port")
            port = value;
        else if (key == "user")
            user = value;
        else if (key == "password")
            password = value;
    }
    //ホストネーム:portの形で格納
    host = hostname +":"+port;
    delete ifs;
}

MySQLConnWrapper::~MySQLConnWrapper()
{
    delete res;
    delete prep_stmt;
    delete stmt;
    delete con;
}

void MySQLConnWrapper::manageException(sql::SQLException& e)
{
    if (e.getErrorCode() != 0){
        cout << "# ERR: SQLException in " << __FILE__;
        cout << "(" << __FUNCTION__ << ") on line " << __LINE__ << endl;
        cout << "# ERR: " << e.what();
        cout << " (MySQL error code: " << e.getErrorCode();
        cout << ", SQLState: " << e.getSQLState() << " )" << endl;
    }
}

void MySQLConnWrapper::connect()
{
    try{
        driver = get_driver_instance();
        con = driver->connect(host, user, password);
    } catch (sql::SQLException &e){
        manageException(e);
    }
}

void MySQLConnWrapper::switchDb(const string& db_name)
{
    try{
        con->setSchema(db_name);
        stmt = con->createStatement();
    } catch (sql::SQLException &e) {
        manageException(e);
    }
}

void MySQLConnWrapper::prepare(const string& query)
{
    try{
        prep_stmt = con->prepareStatement(query);
    } catch (sql::SQLException &e){
        manageException(e);
    }
}

void MySQLConnWrapper::setInt(const int& num, const int& data)
{
    prep_stmt->setInt(num, data);
}

void MySQLConnWrapper::setString(const int& num, const string& data)
{
    prep_stmt->setString(num, data);
}

void MySQLConnWrapper::execute(const string& query)
{

    try {
        if (query != "") {
            res = stmt->executeQuery(query);
        } else {
            res = prep_stmt->executeQuery();
            prep_stmt->close();
        }
    } catch (sql::SQLException &e) {
        manageException(e);
    }
}

bool MySQLConnWrapper::fetch()
{
    return res->next();
}

string MySQLConnWrapper::print(const string& field)
{
    return res->getString(field);
}

string MySQLConnWrapper::print(const int& index)
{
    return res->getString(index);
}

