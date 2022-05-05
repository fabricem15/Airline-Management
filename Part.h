#ifndef PART_H
#define PART_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Date.h"
using namespace std;

class Part{
  friend ostream& operator<<(ostream&, const Part&);
  public:
    Part(const string& n);
    virtual ~Part();
    // getters
    const string& getName()const;
    // member functions
    void addFlightHours(int);
    void install(const Date&);

    // pure virtual function
    virtual bool inspection(const Date& d)const =0;
    virtual void print(ostream&)const;
    const Date& getDate()const;
  protected:
    string name;
    Date installationDate;
    int flighthours;

};

class FH_Part: virtual public Part{
  public:
    FH_Part(const string& name, int number);
    virtual ~FH_Part();
    virtual bool inspection(const Date& d)const;
    virtual void print(ostream&)const;
  protected:
    int fh_inspect;
};

class IT_Part: virtual public Part{
  public:
    IT_Part(const string& n, int num);
    virtual ~IT_Part();
    virtual bool inspection(const Date& d)const;
    virtual void print(ostream&)const;
  protected:
    int it_inspect;
};


class FHIT_Part: public FH_Part, public IT_Part{
  public:
    FHIT_Part(const string& name, int fh, int it);
    virtual ~FHIT_Part();
    virtual bool inspection(const Date& d)const;
    virtual void print(ostream&)const;
};

#endif
