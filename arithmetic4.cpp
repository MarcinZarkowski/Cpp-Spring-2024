//Marcin Zarkowski
//csci135
//this program asks questions from csv file randomly and tells user o answer, it stops when the user answer 60% of the questions in the csv file correctly. 

#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;



int main(){
    fstream file("problems.csv");//open csv file
    if (file.fail()){
        cerr<<"failed";
        exit(1);
    }
    string question[INT16_MAX];
    string answer[INT16_MAX];
    string txt,ans;
    

    int counter=0;
    while(getline(file, txt, ',') && getline(file, ans)){//go through file and collect data in two arrays.
        question[counter]=txt;
        answer[counter]=ans;
        counter++;
    }
    string useranswer;
    int random=0;
    
    float correct=0;
    int size=counter;
   

    while(((correct/counter)*100 < 60)){
        if (size==0){
            break;
        }
        random=rand()%(counter-(counter-size));
        
        cout<<"What is "<<question[random]<<"? ";
        cin>>useranswer;
        
        if(stof(useranswer)==stof(answer[random])){
            correct++;
            cout<<"Correct"<<endl;
        }
        else{
            cout<<"False"<<endl;
        }

        if (size==0){
            break;
        }

        size--;
        swap(question[random], question[size]);
        swap(answer[random], answer[size]);
        

        
    }
    if ((float)correct == 0 || (float)counter == 0) {
    cout << "percentage correct: 0%" << endl;
    } else {
    cout << "percentage correct: " << ((float)correct / counter) * 100 << "%" << endl;
}

}