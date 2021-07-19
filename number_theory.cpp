vector<int> primes;
vector<bool> is_prime;
// generate all primes <= max_val
void sieve(int max_val) {
    primes.reserve(max_val <= 10000 ? 1229 : max_val <= 100000 ? 9592 : 78498);
    is_prime.assign(max_val + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int p = 2; p <= max_val; ++p) {
        if (is_prime[p]) {
            primes.push_back(p);
            for (long long m = 1LL * p * p; m <= max_val; m += p) {
                is_prime[m] = false;
            }
        }
    }
}
constexpr auto genprimes = sieve;

// https://cp-algorithms.com/algebra/factorization.html#toc-tgt-2
// For a given prime p occuring k times in the prime factoriztion of n, the resulting
// vector will similarly contain k instances of p.
vector<long long> prime_factorize(long long n) {
    vector<long long> factorization;
    for (long long d : primes) {
        if (d * d > n)
            break;
        while (n % d == 0) {
            factorization.push_back(d);
            n /= d;
        }
    }
    if (n > 1)
        factorization.push_back(n);
    return factorization;
}

// extended euclidean algorithm
// find (x, y) such that ax + by = 1
// this version assumes that gcd(a, b) = 1
pair<int, int> ext_euclid(int a, int b) {
    #ifdef LOCAL
        assert(std::gcd(a, b) == 1);
    #endif
    if (b == 0) return {1, 0};
    int q = a / b;
    auto [xx, yy] = ext_euclid(b, a % b);
    return {yy, xx - q * yy};
}
