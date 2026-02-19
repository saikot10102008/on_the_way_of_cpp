#include<iostream>
using namespace std;

int main () {
// first way
    char x;
    // char y;
    // char z;
    cout<<"give the first character: ";
    cin>>x;
    // cout<<"\ngive the second character: ";
    // cin>>y;
    // cout<<"\ngive the third character: ";
    // cin>>z;

    if (x >= 'a' && x <= 'z'){
        cout<<"this is a lowercase character";
    } else if (x >= 'A' && x <= 'Z') {
        cout<<"this is an uppercase character";
    }
    // first way ended
    // second way to solve this proble is using ASCII code 

    if (x >= 65 && x <= 90){
        cout<<"\nthis is an uppercase character";
    } else {
        cout<<"\nit is a lowercase character."; //here we can use (else if) if we wanted to make the result more precise by comparing ASCII code with character one more time.On that ASCII code of A is 65 and B is 66 and a is 97 and b is 98 
    }
    // sceond way ended
    }