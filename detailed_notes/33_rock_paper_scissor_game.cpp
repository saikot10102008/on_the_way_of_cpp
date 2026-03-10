#include <cstdlib>
#include <iostream>
#include <string>
#include <ctime>

// rock paper scissor game
// step-1: Take Input
// step-2: Show User Input
// step-3: Generate Random Computer Choice
// step-4: Show Computer Input
// step-5: Get Result
// step-6: Show Result
char userInput();
void user_out(char out);
char computerInput();
void computer_out(char out);
void result(char user , char computer);

int main(){
    char player = userInput();
    user_out(player);
    char computer = computerInput();
    computer_out(computer);
    result(player,computer);

    return 0;
}




// step-1: Take Input

char userInput(){
    char input;
    do{
        std::cout<<"----------CHOOSE ON OF THE OPTIONS BELOW----------\n";
        std::cout<<"1.ROCK(r)\n";
        std::cout<<"2.PAPER(p)\n";
        std::cout<<"3.SCISSOR(s)\n";
        std::cin>>input;
    }while(input != 'r' && input != 'p' && input != 's' );
    return input;
}

// step-2: Show User Input

void user_out(char out){
    std::string name;
    switch (out) {
        case 'r':
            name = "ROCK";
            break;
        case 'p':
            name = "PAPER";
            break;
        case 's':
            name = "SCISSOR";
            break;
    }

    std::cout<<"User's Choice: "<<name<<"\n";
}

// step-3: Generate Random Computer Choice

char computerInput(){
    srand(time(NULL));
    int random = rand() % 3 + 1;

    switch (random) {
        case 1: return 'r';
        case 2: return 'p';
        case 3: return 's';
        default: return 'r';
    }

}

// step-4: Show Computer Input
void computer_out(char out){
    std::string name;
    switch (out) {
        case 'r':
            name = "ROCK";
            break;
        case 'p':
            name = "PAPER";
            break;
        case 's':
            name = "SCISSOR";
            break;
    }

    std::cout<<"Computer's Choice: "<<name<<"\n";
}

// step-5: Get Result
// step-6: Show Result
void result(char user , char computer){
    switch (user) {
        case 'r':
            if(computer == 'r'){std::cout<<"TIE!\n";
            }else if(computer == 'p'){std::cout<<"YOU LOSE!\n";
            }else std::cout<<"YOU WIN!\n";
            break;
        case 'p':
            if(computer == 'r'){std::cout<<"YOU WIN!\n";
            }else if(computer == 'p'){std::cout<<"TIE!\n";
            }else std::cout<<"YOU LOSE!\n";
            break;
        case 's':
            if(computer == 'r'){std::cout<<"YOU LOSE!\n";
            }else if(computer == 'p'){std::cout<<"YOU WIN!\n";
            }else std::cout<<"TIE!\n";
            break;
        default:
            std::cout<<"THIS PROGRAM IS NOT RUNNING CORRECTLY";
    }
}
