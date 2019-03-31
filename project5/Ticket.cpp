//
//  main.cpp
//  Project5
//
//  Created by Shreya Chatterjee on 2/20/19.
//  Copyright © 2019 Shreya Chatterjee. All rights reserved.
//

#include <iostream>
#include <string>
#include "Ticket.h"
using namespace std;

Ticket::Ticket(string row, int seat, string event, string venue, double price, KIND kind, string daytime) {
    mRow = row;
    mSeat = seat;
    mEvent = event;
    mVenue = venue;
    mPrice = price;
    mKind = kind;
    mDayTime = daytime;
}

string Ticket::getRow() {
    return mRow;
}
int Ticket::getSeat() {
    return mSeat;
}
string Ticket::getEvent() {
    return mEvent;
}
string Ticket::getVenue() {
    return mVenue;
}
void Ticket::setPrice (double price) {
    mPrice = price;
}
double Ticket::getPrice() {
    return mPrice;
}
Ticket::KIND Ticket::getKind() {
    return mKind;
}
string Ticket::getDayTime() {
    return mDayTime;
}


