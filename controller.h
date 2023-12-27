#include <iostream>
#include "orders.h"
using namespace std;

class controller
{
  void menu ()
  {
    cout << "Commands: " << endl;
    cout << "[1] vivesti vse zakazi" << endl;
    cout << "[2] sozdat novuyu zapis vzakaze" << endl;
    cout << "[3] udalit zapis o zakaze" << endl;
    cout << "[4] dobavit tekushie zakazi v fail" << endl;
    cout << "[5] perezapisat tekushiy fail s zakazami" << endl;
    cout << "[6] zagruzit zakazi izf aila" << endl;
    cout << "[7] otredaktirovat zakazi" << endl;
    cout << "[8] exit" << endl;
  }
private:
    tipografiya current_service;
public:
  controller ()
  {
  }

  void execute ()
  {
    int run = 1;
    while (run)
      {
	menu ();
	int var = 0;
	while (var < 1 || var > 8)
	  {
	    cout << "Input variant: ";
	    cin >> var;
	  }
	if (var == 8)
	  {
	    run = 0;
	  }
	if (var == 1)
	  {
	    current_service.print ();
	  }
	if (var == 2)
	  {
	    current_service.addRc ();
	    cout << "zakaz sozdan!";
	  }
	if (var == 3)
	  {
	    current_service.print ();
	    cout << "vvedite nomer zakaza kotoriy nado delete:\n";
	    int n;
	    cin >> n;
	    current_service.deleteRc (n);
	  }
	if (var == 4)
	  {
	    current_service.saveToFile (true);
	    cout << "zakazi soxraneni!" << endl;
	  }
	if (var == 5)
	  {
	    current_service.saveToFile (false);
	  }
	if (var == 6)
	  {
	    current_service.loadFile ();
	    cout << "zakazi iz faila uspeshno zagruzheni!" << endl;
	  }
	if (var == 7)
	  {
	    cout << "viberite zakaz dlya redaktirovaniya:" << endl;
	    int choose = 0;
	    while (choose < 1 || choose > current_service.getN () + 1)
	      {
		current_service.print ();
		cout << "[" << current_service.getN () +
		  1 << "] " << "otmena." << endl;
		cin >> choose;

	      }
	    current_service.changeRecord (choose);
	    cout << "zakaz otredaktirovan!" << endl;
	  }
      }
  }


};
