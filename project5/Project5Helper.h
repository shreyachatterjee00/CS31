//
//  Project5Helper.h
//  Project5Helper
//
//  Created by Howard Stahl on 2/13/19.
//  All rights reserved.
//


#ifndef PROJECT5HELPER_H
#define PROJECT5HELPER_H

#include <string>
using namespace std;

class Project5Helper
{
public:
    Project5Helper();
    
    bool startsWithOrchestra(const string & mainStr );
    bool startsWith(const string & mainStr, const string & toMatch);
    
    bool endsWithPM(const string & mainStr );
    bool endsWith(const string & mainStr, const string & toMatch);
};

#endif
