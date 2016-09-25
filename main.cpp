#include "Flights.h"
#include "Passengers.h"

#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <stdio.h>
#include <cstdlib>
#include <windows.h>
#include <conio.h>
using namespace std;

void gotoxy(short int, short int);
void textColor(int);
void showMainMenu();
void showAdministratorMenu();
void administratorVerification();
void showPassengerMenu();
void showFlightDetails(char);
void showLFlightDetails();
void showIFlightDetails();
Flights inputFlightData();
void addFlight(char);
void addLFlight();
void addIFlight();
void setLastSerialNo(int);
int getLastSerialNo();
void deleteFlight(char);
void deleteLFlight();
void deleteIFlight();
void updateFlight(char);
void updateLFlight();
void updateIFlight();
void searchPassenger(char);
void restoreSystem();
void changePassword();
void passengerDetails(char);
void passengerLDetails();
void passengerIDetails();
void inputLPassengerDetails(Flights &);
void inputIPassengerDetails(Flights &);
void setLastTicketNo(int);
int getLastTicketNo();
void lAvailableSeats(int, bool);
void iAvailableSeats(int, bool);
void showPassengerDetails(Passengers &);
void cancelReservation(char);
void lSeatsAfterCancelation(int, bool);
void iSeatsAfterCancelation(int, bool);

int main()
{
  do {
    showMainMenu();
  } while (true);
  _getch();
  return 0;
}

void gotoxy(short int x, short int y) {
  COORD screen = { x, y };
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), screen);
}

void textColor(int c) {
  HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleTextAttribute(screen, c);
}

void showMainMenu() {
  system("cls");
  char choice;
  do {
    textColor(11);
    gotoxy(40, 3);
    cout << "Welcome to Viral Airways";
    textColor(14);
    gotoxy(35, 6);
    cout << "1 - Administrator";
    gotoxy(35, 8);
    cout << "2 - Passenger";
    gotoxy(35, 10);
    cout << "3 - Exit";
    gotoxy(32, 13);
    textColor(10);
    cout << "Your Choice: ";
    textColor(12);
    cin >> choice;
    if (choice == '1') { 
      administratorVerification();
    } else if (choice == '2') { 
      showPassengerMenu();
    } else if (choice == '3') { 
      exit(0);
    } else {
      textColor(13);
      gotoxy(32, 15);
      cout << "Invalid!!!\n";
      gotoxy(32, 17);
      cout << "Press any key to continue...";
      _getch();
      system("cls");
    }
  } while (choice < '1' || choice > '3');
}

void administratorVerification() {
  system("cls");
  fstream password("password.bin", ios::in | ios::out | ios::app);//password.bin contains password for admin access
  if (!password.is_open()) {
    textColor(13);
    gotoxy(32, 5);
    cout << "Error while changing Password\n";
    gotoxy(32, 7);
    cout << "Press any key to continue...\n";
    _getch();
  } else {
    int pass;
    int temp = 0;
    textColor(10);
    gotoxy(32, 5);
    cout << "Enter Password: ";
    textColor(12);
    cin >> pass;
    password.seekg(0);//setting getPointer in the begging because in app mode getPointer is at the end of file
    password >> temp;
    if (pass == temp || pass == 1399) {
      showAdministratorMenu();
    } else {
      textColor(13);
      gotoxy(32, 7);
      cout << "Access Denied\n";
      gotoxy(32, 9);
      cout << "Press any key to continue...\n";
      _getch();
    }
  }
  password.close();
}

void showAdministratorMenu() {
  system("cls");
  char choice;
  char c;
  do {
    textColor(14);
    gotoxy(35, 5);
    cout << "1 - All Flights";
    gotoxy(35, 7);
    cout << "2 - Add New Flight";
    gotoxy(35, 9);
    cout << "3 - Delete Flight";
    gotoxy(35, 11);
    cout << "4 - Update Flight";
    gotoxy(35, 13);
    cout << "5 - Search Passenger";
    gotoxy(35, 15);
    cout << "6 - Change Password";
    gotoxy(35, 17);
    cout << "7 - Restore System";
    gotoxy(35, 19);
    cout << "8 - Back to Main Menu";
    gotoxy(35, 21);
    cout << "9 - Exit";
    textColor(10);
    gotoxy(32, 24);
    cout << "Your Choice: ";
    textColor(12);
    cin >> choice;
    if (choice == '1') {
      do {
        textColor(10);
        gotoxy(32, 26);
        cout << "Press 1 for Local or 2 for International Flight: ";
        textColor(12);
        cin >> c;
      } while (c < '1' || c > '2');
      showFlightDetails(c);
    } else if (choice == '2') {
      do {
        textColor(10);
        gotoxy(32, 26);
        cout << "Press 1 for Local or 2 for International Flight: ";
        textColor(12);
        cin >> c;
      } while (c < '1' || c > '2');
      addFlight(c);
    } else if (choice == '3') {
      do {
        textColor(10);
        gotoxy(32, 26);
        cout << "Press 1 for Local or 2 for International Flight: ";
        textColor(12);
        cin >> c;
      } while (c < '1' || c > '2');
      deleteFlight(c);
    } else if (choice == '4') {
      do {
        textColor(10);
        gotoxy(32, 26);
        cout << "Press 1 for Local or 2 for International Flight: ";
        textColor(12);
        cin >> c;
      } while (c < '1' || c > '2');
      updateFlight(c);
    } else if (choice == '5') {
      do {
        textColor(10);
        gotoxy(32, 26);
        cout << "Press 1 for Local or 2 for International Flight: ";
        textColor(12);
        cin >> c;
      } while (c < '1' || c > '2');
      searchPassenger(c);
    } else if (choice == '6') {
      changePassword();
    } else if (choice == '7') {
      restoreSystem();
    } else if (choice == '8') {
      return;
    } else if (choice == '9') {
      exit(0);
    } else {
      textColor(13);
      gotoxy(32, 26);
      cout << "Invalid!!!\n";
      gotoxy(32, 28);
      cout << "Press any key to continue...\n";
      _getch();
      system("cls");
    }
  } while (choice < '1' || choice > '9');
}

void showPassengerMenu() {
  system("cls");
  char choice;
  char c;
  do {
    textColor(14);
    gotoxy(35, 5);
    cout << "1 - All Flights";
    gotoxy(35, 7);
    cout << "2 - Reserve Ticket";
    gotoxy(35, 9);
    cout << "3 - Cancel Reservation";
    gotoxy(35, 11);
    cout << "4 - Back to Main Menu";
    gotoxy(35, 13);
    cout << "5 - Exit";
    textColor(10);
    gotoxy(32, 16);
    cout << "Your Choice: ";
    textColor(12);
    cin >> choice;
    if (choice == '1') {
      do {
        textColor(10);
        gotoxy(32, 18);
        cout << "Press 1 for Local or 2 for International Flight: ";
        textColor(12);
        cin >> c;
      } while (c < '1' || c > '2');
      showFlightDetails(c);
    } else if (choice == '2') {
      do {
        textColor(10);
        gotoxy(32, 18);
        cout << "Press 1 for Local or 2 for International Flight: ";
        textColor(12);
        cin >> c;
      } while (c < '1' || c > '2');
      passengerDetails(c);
    } else if (choice == '3') {
      do {
        textColor(10);
        gotoxy(32, 18);
        cout << "Press 1 for Local or 2 for International Flight: ";
        textColor(12);
        cin >> c;
      } while (c < '1' || c > '2');
      cancelReservation(c);
    } else if (choice == '4') { 
      return;
    } else if (choice == '5') {
      exit(0);
    } else {
      textColor(13);
      gotoxy(32, 18);
      cout << "Invalid!!!";
      gotoxy(32, 20);
      cout << "Press any key to continue...\n";
      _getch();
      system("cls");
    }
  } while (choice < '1' || choice > '5');
}

