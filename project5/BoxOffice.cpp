//
//  BoxOffice.cpp
//  Project5
//
//  Created by Shreya Chatterjee on 2/21/19.
//  Copyright © 2019 Shreya Chatterjee. All rights reserved.
//

#include <stdio.h>
#include "BoxOffice.h"
#include "Project5Helper.h"
#include <iostream>
#include <string>
using namespace std;

BoxOffice::BoxOffice() {
    
}

Ticket BoxOffice::buyTicket(string row, int seat, string event, string venue, Ticket::KIND kind, string daytime) {
    Ticket ticket (row, seat, event, venue, 0, kind, daytime);
    return ticket;
}

Ticket BoxOffice::buyRoyceHallStudentTicket(string row, int seat, string event, Ticket::KIND kind, string daytime) {
    double price = findGeneralPrice(row, kind, daytime);
    if (price >= 40) {
        price -= 30;
    }
    else {
        price = .8 * price;
    }
    Ticket ticket (row, seat, event, "Royce Hall", price, kind, daytime);
    return ticket;
    
}

Ticket BoxOffice::buyRoyceHallStaffTicket(string row, int seat, string event, Ticket::KIND kind, string daytime) {
    double price = findGeneralPrice(row, kind, daytime);
    if (price >= 40) {
        price -= 20;
    }
    else {
        price = .9 * price;
    }
    Ticket ticket (row, seat, event, "Royce Hall", price, kind, daytime);
    return ticket;
}

Ticket BoxOffice::buyRoyceHallTicket(string row, int seat, string event, Ticket::KIND kind, string daytime) {
    double price = findGeneralPrice(row, kind, daytime);
    Ticket ticket (row, seat, event, "Royce Hall", price, kind, daytime);
    return ticket;
}

double BoxOffice::findGeneralPrice(string row, Ticket::KIND kind, string daytime) {
    //acounts for general price and orchestra vs balcony seating
    //does not account for staff vs student pricing
    Project5Helper obj;
    double price = 0;
    if (kind == Ticket::KIND::ATHLETICGAME) {
        price = 75;
    }
    else if (kind == Ticket::KIND::CONCERT) {
        if (obj.endsWithPM(daytime)) {
            price = 65;
        }
        else {
            price = 50;
        }
    }
    else if (kind == Ticket::KIND::MOVIE) {
        price = 12.5;
    }
    else if (kind == Ticket::KIND::OTHER){
        if (obj.endsWithPM(daytime)) {
            price = 55;
        }
        else {
            price = 40;
        }
    }
    
    if (obj.startsWithOrchestra(row)) {
        price *= 2;
    }
    
    return price;
}




