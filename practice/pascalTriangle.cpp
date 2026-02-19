#include <iostream>
using namespace std;
int fact(int a){
    int ans = 1;
    for (int i = 0; i < a; i++){
        ans *= i+1;
    }
    return ans;
}
int ncr(int n, int r){
    return fact(n)/((fact(n-r))*fact(r));
}
int main () {



// pascal triangle printing
// 1
// 1 1
// 1 2 1
// 1 3 3 1
// 1 4 6 4 1
// 1 5 10 10 5 1
    int n;
    cin>>n;
for (int i = 0; i < n+1; i++){

    // for spaces
    for (int j = 0; j < n-i; j++){
        cout<<" ";
    }

    // for numbers
    for (int j = 0; j < i+1; j++){
        cout<<ncr(i,j)<<" ";
    }
    cout<<endl;

}




    return 0;
}
