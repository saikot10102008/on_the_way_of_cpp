#include <iostream>
using namespace std;

int main()
{

    // // wnated pattern
    // //  *
    // //  * *
    // //  * * *
    // //  * * * *
    // //  for n =4

    // int n;
    // cin >> n;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < i + 1; j++)
    //     {
    //         cout << "* ";
    //     }
    //     cout << "\n";
    // }

    // // triangle number pattern
    // //  expected pattern with n=4
    // //  1
    // //  22
    // //  333
    // //  4444
    // int n;
    // cin >> n;

    // for (int i = 0; i < n;i++){

    //     for (int j = 0; j<=i;j++){//here as condition j < i+1 can also be used
    //     cout<<i+1<<" ";
    //     }
    //     cout<<"\n";
    // }

// homework problem solve:for n = 4
// A
// B B
// C C C
// D D D D
//E E E E E 

int n;
cin >> n;
char character = 'A';

for (int i = 0 ; i < n; i++){
    for(int j = 0; j<=i;j++){

        cout<<character<<" ";
    }
    character++;
    cout<<"\n";

}
    return 0;
}