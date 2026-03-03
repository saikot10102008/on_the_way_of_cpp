#include <cstdlib>
#include <iostream>
#include <ctime>

int main(){

    srand(time(0)); //  time(NULL)  = time(0)  = time(nullptr)  (in modern C++)
    int random_number = ((rand() % 5) + 1);

    switch (random_number) {
        case 1:
            std::cout<<"You are a fool";
            break;
        case 2:
            std::cout<<"You are a not fool";
            break;
        case 3:
            std::cout<<"You are a big fool";
            break;
        case 4:
            std::cout<<"You are not a great fool";
            break;
        case 5:
            std::cout<<"You are nothing";
            break;
        default:
            std::cout<<"You are nobody";
            break;
    }

    return 0;
}
