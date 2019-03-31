//
//  Ticket.h
//  Project5
//
//  Created by Shreya Chatterjee on 2/20/19.
//  Copyright © 2019 Shreya Chatterjee. All rights reserved.
//

#include <string>
#include <iostream>
using namespace std;

#ifndef Ticket_h
#define Ticket_h

class Ticket {
    
public:
    enum KIND {ATHLETICGAME, CONCERT, MOVIE, OTHER};
    /*constructor*/
    Ticket(string row, int seat, string event, string venue, double price, KIND kind, string daytime);
    /*getter functions*/
    string getRow();
    int getSeat();
    string getEvent();
    string getVenue();
    void setPrice (double price);
    double getPrice();
    KIND getKind();
    string getDayTime();
    
    
private:
    string mRow;
    int mSeat;
    string mEvent;
    string mVenue;
    double mPrice;
    KIND mKind;
    string mDayTime;
    
};
#endif /* Ticket_h */
