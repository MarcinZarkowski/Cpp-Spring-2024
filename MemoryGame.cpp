#include "MemoryGame.hpp"
#include <cstdlib> // For rand() function
#include <iostream> 
#include <iomanip>
using namespace std;
MemoryGame::MemoryGame() : MemoryGame(3,8) {
    numPairs=3;
    numSlots=8;
    
};
        
    
MemoryGame::MemoryGame(int numPairs, int numSlots){
    if ((numPairs < 0 or numSlots<0) or (numSlots < 2*numPairs)){
        numPairs=3;
        numSlots=8;

    }

    this->numPairs=numPairs;
    this->numSlots=numSlots;
    values = new string[numSlots];
    bShown = new bool[numSlots];

    // Place pairs of random numbers in the first numPairs * 2 slots
    for(int i=0; i<numPairs;++i){
        int num = rand() % 1000; // Generate a random number
        values[i * 2] = to_string(num);
        values[i * 2 + 1] = to_string(num);
    }

    // Set the rest of the slots to empty strings and initialize bShown to false
    for (int j =numPairs*2; j<numSlots; ++j){
        values[j] = "";
        bShown[j] = false;
    }
}



MemoryGame::MemoryGame(string* words, int size, int numSlots){
    //Assume the number of elements in formal parameter words is size. If formal parameters size or numSlots
    //is non-positive or numSlots is smaller than twice of size, set numSlots to be twice of size
    if(size<0 or numSlots<0 or numSlots<2*size){
        numSlots=2*size;
    }
   // After the above possible adjustment, set data member numPairs to be formal parameter size, and set data
    //member numSlots to be formal parameter numSlots.

    this->numPairs=size;
    this->numSlots=numSlots;
    //Allocate dynamic memory for an array of strings with numSlots elements and assign it to data member
    //values. Place the first word to the first two slots of values, the second word to the next two slots of
    //values, · · · , until all words are placed in pairs in values. Set the rest elements of values to be empty
    //strings.
    this->values= new string[numSlots];

    for (int z=0; z <size;z++){
        values[z*2]=words[z];
        values[z*2+1]=words[z];
    }
    // Allocate dynamic memory for an array of booleans – type bool in C++ – with numSlots elements and assign
    //it to data member bShown. Set each element of bShown to be false.
    this->bShown=new bool[numSlots];
    for (int i=0; i<numSlots;i++){
        bShown[i]=false;
    }

}
MemoryGame::~MemoryGame() {
    delete[] values;
    delete[] bShown;
    values = nullptr; // Avoid dangling pointers
    bShown = nullptr;
}
void MemoryGame::randomize() {
    /*1. Initialize size to be the number of elements of array values, which is saved in data member ... (you find
this out).
2. Generate a random index in [0, size). Swap the element at chosen index with the last element in values.
3. Then reduce size by 1 so that we do not consider the already-chosen element, which resides in the last
element of values.
4. Continue Step 2-3 until size is 1 (why not 0? Hint: do we need to randomize if there is only one element
left in the array to be randomized?) Said differently, as long as size is larger than 1, run codes in Steps 2-3.

}*/
    int size=sizeof(values);
    while (size!=1){
        int random=rand()%size;
        string a = values[random];
        string b=values[size-1];
        values[random]=b;
        values[size-1]=a;
        size=size-1;
    } 
}

void printSeparatedLine(int size) {
    cout << "+"; //the first +
    //draw -----+ for (size) many times
    for (int i = 0; i < size; i++)
    cout << "-----+";

    cout << endl;
}
    
void MemoryGame::display() const {
    cout<<" ";
    for (int i = 0; i < numSlots; i++)
        cout << setw(3) << i << setw(3) << " ";
    

    cout << endl;

    printSeparatedLine(numSlots);
    
    for (int j =0; j<numSlots;j++){
        cout<<"|";
        for (int x=0 ;x<5-(values[j].length());x++){
            cout<<" ";
        }
        if (bShown[j]){
            cout<<values[j];
        }
        else{
            for( int y=0; y<values[j].length();y++){
                cout<<" ";
            }
        }
    }
    cout<<"|";
    cout<<endl;
    printSeparatedLine(numSlots);

}


int MemoryGame::input()const{
    cout<<"Enter a unflipped card in [0, "<<numSlots-1<<"]: ";
    int in;
    cin>>in;
    
    
    
    while(in<0 or in >numSlots-1 ){
        cout<<"input is not in [0, "<<numSlots-1<<"]. Re-enter: ";
        cin>>in;
        
        
    }
    while (bShown[in]==true){
        cout<<"The card is flipped already. Re-enter: ";
        cin>>in;
        
        
    }
    
    return in;

}
void MemoryGame:: play (){
    int counter=0;
    int matches=0;
    bool won=false;
    display();
    randomize();


    do{
        cout<<"Round"<<setw(3)<<counter<<':'<<endl;
        int firstGuess=input();
        bShown[firstGuess]=true;
        counter++;


        display();
        cout<<"Round"<<setw(3)<<counter<<':'<<endl;
        int secondGuess=input();
        bShown[secondGuess]=true;


        if (values[firstGuess]==values[secondGuess] && values[firstGuess]!="" ){
            matches++;

        }
        else{
            bShown[firstGuess]=false;
            bShown[secondGuess]=false;
        }
        if(matches==numPairs){
            won=true;
        }

        display();
        counter++;
    }
    while(won!=true);
    cout<<"Congratulations! Foun out all the pairs in "<<counter-1<<" rounds"<<endl;
}
