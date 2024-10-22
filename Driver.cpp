/*
    Title: Driver.cpp
    Authors: Jack Bender, Cole Wilson
    Date: 10-23-24
    Purpose: provide a way to run the program 
*/

//library inclusions
#include "LinkedList.h"
#include "DataClass.h"
#include "DataClass.cpp"

int main ()
{
    LinkedList<Data> resistorList;
    int menuChoice = 0; 
    //repeat program until user finished 
    do 
    {
        cout << "\n\nHello! Welcome to the Resitor Series Circuit Simplifier Program!"; 

        cout << "\n\n1. View existing resistors"; 
        cout << "\n2. Add a new resitor"; 
        cout << "\n3. Remove an existing resistor"; 
        cout << "\n4. Simplify the circuit"; 
        cout << "\n5. Exit Program"; 

        cout << "\n\nPlease enter an integer from the menu: "; 
        cin >> menuChoice; 
        cin.ignore(); 

        //input validation
            while(!(cin >> menuChoice) || (menuChoice < 1 || menuChoice > 5))
            {
                //have user input another input 
                cout << "\nPlease enter a valid choice: ";
                cin.clear();
                cin.ignore(100, '\n'); 
            }

        switch (menuChoice)
        {
            int subChoice = 0; 

            //view existing resistors
            case 1: 

                //need case for empty list
                //need to look at the data stored in DataClass
                resistorList.displayList();
                break; 

            //add a new resistor 
            case 2: 
                //need to use DataClass functions to actually store info 
                userInputInfo(); 

                //after have the info ask user how they want to add the resistor
                cout << "\n\nHow would you like to add the resistor to the circuit?"; 

                cout << "\n\n1. To the front"; 
                cout << "\n2. To the back"; 
                cout << "\n3. At a more specific spot"; 

                cout << "\n\nPlease enter an integer from the menu: "; 
                cin >> subChoice; 
                cin.ignore(); 

                //input validation
                while(!(cin >> subChoice) || (subChoice < 1 || subChoice > 3))
                {
                    //have user input another input 
                    cout << "\nPlease enter a valid choice: ";
                    cin.clear();
                    cin.ignore(100, '\n'); 
                }

                //switch statement for adding options
                switch(subChoice)
                {
                    //prepend to front 
                    case 1: 
                    
                    break; 

                    //append to back
                    case 2: 

                    break; 

                    //at a specific spot
                    case 3: 

                    break; 
                }

                break; 

            //remove an existing resistor 
            case 3: 
                int removeChoice; 

                cout << "\n\nWhat resistor would you like to remove from the circuit?"; 
                cout << "\nNote: this will remove the resistor completely without simplifying it with the circuit"; 

                cout << "\n\nPlease enter the position of the resistor in the circuit as an integer: "; 
                cin >> removeChoice; 
                cin.ignore(); 

                //input validation
                while(!(cin >> removeChoice))
                {
                    //have user input another input 
                    cout << "\nPlease enter a valid choice: ";
                    cin.clear();
                    cin.ignore(100, '\n'); 
                }

                

            break; 

            //Simplify the circuit 
            case 4: 
                cout << "\n\nHow would you like to simplify the circuit?"; 

                cout << "\n\n1. To simplify two resistors in the front of the circuit"; 
                cout << "\n2. To simplify a specific reistor in the circuit"; 
                cout << "\n3. To simplify the whole circuit down to one resistor"; 
                                                                                //we could have a repeating option to let
                                                                                //people simplify the circuit quickly using pop
                
                cout << "\n\nPlease enter an integer from the menu: "; 
                cin >> subChoice; 
                cin.ignore(); 

                //input validation
                while(!(cin >> subChoice) || (subChoice < 1 || subChoice > 3))
                {
                    //have user input another input 
                    cout << "\nPlease enter a valid choice: ";
                    cin.clear();
                    cin.ignore(100, '\n'); 
                }

                switch(subChoice)
                    {
                        //pop resistor at front 
                        case 1: 

                             

                            
                        
                        break; 

                        //remove resistor at specific spot 
                        case 2: 
                            int resistorChoice = 0; 
                            cout << "\n\nHow would you like to simplify this resistor?"; 
                            cout << "\nYou can combine it with the resistor to the left, or to the right"; 
                            cout << "\n\n1. Right"; 
                            cout << "\n2. Left"; 

                            cout << "\nPlease enter a 1 or 2: "; 
                            cin >> resistorChoice; 
                            cin.ignore(); 

                            //input validation
                            while(!(cin >> resistorChoice) || (resistorChoice < 1 || resistorChoice > 2))
                            {
                                //have user input another input 
                                cout << "\nPlease enter a valid choice: ";
                                cin.clear();
                                cin.ignore(100, '\n'); 
                            }

                            //right
                            if (resistorChoice = 1)
                            {

                            }
                            //left
                            else if (resistorChoice = 2)
                            {

                            }
                            

                        break; 

                        //pop repeated until whole circuit simplified 
                        case 3: 

                        break; 
                    }
            break; 

            //Exit program 
            case 5: 
                //simple goodbye message
                cout << "\n\nThank you for using the Resistor Series Circuit Simplifier Program!"; 
                cout << "\n\nRemember to like, share, and subscribe!"; //the funny (unless this program actually takes off)

            break; 
            }


    } while (menuChoice != 5); //end do while loop 

    //end program 
    return 0; 
}