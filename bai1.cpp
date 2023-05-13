#include<bits/stdc++.h>
using namespace std;


long long pickUpSticks(int n){
    vector<long long>dp(n+1,0);
    dp[0] = 1;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=3 && i>=j;j++){
            dp[i]+=dp[i-j];
        }
    }
    return dp[n];
}
int main(){
    cout<<pickUpSticks(2);
}

