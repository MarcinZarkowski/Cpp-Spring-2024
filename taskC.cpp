//Marcin Zarkowski
//csci135
//this asks questions from a csv file and compares answers of user to the ones in file
//then it gives percentage correct adn letter grade

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    string txt, ans;
    double reply;
    double correct = 0;
    double total = 0;
    double percent;

    fstream fin("problems.csv");//open file
    if (fin.fail()) {
        cerr << "failed" << endl;
        exit(1);
    }


    while (getline(fin, txt, ',')&&getline(fin,ans)){//read file and display question from file
        cout << txt << "? ";
        cin >> reply;

        // Convert the answer to a float before comparing
        if (stof(ans) == reply) {
            correct++;
            cout << "true" << endl;
        } 
        else {
            cout << "false" << endl;
        }
        total++;
    }
    fin.close();

    percent = (correct / total) * 100;
    char grade;
    if (percent >= 90) { // calculate letter grade
        grade = 'A';
    } else if (percent >= 80) {
        grade = 'B';
    } else if (percent >= 70) {
        grade = 'C';
    } else if (percent >= 60) {
        grade = 'D';
    } else {
        grade = 'F';
    }
    cout << "percent correct: " << percent << "%" << endl;
    cout << "letter grade: " << grade;
}