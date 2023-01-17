/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>

/* Add a prototype for a helper function here if you need */
void push(Node*& list, Node*& in);
// push_back the first element of in to the list and then delete the it from in


void split(Node*& in, Node*& odds, Node*& evens)
{
  /* Add code here */
// WRITE YOUR CODE HERE
  if (in == NULL){return;}

  if (in->value % 2 == 0){
    push(evens, in);
    
  }
  else if (in->value % 2 == 1){
    push(odds, in);
    
  }
  split(in, odds, evens);
}

/* If you needed a helper function, write it here */
void push(Node*& list, Node*& in){

  if (list == NULL){
    list = in;
    Node* temp_1 = in->next;
    in->next = NULL;
    in = temp_1;
    return;
  }
  
  Node* next_element;
  next_element = list;

  // find the last element of the list
  while (next_element->next != NULL){
    next_element = next_element->next;

  }
  next_element->next = in;
  Node* temp_2 = in->next;
  in->next = NULL;
  in = temp_2;
  
}