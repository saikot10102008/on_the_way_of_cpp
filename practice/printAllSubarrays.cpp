#include <iostream>
// #include <vector>
using namespace std;
int main(){
    int arr[5] = {1,2,3,4,5};
    int size = 5;
    for (int start = 0; start < size; start++){
        for(int end = start; end < size;end++){
            for (int i = start ; i <=end;i++){
                cout<<arr[i];
            }
            cout<<" ";
        }
        cout<<endl;
    }

    return 0;
}
