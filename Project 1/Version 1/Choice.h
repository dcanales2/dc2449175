/* 
 * File:   Choice.h
 * Author: Daniel Canales
 *
 * Created on July 15, 2014, 11:39 AM
 *
 * Will be used to give player a choice of atk/def/item
 * uses a switch statement with another for checking enemy type
 * and outputs to corresponding
 */

#ifndef PLCHOICE_H
#define	PLCHOICE_H


#include "STATS.H"
#include <iostream>


//player options
void plmove()
{
    //will compare strings to go to correct switch
    string choice;
    string attack = "attack";
    string defend = "defend";
    string item = "item";

    //enter choice
    cout << "What would you like to do?" << endl;
    cout << "Attack" << endl;
    cout << "Defend" << endl;
    cout << "Item" << endl;
    cout << " " << endl;
    cin >> choice;

    //turning string compare to answer
    int ans = 0;
    
    //will be attacks
    //if not written correctly attack will miss and you'll be hit
    //this is for when written correctly
    if(choice.compare(attack) == 0) ans=1;
    if(choice.compare(defend) == 0) ans=2;
    if(choice.compare(item) == 0) ans=3;
    
    /*//for when you misspell
    if(!choice.compare(attack) == 0) ans=4;
    if(!choice.compare(defend) == 0) ans=4;
    if(!choice.compare(item) == 0) ans=4;
    */

    //create switch to use correct option
    //will then add cases incases if possible
    switch(ans)
    {
        case 1: cout << "You chose to attack" << endl;  
                //every attack drops hp by 20
                wolfhp -= platk;
                cout << "Wolf's HP is " << wolfhp << endl;
                break;
        case 2: cout << "You chose to defend"; break;
        case 3: cout << "You chose to use item"; break;
        case 4: cout << "You messed up and missed" << endl; break;
    }
    
}    

//enemy attack
void enmove()
{
    cout << "Its the enemy's turn to attack!" << endl;
    plhp -= wolfatk;
    cout << "You have " << plhp << " HP remaining" << endl;
}

//starts the encounter and ends when someone dies
//HAVE TO REWRITE BATTLE IN MAIN BECAUSE IT WONT AUTOCHANGE
void battle()
{
    //does battle but crashes if lost
    //need to reset health for animals
    if(plhp != 0)
    {
        do{
            //checks to see if your alive to continue loop
            if(plhp>=1)plmove(); 
            if(wolfhp>=1)enmove();

            //once dead if activates depending on who died and returns back
            if(wolfhp<=0)
            {
                cout << "You killed the wolf" << endl;
                wolfhp == 0;
            }
            if(plhp<=0)
            {
                cout << "You are dead" << endl;
                plhp == 0;
            }

            //i couldnt get (wolfhp>=1 || plhp>=1) to work so i made it
            //into 2 do while loops instead
          }while(wolfhp>=1);
      }
      else return;
}




#endif	/* PLCHOICE_H */

