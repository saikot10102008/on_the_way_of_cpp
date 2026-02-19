#include <iostream>
using namespace std;
long long flowerGame(int n, int m) {

        long long odd_n = (n+1)/2;
        long long odd_m = (m+1)/2;
        long long even_n = n/2;
        long long even_m = m/2;
        long long ans_1 = odd_n * even_m;
        long long ans_2 = odd_m * even_n;
        long long ans = ans_1 + ans_2;
        return ans;
    }
int main(){
    int n=2 , m = 4;
    cout<<flowerGame(n,m)<<endl;
}
