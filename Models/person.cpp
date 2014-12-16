#include "person.h"
#include <QDebug>

Person::Person()
{
    pid = 0;
    first_name = "";
    last_name = "";
    sex = '\0';
    birth_year = 0;
    death_year = 0;
    nationality = "";
    imagePath = "";
}

Person::Person(int id, string fn, string ln, int by, int dy, string s, string n, string ip)
{
    pid = id;
    first_name = fn;
    last_name = ln;
    sex = s;
    birth_year = by;
    death_year = dy;
    nationality = n;
    imagePath = ip;
}

ostream& operator <<(ostream& out, const Person& listed)
{
        // out << setw(3) << listed.getID()+1
        out  << setw(37) << listed.getFName() + " " + listed.getLName()
             << setw(18) << listed.getNationality()
             << setw(5) << listed.getBY()
             << setw(5); if(listed.getDY() == 0){ out << "-"; } else { out << listed.getDY(); }
        out << setw(5) << listed.getSex()
             << endl;

    return out;
}

// Gettarar:
int Person::getID() const
{
    return pid;
}
string Person::getFName() const
{
    return first_name;
}

string Person::getLName() const
{
    return last_name;
}

int Person::getBY() const
{
    return birth_year;
}

int Person::getDY() const
{
    return death_year;
}

string Person::getSex() const
{
    return sex;
}

string Person::getNationality() const
{
    return nationality;
}

string Person::getImagePath() const
{
    return imagePath;
}

string Person::toString()
{
   string result = this->getFName() + " " + this->getLName();
   result += " " + this->getNationality();
   result += " " + utils::int2str(this->getBY());
   result += " " + utils::int2str(this->getDY());

   return result;
}

bool Person::contains(string str)
{
    if(str == "")
    {
        return true;
    }

    string searchStringToLower = utils::str2lower(str);

    if(utils::str2lower(this->toString()).find(searchStringToLower) != string::npos)
    {
        return true;
    }
    else
    {
        return false;
    }
}

string Person::getWholeName() const
{
    string result = this->getFName() + " ";
    result += this->getLName();
    return result;
}

string Person::getLifespan() const
{
    string result = "";
    int born = this->getBY();
    int dead = this->getDY();

    if(born != 0)
        result += utils::int2str(born);
    result += "-";
    if(dead != 0)
        result += utils::int2str(dead);

    return result;

}
