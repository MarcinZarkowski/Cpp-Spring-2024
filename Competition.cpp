//Marcin Zarkowski
//csci135
//this is project 3 task D
//Ties together all classes to make the game work in the play method of Competition


#include "Competition.hpp"
#include "Tortoise.hpp"
#include "Hare.hpp"
#include <iostream>
using namespace std;

Competition::Competition(){
    rabbit=Hare();
    tor=Tortoise();
    lane= Road();
};
Competition::Competition(Hare coney, Tortoise cooter, int length ){
    rabbit=coney;
    tor=cooter;
    lane = Road(length);
};
void Competition::play(){
    int round=1;
    int size=lane.length();
    bool torfinished=false;
    bool rabbitfinished=false;

    while (torfinished==false && rabbitfinished==false){
        //rabbit moves
        rabbit.move();
        if (rabbit.getPosition()<0){
            rabbit.setPosition(0);
        }
        else if(rabbit.getPosition()>size-1){
            rabbit.setPosition(size-1);
            
        }
        if(rabbit.getPosition()==size-1){
            rabbitfinished=true;
        }
        lane.mark(rabbit.getPosition(),'H');

        //tor moves
        tor.move();
        if (tor.getPosition()<0){
            tor.setPosition(0);
        }
        else if(tor.getPosition()>size-1){
            tor.setPosition(size-1);
            
        }
        if(tor.getPosition()==size-1){
            torfinished=true;
        }
        lane.mark(tor.getPosition(),'T');

        cout<<"round: "<<round<<": ";
        lane.display();
        if(tor.getPosition()==rabbit.getPosition()){
            cout<<"Ouch! Tortoise bites hare."<<endl; 
        }
        round++;
        lane.mark(rabbit.getPosition(), ' ');
        lane.mark(tor.getPosition(), ' ');

    }
    if(rabbitfinished==true && torfinished==false){
        cout<<"Yuck. Hare wins."<<endl;
    }
    else if (rabbitfinished==false && torfinished==true){
        cout<<"Yay! Tortoise wins!"<<endl;
    }
    else{
        cout<<"Tie."<<endl;
    }
}