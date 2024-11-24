#include <iostream>
using namespace std;

void sort(int arr[], int size);

int main(){
    int size, i;

    cout << "How many numbers do you want to enter: ";
    cin >> size;

    int arr[size];

    cout<< "Enter numbers, one per line: "<<endl;
    for(i = 0; i <size; i++){
        cin >> arr[i];
    }
    
    sort(arr, size);

    bool isValid = true;
    for(i = 1; i <size; i++){
        if(arr[i]==arr[i - 1]){
            cout << arr[i] << " appears more than once" << endl;
            isValid = false;
            break;
        }
        if(arr[i]-arr[i - 1]!= 1){
            isValid = false;
        }
    }

    if(isValid){
        cout << "The array can be rearranged to form a consecutive list."<<endl;
    }
    else{
        cout << "The array cannot be rearranged to form a consecutive list."<<endl;
    }
    return 0;
}

void sort(int arr[], int size){

    for(int i = 0; i<size-1; i++){
        for(int j = 0; j<size-i-1; j++){
            if(arr[j] > arr[j + 1]){
                int temp=arr[j];
                arr[j]=arr[j + 1];
                arr[j + 1] = temp;
               }
            }
        }
    }