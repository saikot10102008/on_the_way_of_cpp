#include<iostream>

// Array in C++ -> An array in C++ is a **collection of variables of the same data type stored in contiguous memory locations that can be accessed using an index number starting from 0**.

int main(){

    // initializing an array of double data type

    double arr[3] = {1,2,3}; // array with a size of 3 and 3 elements in it
    double arr2[4] = {1,2,3}; // array with a size of 4 but 3 elements in it, so the 4th element is a garbage value
    double arr3[] = {1,2,3,4,5,6}; // array with no pre initialized size, compiler auto calculates the size
    double arr4[10]; // array with size of 10 but no value initialized , so all the values are garbage values

    std::cout<<arr4[3]; //to access a value in a array we use array_name[index_of_the_value] but we can't print a array like a variable because it will print the address of the array
    std::cout<<"\n"<<arr4;

    return 0;
}