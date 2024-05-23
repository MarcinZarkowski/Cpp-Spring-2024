//Marcin Zarkowski
//csci35
//this is a constructor file of class Hare


#include "Tortoise.hpp"
#include <cstdlib>
using namespace std;



Tortoise::Tortoise(){
    patterns={3,3,3,3,3,-6,-6,1,1,1};
    position=0;
};
Tortoise::Tortoise(int* arr , int size, int position){
    for (int i=0; i<size; i++){
        patterns.push_back(arr[i]);
    }
    this->position=position;
};

Tortoise::Tortoise(vector<int> patterns, int position){
    for (int i =0; i<patterns.size();i++){
        this->patterns.push_back(patterns[i]);
    }
    this->position=position;
};
void Tortoise::move(){
    int num=rand()%patterns.size();
    int stepsToMove=patterns[num];
    position+=stepsToMove;

};
int Tortoise::getPosition() const{
    return position;
}

void Tortoise::setPosition(int position){
    this->position=position;
};