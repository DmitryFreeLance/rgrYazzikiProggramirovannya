#include <iostream>
#include <string>
#include <stdlib.h>
#include "people.h"
#include <time.h>
using namespace std;

class record
{
private:
  string type_object[4] =
  {
  "listovki", "birki", "nakleiki", "magniti"};
  string object;
  int number;
  int amount;
  client cl;

public:
  record ()
  {
    object = "listovki";
    amount = 10;
    number = 100;
  }
  record (string name, string surname, string number, string adres,
	  string object, int amount, int numb)
  {
    this->cl = *(new client (name, surname, number, adres));
    this->object = object;
    this->amount = amount;
    this->number = numb;
  }
  string getObject ()
  {
    return object;
  }
  int getAmount ()
  {
    return amount;
  }
  int getNumber ()
  {
    return number;
  }
  client getClient ()
  {
    return cl;
  }
  void getClientInfo ()
  {
    cl.print ();
  }
  void print ()
  {
    cl.print ();
    cout << "tovar: " << object << "; kol vo partiy: " << amount <<
      ". kol vo v ozdnoy partii: " << number << endl;
  }
  void change ()
  {
    cout << "viberite punkt zakaza dlya redaktirovaniya:\n";
    cout << "1 - tovar\n";
    cout << "2 - kol vo partiy\n";
    cout << "3 - kol vo shtuk tovara v ondoy partii\n";
    cout << "4 - informaciya o kliente\n";
    int choose = 0;
    while (choose < 1 || choose > 4)
      {
	cin >> choose;
      }
    switch (choose)
      {
      case 1:
	{
	  cout << "viberite tip tovara:" << endl;
	  int select = 0;
	  for (int i = 0; i < 4; i++)
	    {
	      cout << "[" << i + 1 << "] " << type_object[i] << endl;
	    }
	  while (select < 1 || select > 4)
	    {
	      cin >> select;
	    }
	  object = type_object[select - 1];
	  break;
	}
      case 2:
	{
	  cout << "ukazhiete kol vo partiy tovara: ";
	  cin >> amount;
	  break;
	}
      case 3:
	{
	  int select = 0;
	  cout << "ukazhite kol vo shtuk tovara v ondoy partii:" << endl;
	  do
	    {
	      cin >> number;

	    }
	  while (number < 1);

	  break;
	}
      case 4:
	{
	  string name, surname, number, adres;
	  cout << "ukazhite imya novogo klienta: ";
	  cin >> name;
	  cout << "ukazhite familiyu novogo klienta: ";
	  cin >> name;
	  cout << "ukazhite nomer telephone: ";
	  cin >> number;
	  cout << "ukazhite kompaniyu zakazhchika";
	  cin >> adres;
	  cl = client (name, surname, number, adres);
	  break;
	}
      default:
	break;
      }
  }
};
