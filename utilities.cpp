#include "utilities.h"
#include <QString>

namespace utils {
    QSqlDatabase getDatabaseConnection()
    {
        QString connectionName = "Connection";

        QSqlDatabase db;

        if(QSqlDatabase::contains(connectionName))
        {
            db = QSqlDatabase::database(connectionName);
        }
        else
        {
            db = QSqlDatabase::addDatabase("QSQLITE", connectionName);
            db.setDatabaseName("verkur.sqlite");

            db.open();
        }

        return db;
    }

    string str2upper(string str)
    {
        transform(str.begin(), str.end(), str.begin(),::toupper);

        return str;
    }

    string str2lower(string str)
    {
        transform(str.begin(), str.end(), str.begin(),::tolower);

        return str;
    }

    string int2str(const int& a)
    {
        stringstream ss;
        ss << a;
        string str;
        ss >> str;

        return str;
    }

    bool isYear(const string& year)
    {
        bool result;

        if(year.size() < 5 && year.size() > 0)
        {
            result = true;

            for(unsigned int i = 0; i < year.size(); i++)
            {
                if(!isdigit(year[i]))
                    result = false;
            }
        }
        else
        {
            result = false;
        }

        return result;
    }
}
