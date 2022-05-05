#include "Airline.h"

Airline::Airline(const string& name):name(name){}
Airline::~Airline(){
  for (int i = 0; i < planes.getSize(); i++){
    delete planes[i];
  }
  for (int i = 0; i < parts.getSize(); i++){
    delete parts[i];
  }
}
/*
  A getter for the Aircraft. Takes the aircraft registration and a pointer by reference as parameters.
  If the aircraft is found, it is returned as a pointer. Otherwise, the aircraft pointer points to NULL.
*/
void Airline::getAircraft(const string& reg, Aircraft** ac)const{
  for (int i = 0; i < planes.getSize(); i++){
    if (planes[i]->getRegistration() == reg){
      *ac = planes[i];
      return;
    }
  }
  *ac = NULL;
  cout << "Error: " << reg << " was not found. " << endl;
}
/*A getter for the Part. Takes the part name and a pointer by reference as parameters.
If the part is found, it is returned as a pointer. Otherwise, the aircraft pointer points to NULL.
*/
void Airline::getPart(const string& name, Part** part)const{
  for (int i = 0; i < parts.getSize(); i++){
    if (parts[i]->getName() == name){
      *part = parts[i];
      return;
    }
  }
  *part = NULL;
  cout << "Error: " << name << " was not found. " << endl;
}

void Airline::addAircraft(const string& type, const string& reg){
  Aircraft* newAircraft = new Aircraft(type, reg);
  planes.add(newAircraft);
}

void Airline::addPart(const string& name, int fh_inspect, int it_inspect){
  Part* newPart;

  if (fh_inspect == 0 && it_inspect == 0){
    cout << "Error: All parts must be inspected. Flight hours and Installed time cannot both be 0." << endl;
  }
  else if (fh_inspect != 0 && it_inspect != 0){
    newPart = new FHIT_Part(name, fh_inspect, it_inspect);
  }
  else if (fh_inspect == 0){
    newPart = new IT_Part(name, it_inspect);
  }
  else if (it_inspect==0){
    newPart = new FH_Part(name, fh_inspect);
  }
  parts.add(newPart);
}


void Airline::takeFlight(const string& reg, int hours){
    Aircraft* ac;
    getAircraft(reg, &ac);
    if (ac != NULL){
      ac->takeFlight(hours);
    }
}


ostream& operator<<(ostream& out, Airline& air){
  out << "--------------------------------" << air.name<< "--------------------------------" << endl;
  out << "Aircrafts: "<<endl<<air.planes<<endl;
  out << "Parts: " << endl<< air.parts<<endl;
  return out;
}


void Airline::inspectionReport(const string& reg, const Date& d){

  Aircraft* ac;
  getAircraft(reg, &ac);

  if (ac == NULL){
    return;
  }
  if (ac!=NULL){

    cout << "The following parts from "<< ac->getRegistration() <<  " require inspection:" << endl;

    Array<Part*> arr;
    ac->inspectionReport(d, arr);

    for (int i = 0; i < arr.getSize(); i++){ // print all parts that require inspection
      cout << *arr[i]<<endl;
    }
  }
}

bool Airline::install(const string& reg, const string& name, const Date& d){
  Aircraft* ac;
  getAircraft(reg, &ac);
  Part* part;
  getPart(name, &part);

  if (part != NULL && ac != NULL){
    ac->install(part, d);
    return true;
  }
  return false;
}

void Airline::printAircraft()const{
  cout << endl;
  for (int i =0;i < planes.getSize();++i){
    cout << *planes[i] << endl;
  }
}

void Airline::printParts()const{
  for (int i =0;i < parts.getSize();++i){
    cout << *parts[i] << endl;
  }
}
