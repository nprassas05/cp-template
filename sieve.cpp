set<int> primes;

void sieve(int n) 
{
    bool prime[n+1]; 
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