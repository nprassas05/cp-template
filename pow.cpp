template<typename T>
ll pow(T n, int k, int mod = 0) {
    ll r = 1;
    while (k > 0) {
        if (k & 1) {
            r *= n;
            if (mod) {
                r %= mod;
            }
        }
        n *= n;
        if (mod) {
            n %= mod;
        }
        k >>= 1;
    }
    return r;
}
