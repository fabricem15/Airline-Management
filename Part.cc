#include "Part.h"

/*
    PART
*/

Part::Part(const string& n): name(n) {
  flighthours = 0;
}
Part::~Part(){}
const string& Part::getName()const{ return name;}

void Part::addFlightHours(int h){flighthours += h;}
void Part::install(const Date& d){installationDate = d;}

const Date& Part::getDate()const{return installationDate;}

void Part::print(ostream& out)const{
  out << endl << left<< setw(23)<<"Part: " <<name << endl << left<< setw(23)<<"Flight Hours: " << flighthours << endl;
  out << left<< setw(23)<<"Installation date: " << installationDate;
}
/*
    FH_PART
*/

FH_Part::FH_Part(const string& name, int number): fh_inspect(number), Part(name) {}
FH_Part::~FH_Part(){}
bool FH_Part::inspection(const Date& d)const{
  if (flighthours >= fh_inspect){return true;}
  return false;
}

void FH_Part::print(ostream& out)const{
  Part::print(out);
  out << left<< setw(23)<<"Inspect every: " << fh_inspect << " flight hours" << endl;
}


/*
    IT_PART
*/

IT_Part::IT_Part(const string& n, int num):it_inspect(num), Part(n){}
IT_Part::~IT_Part(){}
bool IT_Part::inspection(const Date& d)const{
  if (d.toDays() -getDate().toDays() >= it_inspect){return true;}
  return false;
}

void IT_Part::print(ostream& out)const{
  Part::print(out);
  out << left<< setw(23)<<"Inspect every: " << it_inspect << " days installed" << endl;
}

/*
    FHIT_PART
*/

FHIT_Part::FHIT_Part(const string& name, int fh, int it): FH_Part(name, fh), IT_Part(name, it), Part(name){}
FHIT_Part::~FHIT_Part(){}
bool FHIT_Part::inspection(const Date &d)const{
  if (IT_Part::inspection(d) || FH_Part::inspection(d)){
    return true;
  }
  return false;
}
void FHIT_Part::print(ostream& out)const{
  Part::print(out);
  out <<left<< setw(23)<<"Inspect every: " << fh_inspect << " flight hours and " << it_inspect << " days installed" << endl;
}


ostream& operator<<(ostream& out, const Part& part){
  part.print(out);
  return out;
}
