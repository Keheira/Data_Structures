#include "doublelink.h"
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
        p->prev = ptr;
        p->next = NULL;
    }
}

bool List::InList(ElementType x) { // return true if x is in the list, otherwise return false
    Node *ptr = first;
    if (!empty())
        //cout<<"I'm not empty"<<endl;
        while (ptr != NULL) {
            if (ptr ->data == x) {
                return true;
            }
            //cout<<"going to change"<<endl;
            ptr = ptr->next;
        }
    //cout<<"I'm empty"<<endl;
    return false;
}

void List::Delete(ElementType x) { //if value x is in the list, remove x
    if (first == NULL)
        return;
    Node *ptr = first;
    Node* trail = ptr;
    if (first ->data == x) { //check first node
        first = first ->next;
        ptr = first;
        delete trail;
    } else {

        while (ptr ->next != NULL) { //check middle nodes

            if (ptr ->data == x) {
                trail->next = ptr ->next;
                trail->next->next->prev = ptr ->prev;
                ptr ->next = NULL;
                ptr ->prev = NULL;
                delete ptr;
                return;
            } else {

                trail = ptr;
                ptr = ptr->next;
            }
        }
        if (ptr ->data == x) { //Check 2nd to last node
            ptr->prev = NULL;
            trail->next = NULL;
            delete ptr;
        }
    }
}

void List::Display() { // Display the data values in the list
    Node* ptr = first;
    Node* trail = ptr;
    int y = 0;
    do {//print the numbers forwards
        cout << ptr->data << " ";
        trail = ptr;
        ptr = ptr->next;
    } while (ptr != NULL);

    ptr = trail;
    int x = 0;
    do {//print the numbers backwards
        cout << ptr->data << " ";
        ptr = ptr->prev;
    } while (ptr != NULL);
    //cout << ptr->data << " ";
}
