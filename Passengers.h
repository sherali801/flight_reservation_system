#pragma once

#ifndef PASSENGERS_H
#define PASSENGERS_H

#include "Flights.h"

class Passengers : public Flights {
  bool pClass;//true if economy class or false for business class 
  int pFair;
  char pName[25];
  char pAddress[50];
  char pGender;
  int pAge;
  int pSeatNo;
  int ticketNo;
public:
  Passengers();
  void setPClass(bool);
  void setPFair(int);
  void setPName(char[25]);
  void setPAddress(char[50]);
  void setPGender(char);
  void setPAge(int);
  void setPSeatNo(int);
  void setTicketNo(int);
  bool getPClass();
  int getPFair();
  char * getPName();
  char * getPAddress();
  char getPGender();
  int getPAge();
  int getPSeatNo();
  int getTicketNo();
};

#endif // !PASSENGERS_H