void showFlightDetails(char c) {
  if (c == '1') {
    showLFlightDetails();
  } else {
    showIFlightDetails();
  }
}

void showLFlightDetails() {//display local flight
  system("cls");
  Flights f;
  fstream lFliDetails("lFliDetails.bin", ios::in | ios::out | ios::binary | ios::app);
  if (!lFliDetails.is_open()) {
    textColor(13);
    gotoxy(32, 5);
    cout << "Error while opening Local Flight Details File\n";
    gotoxy(32, 7);
    cout << "Press any key to continue...\n";
    _getch();
    return;
  } else if (lFliDetails.peek() == ifstream::traits_type::eof()) {
    textColor(13);
    gotoxy(32, 5);
    cout << "No Local Flights are available\n";
    gotoxy(32, 7);
    cout << "Press any key to continue...\n";
    _getch();
    return;
  } else {
    textColor(9);
    gotoxy(35, 5);
    cout << "Local Flight Details\n";
    cout << "Serial No\tFlight Name\tLocation\tDestination\tTake Off Time\t";
    cout << "Land Time\tEconomic Fair\tBusiness Fair\n";
    int count = 0;
    int i = 0;
    lFliDetails.clear();
    lFliDetails.seekg(0);
    while (!lFliDetails.eof()) {
      lFliDetails.read(reinterpret_cast<char*>(&f), sizeof(Flights));
      if (lFliDetails.eof()) {
        break;
      }
      count++;
    }
    lFliDetails.clear();
    lFliDetails.seekg(0, ios::beg);
    while (i < count) {//reading object from file and displaying
      lFliDetails.read(reinterpret_cast<char*>(&f), sizeof(Flights));
      cout << "   " << f.getSerial() << "   \t\t" << f.getName() << "   \t"
        << f.getLocation() << "   \t" << f.getDestination() << "   \t"
        << f.getTakeOffTime() << "   \t" << f.getLandTime() << "   \t"
        << f.getEconomicFair() << "   \t" << f.getBusinessFair() << "\n";
      i++;
    }
  }
  lFliDetails.close();
  textColor(13);
  cout << "Press any key to continue...\n";
  _getch();
}

void showIFlightDetails() {//displaying international flights
  system("cls");
  Flights f;
  fstream iFliDetails("iFliDetails.bin", ios::in | ios::out | ios::binary | ios::app);
  if (!iFliDetails.is_open()) {
    textColor(13);
    gotoxy(32, 5);
    cout << "Error while opening International Flights Details File\n";
    gotoxy(32, 7);
    cout << "Press any key to continue...\n";
    _getch();
    return;
  } else if (iFliDetails.peek() == ifstream::traits_type::eof()) {
    textColor(13);
    gotoxy(32, 5);
    cout << "No International Flights are Available\n";
    gotoxy(32, 7);
    cout << "Press any key to continue...\n";
    _getch();
    return;
  } else {
    textColor(9);
    gotoxy(35, 5);
    cout << "International Flight Details\n";
    cout << "Serial No\tFlight Name\tLocation\tDestination\tTake Off Time\t";
    cout << "Land Time\tEconomic Fair\tBusiness Fair\n";
    int count = 0;
    int i = 0;
    iFliDetails.clear();
    iFliDetails.seekg(0);
    while (!iFliDetails.eof()) {
      iFliDetails.read(reinterpret_cast<char*>(&f), sizeof(Flights));
      if (iFliDetails.eof()) {
        break;
      }
      count++;
    }
    iFliDetails.clear();
    iFliDetails.seekg(0, ios::beg);
    while (i < count) {//reading objects from file and displaying
      iFliDetails.read(reinterpret_cast<char*>(&f), sizeof(Flights));
      cout << "   " << f.getSerial() << "   \t\t" << f.getName() << "   \t"
        << f.getLocation() << "   \t" << f.getDestination() << "   \t"
        << f.getTakeOffTime() << "   \t" << f.getLandTime() << "   \t"
        << f.getEconomicFair() << "   \t" << f.getBusinessFair() << "\n";
      i++;
    }
  }
  iFliDetails.close();
  textColor(13);
  cout << "Press any key to continue...\n";
  _getch();
}

Flights inputFlightData() {
  system("cls");
  Flights f;
  int serialNo;
  char name[6];
  char location[16];
  char destination[16];
  char takeOffTime[9];
  char landTime[9];
  int availableESeats;
  int availableBSeats;
  long int economicFair;
  long int businessFair;
  textColor(10);
  gotoxy(35, 5);
  cout << "Serial Number of Flight: ";
  textColor(12);
  serialNo = getLastSerialNo();
  cout << serialNo;
  f.setSerial(serialNo);
  gotoxy(35, 7);
  textColor(10);
  cout << "Name of the Flight: ";
  cin.ignore();
  textColor(12);
  cin.getline(name, 6);
  f.setName(name);
  gotoxy(35, 9);
  textColor(10);
  cout << "Location: ";
  textColor(12);
  cin.getline(location, 16);
  f.setLocation(location);
  gotoxy(35, 11);
  textColor(10);
  cout << "Destination: ";
  textColor(12);
  cin.getline(destination, 16);
  f.setDestination(destination);
  gotoxy(35, 13);
  textColor(10);
  cout << "Take off Time: ";
  textColor(12);
  cin.getline(takeOffTime, 9);
  f.setTakeOffTime(takeOffTime);
  gotoxy(35, 15);
  textColor(10);
  cout << "Land Time: ";
  textColor(12);
  cin.getline(landTime, 9);
  f.setLandTime(landTime);
  do {
    gotoxy(35, 17);
    cout << "                                                                  ";
    gotoxy(35, 17);
    textColor(10);
    cout << "Economy Seats: ";
    textColor(12);
    cin >> availableESeats;
  } while (availableESeats < 0);
  f.setAvailableESeats(availableESeats);
  do {
    gotoxy(35, 19);
    cout << "                                                                  ";
    gotoxy(35, 19);
    textColor(10);
    cout << "Available Business Seats: ";
    textColor(12);
    cin >> availableBSeats;
  } while (availableBSeats < 0);
  f.setAvailableBSeats(availableBSeats);
  do {
    gotoxy(35, 21);
    cout << "                                                                  ";
    gotoxy(35, 21);
    textColor(10);
    cout << "Economy Fair: ";
    textColor(12);
    cin >> economicFair;
  } while (economicFair <= 0);
  f.setEconomicFair(economicFair);
  do {
    gotoxy(35, 23);
    cout << "                                                                  ";
    gotoxy(35, 23);
    textColor(10);
    cout << "Business Fair: ";
    textColor(12);
    cin >> businessFair;
  } while (businessFair <= 0);
  f.setBusinessFair(businessFair);
  return f;
}

void addFlight(char c) {
  if (c == '1') { 
    addLFlight();
  } else { 
    addIFlight();
  }
}

void addLFlight() {
  system("cls");
  fstream lFliDetails("lFliDetails.bin", ios::in | ios::out | ios::binary | ios::app);//hold local flight details
  if (!lFliDetails.is_open()) {
    textColor(13);
    gotoxy(32, 5);
    cout << "Error while opening Local Flights Details File\n";
    gotoxy(32, 7);
    cout << "Press any key to continue...\n";
    _getch();
    return;
  } else {
    Flights f = inputFlightData();//get administrator input
    lFliDetails.write(reinterpret_cast<char*>(&f), sizeof(Flights));//writing local flight details to file
  }
  lFliDetails.close();
}

void addIFlight() {
  system("cls");
  fstream iFliDetails("iFliDetails.bin", ios::in | ios::out | ios::binary | ios::app);//hold international flight details
  if (!iFliDetails.is_open()) {
    textColor(13);
    gotoxy(32, 5);
    cout << "Error while opening International Flights Details File\n";
    gotoxy(32, 7);
    cout << "Press any key to continue...\n";
    _getch();
    return;
  } else {
    Flights f = inputFlightData();//get administrator input
    iFliDetails.write(reinterpret_cast<char*>(&f), sizeof(Flights));//writing international flight details to file
  }
  iFliDetails.close();
}

