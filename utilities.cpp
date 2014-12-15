#include "utilities.h"
#include <QString>
#include <QDate>

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

        QDate date = QDate::currentDate();
        int year_now = date.year();

        if(atoi(year.c_str()) <= year_now && year.size() > 0)
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

    void trimWS(string& str)
    {
        stringstream ss;
        ss << str;
        char nextin;
        char last;
        string input, output;
        getline(ss, input);

        for (int i = 0; i < strlen(input.c_str()); i++)
        {
            if(input[i] != ' ')
            {
                if(input[i-1] == ' ')
                    output += " ";
                output += input[i];
            }
        }

        str = output;
    }

    void firstCap(string& str)
    {
        if(islower(str[0]))
            str[0] = toupper(str[0]);
    }
}
