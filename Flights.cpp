#include "Flights.h"

Flights::Flights() { }

void Flights::setSerial(int serial) { this->serial = serial; }

void Flights::setName(char name[6]) {
  for (int i = 0; i < 6; i++) {
    this->name[i] = name[i];
  }
}

void Flights::setLocation(char location[16]) {
  for (int i = 0; i < 16; i++) {
    this->location[i] = location[i];
  }
}

void Flights::setDestination(char destination[16]) {
  for (int i = 0; i < 16; i++) {
    this->destination[i] = destination[i];
  }
}

void Flights::setTakeOffTime(char takeOffTime[9]) {
  for (int i = 0; i < 9; i++) {
    this->takeOffTime[i] = takeOffTime[i];
  }
}

void Flights::setLandTime(char landTime[9]) {
  for (int i = 0; i < 9; i++) {
    this->landTime[i] = landTime[i];
  }
}

void Flights::setAvailableESeats(int availableESeats) { this->availableESeats = availableESeats; }

void Flights::setAvailableBSeats(int availableBSeats) { this->availableBSeats = availableBSeats; }

void Flights::setEconomicFair(long int econimicFair) { this->economicFair = econimicFair; }

void Flights::setBusinessFair(long int businessFair) { this->businessFair = businessFair; }

int Flights::getSerial() { return serial; }

char * Flights::getName() { return name; }

char * Flights::getLocation() { return location; }

char * Flights::getDestination() { return destination; }

char * Flights::getTakeOffTime() { return takeOffTime; }

char * Flights::getLandTime() { return landTime; }

int Flights::getAvailableESeats() { return availableESeats; }

int Flights::getAvailableBSeats() { return availableBSeats; }

long int Flights::getEconomicFair() { return economicFair; }

long int Flights::getBusinessFair() { return businessFair; }
