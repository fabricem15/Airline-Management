#ifndef AIRLINE_H
#define AIRLINE_H

#include "Array.h"
#include "Part.h"
#include "Aircraft.h"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
class Airline{
  friend ostream& operator<<(ostream&, Airline&);

  public:
    Airline(const string& name);
    ~Airline();
    void addPart(const string& part, int fh_inspect, int it_inspect);
    void addAircraft(const string& type, const string& );

    void printAircraft()const;
    void printParts()const;
    void takeFlight(const string&, int);
    void inspectionReport(const string& reg,  const Date& d);
    bool install(const string&, const string&, const Date&);
  private:
    string name;
    Array<Part*> parts;
    Array<Aircraft*> planes;

    //helper functions
    void getAircraft(const string& reg, Aircraft** ac)const;
    void getPart(const string& part, Part**)const;
};
#endif
