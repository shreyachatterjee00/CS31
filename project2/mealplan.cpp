//
//  main.cpp
//  Project2
//
//  Created by Shreya Chatterjee on 1/19/19.
//  Copyright © 2019 Shreya Chatterjee. All rights reserved.
//

#include <iostream>
using namespace std;
#include <string>

string ticketOrBcard() { //asks user if they want have a BruinCard or Ticket
    string ticketOrBcardInput;
    cout << "Ticket or BruinCard? ";
    getline(cin, ticketOrBcardInput);
    return ticketOrBcardInput;
}

string mealTime () {    //asks user what meal they want
    string mealTimeInput;
    cout << "Breakfast, Lunch or Dinner? ";
    getline(cin, mealTimeInput);
    return mealTimeInput;
}

string studentOrStaff () {      //asks if user if they are student or staff
    string studentOrStaffInput;
    cout << "Student or Staff? ";
    getline(cin, studentOrStaffInput);
    return studentOrStaffInput;
}

string resident () {        //asks user if they are a resident
    string residentInput;
    cout << "Resident? ";
    getline(cin, residentInput);
    return residentInput;
}

int main() {
    string input;
    input = ticketOrBcard();    //store user input from functions as 'input'
    if (input == "Ticket") {
        input = mealTime();
        if (input == "Breakfast") {
            cout << "Thank you for eating at UCLA today.  Your meal cost is $12.50." << endl;
            return 0;
        }
        else if (input == "Lunch") {
            cout << "Thank you for eating at UCLA today.  Your meal cost is $14.50." << endl;
            return 0;
        }
        else if (input == "Dinner") {
            cout << "Thank you for eating at UCLA today.  Your meal cost is $17.00." << endl;
        }
        else {
            cout << "The meal value must either be Breakfast, Lunch or Dinner." << endl;
            return 0;
        }
    }
    
    else if (input == "BruinCard") {
        string userMealTime = mealTime();   //stores meal time input as userMealTime
        string userStudentOrStaff = studentOrStaff();   //stores if user is student or staff in userStudentOrStaff
        
        if (userStudentOrStaff == "Staff") {
            if (userMealTime == "Breakfast") {
                cout << "Thank you for eating at UCLA today.  Your meal cost is $11.25." << endl;
                return 0;
            }
            else if (userMealTime == "Lunch") {
                cout << "Thank you for eating at UCLA today.  Your meal cost is $12.75." << endl;
                return 0;
            }
            else if (userMealTime == "Dinner") {
                cout << "Thank you for eating at UCLA today.  Your meal cost is $14.75." << endl;
                return 0;
            }
            else {
                cout << "The meal value must either be Breakfast, Lunch or Dinner." << endl;
                return 0;
            }
        }
        
        else if (userStudentOrStaff == "Student") {
            string userResident = resident();   //stores input as userResident
            
            if (userResident == "Yes") {
                if (userMealTime == "Breakfast") {
                    cout << "Thank you for eating at UCLA today.  Your meal cost is $9.75." << endl;
                    return 0;
                }
                else if (userMealTime == "Lunch") {
                    cout << "Thank you for eating at UCLA today.  Your meal cost is $11.25." << endl;
                    return 0;
                }
                else if (userMealTime == "Dinner") {
                    cout << "Thank you for eating at UCLA today.  Your meal cost is $12.25." << endl;
                    return 0;
                }
                else {
                    cout << "The meal value must either be Breakfast, Lunch or Dinner." << endl;
                    return 0;
                }
            }
            else if (userResident == "No") {
                if (userMealTime == "Breakfast") {
                    cout << "Thank you for eating at UCLA today.  Your meal cost is $10.00." << endl;
                    return 0;
                }
                else if (userMealTime == "Lunch") {
                    cout << "Thank you for eating at UCLA today.  Your meal cost is $11.75." << endl;
                    return 0;
                }
                else if (userMealTime == "Dinner") {
                    cout << "Thank you for eating at UCLA today.  Your meal cost is $12.75." << endl;
                    return 0;
                }
                
            }
            else {
                cout << "The resident value must either be Yes or No." << endl;
                return 0;
            }
            
        }
        else {
            cout << "The type value must either be Student or Staff." << endl;
            return 0;
        }
        
    }
    
    else {
        cout << "The kind value must either be Ticket or BruinCard." << endl;
        return 0;
    }
}



