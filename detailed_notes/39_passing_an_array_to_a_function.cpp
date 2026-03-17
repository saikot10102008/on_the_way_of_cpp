#include<iostream>

// Function declaration (prototype)
// double[] is allowed here because parameter names are optional in declarations
// The array parameter decays to a pointer to the first element
double getTotal(double[] , int);

int main(){
    double arr[] = {1,2,3,4,5,7.8};           // Original array in main()
    int size = sizeof(arr)/sizeof(arr[0]);     // Calculates number of elements (6)
    double total = getTotal(arr,size);         // Passing array - actually passes pointer to first element
}

double getTotal(double array[] , int size){    // double array[] is actually double* array
    std::cout<<array<<'\n';                     // Prints memory address of first element (pointer value)
    std::cout<<array[0]<<'\n';                   // Prints first element (1) - pointer arithmetic: *(array+0)
    std::cout<<sizeof(array[0])<<'\n';           // Prints size of double (typically 8 bytes)
    std::cout<<array[6]<<'\n';                   // Accessing out of bounds (index 6, but array has 6 elements: 0-5)
    std::cout<<array[7]<<'\n';                   // Accessing out of bounds (index 7)
    std::cout<<sizeof(array);                    // Prints size of pointer (typically 8 bytes), NOT array size!
    return 0;                                    // Function returns 0, but getTotal name suggests it should return total
}







// Here is the original code written by me and above is AI generated comments with my code



// #include<iostream>

// double getTotal(double[] , int);

// int main(){
//     double arr[] = {1,2,3,4,5,7.8};
//     int size = sizeof(arr)/sizeof(arr[0]);
//     double total = getTotal(arr,size);
// }

// double getTotal(double array[] , int size){
//     std::cout<<array<<'\n';
//     std::cout<<array[0]<<'\n';
//     std::cout<<sizeof(array[0])<<'\n';
//     std::cout<<array[6]<<'\n';
//     std::cout<<array[7]<<'\n';
//     std::cout<<sizeof(array);
//     return 0;
// }