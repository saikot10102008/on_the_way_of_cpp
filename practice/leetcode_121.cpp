#include <iostream>
#include <vector>
using namespace std;
 int maxProfit(vector<int>& prices) {
        int maxprofit = 0;
        int bestbuy = prices[0];
        for (int i =1 ; i < prices.size(); i++){
            // best buying price calculation
            bestbuy = min(bestbuy,prices[i]);
            //best profit calculation if current price is higher
            // than best buying price
            if (prices[i]>bestbuy){
                maxprofit = max(maxprofit, prices[i] - bestbuy);
            }
        }
        return maxprofit;
    }
int main(){
    vector<int> vec = {1,2,3,4,5,6,7};
    int ans = maxProfit(vec);
    cout<<ans;
    return 0;
}
