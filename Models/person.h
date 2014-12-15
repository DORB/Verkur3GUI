#ifndef PERSON_H
#define PERSON_H

#include <string>
#include <iostream>
#include <iomanip>
#include "utilities.h"
using namespace std;

class Person
{
public:
    Person();
    Person(int id, string fn, string ln, int by, int dy, string s, string n, string ip);
    // friend ostream& operator <<(ostream& out, const Person& p);
    int getID() const;
    int getBY() const;
    int getDY() const;
    string getFName() const;
    string getLName() const;
    string getSex() const;
    string getNationality() const;
    string toString();
    string getWholeName();
    string getImagePath() const;
    bool contains(string str);
private:
    int pid;
    int birth_year;
    int death_year;
    string first_name;
    string last_name;
    string sex;
    string nationality;
    string imagePath;
};

#endif // PERSON_H
