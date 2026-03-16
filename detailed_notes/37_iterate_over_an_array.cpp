#include<iostream>

int main(){

    double array1[] = {1,2,3,4,6.7,9.9}; // this is an array

    // let's print the array and get the total of the numbers inside the array also

    int size = sizeof(array1)/sizeof(array1[0]);
    double total = 0;

    for (int i = 0; i < size; i++ ){

        std::cout<<array1[i]<<'\n';
        total+= array1[i];

    }

    std::cout<<"TOTAL: "<<total<<'\n';

    return 0;
}