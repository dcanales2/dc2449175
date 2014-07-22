/* 
 * File:   main.cpp
 * Author: Daniel Canales
 *
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

    //holds how far along youve gone
    int space = 0;
    
   //create the board-start off 50 spaces split into 4 sections
    do{     
        //gets the roll
        cout << "You rolled a " << diceroll() << endl;
        //adds roll to space counter
        space += diceroll();

        //switch case space to see what part of map does what
        switch(space)
        {
            case  1 ... 15: cout << "Your in section 1" << endl; 
                                                           battle();
                                                           break;
            case 16 ... 30: cout << "Your in section 2" << endl; 
                                                           break;
            case 31 ... 45: cout << "Your in section 3" << endl; 
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

