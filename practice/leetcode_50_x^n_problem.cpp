#include<iostream>
using namespace std;
double myPow(double x, int n) {
        long bin = n;
        double ans =1;
        if (bin < 0){
            x = 1/x;
            bin = -bin; //bin = -bin; it cannot be bin = -n; because -2^31 doesn't exist in integers
            }

        while(bin > 0){
            if (bin % 2 == 1){
                ans *= x;
            }
            x *= x;
            bin /= 2;
        }
        return ans;
    }
int main(){
    double x = 2.0;
    int n = 10;
    double result = myPow(x, n);
    cout << result << endl;
    return 0;
}