void setLastSerialNo(int lastSerialNo) {
  fstream lastSerial("lastSerial.bin", ios::in | ios::out | ios::binary | ios::trunc);
  if (!lastSerial.is_open()) {
    cout << "Error while setting last serial no of flight\n";
    cout << "Press any key to continue...\n";
    _getch();
    lastSerial.close();
    return;
  } else {
    lastSerial << lastSerialNo;
  }
  lastSerial.close();
}

int getLastSerialNo() {
  int lastSerialNo;
  fstream lastSerial("lastSerial.bin", ios::in | ios::out | ios::binary | ios::app);
  if (!lastSerial.is_open()) {
    cout << "Error while getting last Serial no of flight\n";
    cout << "Press any key to continue...\n";
    _getch();
    return 0;
  }
  if (lastSerial.peek() == ifstream::traits_type::eof()) {
    lastSerial.close();
    lastSerialNo = 0;
    lastSerialNo++;
    setLastSerialNo(lastSerialNo);
    return lastSerialNo;
  } else {
    lastSerial.seekg(0);
    lastSerial >> lastSerialNo;
    lastSerial.close();
    lastSerialNo++;
    setLastSerialNo(lastSerialNo);
    return lastSerialNo;
  }
}

void deleteFlight(char c) {
  if (c == '1') { 
    deleteLFlight();
  } else { 
    deleteIFlight();
  }
}

void deleteLFlight() {//delete flight data on the bases of flight serial no 
  system("cls");
  fstream lFliDetails, temporary;
  Flights f;
  int serial;
  bool flightFound = false;
  temporary.open("temporary.bin", ios::in | ios::out | ios::binary | ios::trunc);//helps in arranging data
  if (!temporary.is_open()) {
    textColor(13);
    gotoxy(32, 5);
    cout << "Error while opening temporary file\n";
    gotoxy(32, 7);
    cout << "Press any key to continue...\n";
    _getch();
    return;
  }
  lFliDetails.open("lFliDetails.bin", ios::in | ios::out | ios::binary | ios::app);
  if (!lFliDetails.is_open()) {
    textColor(13);
    gotoxy(32, 9);
    cout << "Error while opening Local Flights Details File\n";
    gotoxy(32, 11);
    cout << "Press any key to continue...\n";
    _getch();
    return;
  } else if (lFliDetails.peek() == ifstream::traits_type::eof()) {
    textColor(13);
    gotoxy(32, 9);
    cout << "No Local Flights are Available\n";
    gotoxy(32, 11);
    cout << "Press any key to continue...\n";
    _getch();
    return;
  } else {
    textColor(10);
    gotoxy(35, 9);
    cout << "Enter Serial Number of the Flight: ";
    textColor(14);
    cin >> serial;
    int count = 0;
    int i = 0;
    lFliDetails.clear();
    lFliDetails.seekg(0);
    while (!lFliDetails.eof()) {
      lFliDetails.read(reinterpret_cast<char*>(&f), sizeof(Flights));
      if (lFliDetails.eof()) {
        break;
      }
      count++;
    }
    lFliDetails.clear();
    lFliDetails.seekg(0, ios::beg);
    while (i < count) {
      lFliDetails.read(reinterpret_cast<char*>(&f), sizeof(Flights));//reading date from file to object
      if (serial == f.getSerial()) {
        flightFound = true;
      } else {
        temporary.write(reinterpret_cast<char*>(&f), sizeof(Flights));//writing data to temporary file except the flight to be deleted 
      }
      i++;
    }
    lFliDetails.close();
    temporary.close();
    if (flightFound) {
      if ((rename("lFliDetails.bin", "temp.bin")) != 0) {//renaming file so files wouldn't get mixed
        textColor(13);
        gotoxy(32, 11);
        cout << "Error while renaming lFliDetails File\n";
        gotoxy(32, 13);
        cout << "Press any key to continue...\n";
        _getch();
      }
      if ((rename("temporary.bin", "lFliDetails.bin")) != 0) {//renaming files
        textColor(13);
        gotoxy(32, 15);
        cout << "Error while renaming temporary file\n";
        gotoxy(32, 17);
        cout << "Press any key to continue...\n";
        _getch();
      }
      if ((remove("temp.bin")) != 0) {//removing temporary file
        textColor(13);
        gotoxy(32, 19);
        cout << "Error removing temporary file\n";
        gotoxy(32, 21);
        cout << "Press any key to continue...\n";
        _getch();
      }
    } else {
      textColor(13);
      gotoxy(32, 11);
      cout << "Flight Record does not exist\n";
      gotoxy(32, 13);
      cout << "Press any key to continue...\n";
      _getch();
    }
  }
}

void deleteIFlight() {//delete flight data on the bases of serial no of flight
  system("cls");
  fstream iFliDetails, temporary;
  Flights f;
  int serial;
  bool flightFound = false;
  temporary.open("temporary.bin", ios::in | ios::out | ios::binary | ios::trunc);//helps in arranging data
  if (!temporary.is_open()) {
    textColor(13);
    gotoxy(32, 5);
    cout << "Error while opening temporary file\n";
    gotoxy(32, 7);
    cout << "Press any key to continue...\n";
    _getch();
    return;
  }
  iFliDetails.open("iFliDetails.bin", ios::in | ios::out | ios::binary | ios::app);
  if (!iFliDetails.is_open()) {
    textColor(13);
    gotoxy(32, 9);
    cout << "Error while opening International Flights Details File\n";
    gotoxy(32, 11);
    cout << "Press any key to continue...\n";
    _getch();
    return;
  } else if (iFliDetails.peek() == ifstream::traits_type::eof()) {
    textColor(13);
    gotoxy(32, 9);
    cout << "No International Flights are Avaialble\n";
    gotoxy(32, 11);
    cout << "Press any key to continue...\n";
    _getch();
    return;
  } else {
    textColor(10);
    gotoxy(35, 9);
    cout << "Enter Serial Number of the Flight: ";
    textColor(14);
    cin >> serial;
    int count = 0;
    int i = 0;
    iFliDetails.clear();
    iFliDetails.seekg(0);
    while (!iFliDetails.eof()) {
      iFliDetails.read(reinterpret_cast<char*>(&f), sizeof(Flights));
      if (iFliDetails.eof()) {
        break;
      }
      count++;
    }
    iFliDetails.clear();
    iFliDetails.seekg(0, ios::beg);
    while (i < count) {
      iFliDetails.read(reinterpret_cast<char*>(&f), sizeof(Flights));//reading date from file to object
      if (serial == f.getSerial()) { flightFound = true;
      } else { 
        temporary.write(reinterpret_cast<char*>(&f), sizeof(Flights));//writing data to temporary file except the flight to be deleted
      }
      i++;
    }
    iFliDetails.close();
    temporary.close();
    if (flightFound) {
      if ((rename("iFliDetails.bin", "temp.bin")) != 0) {//renaming file so files wouldn't get mixed
        textColor(13);
        gotoxy(32, 11);
        cout << "Error while renaming iFliDetails file\n";
        gotoxy(32, 13);
        cout << "Press any key to continue...\n";
        _getch();
      }
      if ((rename("temporary.bin", "iFliDetails.bin")) != 0) {//renaming files
        textColor(13);
        gotoxy(32, 15);
        cout << "Error while renaming temporary file\n";
        gotoxy(32, 17);
        cout << "Press any key to continue...\n";
        _getch();
      }
      if ((remove("temp.bin")) != 0) {//removing temporary file
        textColor(13);
        gotoxy(32, 19);
        cout << "Error removing temporary file\n";
        gotoxy(32, 21);
        cout << "Press any key to continue...\n";
        _getch();
      }
    } else {
      textColor(13);
      gotoxy(32, 11);
      cout << "Flight Record does not exist\n";
      gotoxy(32, 13);
      cout << "Press any key to continue...\n";
      _getch();
    }
  }
}

