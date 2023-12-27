#include <iostream>
#include "controller.h"
#include <stdlib.h>
#include <time.h>
using namespace std;


int
main ()
{
  srand (time (NULL));
  controller ctrl;
  ctrl.execute ();
}
