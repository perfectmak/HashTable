/* 
 * File:   main.cpp
 * Author: perfectmak
 *
 * Created on September 26, 2015, 2:07 AM
 */

#include <iostream>
#include <string>
#include <vector>
#include "Hash.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {

    Hash<int, string> hashMap;
    hashMap.insert(2,"perfect");
    hashMap.insert(4, "Excellent");
    try
    {
        cout << "Value is " << hashMap.get(4);
    }
    catch(string error)
    {
        cout << "Could not find\n" << error << endl;
    }
    cin.get();
    return 0;
}