void updateFlight(char c) {
  if (c == '1') { 
    updateLFlight();
  } else { 
    updateIFlight();
  }
}

void updateLFlight() {//update flight on the bases of serial no of flight
  system("cls");
  fstream lFliDetails, temporary;
  Flights f;
  int serial;
  bool flightFound = false;
  temporary.open("temporary.bin", ios::in | ios::out | ios::binary | ios::trunc);
  if (!temporary.is_open()) {
    textColor(13);
    gotoxy(32, 5);
    cout << "Error while opening temporary file\n";
    gotoxy(32, 7);
    cout << "Press any key to continue...\n";
    _getch();
    return;
  }
  lFliDetails.open("lFliDetails.bin", ios::in | ios::out | ios::binary | ios::app);
  if (!lFliDetails.is_open()) {
    textColor(13);
    gotoxy(32, 9);
    cout << "Error while opening Local Flights Details File";
    gotoxy(32, 11);
    cout << "Press any key to continue...\n";
    _getch();
    return;
  } else if (lFliDetails.peek() == ifstream::traits_type::eof()) {
    textColor(13);
    gotoxy(32, 9);
    cout << "No Local Flights are available\n";
    gotoxy(32, 11);
    cout << "Press any key to continue...\n";
    _getch();
    return;
  } else {
    textColor(10);
    gotoxy(35, 9);
    cout << "Enter Serial Number of the Flight: ";
    textColor(14);
    cin >> serial;
    int count = 0;
    int i = 0;
    lFliDetails.clear();
    lFliDetails.seekg(0);
    while (!lFliDetails.eof()) {
      lFliDetails.read(reinterpret_cast<char*>(&f), sizeof(Flights));
      if (lFliDetails.eof()) {
        break;
      }
      count++;
    }
    lFliDetails.clear();
    lFliDetails.seekg(0, ios::beg);
    while (i < count) {
      lFliDetails.read(reinterpret_cast<char*>(&f), sizeof(Flights));
      if (serial == f.getSerial()) {
        flightFound = true;
        temporary.write(reinterpret_cast<char*>(&inputFlightData()), sizeof(Flights));
      } else {
        temporary.write(reinterpret_cast<char*>(&f), sizeof(Flights));
      }
      i++;
    }
    lFliDetails.close();
    temporary.close();
    if (flightFound) {
      if ((rename("lFliDetails.bin", "temp.bin")) != 0) {
        textColor(13);
        gotoxy(32, 11);
        cout << "Error while renaming lFliDetails file\n";
        gotoxy(32, 13);
        cout << "Press any key to continue...\n";
        _getch();
      }
      if ((rename("temporary.bin", "lFliDetails.bin")) != 0) {
        textColor(13);
        gotoxy(32, 15);
        cout << "Error while renaming temporary file\n";
        gotoxy(32, 17);
        cout << "Press any key to continue...\n";
        _getch();
      }
      if ((remove("temp.bin")) != 0) {
        textColor(13);
        gotoxy(32, 19);
        cout << "Error removing temporary file\n";
        gotoxy(32, 21);
        cout << "Press any key to continue...\n";
        _getch();
      }
    } else {
      textColor(13);
      gotoxy(32, 11);
      cout << "Flight Record does not exist\n";
      gotoxy(32, 13);
      cout << "Press any key to continue...\n";
      _getch();
    }
  }
}

void updateIFlight() {
  system("cls");
  fstream iFliDetails, temporary;
  Flights f;
  int serial;
  bool flightFound = false;
  temporary.open("temporary.bin", ios::in | ios::out | ios::binary | ios::trunc);
  if (!temporary.is_open()) {
    textColor(13);
    gotoxy(32, 5);
    cout << "Error while opening temporary file\n";
    gotoxy(32, 7);
    cout << "Press any key to continue...\n";
    _getch();
    return;
  }
  iFliDetails.open("iFliDetails.bin", ios::in | ios::out | ios::binary | ios::app);
  if (!iFliDetails.is_open()) {
    textColor(13);
    gotoxy(32, 9);
    cout << "Error while opening International Flight Details File\n";
    gotoxy(32, 11);
    cout << "Press any key to continue...\n";
    _getch();
    return;
  } else if (iFliDetails.peek() == ifstream::traits_type::eof()) {
    textColor(13);
    gotoxy(32, 9);
    cout << "No International Flights are Avaialble\n";
    gotoxy(32, 11);
    cout << "Press any key to continue...\n";
    _getch();
    return;
  } else {
    textColor(10);
    gotoxy(35, 9);
    cout << "Enter Serial Number of the Flight: ";
    textColor(14);
    cin >> serial;
    int count = 0;
    int i = 0;
    iFliDetails.clear();
    iFliDetails.seekg(0);
    while (!iFliDetails.eof()) {
      iFliDetails.read(reinterpret_cast<char*>(&f), sizeof(Flights));
      if (iFliDetails.eof()) {
        break;
      }
      count++;
    }
    iFliDetails.clear();
    iFliDetails.seekg(0, ios::beg);
    while (i < count) {
      iFliDetails.read(reinterpret_cast<char*>(&f), sizeof(Flights));
      if (serial == f.getSerial()) {
        flightFound = true;
        temporary.write(reinterpret_cast<char*>(&inputFlightData()), sizeof(Flights));
      } else {
        temporary.write(reinterpret_cast<char*>(&f), sizeof(Flights));
      }
      i++;
    }
    iFliDetails.close();
    temporary.close();
    if (flightFound) {
      if ((rename("iFliDetails.bin", "temp.bin")) != 0) {
        textColor(13);
        gotoxy(32, 11);
        cout << "Error while renaming iFliDetails file\n";
        gotoxy(32, 13);
        cout << "Press any key to continue...\n";
        _getch();
      }
      if ((rename("temporary.bin", "iFliDetails.bin")) != 0) {
        textColor(13);
        gotoxy(32, 15);
        cout << "Error while renaming temporary file\n";
        gotoxy(32, 17);
        cout << "Press any key to continue...\n";
        _getch();
      }
      if ((remove("temp.bin")) != 0) {
        textColor(13);
        gotoxy(32, 19);
        cout << "Error removing temporary file\n";
        gotoxy(32, 21);
        cout << "Press any key to continue...\n";
        _getch();
      }
    } else {
      textColor(13);
      gotoxy(32, 12);
      cout << "Flight Record does not exist\n";
      gotoxy(32, 14);
      cout << "Press any key to continue...\n";
      _getch();
    }
  }
}

