/* 
 * File:   main.cpp
 * Author: keheira
 *
 * Created on September 25, 2013, 3:23 PM
 */

#include "doublelink.h"
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    List a;
    int y;
    bool n = true;
    
    while(n){
        cout<<"Enter a number: ";
        cin>>y;
        
                if(!a.InList(y))
            a.InsertAtEnd(y);
                else{
            
                a.Delete(y);
           
        }
        a.Display();
        //a.DisplayBack();
    }
    return 0;
}
