#ifndef UTILITIES_H
#define UTILITIES_H

#include <QtSql>
#include <string>
#include <QMessageBox>
#include <algorithm>
#include <sstream>

using namespace std;

namespace utils {
    QSqlDatabase getDatabaseConnection();
    string str2upper(string str);
    string str2lower(string str);
    string int2str(const int& a);
}

#endif // UTILITIES_H