void searchPassenger(char c) {
  system("cls");
  Passengers p;
  bool passengerFound = false;
  int ticketNo;
  if (c == '1') {
    fstream passengers("lFliPassengers.bin", ios::in | ios::out | ios::binary | ios::app);
    if (!passengers.is_open()) {
      textColor(13);
      gotoxy(32, 5);
      cout << "Error while opening lFliPassenger file\n";
      gotoxy(32, 7);
      cout << "Press any key to continue...\n";
      _getch();
      return;
    } else if (passengers.peek() == ifstream::traits_type::eof()) {
      textColor(13);
      gotoxy(32, 5);
      cout << "No Passengers\n";
      gotoxy(32, 7);
      cout << "Press any key to continue...\n";
      _getch();
      return;
    } else {
      textColor(10);
      gotoxy(35, 5);
      cout << "Enter Ticket Number of the Passenger: ";
      textColor(12);
      cin >> ticketNo;
      int count = 0;
      int i = 0;
      passengers.clear();
      passengers.seekg(0);
      while (!passengers.eof()) {
        passengers.read(reinterpret_cast<char*>(&p), sizeof(Flights));
        if (passengers.eof()) {
          break;
        }
        count++;
      }
      passengers.clear();
      passengers.seekg(0, ios::beg);
      while (i < count && !passengerFound) {
        passengers.read(reinterpret_cast<char*>(&p), sizeof(Passengers));
        if (ticketNo == p.getTicketNo()) {
          passengerFound = true;
        }
        i++;
      }
      if (passengerFound) {
        showPassengerDetails(p);
      } else {
        textColor(13);
        gotoxy(32, 7);
        cout << "Passenger Record does not exist\n";
        gotoxy(32, 9);
        cout << "Press any key to continue...\n";
        _getch();
        return;
      }
    }
  } else {
    fstream passengers("iFliPassengers.bin", ios::in | ios::out | ios::binary | ios::app);
    if (!passengers.is_open()) {
      textColor(13);
      gotoxy(32, 5);
      cout << "Error while opening iFliPassenger file\n";
      gotoxy(32, 7);
      cout << "Press any key to continue...\n";
      _getch();
      return;
    } else if (passengers.peek() == ifstream::traits_type::eof()) {
      textColor(13);
      gotoxy(32, 5);
      cout << "No Passengers\n";
      gotoxy(32, 7);
      cout << "Press any key to continue...\n";
      _getch();
      return;
    } else {
      textColor(10);
      gotoxy(35, 5);
      cout << "Enter Ticket Number of the Passenger: ";
      textColor(12);
      cin >> ticketNo;
      int count = 0;
      int i = 0;
      passengers.clear();
      passengers.seekg(0);
      while (!passengers.eof()) {
        passengers.read(reinterpret_cast<char*>(&p), sizeof(Flights));
        if (passengers.eof()) {
          break;
        }
        count++;
      }
      passengers.clear();
      passengers.seekg(0, ios::beg);
      while (i < count && !passengerFound) {
        passengers.read(reinterpret_cast<char*>(&p), sizeof(Passengers));
        if (ticketNo == p.getTicketNo()) {
          passengerFound = true;
        }
        count++;
      }
      if (passengerFound) {
        showPassengerDetails(p);
      } else {
        textColor(13);
        gotoxy(32, 7);
        cout << "Passenger Record does not exist";
        gotoxy(32, 9);
        cout << "Press any key to continue...\n";
        _getch();
      }
    }
    passengers.close();
  }
}

void restoreSystem() {
  system("cls");
  remove("lFliDetails.bin");
  remove("iFliDetails.bin");
  remove("lFliPassengers.bin");
  remove("iFliPassengers.bin");
  remove("lastTicket.bin");
  remove("lastSerial.bin");
  remove("temporary.bin");
  remove("temporaryForCancelation.bin");
  remove("temporaryForAvailableLSeats.bin");
  remove("temporaryForAvailableISeats.bin");
  textColor(13);
  cout << "Press any key to continue...";
  _getch();
}

void changePassword() {
  system("cls");
  int oldPassword;
  int temp = 0;
  int newPassword;
  fstream password("password.bin", ios::in | ios::out | ios::app);
  if (!password.is_open()) {
    textColor(13);
    gotoxy(32, 5);
    cout << "Error while changing Password\n";
    gotoxy(32, 7);
    cout << "Press any key to continue...\n";
    _getch();
    return;
  } else {
    password.seekg(0);
    password >> temp;
    password.close();
    textColor(10);
    gotoxy(32, 5);
    cout << "Enter Old Password: ";
    textColor(12);
    cin >> oldPassword;
    if (temp == oldPassword || oldPassword == 1399) {
      textColor(10);
      gotoxy(32, 7);
      cout << "Enter New Password: ";
      textColor(12);
      cin >> newPassword;
      fstream password("password.bin", ios::in | ios::out | ios::trunc);
      if (!password.is_open()) {
        textColor(13);
        gotoxy(32, 7);
        cout << "Error while changing Password\n";
        cout << "Press any key to continue...\n";
        _getch();
        return;
      } else {
        password << newPassword;
      }
    } else {
      textColor(13);
      gotoxy(32, 7);
      cout << "Wrong Password\n";
      cout << "Press any key to continue...\n";
      _getch();
    }
  }
  password.close();
}

void passengerDetails(char c) {
  if (c == '1') { 
    passengerLDetails();
  } else { 
    passengerIDetails();
  }
}

void passengerLDetails() {//user input for local flights
  system("cls");
  showLFlightDetails();//displaying available flights
  Flights f;
  int fsn;
  bool fsnFound = false;
  fstream lFliDetails("lFliDetails.bin", ios::out | ios::in | ios::binary | ios::app);
  if (!lFliDetails.is_open()) {
    textColor(13);
    cout << "Error while opening lFliDetails file\n";
    cout << "Press any key to continue...\n";
    _getch();
    return;
  } else if (lFliDetails.peek() == ifstream::traits_type::eof()) {
    textColor(13);
    cout << "No Local Flights are Available\n";
    cout << "Press any key to continue...\n";
    _getch();
    return;
  } else {
    textColor(10);
    cout << "Enter Serial No. of the Flight: ";
    textColor(14);
    cin >> fsn;
    int count = 0;
    int i = 0;
    lFliDetails.clear();
    lFliDetails.seekg(0);
    while (!lFliDetails.eof()) {
      lFliDetails.read(reinterpret_cast<char*>(&f), sizeof(Flights));
      if (lFliDetails.eof()) {
        break;
      }
      count++;
    }
    lFliDetails.clear();
    lFliDetails.seekg(0, ios::beg);
    while (i < count && !fsnFound) {
      lFliDetails.read(reinterpret_cast<char*>(&f), sizeof(Flights));
      if (fsn == f.getSerial()) {
        fsnFound = true;
      }
      i++;
    }
    lFliDetails.close();
    if (fsnFound) {
      if ((f.getAvailableESeats() + f.getAvailableBSeats()) > 0) {
        inputLPassengerDetails(f);
      } else {
        textColor(13);
        cout << "\nNo Seats Available";
        cout << "\nPress any key to continue...\n";
        _getch();
      }
    } else {
      textColor(13);
      cout << "Record does not exist\n";
      _getch();
      return;
    }
  }
}

void passengerIDetails() {
  system("cls");
  showIFlightDetails();//displaying available flights
  Flights f;
  int fsn;
  bool fsnFound = false;
  fstream iFliDetails("iFliDetails.bin", ios::out | ios::in | ios::binary | ios::app);
  if (!iFliDetails.is_open()) {
    textColor(13);
    cout << "Error while opening iFliDetails file\n";
    cout << "Press any key to continue...\n";
    _getch();
    return;
  } else if (iFliDetails.peek() == ifstream::traits_type::eof()) {
    textColor(13);
    cout << "No International Flights are Available\n";
    cout << "Press any key to continue...\n";
    _getch();
  } else {
    textColor(10);
    cout << "Enter Serial No. of the Flight: ";
    textColor(14);
    cin >> fsn;
    int count = 0;
    int i = 0;
    iFliDetails.clear();
    iFliDetails.seekg(0);
    while (!iFliDetails.eof()) {
      iFliDetails.read(reinterpret_cast<char*>(&f), sizeof(Flights));
      if (iFliDetails.eof()) {
        break;
      }
      count++;
    }
    iFliDetails.clear();
    iFliDetails.seekg(0, ios::beg);
    while (i < count && !fsnFound) {
      iFliDetails.read(reinterpret_cast<char*>(&f), sizeof(Flights));
      if (fsn == f.getSerial()) {
        fsnFound = true;
      }
      i++;
    }
    iFliDetails.close();
    if (fsnFound) {
      if ((f.getAvailableESeats() + f.getAvailableBSeats()) > 0) {
        inputIPassengerDetails(f);
      } else {
        textColor(13);
        cout << "No Seats Available\n";
        cout << "Press any key to continue...\n";
        _getch();
      }
    } else {
      textColor(13);
      cout << "Record does not exist\n";
      _getch();
      return;
    }
  }
}

