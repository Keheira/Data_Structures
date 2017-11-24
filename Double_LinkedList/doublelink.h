/* 
 * File:   doublelink.h
 * Author: keheira
 *
 * Created on September 25, 2013, 3:25 PM
 */

#ifndef DOUBLELINK_H
#define	DOUBLELINK_H

typedef int ElementType;
struct Node {
 	ElementType data;
	Node * next;
        Node * prev;
};
class List
{
 public: 
   List(); //create an empty list by setting first to NULL
   bool empty(); // return true if the list is empty, otherwise return false
   void InsertAtEnd(ElementType x);//insert a value x at the end of list
   bool InList (ElementType x); // return true if x is in the list, otherwise return false
   void Delete(ElementType x); //if value x is in the list, remove x
   void Display();// Display the data values in the list
   void DisplayBack();// Display the data values in the list backwards

 private:
   Node * first;//pointer to the first item in the list
};

#endif	/* DOUBLELINK_H */
