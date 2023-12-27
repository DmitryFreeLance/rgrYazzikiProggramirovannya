#include <iostream>
#include <string>
using namespace std;

class client
{
private:
  string name, surname, number, adres;
public:
  string getName ()
  {
    return name;
  }
  string getSurname ()
  {
    return surname;
  }
  string getNumber ()
  {
    return number;
  }
  string getAdres ()
  {
    return adres;
  }
  client ()
  {
    
  }
  
  client (string name, string surname, string number, string adres)
  {
    this->name = name;
    this->surname = surname;
    this->number = number;
    this->adres = adres;
  }
  void print ()
  {
    cout << surname << " " << name << "  +" << number << " " << adres <<
      endl;;
  }
};
