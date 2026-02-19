#include <iostream>
using namespace std;
int main(){
    int array[20];
    int size_of_array = sizeof(array)/sizeof(array[0]);
    for (int i = 0; i < size_of_array;i++){
        cout<<"Enter element "<<i+1<<": ";
        cin>>array[i];}
    int smallest = INT_MAX,largest = INT_MIN;
    for (int i =0;i < size_of_array;i++){
        smallest = min(array[i],smallest);
        largest = max(array[i],largest);
    }
    cout<<"Smallest element is "<<smallest<<endl;
    cout<<"Largest element is "<<largest<<endl;
    for (int i = 0; i < size_of_array; i++){
        if (array[i] == smallest)
            cout<<"Element "<<i+1<<" is the smallest element."<<endl;
        if (array[i] == largest)
            cout<<"Element "<<i+1<<" is the largest element."<<endl;    }

}