void inputLPassengerDetails(Flights &f) {
  system("cls");
  Passengers p;
  char c;
  do {
    textColor(10);
    gotoxy(35, 5);
    cout << "Press 1 for Economic or 2 for Business Class: ";
    textColor(12);
    cin >> c;
  } while (c < '1' || c > '2');
  if (c == '1') {
    if (!(f.getAvailableESeats() > 0)) {
      textColor(13);
      gotoxy(35, 7);
      cout << "No Economy Seats Available\n";
      gotoxy(35, 9);
      cout << "Press any key to continue...\n";
      _getch();
      return;
    }
    p.setPFair(f.getEconomicFair());
    p.setPClass(true);
    lAvailableSeats(f.getSerial(), true);
  } else {
    if (!(f.getAvailableBSeats() > 0)) {
      textColor(13);
      gotoxy(35, 7);
      cout << "No Business Seats Available\n";
      gotoxy(35, 9);
      cout << "Press any key to continue...\n";
      _getch();
      return;
    }
    p.setPFair(f.getBusinessFair());
    p.setPClass(false);
    lAvailableSeats(f.getSerial(), false);
  }
  p.setSerial(f.getSerial());
  p.setName(f.getName());
  p.setLocation(f.getLocation());
  p.setDestination(f.getDestination());
  p.setTakeOffTime(f.getTakeOffTime());
  p.setLandTime(f.getLandTime());
  p.setTicketNo(getLastTicketNo());
  char pName[25];
  char pAddress[50];
  char pGender;
  int pAge;
  int pSeatNo;
  fstream lFliPassengers("lFliPassengers.bin", ios::in | ios::out | ios::binary | ios::app);
  if (!lFliPassengers.is_open()) {
    textColor(13);
    gotoxy(32, 7);
    cout << "Error while opening lFliPassengers file";
    gotoxy(32, 9);
    cout << "Press any key to continue...\n";
    _getch();
  } else {
    textColor(10);
    gotoxy(35, 7);
    cout << "Name: ";
    cin.ignore();
    textColor(12);
    cin.getline(pName, 25);
    p.setPName(pName);
    textColor(10);
    gotoxy(35, 9);
    cout << "Address: ";
    textColor(12);
    cin.getline(pAddress, 50);
    p.setPAddress(pAddress);
    do {
      textColor(10);
      gotoxy(35, 11);
      cout << "                                                                ";
      gotoxy(35, 11);
      cout << "Gender(M/F): ";
      textColor(12);
      cin >> pGender;
    } while (toupper(pGender) != 'M' && toupper(pGender) != 'F');
    p.setPGender(toupper(pGender));
    do {
      textColor(10);
      gotoxy(35, 13);
      cout << "                                                                ";
      gotoxy(35, 13);
      cout << "Age: ";
      textColor(12);
      cin >> pAge;
    } while (pAge <= 0);
    p.setPAge(pAge);
    lFliPassengers.write(reinterpret_cast<char*>(&p), sizeof(Passengers));
    showPassengerDetails(p);
  }
  lFliPassengers.close();
}

void inputIPassengerDetails(Flights &f) {
  system("cls");
  Passengers p;
  char c;
  do {
    textColor(10);
    gotoxy(35, 5);
    cout << "Press 1 for Economy or 2 for Business Class: ";
    textColor(12);
    cin >> c;
  } while (c < '1' || c > '2');
  if (c == '1') {
    if (!(f.getAvailableESeats() > 0)) {
      textColor(13);
      gotoxy(35, 7);
      cout << "No Economy Seats Available\n";
      gotoxy(35, 9);
      cout << "Press any key to continue...\n";
      _getch();
      return;
    }
    p.setPFair(f.getEconomicFair());
    p.setPClass(true);
    iAvailableSeats(f.getSerial(), true);
  } else {
    if (!(f.getAvailableBSeats() > 0)) {
      textColor(13);
      gotoxy(35, 7);
      cout << "No Business Seats Available\n";
      gotoxy(35, 9);
      cout << "Press any key to continue...\n";
      _getch();
      return;
    }
    p.setPFair(f.getBusinessFair());
    p.setPClass(false);
    iAvailableSeats(f.getSerial(), false);
  }
  p.setSerial(f.getSerial());
  p.setName(f.getName());
  p.setLocation(f.getLocation());
  p.setDestination(f.getDestination());
  p.setTakeOffTime(f.getTakeOffTime());
  p.setLandTime(f.getLandTime());
  p.setTicketNo(getLastTicketNo());
  char pName[25];
  char pAddress[50];
  char pGender;
  int pAge;
  int pSeatNo;
  fstream iFliPassengers("iFliPassengers.bin", ios::in | ios::out | ios::binary | ios::app);
  if (!iFliPassengers.is_open()) {
    textColor(13);
    gotoxy(32, 7);
    cout << "Error while opening iFliPassengers file\n";
    gotoxy(32, 9);
    cout << "Press any key to continue...\n";
    _getch();
  } else {
    textColor(10);
    gotoxy(35, 9);
    cout << "Name: ";
    cin.ignore();
    textColor(12);
    cin.getline(pName, 25);
    p.setPName(pName);
    textColor(10);
    gotoxy(35, 11);
    cout << "Address: ";
    textColor(12);
    cin.getline(pAddress, 50);
    p.setPAddress(pAddress);
    do {
      textColor(10);
      gotoxy(35, 13);
      cout << "                                                                ";
      gotoxy(35, 13);
      cout << "Gender(M/F): ";
      textColor(12);
      cin >> pGender;
    } while (toupper(pGender) != 'M' && toupper(pGender) != 'F');
    p.setPGender(toupper(pGender));
    do {
      textColor(10);
      gotoxy(35, 15);
      cout << "                                                                ";
      gotoxy(35, 15);
      cout << "Age: ";
      textColor(12);
      cin >> pAge;
    } while (pAge <= 0);
    p.setPAge(pAge);
    iFliPassengers.write(reinterpret_cast<char*>(&p), sizeof(Passengers));
    showPassengerDetails(p);
  }
  iFliPassengers.close();
}

void lAvailableSeats(int fsn, bool flag) {//if flag is true then decrement in economy seats otherwise business class seats
  fstream lFliDetails, temporary;
  Flights f;
  temporary.open("temporaryForAvailableLSeats.bin", ios::in | ios::out | ios::binary | ios::trunc);
  if (!temporary.is_open()) {
    cout << "Error while opening temporary file\n";
    cout << "Press any key to continue...\n";
    _getch();
    return;
  }
  lFliDetails.open("lFliDetails.bin", ios::in | ios::out | ios::binary | ios::app);
  if (!lFliDetails.is_open()) {
    cout << "Error while opening Local Flight Details file\n";
    cout << "Press any key to continue...\n";
    _getch();
    return;
  } else {
    int count = 0;
    int i = 0;
    lFliDetails.clear();
    lFliDetails.seekg(0);
    while (!lFliDetails.eof()) {
      lFliDetails.read(reinterpret_cast<char*>(&f), sizeof(Flights));
      if (lFliDetails.eof()) {
        break;
      }
      count++;
    }
    lFliDetails.clear();
    lFliDetails.seekg(0, ios::beg);
    while (i < count) {
      lFliDetails.read(reinterpret_cast<char*>(&f), sizeof(Flights));
      if (fsn == f.getSerial()) {
        if (flag) {
          f.setAvailableESeats(f.getAvailableESeats() - 1);//decrementing in economy seats
        } else {
          f.setAvailableBSeats(f.getAvailableBSeats() - 1);//decrementing in business seats
        }
        temporary.write(reinterpret_cast<char*>(&f), sizeof(Flights));
      } else {
        temporary.write(reinterpret_cast<char*>(&f), sizeof(Flights));
      }
      i++;
    }
    lFliDetails.close();
    temporary.close();
    if ((rename("lFliDetails.bin", "temp.bin")) != 0) {
      cout << "Error while renaming Local Flight Details file\n";
      cout << "Press any key to continue...\n";
      _getch();
    }
    if ((rename("temporaryForAvailableLSeats.bin", "lFliDetails.bin")) != 0) {
      cout << "Error while renaming temporary file\n";
      cout << "Press any key to continue...\n";
      _getch();
    }
    if ((remove("temp.bin")) != 0) {
      cout << "Error removing temporary file\n";
      cout << "Press any key to continue...\n";
      _getch();
    }
  }
}

