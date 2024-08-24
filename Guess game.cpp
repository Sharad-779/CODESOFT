#include <iostream>
using namespace std;
int main() {
    srand(time(0));
    int range;
    cin>>range;
    int num=rand()%range;
    int i=1;
    while(i>0){
        cout<<"Guess the Number"<<" ";
        int guess;
        cin>>guess;
        if(num==guess){
            cout<<"correct number";
            break;
        }else if(guess>num){
            cout<<"Too High"<<endl;
        }
        else{
            cout<<"Too Low"<<endl;
        }
        i++;
    }
    return 0;
}
