#include "computer.h"

Computer::Computer()
{
}

Computer::Computer(int id, string n, string t, int yb, bool b, string ip)
{
    cid = id;
    name = n;
    type = t;
    year_built = yb;
    build = b;
    imagePath = ip;
}

/*
ostream& operator <<(ostream& out, const Computer& listed)
{
    // out << setw(3) << listed.getID()
    out  << setw(27) << listed.getName()
         << setw(15) << listed.getType()
         << setw(5)  << listed.getBuildYear();
    out << setw(6); (listed.getBuild())? out << "Yes" : out << "No";
    out << endl;

    return out;
}
*/

int Computer::getID() const
{
    return cid;
}

string Computer::getName() const
{
    return name;
}

string Computer::getType() const
{
    return type;
}

int Computer::getBuildYear() const
{
    return year_built;
}

bool Computer::getBuild() const
{
    return build;
}

string Computer::getimagePath() const
{
    return imagePath;
}

string Computer::toString()
{
    string result = this->getName() + " " + this->getType();
    result += " " + utils::int2str(this->getBuildYear());

    return result;
}

bool Computer::contains(string str)
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
