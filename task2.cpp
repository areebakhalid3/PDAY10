#include <iostream>
using namespace std;

int main(){

    int n;

    cout << "Enter number of directions: ";
    cin >> n;

    string dir[n];
    cout << "Enter directions(left or right), one per line :"<< endl;
    
    for(int i = 0; i < n; i++){
        cin >> dir[i];
    }

    int count=0;

    for (int j=0;j<n;j++){
        if(dir[j]=="right"){
            count +=90;
        }
        else if (dir[j]=="left"){
            count -=90;
        } 
    }
  
   if(count<0){
    count= -count;
   }

   int r=count/360;

    cout << "There will be " <<r<< " rotations. "<<endl;
    
    return 0;
}