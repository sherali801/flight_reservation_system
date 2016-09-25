#include "Passengers.h"

#include <iostream>
#include <fstream>
using namespace std;

Passengers::Passengers() { }

void Passengers::setPClass(bool pClass) { this->pClass = pClass; }

void Passengers::setPFair(int pFair) { this->pFair = pFair; }

void Passengers::setPName(char pName[25]) {
  for (int i = 0; i < 25; i++) {
    this->pName[i] = pName[i];
  }
}

void Passengers::setPAddress(char pAddress[50]) {
  for (int i = 0; i < 50; i++) {
    this->pAddress[i] = pAddress[i];
  }
}

void Passengers::setPGender(char pGender) { this->pGender = pGender; }

void Passengers::setPAge(int pAge) { this->pAge = pAge; }

void Passengers::setPSeatNo(int pSeatNo) { this->pSeatNo = pSeatNo; }

void Passengers::setTicketNo(int ticketNo) { this->ticketNo = ticketNo; }

bool Passengers::getPClass() { return pClass; }

int Passengers::getPFair() { return pFair; }

char * Passengers::getPName() { return pName; }

char * Passengers::getPAddress() { return pAddress; }

char Passengers::getPGender() { return pGender; }

int Passengers::getPAge() { return pAge; }

int Passengers::getPSeatNo() { return pSeatNo; }

int Passengers::getTicketNo() { return ticketNo; }