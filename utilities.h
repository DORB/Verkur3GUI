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
    bool isYear(const string& year);
    void trimWS(string& str);
    void firstCap(string& str);
}

#endif // UTILITIES_H
