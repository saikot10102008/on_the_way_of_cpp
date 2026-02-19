#include <iostream>
using namespace std;
int main()
{
    int n;
    cin >> n;
    // //to get the result: for n=2
    //* *
    //* *
    // for (int i = 1; i <= n; i++)
    // {

    //     for (int j = 1; j <= n; j++)
    //     {
    //         cout << "* ";
    //     }
    //     cout << "\n";
    // }
    // to get the result where stars are replaced by numbers

    //
    // for (int i = 1; i <= n; i++) // outer loop
    // {

    //     for (int j = 1; j <= n; j++) // inner loop
    //     {
    //         cout << j << " ";
    //     }
    //     cout << "\n";
    // }

    //let's replace numbers by characters


    for (int i = 0 ;i < n;i++ ){
        char hh = 'A';
        for (int j = 0; j < n ;j++){
            cout<<hh<<" ";
            hh += 1;
        }
        cout<<"\n";
    }
    return 0;
}

// it is a good practice to start loop variable with value '0'