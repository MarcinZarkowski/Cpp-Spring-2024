#include <iostream>
using namespace std;
int main(){
    int pos=0;
    cout<<"Enter int";
    float total=0;
    float input;
    while(cin>>input ){
        total++;
        if (input>0){
            pos++;
        }
    }
    float percent= pos/total;
    cout<<"Entered"<<pos<<"positive integers"<<endl;
    cout<<"percentage: "<<percent<<endl;

}
