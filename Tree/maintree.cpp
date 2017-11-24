/* 
 * File:   main.cpp
 * Author: keheira
 *
 * Created on November 5, 2013, 2:09 PM
 */

#include "Tree.h"
#include <iostream>

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Tree b;
    int x;
    
    while(true){
        cout<<"Please enter a number to add to the tree. When finished enter -1.";
        cin>>x;
        if(x==-1)
            break;
        b.Insert(x);
        b.Display();
    }
    while(true){
        cout<<"Please enter a number to delete from the tree. When finished enter -1.";
        cin>>x;
        if(x==-1)
            break;
        b.Delete(x);
        b.Display();
    }
    
    return 0;
}
