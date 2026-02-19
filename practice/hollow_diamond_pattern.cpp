// // hollow diamond triangle
// //     *
// //    * *
// //   *   *
// //  *     *
// // *       *
// //  *     *
// //   *   *
// //    * *
// //     *
#include <iostream>
using namespace std;
int main()
{

    int n = 10;

    for (int i = 0; i <= n; i++)
    {

        for (int j = n; j >= i; j--)
        {
            cout << " ";
        }
        cout << "*";
        if (i == 0)
            cout << endl;
        if (i != 0)
        {
            for (int j = 0; j < (1 + (i - 1) * 2); j++)
            {
                cout << " ";
            }
            cout << "*";
            cout << endl;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= (i + 1); j++)
        {
            cout << " ";
        }
        cout << "*";
        // n
        if (i != n - 1)
        {
            int space = 1 + ((n - 2) * 2);
            int total_space = space + (((i + 1) - 1) * (-2));
            for (int j = total_space; j > 0; j--)
            {
                cout << " ";
            }
            cout << "*";
            cout << endl;
        }
    }

    return 0;
}
