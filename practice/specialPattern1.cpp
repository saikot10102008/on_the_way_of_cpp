#include <iostream>
using namespace std;
int main()
{
//question solve for n=3
//123
//456
//789
    int n;
    cin >> n;
    // int nn = 1;//here if we place this variable outside of the loop body then it won't reset and continue with older value

    // for (int i = 0; i < n; i++)
    // {

    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << nn;
    //         nn++;
    //     }
    //     cout << "\n";
    // }

//homework problem solve:
//replacing numbers with characters
char character = 'A';


for (int i = 0; i < n; i++){

    for (int j = 0; j < n; j++){
        cout<<character<<" ";
        character++;
    }
    cout<<"\n";
}

    return 0;
}