//Marcin Zarkowski
#include <iostream>
#include <cstdlib>
using namespace std;

int main() {
    // Array to store operators
    char operators[] = {'+', '-', '*', '/', '%'};
    int size= sizeof(operators)/sizeof(operators[0]);
    int index = rand() % size;

    // Randomly select an operator
    char sign = operators[index];

    // Randomly generate two numbers based on the operator
    int num1 = rand() % 10;
    int num2;

    if (sign == '/' || sign == '%') {
        num2 = rand() % 9 + 1;
    } 
    else {
        num2 = rand() % 10;
    }

    // Display the arithmetic expression
    cout << "What is " << num1 << " " << sign << " " << num2 << "? ";

    // Get user input for the answer
    int userAnswer;
    cin >> userAnswer;

    // Check if the user's answer is correct
    if (sign=='%'){
        if (num1 % num2 == userAnswer){
            cout << "True";
        }
        else{
            cout<<"False";
        }

    }
    else if (sign == '/') {
        if (num1 / num2 == userAnswer){
            cout << "True";
            }
        else{
            cout<<"False";
        }
    }
    else if (sign == '+') {
        if (num1 + num2 == userAnswer){
            cout << "True";
            }
        else{
            cout<<"False";
        }
    }
    else if (sign == '-') {
        if (num1 - num2 == userAnswer){
            cout << "True";
            }
        else{
            cout<<"False";
        }
    }
    else if (sign == '*') {
        if (num1 * num2 == userAnswer){
            cout << "True";
            }
        else{
            cout<<"False";
        }
    }
   

    return 0;
}
