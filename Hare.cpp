//Marcin Zarkowski
//csci35
//this is a constructor file of class Hare

#include "Hare.hpp"
#include <cstdlib>
#include <vector>
using namespace std;


Hare::Hare(){
    patterns={0,0,9,9,-12,1,1,1,-2,-2};
    position=0;
};
Hare::Hare(vector<int> patterns, int position){
    for (int i =0; i<patterns.size();i++){
        this->patterns.push_back(patterns[i]);
    }
    this->position=position;

};

int Hare::getPosition() const{
    return position;
};

Hare::Hare(int* arr, int size, int position){
    for (int i=0; i<size; i++){
        patterns.push_back(arr[i]);
    }
    this->position=position;
};

void Hare::move(){
    int num=rand()%patterns.size();
    int stepsToMove=patterns[num];
    position+=stepsToMove;
};


void Hare::setPosition(int position){
    this->position=position;
};