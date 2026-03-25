#include <iostream>
#include <string>

// a struct can be passed to a function as we pass a variable
// structs are pass by reference

struct personal_details{

    std::string name;
    double age;
    bool alive;

};

void print(personal_details x);
void aged(personal_details& x);

int main(){
    personal_details Saikot;
    Saikot.name = "Sakhwat Hossain Saikot";
    Saikot.age = 18.4;
    Saikot.alive = true;

    aged(Saikot);
    print(Saikot);

}

void print(personal_details x){
    std::cout<<x.name<<'\n';
    std::cout<<x.age<<'\n';
    std::cout<<x.alive<<'\n';
}

void aged(personal_details& x){
    x.age += 1;
}
