#include <iostream>
using namespace std;
int main(){
    int s=0;
    int t;
    for (int i= 1; i<19;i++){
        t=0;
        for (int j=i+2;j<21;j++){
            t=t+1;
            s=s+1;
        }
        cout<<t<<endl;

    }
    cout<<s<<endl;
}