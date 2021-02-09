#include <bits/stdc++.h>
using namespace std;

void sieve_old(const int n) 
{
    set<int> primes;
    const int max_n = 30303;
    bool prime[max_n]; 
    memset(prime, true, sizeof(prime)); 
  
    for (int p=2; p*p<=n; p++) 
    { 
        // If prime[p] is not changed, then it is a prime 
        if (prime[p] == true) 
        {
			primes.insert(p);
            for (int i=p*p; i<=n; i += p) 
                prime[i] = false; 
        }
    }
    
    //~ for (int p=2; p<=n; p++) 
       //~ if (prime[p]) 
          //~ cout << p << endl;
}

const int N = 30303;
void sieve() {
    vector<int> primes;
    primes.reserve(N);
    vector<bool> isPrime(N);
    for (int i = 2; i < N; i++)
            isPrime[i] = 1;
    for (int x = 2; x < N; x++) {
        if (!isPrime[x]) continue;
        primes.push_back(x);
        for (int y = 2 * x; y < N; y += x)
            isPrime[y] = 0;
    }
}

int main() {
    return 0;
}