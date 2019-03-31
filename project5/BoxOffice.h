//
//  BoxOffice.h
//  Project5
//
//  Created by Shreya Chatterjee on 2/21/19.
//  Copyright © 2019 Shreya Chatterjee. All rights reserved.
//

#include <string>
#include <iostream>
#include "Ticket.h"
using namespace std;

#ifndef BoxOffice_h
#define BoxOffice_h

class BoxOffice {
public:
    BoxOffice();
    /*buy a general ticket*/
    Ticket buyTicket(string row, int seat, string event, string venue, Ticket::KIND kind, string daytime);
    /*buy a student ticket*/
    Ticket buyRoyceHallStudentTicket(string row, int seat, string event, Ticket::KIND kind, string daytime);
    /*buy a staff ticket*/
    Ticket buyRoyceHallStaffTicket(string row, int seat, string event, Ticket::KIND kind, string daytime);
    /*buy a general royce hall ticket*/
    Ticket buyRoyceHallTicket (string row, int seat, string event, Ticket::KIND kind, string daytime);
    /*helper function to find price of ticket*/
    double findGeneralPrice (string row, Ticket::KIND kind, string daytime);
};


#endif /* BoxOffice_h */
