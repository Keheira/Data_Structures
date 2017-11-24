#include "Stack.h"
#include <iostream>
using namespace std;

Stack::Stack(){ // create an empty stack
    mytop = NULL;
}

bool Stack::empty(){ //return true if stack is empty, otherwise return false
    if(mytop == NULL)
        return true;
    return false;
}

void Stack::push(StackElement x){ //add a new value to the top of the stack
    if(empty()){
        node* temp = new node;
        temp->data=x;
        temp->next = NULL;
        mytop = temp;
    }
    else{
        node* temp = new node;
        node* hold = mytop; //temporary hold on the last value entered
        temp->data = x;
        temp->next = NULL;
        mytop = temp;
        mytop->next = hold;//set next backwards so it prints top to bottom
    }
}

bool Stack::Top(StackElement & x){ //retrieves the data that is at the top of the stack
    x = mytop->data;
    return true;
}

void Stack::pop(){ //removes the value at the top of the stack
    node* temp = mytop;
    mytop = temp->next;
    temp->next = NULL;
    delete temp;
}

void Stack::display(){ //displays the data stored in the stack
    node* ptr = mytop;
    while(ptr != NULL){ //print top to bottom
        cout<<ptr->data;
        cout<<" ";
        ptr = ptr->next;
    }
}
