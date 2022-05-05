
#include <iostream>
#include <string>
#include <iomanip>

// #include "View.h"
#include "Airline.h"


int main(){

  Airline air("Brussels Airlines");
  air.printParts();
  air.printAircraft();

  air.addPart("ABC", 0, 45);
  air.printParts();

  air.addAircraft("Boeing", "747");
  air.printAircraft();

  Date d(2022, 04, 03);
  air.install("747", "ABC", d);

  cout << air;


  return 0;
}
