#ifndef COMPUTER_H
#define COMPUTER_H
#include <string>
#include <fstream>
#include <iomanip>
#include "utilities.h"

using namespace std;

class Computer
{
public:
    Computer();
    Computer(int cid, string name, string type, int year_built, bool build, string imagePath);
    int getID() const;
    string getName() const;
    string getType() const;
    int getBuildYear() const;
    bool getBuild() const;
    string getimagePath() const;
    string toString();
    bool contains(string str);
    // friend ostream& operator <<(ostream& out, const Computer& listed);
private:
    int cid;
    string name;
    string type;
    int year_built;
    bool build;
    string imagePath;
};

#endif // COMPUTER_H
