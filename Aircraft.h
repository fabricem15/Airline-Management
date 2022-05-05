#ifndef AIRCRAFT_H
#define AIRCRAFT_H
#include "Part.h"
#include "Array.h"
#include <iostream>
#include <string>

using namespace std;

class Aircraft{
  friend ostream& operator<<(ostream&, Aircraft&);
  public:
    Aircraft(const string& type, const string& reg);
    ~Aircraft();

    const string& getRegistration()const;
    Array<Part*> getParts()const;
    void install(Part*, const Date&);
    void takeFlight(int hours);
    void inspectionReport(const Date&, Array<Part*>&)const;
  private:
    string type;
    string registration;
    int flighthours;
    Array<Part*> parts;
};
#endif
