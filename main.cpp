#include <iostream>
#include <string>
#include "Hare.hpp"


//g++ -std=c++11 main.cpp would be fine with #include "Hare.cpp"
//#include <vector> //included in "Hare.hpp" already
using namespace std;



int main(int argc, const char *argv[]) { //does not take input from users
    Hare hare;
    


    vector<int> patterns = {1, -2, 6}; //c++11
    Hare hare2(patterns, 2);

    int arr[] = {1, 1, 2, -3, 5};
    int size = sizeof(arr) / sizeof(arr[0]);
    Hare hare3(arr, size, 6);

    switch (*argv[1]) {
    case 'A': //default constructor
        cout << "After calling default constructor, data member patterns is {";
        for (int i = 0; i < hare.patterns.size(); i++) {
            cout << hare.patterns[i];
            if (i < hare.patterns.size()-1)
                cout << ",";
        }
        cout << "}" << endl;
        cout << "After calling default constructor, data member position is ";
        cout << hare.position<< endl;
        break;
//a typical hare that sleeps 20% of the time,
//move 9 squares to the right 20% of the time,
//move 12 squares to the left 10% of the time,
//move 1 square to the right 30% of the time,
//move 2 squares to the left 20% of the time.
    case 'B': //Hare(std::vector<int> patterns, int position);
        cout << "After calling constructor Hare(std::vector<int>, int), data member patterns is {";
        for (int i = 0; i < hare2.patterns.size(); i++) {
            cout << hare2.patterns[i];
            if (i < hare2.patterns.size()-1)
                cout << ",";
        }
        cout << "}" << endl;
        cout << "After calling constructor Hare(std::vector<int>, int), data member position is ";
        cout << hare2.position << endl;
    break;
    case 'C': //Hare(int* arr, int size, int position);
        cout << "After calling constructor Hare(int*, int, int), data member patterns is {";
        for (int i = 0; i < hare3.patterns.size(); i++) {
            cout << hare3.patterns[i];
            if (i < hare3.patterns.size()-1)
                cout << ",";
        }
        cout << "}" << endl;
        cout << "After calling constructor Hare(int*, int, int), data member position is ";
        cout << hare3.position << endl;
        break;
    case 'D': //void move();
        cout << "After calling move method, data member position is ";
        hare.move();
        cout << hare.position<< endl;
        break;
    case'E': //int getPosition();
        cout << "After setting hare’s position to be 10 and calling getPosition method, data member position is ";
        hare.position = 10;
        cout << hare.position << endl;
        break;
    case 'F': //void setPosition(int position);
    cout << "After hare.setPosition(3); data member position is ";
    hare.setPosition(3);
    cout << hare.position << endl;
    break;
    default:
        cout << "wrong option";
    }

    return 0;
}