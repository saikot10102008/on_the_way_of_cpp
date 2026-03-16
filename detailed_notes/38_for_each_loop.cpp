#include<iostream>

int main(){

    // print an array with for each loop 

    double array1[] = {1,2,3,4,5,6.7,8.9};

    // this is a for each loop
    for(double x: array1){  // here array1 is the array that we will traverse and x is the variable which will carry the value of each index of the array each time
        std::cout<<x<<'\n';
    }

    return 0;

}

// short answer on what is for each loop

// A for-each loop (range-based for loop) in C++ provides a simplified syntax to 
// iterate through each element in a container (like arrays or vectors) without using 
// an index or iterator. It automatically handles the iteration from the first to 
// the last element, making code cleaner and less error-prone. The syntax is 
// `for (type variableName : container) { /* code */ }`, where `variableName` takes 
// the value of each element in the container.