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

            /*
            if(db.open())
            {
                qDebug() << "It's open baby";
                qDebug() << db.tables();

                QSqlQuery query(db);
                query.exec("SELECT * FROM Programmers");
                qDebug() << query.isValid();

                while(query.next())
                {
                    qDebug() << "Hæ";
                }
            }
            */
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
}
