//
// Created by user on 16/11/02.
//

#ifndef PROJECTPI_JOBS_H
#define PROJECTPI_JOBS_H

#include "mySql/MySQLConnWrapper.h"


class Jobs {
public:
    Jobs();

private:
    MySQLConnWrapper *mscw;

};


#endif //PROJECTPI_JOBS_H
