/* 
 * File:   main.cpp
 * Author: keheira
 *
 * Created on September 17, 2013, 2:47 PM
 */

#include "linkedlist.h"
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
    }
    return 0;
}
