//Marcin Zarkowski
//csci135
//this is project 3 task C

#include "Road.hpp"
#include <iostream>
#include <vector>
using namespace std;
Road::Road(){
    blocks.assign(70, ' ');
};
Road::Road(int length){
    if(length<0){
        blocks.assign(70, ' ');
    }
    else{
        blocks.assign(length, ' ');
    }
};
void Road::mark(int index, char ch){
    if(index>=0 && index<blocks.size()){
        blocks[index]=ch;
    }
}
void Road::display() const{
    for(int i =0; i<blocks.size();i++){
        cout<<blocks[i];
    }
    cout<<endl;
}
int Road::length() const{
    return blocks.size();
    
}