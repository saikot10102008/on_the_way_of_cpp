#include<iostream>
using namespace std;
int binToDec(int bin){ // function to convert binary to decimal
    //initialize answer and power
    int ans = 0,power = 1;
    //using while loop to iterate through each digit of binary number
    while(bin > 0){
        //cutting remainder which exactly is the last digit of binary number
        int remainder = bin%10;
        //adding positional value to answer
        ans += remainder*power;
        //updation
        bin /= 10; // updating binary number by dividing it by 10 to remove the last digit
        power*= 2;
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    cout<<"the binary number is "<<n<<"and the decimal number is "<<binToDec(n);

    return 0;
}
