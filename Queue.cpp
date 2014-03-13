#include "Queue.h"
#include "Stack.h"
#include <iostream>
using namespace std;

Queue::Queue(){ // create an empty Queue
    myfront = NULL;
    myback = NULL;
}

bool Queue::empty(){ //return true if Queue is empty, otherwise return false
    if(myfront == NULL)
        return true;
    return false;
}

void Queue::AddQ(QueueElement x){ //add a new value to the back of the Queue
    if(empty()){ //if list is empty
        qnode* temp = new qnode;
        temp->data=x;
        temp->next = NULL;
        myback = temp;
        myfront = myback;
    }
    else{ //if list has values
        qnode* temp = new qnode;
        temp->data=x;
        temp->next = NULL;
        myback->next = temp;
        myback= temp;
    }
}

bool Queue::Front (QueueElement & x){ //retrieve the data at the front of the Queue
    x = myfront->data;
    return true;
}
void Queue::RemoveQ(){ //remove the value at the front of the Queue
    qnode* hold = myfront->next;
    qnode* temp = myfront;
    temp->next = NULL;
    myfront = hold;
    delete temp;
}
void Queue::display(){ //displays the data stored in the Queue from front to back
    qnode* ptr = myfront;
    while(ptr != NULL){
        cout<<ptr->data;
        cout<<" ";
        ptr=ptr->next;
    }
}
