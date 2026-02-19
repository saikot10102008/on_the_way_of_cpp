#include<iostream>
#include<cmath>
int main(){

    double x = 3;
    double y = 4;
    double z;
    double k;


    // first is max function which gives us the greater value out of two
    z = std::max(x, y);

    // min function gives the value which is lower of given two
    k = std::min(x, y);

    std::cout<<"max: "<<z<<" "<<"min: "<<k<<"\n";

    // rest of the function is found on cmath header file

    // pow(x,y) function = x^y
    z = pow(2, 3);
    // sqrt(x) = square root of x
    k = sqrt(9);
    // abs(x) = absolute value of x

    std::cout<<"absolute value: "<<abs(-90)<<" "<<"2^3: "<<z<<" "<<"square root of 9: "<<k<<"\n";

    // round(x) = round function -> rounds
    std::cout<<round(9.5)<<" "<<round(9.8)<<" "<<round(9.1)<<"\n";
    // ceil(x) = ceiling function -> rounds up -> means every number greater than 3 and less than 4 is 4
    std::cout<<ceil(9.5)<<" "<<ceil(9.8)<<" "<<ceil(9.1)<<"\n";
    // floor(x) = floor function which rounds down the number -> means every number less than 4 but greater than 3 is still 3
    std::cout<<floor(9.5)<<" "<<floor(9.8)<<" "<<floor(9.1)<<"\n";


    // for reference: https://cplusplus.com/reference/cmath/
    
    return 0;
}