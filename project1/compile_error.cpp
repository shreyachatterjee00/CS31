//
//  compile_error.cpp
//  Project1Step7
//
//  Created by Shreya Chatterjee on 1/9/19.
//  Copyright © 2019 Shreya Chatterjee. All rights reserved.
//

// Code for Project 1
// Congress results

#include <iostream>
using namespace std;   // pp. 37-38 in Savitch book explain this line

int main()
{
    int republicanSeats;
    int democraticSeats;
    int independentSeats;
    
    cout << "How many seats are held by Democrats? " //took out a semicolon
    cin >> democraticSeats;
    cout << "How many seats are held by Republicans? ";
    cin >> republicanSeats;
    cout << "How many seats are held by Independents? ";
    cin >> independentSeats;
    
    int total = republicanSeats + democraticSeats + independentSeats;
    
    double pctRep = 100.0 * republicanSeats / total;
    double pctDem = 100.0 * democraticSeats / total;
    double pctInd = 100.0 * independentSeats / total;
    
    cout.setf(ios::fixed);       // see pp. 30-31 in Savitch book
    cout.precision(1);
    cout << endl << endl;
    cout >> pctRep << "% Republicans" << endl;  //changed the << after cout to >>
    cout << pctDem << "% Democrats" << endl;
    cout << pctInd  << "% Independents" << endl;
    
    if (pctRep > pctDem)
    {
        cout << "Looks like control goes to the Republicans." << endl;
        
    }
    else
    {
        cout << "Looks like control goes to the Democrats." << endl;
        
    }
    return(0);
    
}