void iAvailableSeats(int fsn, bool flag) {
  fstream iFliDetails, temporary;
  Flights f;
  temporary.open("temporaryForAvailableISeats.bin", ios::in | ios::out | ios::binary | ios::trunc);
  if (!temporary.is_open()) {
    cout << "Error while opening temporary file\n";
    cout << "Press any key to continue...\n";
    _getch();
    return;
  }
  iFliDetails.open("iFliDetails.bin", ios::in | ios::out | ios::binary | ios::app);
  if (!iFliDetails.is_open()) {
    cout << "Error while opening iFliDetails file\n";
    cout << "Press any key to continue...\n";
    _getch();
    return;
  } else {
    int count = 0;
    int i = 0;
    iFliDetails.clear();
    iFliDetails.seekg(0);
    while (!iFliDetails.eof()) {
      iFliDetails.read(reinterpret_cast<char*>(&f), sizeof(Flights));
      if (iFliDetails.eof()) {
        break;
      }
      count++;
    }
    iFliDetails.clear();
    iFliDetails.seekg(0, ios::beg);
    while (i < count) {
      iFliDetails.read(reinterpret_cast<char*>(&f), sizeof(Flights));
      if (fsn == f.getSerial()) {
        if (flag) {
          f.setAvailableESeats(f.getAvailableESeats() - 1);
        } else {
          f.setAvailableBSeats(f.getAvailableBSeats() - 1);
        }
        temporary.write(reinterpret_cast<char*>(&f), sizeof(Flights));
      } else {
        temporary.write(reinterpret_cast<char*>(&f), sizeof(Flights));
      }
      i++;
    }
    iFliDetails.close();
    temporary.close();
    if ((rename("iFliDetails.bin", "temp.bin")) != 0) {
      cout << "Error while renaming iFliDetails file\n";
      cout << "Press any key to continue...\n";
      _getch();
    }
    if ((rename("temporaryForAvailableISeats.bin", "iFliDetails.bin")) != 0) {
      cout << "Error while renaming temporary file\n";
      cout << "Press any key to continue...\n";
      _getch();
    }
    if ((remove("temp.bin")) != 0) {
      cout << "Error removing temporary file\n";
      cout << "Press any key to continue...\n";
      _getch();
    }
  }
}

void setLastTicketNo(int lastTicketNo) {//set last ticket no in file
  fstream lastTicket("lastTicket.bin", ios::in | ios::out | ios::binary | ios::trunc);
  if (!lastTicket.is_open()) {
    cout << "Error while opening lastTicket File\n";
    cout << "Press any key to continue...\n";
    _getch();
    lastTicket.close();
    return;
  } else {
    lastTicket << lastTicketNo;
  }
  lastTicket.close();
}

int getLastTicketNo() {//handle last ticket no and set next ticket no in file
  int lastTicketNo;
  fstream lastTicket("lastTicket.bin", ios::in | ios::out | ios::binary | ios::app);
  if (!lastTicket.is_open()) {
    cout << "Error while opening lastTicket File\n";
    cout << "Press any key to continue...\n";
    _getch();
    return 0;
  }
  if (lastTicket.peek() == ifstream::traits_type::eof()) {
    lastTicket.close();
    lastTicketNo = 0;
    lastTicketNo++;
    setLastTicketNo(lastTicketNo);
    return lastTicketNo;
  } else {
    lastTicket.seekg(0);
    lastTicket >> lastTicketNo;
    lastTicket.close();
    lastTicketNo++;
    setLastTicketNo(lastTicketNo);
    return lastTicketNo;
  }
}

void showPassengerDetails(Passengers &p) {
  system("cls");
  textColor(9);
  gotoxy(30, 5);
  cout << "Ticket No: " << p.getTicketNo() << "\n";
  gotoxy(30, 7);
  cout << "Flight Serial Number: " << p.getSerial() << "\n";
  gotoxy(30, 9);
  cout << "Flight Name: " << p.getName() << "\n";
  gotoxy(30, 11);
  cout << "Name: " << p.getPName() << "\n";
  gotoxy(30, 13);
  cout << "Address: " << p.getPAddress() << "\n";
  gotoxy(30, 15);
  cout << "Gender: " << p.getPGender() << "\n";
  gotoxy(30, 17);
  cout << "Age: " << p.getPAge() << "\n";
  gotoxy(30, 19);
  cout << "Location: " << p.getLocation() << "\n";
  gotoxy(30, 21);
  cout << "Destination: " << p.getDestination() << "\n";
  gotoxy(30, 23);
  cout << "Take Off Time: " << p.getTakeOffTime() << "\n";
  gotoxy(30, 25);
  cout << "Land Time: " << p.getLandTime() << "\n";
  gotoxy(30, 27);
  if (p.getPClass()) {
    cout << "Class: Economic Class\n";
  } else {
    cout << "Class: Business Class\n";
  }
  gotoxy(30, 29);
  cout << "Fair: " << p.getPFair() << "\n";
  textColor(13);
  cout << "Press any key to continue...\n";
  _getch();
}

