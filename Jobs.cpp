//
// Created by user on 16/11/02.
//

#include "Jobs.h"

Jobs::Jobs() {
    mscw = new MySQLConnWrapper();
    mscw->connect();
    mscw->switchDb("data");

}
