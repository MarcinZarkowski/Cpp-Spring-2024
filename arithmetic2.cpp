//Marcin Zarkowski
//Cs135
//This is project 1 task B

#include <iostream>
using namespace std;

int main(){
    float questions;
    cout<<"Enter the total number of questions to ask: ";
    cin>>questions;
    float correct;

    while (questions<=0){
        cout<<"The number of questions cannot be zero or negative. Re-enter: ";
        cin>>questions;
        
    }
    char operators[] = {'+', '-', '*', '/', '%'};
    for (int i=0; i < questions; i++){//repeat generation of questions,questioning as many times as user wants there to be questions. 
        // Randomly select an operator
        int size= sizeof(operators)/sizeof(operators[0]);
        
        int index = rand() % size;
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
                cout << "True"<<endl;
                correct+=1;
            }
            else{
                cout<<"False"<<endl;
            }

        }
        else if (sign == '/') {
            if (num1 / num2 == userAnswer){
                cout << "True"<<endl;
                correct+=1;
                }
            else{
                cout<<"False"<<endl;
            }
        }
        else if (sign == '+') {
            if (num1 + num2 == userAnswer){
                cout << "True"<<endl;
                correct+=1;
                }
            else{
                cout<<"False"<<endl;
            }
        }
        else if (sign == '-') {
            if (num1 - num2 == userAnswer){
                cout << "True"<<endl;
                correct+=1;
                }
            else{
                cout<<"False"<<endl;
            }
        }
        else if (sign == '*') {
            if (num1 * num2 == userAnswer){
                cout << "True"<<endl;
                correct+=1;
                }
            else{
                cout<<"False"<<endl;
            }
        }
        
    }
    double percentage;//make double because percentage can be exact
    percentage= (correct/questions) *100;//calculate percentage using how many questions were asnwered correct
    cout<<"percentage "<<percentage<<"%"<<endl;
    char grade;
    if (percentage >= 90){//calculate letter grade 
        grade='A';
    }
    else if(percentage>=80){
        grade='B';
    }
    else if(percentage>=70){
        grade='C';
    }
    else if(percentage>=60){
        grade='D';
    }
    else{
        grade='F';
    }

    cout<<"letter grade "<<grade<<endl;


    return 0;


}