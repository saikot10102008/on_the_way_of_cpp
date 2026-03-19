#include <iostream>
#include <string>

int main(){

    std::string arr[10];
    int size = sizeof(arr)/sizeof(arr[0]);

    for(int i = 0; i<size ; i++){
        std::string temp;

        std::cout<<"Enter a number or 'q' to quit #"<<i+1<<" :";
        std::getline(std::cin, temp);
        if(temp == "q"){
            break;
        }else{
        arr[i] = temp;
        }
    }

    for (int i = 0; !arr[i].empty();i++){
        std::cout<<arr[i]<<'\n';
    }
}
