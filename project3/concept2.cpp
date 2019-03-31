//
//  main.cpp
//  CS31Proj3
//
//  Created by Shreya Chatterjee on 1/29/19.
//  Copyright © 2019 Shreya Chatterjee. All rights reserved.
//

#include <iostream>
using namespace std;
#include <string>
#include <cassert>
#include <cctype>

int number(string s, int& startingPosition);

/*returns true if string is valid, false otherwise*/
bool isValidRowerString (string rowerString);

/*helper function: if there are no minutes, returns true if next value is a colon and false otherwise */
bool isColon (string rowerString, int &i, int time);

/*helper function: returns true if next four characters in rowerString are ' s/m' and false otherwise*/
bool isStrokesPerMin (string rowerString, int &i);

/*helper function: returns true if next two characters in rowerString are ' m' and false otherwise*/
bool isMeters (string rowerString, int &i);

/*helper function: returns true if there is a zero before the seconds*/
bool isZero (string rowerString, int &i);

/*returns total meters rowed so far if string is valid, otherwise returns -1*/
int totalDistance(string rowerString);

/*returns heart rate if string is valid, otherwise returns -1*/
int heartRate(string rowerString);

/*returns strokes per minute if string is valid, otherwise returns -1*/
int strokesPerMinute (string rowerString);

/*returns minutes elapsed if string is valid, otherwise returns -1*/
int elapsedMinutes (string rowerString);

/*returns seconds elapsed if string is valid, otherwise returns -1*/
int elapsedSeconds (string rowerString);



int main() {
    string rowerString;
    cout << "enter string: " << endl;
    getline(cin, rowerString);
    isValidRowerString(rowerString);
    
    cout <<  "mins: " << elapsedMinutes(rowerString) << endl;
    cout << "seconds: " << elapsedSeconds(rowerString) << endl;
    cout << "strokes: " << strokesPerMinute(rowerString) << endl;
    cout << "distance: " << totalDistance(rowerString) << endl;
    cout << "heart rate: " << heartRate(rowerString) << endl;
    
}

bool isValidRowerString (string rowerString) {
    int i = 0;
    
    //call number function
    int minutes = number(rowerString, i);
    
    //check if minutes are between 1 and 59 or if time is 0, check if next character is a colon
    if ((minutes >= 1 && minutes <= 59) || (isColon (rowerString, i, minutes))) {
        i++;
        
        //check if seconds are between 0 and 59
        int seconds = number(rowerString, i);
        if ((seconds >=10 && seconds <= 59) || isZero (rowerString, i)) {
            
            //check if strokes per minute are between 1 and 999 AND check if next value is s/m
            int strokesPerMin = number(rowerString, i);
            if ((strokesPerMin >= 1 && strokesPerMin <= 999) && isStrokesPerMin(rowerString, i)) {
                
                //check if meters are non negative AND check if next value is m
                int meters = number(rowerString, i);
                if (meters >= 0 && isMeters(rowerString, i)) {
                    
                    //check if heart rate is between 1 and 999
                    int heartRate = number(rowerString, i);
                    if (heartRate >= 1 && heartRate <= 999) {
                        
                        //check if string is over
                        if (i == rowerString.length()) {
                            return true;
                        }
                        
                        else {
                            return false;
                        }
                    }
                    
                    else {
                        return false;
                    }
                }
                
                else {
                    return false;
                }
            }
            
            else {
                return false;
                
            }
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
    
}

bool isColon (string rowerString, int & i, int minutes) {
    if ((minutes == 0) && rowerString [i] == ':') {
        return true;
    }
    else {
        return false;
    }
}

bool isStrokesPerMin (string rowerString, int &i) {
    char space = rowerString[i];
    i++;
    char strokes = rowerString [i];
    i++;
    char slash = rowerString [i];
    i++;
    char minutes = rowerString [i];
    i++;
    
    if ((space == ' ') && (strokes == 's') && (slash == '/') && (minutes == 'm')) {
        return true;
    }
    
    else {
        return false;
    }
}

bool isMeters (string rowerString, int &i) {
    if (rowerString[i] == '0') {
        i++;
    }
    char space = rowerString [i];
    i++;
    char meters = rowerString[i];
    i++;
    
    if ((space == ' ') && (meters == 'm')) {
        return true;
    }
    else {
        return false;
    }
}

bool isZero (string rowerString, int &i) {
    if (rowerString[i] == '0') {
        i++;
        char secondsAfterZero = number(rowerString, i);
        if (secondsAfterZero >= 0 && secondsAfterZero <=9) {
            if (secondsAfterZero == 0) {
                i++;
            }
            return true;
        }
        else {
            return false;
        }
    }
    else {
        return false;
    }
}

int elapsedMinutes (string rowerString) {
    if (isValidRowerString(rowerString)) {
        int i = 0;
        return number(rowerString, i);
    }
    else {
        return -1;
    }
}

int elapsedSeconds (string rowerString) {
    if (isValidRowerString(rowerString)) {
        int startingPlace = 0; //find the colon, because the elapsed seconds will come after it
        for (int i = 0; i < rowerString.length(); i++) {
            if (rowerString[i] == ':') {
                startingPlace = i + 1;
                if (rowerString [startingPlace] == '0') {
                    startingPlace++;
                }
                break;
            }
        }
        return number(rowerString, startingPlace);
    }
    else {
        return -1;
    }
}

int strokesPerMinute (string rowerString) {
    if (isValidRowerString(rowerString)) {
        int i = 0;
        number(rowerString, i); //minutes
        i++;
        number(rowerString, i); //seconds
        if (rowerString [i] == '0') {
            i = i + 2;
        }
        int strokesPerMin = number(rowerString, i); //strokesPerMin
        return strokesPerMin;
    }
    else {
        return -1;
    }
}

int totalDistance (string rowerString) {
    if (isValidRowerString(rowerString)) {
        int i = 0;
        number(rowerString, i); //minutes
        i++;
        number(rowerString, i); //seconds
        if (rowerString [i] == '0') {
            i = i + 2;
        }
        number(rowerString, i); //strokesPerMin
        i = i + 4;
        int distance = number(rowerString, i);
        return distance;
    }
    else {
        return -1;
    }
}

int heartRate (string rowerString) {
    if (isValidRowerString(rowerString)) {
        int i = 0;
        number(rowerString, i); //minutes
        i++;
        number(rowerString, i); //seconds
        if (rowerString [i] == '0') {
            i = i + 2;
        }
        number(rowerString, i); //strokesPerMin
        i = i + 4;
        number(rowerString, i); //distance
        if (rowerString [i] == '0') {
            i = i + 3;
        }
        else {
            i = i + 2;
        }
        int heartRate = number(rowerString, i);
        return heartRate;
    }
    else {
        return -1;
    }
}

int number(string s, int& startingPosition) {
    
    int result = 0;
    
    // ignore leading whitespace
    while (startingPosition < s.length() &&  isspace( s.at( startingPosition))) {
        startingPosition = startingPosition + 1;
    }
    
    // no leading zeros
    
    if (startingPosition < s.length()) {
        
        if (s.at( startingPosition ) >= '1' && s.at( startingPosition ) <= '9') {
            
            while (startingPosition < s.length() && s.at( startingPosition ) >= '0' && s.at( startingPosition ) <= '9') {
                
                int value = s.at( startingPosition ) - '0';
                
                result = (result * 10) + value;
                
                /// move on down the road
                
                startingPosition = startingPosition + 1;
                
            }
            
        }
        
    }
    
    else {
        
        result = -1;
        
    }
    
    return(result);
    
}



