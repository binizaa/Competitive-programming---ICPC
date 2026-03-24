#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <set>

using namespace std;

//ICPC
long long binomial(long long n, long long k) {
	// dp[i][j] stores iCj
	vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));

	// base cases described above
	for (long long i = 0; i <= n; i++) {
		/*
		 * i choose 0 is always 1 since there is exactly one way
		 * to choose 0 elements from a set of i elements
		 * (don't choose anything)
		 */
		dp[i][0] = 1;
		/*
		 * i choose i is always 1 since there is exactly one way
		 * to choose i elements from a set of i elements
		 * (choose every element in the set)
		 */
		if (i <= k) { dp[i][i] = 1; }
	}

	for (long long i = 0; i <= n; i++) {
		for (long long j = 1; j <= min(i, k); j++) {
			if (i != j) {  // skips over the base cases
				// uses the recurrence relation above
				dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) ;
			}
		}
	}

	return dp[n][k];  // returns nCk modulo p
}

int main(){
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    long long h, m, t; cin>>h>>m>>t;

    long long result = 0;

    for(long long i = 4; i < t; i++){
        result += binomial(h,i)*binomial(m,t-i);
    }

    cout<<result<<endl;
}