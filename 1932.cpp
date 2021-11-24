#include <iostream>
#include <vector>

using namespace std;

int dp[501][501];


int main() {
  int n , input;
  vector<int> tri[501];
  cin >> n;
  for(int i =0 ; i< n; i++){
    for(int j = 0; j<=i; j++){
      cin >>  input;
      tri[i].push_back(input);
    }
  }
  dp[0][0] = tri[0][0];

  int left, right;
  for(int i =1 ; i< n; i++){
    for(int j = 0; j<=i; j++){
      if(j == 0){
        dp[i][j] = tri[i][j] + dp[i-1][j];
      }
      else if(j == i){
        dp[i][j] = tri[i][j] + dp[i-1][j-1];
      }
      else{
        if(dp[i-1][j-1] > dp[i-1][j]){
          dp[i][j] = tri[i][j] + dp[i-1][j-1];
        }
        else{
          dp[i][j] = tri[i][j] + dp[i-1][j];
        }
      }
    }
    
  }


  int ans = 0;
  for(int i =0; i<n; i++){
    if(ans < dp[n-1][i]){
      ans = dp[n-1][i];
    }
  }
  
  cout << ans;
  return 0;
} 