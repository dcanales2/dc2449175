 /* 
 * File:   main.cpp
 * Author: Daniel Canales
 * I have 2 header files name Choice and Stash 
 * For making my program neater and organized by catagory
 * Created on July 14, 2014, 11:03 AM
 */

#include <cstdlib>
#include <ctime>
#include <iostream>
#include "STATS.H"
#include "CHOICE.h"
using namespace std;

/*
 * 
 */
//functions
int diceroll();
void clear();


int main(int argc, char** argv) {
    
    

    //placed here to make everything random when needed
    srand(static_cast<unsigned int>(time(0)));
    
    //keeps track of how far youve gone
    int space = 0;

   //create the board-start off 50 spaces split into 4 sections
    do{     
        int roll = diceroll();
        char hit;
        cout << "The dice is rolling" << endl;
        cout << "Push H or h to stop the dice" << endl;
        cin >> hit;
        do
        {
            //gets the roll
            cout << "You rolled the dice" << endl;
            cout << "You rolled a " << roll << endl;
            //adds roll to space counter
            //stops the loop so it can keep going
            break;
        }while(hit=='h' || hit=='H');

        space += roll;

        //switch case space to see what part of map does what
        switch(space)
        {
            //case numbers represent spaces
            case  1 ... 15: cout << "Your in section 1" << endl; 
                                                           turn();
                                                           break;
            case 16 ... 30: cout << "Your in section 2" << endl; 
                                                           turn();
                                                           break;
            case 31 ... 45: cout << "Your in section 3" << endl; 
                                                           turn();
                                                           break;
            case 46 ... 50: cout << "You are in the final section" << endl;
                                                           break;
        }

    }while(space <= 50);
    return 0;
}



//returns dice value 
int diceroll()
{
    int dice = rand()%6+1;
    return dice;
}

//cleans up the screen 
void clear()
{
    for(int i=0; i<=15; i++)
    {
        cout << " " << endl;
    }
}

