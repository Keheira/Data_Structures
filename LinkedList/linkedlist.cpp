#include "linkedlist.h"
#include <iostream>
using namespace std;

List::List() { //create an empty list by setting first to NULL
    first = NULL;
}

bool List::empty() { // return true if the list is empty, otherwise return false
    if (first == NULL)
        return true;
    return false;
}

void List::InsertAtEnd(ElementType x) { //insert a value x at the end of list
    Node *p = new Node;
    p ->data = x;
    p -> next = NULL;
    
    if (empty()) { //use if list is empty
        first = p;
    } else { //use when there is something in the first position
        Node* ptr = first;
        while (ptr->next != NULL) {
            ptr = ptr->next;
        }
        ptr->next = p;
    }
}

bool List::InList(ElementType x) { // return true if x is in the list, otherwise return false
    Node *ptr = first;
    if(!empty())
    while (ptr != NULL) {
        if (ptr ->data == x)
        return true;
        ptr=ptr->next;
    }
    return false;
}

void List::Delete(ElementType x) { //if value x is in the list, remove x
    Node *ptr = first;
    Node* trail = ptr;
    if (first ->data == x){ //check first node
        first = first ->next;
        ptr ->next = NULL;}
    else{
    
    while (ptr ->next != NULL) { //check middle nodes
        
        if (ptr ->data == x) {
            trail->next = ptr ->next;
            ptr ->next = NULL;
            delete ptr;
            return;
        }
        else{
            
        trail=ptr;
        ptr = ptr->next;
        }
    }
    //cout<<"Last Number "<<ptr->data;
     if (ptr ->data == x) { //Check last node
         
    trail->next = NULL;
           
            delete ptr;
     }    
    }
}

void List::Display() { // Display the data values in the list
    Node* ptr = first;
    while (ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
