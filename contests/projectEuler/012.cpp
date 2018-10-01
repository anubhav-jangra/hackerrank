#include <map>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

long long int factor(int n) {
    int count = 0; 
    long long int total = 1;
    while(n % 2 == 0) {
        count++;
        n /= 2;
    }
    total *= (count+1);
    for(long int i = 3; i <= sqrt(n); i += 2) {
        count = 0;
        while(n % i == 0) {
            count++;
            n /= i;
        }
        total *= (count+1);
    }
    if(n > 2){
		total *= 2;
    }
    
    return total;
}

int main() {
    long t;
    cin>>t;
    if(t<=10)
    {
        for(int t_i = 0; t_i < t; t_i++)
        {  
            long n;
            cin>>n;
            if(n>=1 && n<=1000)
            {
            	//code begins 
                long long num,sum,number=1;
                sum=(number * (number + 1)/2);
                num=factor(sum);
                while(num<=n){
                    number++;
                    sum=(number * (number + 1)/2);
                    num=factor(sum);                    
                }
            	cout<<sum<<endl;
			}
        }
    }
	return 0;
}
/*
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;

const int MAXN = 100*1000;
unordered_map<int,int> factors[MAXN+10];
vector<bool> isprime(MAXN+10, true);
int primeFactor[MAXN+10];

void init() {
   isprime[0] = isprime[1] = false;
   for(int i = 2; i*i <= MAXN; i++) {
     if(isprime[i]) {
       for(int j = i*i; j <= MAXN; j += i) {
          isprime[j] = false;
          primeFactor[j] = i;
       }
     }
   }
   for(int i = 2; i <= MAXN; i++) {
     if(isprime[i]) factors[i][i] = 1;
     else {
       int dv = primeFactor[i];
       factors[i] = factors[i/dv];
       factors[i][dv]++;
     }
   }
}

int main() {
   init();
   cout<<factors[1][1]<<endl;
   for(int i = 0; i <= 20; i++) {
      for(int j = 0; j < MAXN; j++) {
         if(factors[i][j] != 0)
         cout<<"factors["<<i<<"]["<<j<<"]: "<<factors[i][j]<<endl;
      }
   }
   
    int t, n;
    long long int ans;
    cin>>t;
    while(t--) {
        cin>>n;
        ans = 1;
        for(int j = 0; j < MAXN + 10; j++) {
            if(isprime[j] && factors[n][j] != 0)
                ans *= factors[n][j] + 1;
        }
        cout<<ans<<endl;
    }
    return 0;
}
*/
