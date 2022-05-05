#include "Aircraft.h"

Aircraft::Aircraft(const string& type, const string& reg): type(type), registration(reg), flighthours(0){
}

Aircraft::~Aircraft(){}
const string& Aircraft::getRegistration()const{
  return registration;
}

void Aircraft::install(Part* part, const Date& d){
  part->install(d);
  parts.add(part);
}


void Aircraft::takeFlight(int hours){
  if (hours < 0){return;}
  flighthours += hours;
  for (int i = 0; i < parts.getSize(); ++i){
    parts[i]->addFlightHours(hours);
  }
}

Array<Part*> Aircraft::getParts()const{
  return parts;
}
void Aircraft::inspectionReport(const Date& d, Array<Part*>& newParts)const{
  for (int i= 0; i < parts.getSize(); ++i){
    if (parts[i]->inspection(d)){
      newParts.add(parts[i]);
    }
  }
}

ostream& operator<<(ostream& out, Aircraft& plane){
  out << left<< setw(17)<<"Aircraft Type: " << plane.type << endl<< left<< setw(17)<<"Registration: " << plane.registration << endl;
  out << left<< setw(17)<<"Flight Hours: " << plane.flighthours << endl;
  return out;
}
