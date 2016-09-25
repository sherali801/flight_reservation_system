#pragma once

#ifndef FLIGHTS_H
#define FLIGHTS_H

class Flights {
  int availableESeats;
  int availableBSeats;
protected:
  int serial;
  char name[6];
  char location[16];
  char destination[16];
  char takeOffTime[9];
  char landTime[9];
  long int economicFair;
  long int businessFair;
public:
  Flights();
  void setSerial(int);
  void setName(char[6]);
  void setLocation(char[16]);
  void setDestination(char[16]);
  void setTakeOffTime(char[9]);
  void setLandTime(char[9]);
  void setAvailableESeats(int);
  void setAvailableBSeats(int);
  void setEconomicFair(long int);
  void setBusinessFair(long int);
  int getSerial();
  char * getName();
  char * getLocation();
  char * getDestination();
  char * getTakeOffTime();
  char * getLandTime();
  int getAvailableESeats();
  int getAvailableBSeats();
  long int getEconomicFair();
  long int getBusinessFair();
};

#endif // !FLIGHTS_H