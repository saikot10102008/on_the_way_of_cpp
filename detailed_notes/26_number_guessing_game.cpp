#include <cstddef>
#include <cstdlib>
#include <iostream>
#include <ctime>

int main(){
    srand(time(NULL));

    int guess , tri , num;
    num = (rand()%100)+1;
    tri = 0;

    do{
        std::cout<<"\nGuess a number between 1-100: ";
        std::cin>>guess;
        if(guess==num){
            std::cout<<"CORRECT!";
        }else if (guess<num) {
            std::cout<<"TOO LOW!";
        }else {
            std::cout<<"TOO HIGH!";
        }
        tri++;
    }while(guess!=num);

    return 0;
}