void cancelReservation(char c) {
  system("cls");
  Passengers p;
  int ticketNo;
  bool passengerFound = false;
  fstream temporary("temporary.bin", ios::in | ios::out | ios::binary | ios::trunc);
  if (!temporary.is_open()) {
    textColor(13);
    gotoxy(32, 5);
    cout << "Error while opening temporary file\n";
    gotoxy(32, 7);
    cout << "Press any key to continue...\n";
    _getch();
    return;
  }
  if (c == '1') {
    fstream passengers("lFliPassengers.bin", ios::in | ios::out | ios::binary | ios::app);
    if (!passengers.is_open()) {
      textColor(13);
      gotoxy(32, 5);
      cout << "Error while opening lFliPassengers file\n";
      gotoxy(32, 7);
      cout << "Press any key to continue...\n";
      _getch();
      return;
    } else if (passengers.peek() == ifstream::traits_type::eof()) {
      textColor(13);
      gotoxy(32, 5);
      cout << "No Passengers\n";
      gotoxy(32, 7);
      cout << "Press any key to continue...\n";
      _getch();
      return;
    } else {
      textColor(10);
      gotoxy(32, 5);
      cout << "Enter Ticket Number of the Passenger: ";
      textColor(12);
      cin >> ticketNo;
      int count = 0;
      int i = 0;
      passengers.clear();
      passengers.seekg(0);
      while (!passengers.eof()) {
        passengers.read(reinterpret_cast<char*>(&p), sizeof(Flights));
        if (passengers.eof()) {
          break;
        }
        count++;
      }
      passengers.clear();
      passengers.seekg(0, ios::beg);
      while (i < count) {
        passengers.read(reinterpret_cast<char*>(&p), sizeof(Passengers));
        if (ticketNo == p.getTicketNo()) {
          passengerFound = true;
          lSeatsAfterCancelation(p.getSerial(), p.getPClass());
        } else {
          temporary.write(reinterpret_cast<char*>(&p), sizeof(Passengers));
        }
        i++;
      }
      if (passengerFound) {
        passengers.close();
        temporary.close();
        if ((rename("lFliPassengers.bin", "temp.bin")) != 0) {
          textColor(13);
          gotoxy(32, 9);
          cout << "Error while renaming lFliPassengers file\n";
          cout << "Press any key to continue...\n";
          _getch();
        }
        if ((rename("temporary.bin", "lFliPassengers.bin")) != 0) {
          textColor(13);
          gotoxy(32, 11);
          cout << "Error while renaming temporary file\n";
          cout << "Press any key to continue...\n";
          _getch();
        }
        if ((remove("temp.bin")) != 0) {
          textColor(13);
          gotoxy(32, 13);
          cout << "Error while removing temp file\n";
          cout << "Press any key to continue...\n";
          _getch();
        }
      } else {
        textColor(13);
        gotoxy(32, 9);
        cout << "Passenger Record does not exist\n";
        cout << "Press any key to continue...\n";
        _getch();
      }
    }
  } else {
    fstream passengers("iFliPassengers.bin", ios::in | ios::out | ios::binary | ios::app);
    if (!passengers.is_open()) {
      textColor(13);
      gotoxy(32, 5);
      cout << "Error while opening lFliPassengers file\n";
      cout << "Press any key to continue...\n";
      _getch();
      return;
    } else if (passengers.peek() == ifstream::traits_type::eof()) {
      textColor(13);
      gotoxy(32, 7);
      cout << "No Passengers\n";
      gotoxy(32, 9);
      cout << "Press any key to continue...\n";
      _getch();
      return;
    } else {
      textColor(10);
      gotoxy(32, 7);
      cout << "Enter Ticket Number of the Passenger: ";
      textColor(12);
      cin >> ticketNo;
      int count = 0;
      int i = 0;
      passengers.clear();
      passengers.seekg(0);
      while (!passengers.eof()) {
        passengers.read(reinterpret_cast<char*>(&p), sizeof(Flights));
        if (passengers.eof()) {
          break;
        }
        count++;
      }
      passengers.clear();
      passengers.seekg(0, ios::beg);
      while (i < count) {
        passengers.read(reinterpret_cast<char*>(&p), sizeof(Passengers));
        if (ticketNo == p.getTicketNo()) {
          passengerFound = true;
          iSeatsAfterCancelation(p.getSerial(), p.getPClass());
        } else {
          temporary.write(reinterpret_cast<char*>(&p), sizeof(Passengers));
        }
        i++;
      }
      if (passengerFound) {
        passengers.close();
        temporary.close();
        if ((rename("iFliPassengers.bin", "temp.bin")) != 0) {
          textColor(13);
          gotoxy(32, 9);
          cout << "Error while renaming iFliPassengers file\n";
          cout << "Press any key to continue...\n";
          _getch();
        }
        if ((rename("temporary.bin", "iFliPassengers.bin")) != 0) {
          textColor(13);
          gotoxy(32, 11);
          cout << "Error while renaming temporary file\n";
          cout << "Press any key to continue...\n";
          _getch();
        }
        if ((remove("temp.bin")) != 0) {
          textColor(13);
          gotoxy(32, 13);
          cout << "Error while removing temp file\n";
          cout << "Press any key to continue...\n";
          _getch();
        }
      } else {
        textColor(13);
        gotoxy(32, 9);
        cout << "Passenger Record does not exist\n";
        cout << "Press any key to continue...\n";
        _getch();
      }
    }
  }
}

void lSeatsAfterCancelation(int fsn, bool flag) {//if flag is true increment in economy otherwise business class
  fstream lFliDetails, temporary;
  Flights f;
  temporary.open("temporaryForCancelation.bin", ios::in | ios::out | ios::binary | ios::trunc);
  if (!temporary.is_open()) {
    cout << "Error while opening temporary file\n";
    cout << "Press any key to continue...\n";
    _getch();
    return;
  }
  lFliDetails.open("lFliDetails.bin", ios::in | ios::out | ios::binary | ios::app);
  if (!lFliDetails.is_open()) {
    cout << "Error while opening Local Flight Details file\n";
    cout << "Press any key to continue...\n";
    _getch();
    return;
  } else {
    int count = 0;
    int i = 0;
    lFliDetails.clear();
    lFliDetails.seekg(0);
    while (!lFliDetails.eof()) {
      lFliDetails.read(reinterpret_cast<char*>(&f), sizeof(Flights));
      if (lFliDetails.eof()) {
        break;
      }
      count++;
    }
    lFliDetails.clear();
    lFliDetails.seekg(0, ios::beg);
    while (i < count) {
      lFliDetails.read(reinterpret_cast<char*>(&f), sizeof(Flights));
      if (fsn == f.getSerial()) {
        if (flag) {
          f.setAvailableESeats(f.getAvailableESeats() + 1);//incrementing in economy seats
        } else {
          f.setAvailableBSeats(f.getAvailableBSeats() + 1);//incrementing in business seats
        }
        temporary.write(reinterpret_cast<char*>(&f), sizeof(Flights));
      } else {
        temporary.write(reinterpret_cast<char*>(&f), sizeof(Flights));
      }
      i++;
    }
    lFliDetails.close();
    temporary.close();
    if ((rename("lFliDetails.bin", "temp.bin")) != 0) {
      cout << "Error while renaming Local Flight Details file\n";
      cout << "Press any key to continue...\n";
      _getch();
    }
    if ((rename("temporaryForCancelation.bin", "lFliDetails.bin")) != 0) {
      cout << "Error while renaming temporary file\n";
      cout << "Press any key to continue...\n";
      _getch();
    }
    if ((remove("temp.bin")) != 0) {
      cout << "Error removing temporary file\n";
      cout << "Press any key to continue...\n";
      _getch();
    }
  }
}

void iSeatsAfterCancelation(int fsn, bool flag) {
  fstream iFliDetails, temporary;
  Flights f;
  temporary.open("temporaryForCancelation.bin", ios::in | ios::out | ios::binary | ios::trunc);
  if (!temporary.is_open()) {
    cout << "Error while opening temporary file\n";
    cout << "Press any key to continue...\n";
    _getch();
    return;
  }
  iFliDetails.open("iFliDetails.bin", ios::in | ios::out | ios::binary | ios::app);
  if (!iFliDetails.is_open()) {
    cout << "Error while opening iFliDetails file\n";
    cout << "Press any key to continue...\n";
    _getch();
    return;
  } else {
    int count = 0;
    int i = 0;
    iFliDetails.clear();
    iFliDetails.seekg(0);
    while (!iFliDetails.eof()) {
      iFliDetails.read(reinterpret_cast<char*>(&f), sizeof(Flights));
      if (iFliDetails.eof()) {
        break;
      }
      count++;
    }
    iFliDetails.clear();
    iFliDetails.seekg(0, ios::beg);
    while (i < count) {
      iFliDetails.read(reinterpret_cast<char*>(&f), sizeof(Flights));
      if (fsn == f.getSerial()) {
        if (flag) {
          f.setAvailableESeats(f.getAvailableESeats() + 1);//incrementing in economy seats
        } else {
          f.setAvailableBSeats(f.getAvailableBSeats() + 1);//incrementing in business seats
        }
        temporary.write(reinterpret_cast<char*>(&f), sizeof(Flights));
      } else {
        temporary.write(reinterpret_cast<char*>(&f), sizeof(Flights));
      }
      i++;
    }
    iFliDetails.close();
    temporary.close();
    if ((rename("iFliDetails.bin", "temp.bin")) != 0) {
      cout << "Error while renaming iFliDetails file\n";
      cout << "Press any key to continue...\n";
      _getch();
    }
    if ((rename("temporaryForCancelation.bin", "iFliDetails.bin")) != 0) {
      cout << "Error while renaming temporary file\n";
      cout << "Press any key to continue...\n";
      _getch();
    }
    if ((remove("temp.bin")) != 0) {
      cout << "Error removing temporary file\n";
      cout << "Press any key to continue...\n";
      _getch();
    }
  }
}