#include <iostream>

int main(){

    auto testRun = [] (int a) {
      std::cout<<"Lamda function is working and passed number is "<<a<<"\n";
    };
    testRun(9);
}
