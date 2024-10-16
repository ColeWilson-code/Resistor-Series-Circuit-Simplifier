/*
    Title: LinkedList.h
    Authors: Jack Bender, Cole Wilson
    Date: 10-15-24
    Purpose: create the LinkedList class and the Template helper class
*/

//define header
#ifndef LINKED_LIST_H
#define LINKED_LIST_H



//library inclusions 
#include <iostream>
#include <list>
using namespace std; 

//template to be used with TemplateHelper class
template <typename T>

//LinkedList class
//need at least 10 functions 
class LinkedList
{
    private: 
        //attributes
       


        //constructor 
        LinkedList()
        {
           
        }

        //destructor 
        ~LinkedList()
        {

        }


    public: 
        //add functions 

            //append 
            void append(T)
            {

            }



            //prepend
            void prepend(T)
            {
                
            }



            //insert
            void insert(T)
            {

            }



        //get functions

            //back
            void getBack()
            {

            }



            //front
            void getFront()
            {

            }



            //at
            void getAt()
            {

            }



        //remove functions 

            //pop
            void pop(T)
            {

            }

            //erase 
            void erase(T)
            {

            }


            //remove
            void remove(T)
            {

            }



        //friend functions

            //sort
                //needs to be able to sort in ascending and descending order
                //maybe use a bool to specify direction your sorting?



            //stream operator



};



//template to be used with TemplateHelper class
template <typename T>

//Template Helper class is like List Node but seperate class
//List node same file
class TemplateHelper
{
    private: 
        //stores data of the template type
        T data; 
        
        //holds two pointers to another list node
        TemplateHelper *next; 
        TemplateHelper *previous; 

    public: 
        //get data at this location 
        T getData()
        {

        }

        //iterate forward and backwards

            //forward 
            void moveForward()
            {
                data = data->next; 
            }


            //backwards 
            void moveBackward()
            {
                data = data->previous; 
            }

        //set data, next and previous 

            //data
            void setData(T)
            {
                
            }

            //next
            void setNext(T)
            {

            }

            //previous
            void setPrevious(T)
            {

            }

}; 











#endif 