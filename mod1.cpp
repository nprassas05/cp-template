#include <bits/stdc++.h>
using namespace std;

namespace mod_defaults {
    const int mod = (int) 1e9 + 7;
}

template<typename T>
T bin_pow(T a, T p, T mod = mod_defaults::mod) {
    T res = 1;
    while (p) {
        if (p % 2 == 0) {
            a = (1LL * a * a) % mod;
            p /= 2;
        } else {
            res = (1LL * res * a) % mod;
            p--;
        }
    }
    return res;
}

template<typename T>
T mod_inv(T a, T mod = mod_defaults::mod) {
    return bin_pow(a, mod - 2, mod);
}

template<typename T>
T mod_add(T a, T b, T mod = mod_defaults::mod) {
    return (a + b) % mod;
}

template<typename T>
T mod_subtract(T a, T b, T mod = mod_defaults::mod) {
    return (a - b + mod) % mod;
}

template<typename T>
T mod_mul(T a, T b, T mod = mod_defaults::mod) {
    return (1LL * a * b) % mod;
}

template<typename T>
T fact(T x) {
    T res = 1;
    while (x > 1) {
        res = mod_mul(res, x);
        --x;
    }
    return res;
}

template<typename T>
T nChooseR(T n, T r) {
    assert(n >= r);
    T res = mod_mul(fact(n), mod_mul(mod_inv(fact(r)), mod_inv(fact(n - r))));
    return res;
}

int main() {
    cout << bin_pow(3, 5) << endl;
    cout << mod_inv(358) << endl;
    cout << "805 times " << mod_inv(805) << " (mod) = " << mod_mul(805, mod_inv(805)) << endl;
    cout << mod_subtract(4, 5, 7) << endl;
    return 0;
}