//
//  main.cpp
//  Project4
//
//  Created by Shreya Chatterjee on 2/13/19.
//  Copyright © 2019 Shreya Chatterjee. All rights reserved.
//

#include <iostream>
using namespace std;
#include <string>
#include <cassert>

/*return true if an element is found more than once, false otherwise*/
bool hasDuplicates (const string array[], int size);

/*returns total number of digit characters found in array*/
int countAllDigits (const string array[], int size);

/*returns true if array is in decreasing order, false otherwise*/
bool isInDecreasingOrder(const string array[], int size);

/*shift each element to the right by amount parameter*/
int shiftRight (string array [], int size, int amount, string placeholder);

/*return smallest index of element whose value equals match parameter in array*/
int find (const string array[], int size, string match);

/*replace all instances of findLetter with replaceLetter, return how many letters were replaced*/
int replaceAllCharacters (string array[], int size, char findLetter, char replaceLetter);

int main()
{
    string a[6] = { "alpha", "beta", "gamma", "gamma", "beta", "delta" };
    
    assert(hasDuplicates(a, 3 ) == false);
    assert(hasDuplicates(a, 6 ) == true);
    
    cout << "All tests succeeded" << endl;
    return( 0 );
}

bool hasDuplicates (const string array[], int size) {
    bool flag = false;
    if (size <= 0) {
        return false;
    }
    
    else {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (i != j) {                   //if i = j, this next if statement will always be true
                    if (array[i] == array[j]) {
                        flag = true;
                    }
                }
            }
        }
    }
    return flag;
}

bool isInDecreasingOrder (const string array[], int size) {
    int counter = 0;
    bool flag = false;
    if (size < 0) {
        return false;
    }
    
    else {
        for (int i = 0; i < size; i++) {
            if (array[i+1] < array [i]) {
                counter++;
            }
        }
        
        if (counter == size) {  //if counter = size, then everything is in decreasing order
            flag = true;
        }
    }
    return flag;
}

int countAllDigits (const string array[], int size) {
    if (size <= 0) {
        return -1;
    }
    string element;     //need to etermine if each element in the array has numbers in it
    int counter = 0;
    for (int i = 0; i < size; i++) {
        element = array[i];
        for (size_t j = 0; j < element.size(); j++) {
            if (element[j] == '0' || element[j] == '1' || element[j] == '2' || element[j] == '3' || element[j] == '4' || element[j] == '5' || element[j] == '6' || element[i] == '7' || element[j] == '8' || element[j] == '9') {
                counter ++;
            }
        }
    }
        return counter;
   
}

int shiftRight (string array[], int size, int amount, string placeholder) {
    if (size < 0 || amount < 0) {
        return -1;
    }
    else {
        if (amount > size) {            //if amount is greater than size, all elements will be changed
            for (int i = 0; i < size; i++) {
                array[i] = placeholder;
            }
            return size;
        }
        
        else {
            for (int i = 0; i < size - amount + 1; i++) {
                array[i + amount] = array[i];
                array[i] = placeholder;
            }
            int counter = 0;
            for (int i = 0; i < size; i++) {
                if (array[i] == placeholder) {
                    counter++;
                }
            }
            return counter;
        }
    }
}

int find (const string array[], int size, string match) {
    if (size <= 0) {
        return -1;
    }
    for (int i = 0; i < size; i++) {
        if (array[i] == match) {
            return i;
        }
    }
    return -1;
}

int replaceAllCharacters (string array[], int size, char findLetter, char replaceLetter) {
    if (size <= 0) {
        return -1;
    }
    string element = "";
    int counter = 0;
    for (int i = 0; i < size; i++) {
        element = array[i];
        for (int j = 0; j < element.size(); j++) {  //for each element, determine if string has findLetter, and if so, replace with replaceLetter
            if (element[j] == findLetter) {
                element[j] = replaceLetter;
                counter++;
            }
            array[i] = element;
        }
    }
    return counter;
}
