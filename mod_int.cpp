template<int Mod>
struct mint {
    int val;

    mint(int64_t v = 0) {
        if (v < 0) v = v % Mod + Mod;
        if (v >= Mod) v %= Mod;
        val = int(v);
    }

    mint pow(int64_t);

    mint& operator +=(const mint &other) {
        if ((val += other.val) >= Mod) val -= Mod;
        return *this;
    }

    mint& operator -=(const mint &other) {
        if ((val -= other.val < 0)) val += Mod;
        return *this;
    }

    mint& operator +=(int x) {
        return *this += mint(x);
    }

    mint& operator -=(int x) {
        return *this -= mint(x);
    }

    mint& operator++() { return *this += 1; }
    mint& operator--() { return *this -= 1; }
    mint operator++(int) { mint temp = *this; ++*this; return temp; }
    mint operator--(int) { mint temp = *this; --*this;; return temp; }

    static unsigned fast_mod(uint64_t x, unsigned m = Mod) {
        #if !defined(_WIN32) || defined(_WIN64)
                return unsigned(x % m);
        #endif
        // copied from another codeforces user
        // Optimized mod for Codeforces 32-bit machines.
        // x must be less than 2^32 * m for this to work, so that x / m fits in an unsigned 32-bit int.
        unsigned x_high = unsigned(x >> 32), x_low = unsigned(x);
        unsigned quot, rem;
        asm("divl %4\n"
            : "=a" (quot), "=d" (rem)
            : "d" (x_high), "a" (x_low), "r" (m));
        return rem;
    }

    mint& operator*=(const mint &other) {
        val = fast_mod(uint64_t(val) * other.val);
        return *this;
    }

    mint& operator/=(const mint &other) {
        return *this *= other.inv();
    }

    friend mint operator+(const mint &lhs, const mint &rhs) { return mint(lhs) += rhs; }
    friend mint operator-(const mint &lhs, const mint &rhs) { return mint(lhs) -= rhs; }
    friend mint operator*(const mint &lhs, const mint &rhs) { return mint(lhs) *= rhs; }
    friend mint operator/(const mint &lhs, const mint &rhs) { return mint(lhs) /= rhs; }

    friend bool operator==(const mint &lhs, const mint &rhs) { return lhs.val == rhs.val; }
    friend bool operator!=(const mint &lhs, const mint &rhs) { return lhs.val != rhs.val; }
    friend bool operator<(const mint &lhs, const mint &rhs) { return lhs.val < rhs.val; }
    friend bool operator>(const mint &lhs, const mint &rhs) { return lhs.val > rhs.val; }
    friend bool operator<=(const mint &lhs, const mint &rhs) { return lhs.val <= rhs.val; }
    friend bool operator>=(const mint &lhs, const mint &rhs) { return lhs.val >= rhs.val; }

    mint inv() {
        return this.pow(Mod - 2);
    }

    mint pow(int64_t p) const {
        if (p < 0) {
            return inv().pow(-p);
        }
        mint a = *this;
        mint res = 1;
        while (p) {
            if (p & 1 == 0) {
                a *= a;
                p /= 2;
            } else {
                res *= a;
                --p;
            }
        }
        return res;
    }

    friend ostream& operator<<(ostream &os, const mint &m) {
        return os << m.val;
    }
};

template <int M, typename U> bool operator==(const mint<M>& lhs, U rhs) { return lhs == mint<M>(rhs); }
template <int M, typename U> bool operator==(U lhs, const mint<M>& rhs) { return mint<M>(lhs) == rhs; }

template <int M, typename U> bool operator!=(const mint<M>& lhs, U rhs) { return !(lhs == rhs); }
template <int M, typename U> bool operator!=(U lhs, const mint<M>& rhs) { return !(lhs == rhs); }

template <int M, typename U> mint<M> operator+(const mint<M>& lhs, U rhs) { return mint<M>(lhs) += rhs; }
template <int M, typename U> mint<M> operator+(U lhs, const mint<M>& rhs) { return mint<M>(lhs) += rhs; }

template <int M, typename U> mint<M> operator-(const mint<M>& lhs, U rhs) { return mint<M>(lhs) -= rhs; }
template <int M, typename U> mint<M> operator-(U lhs, const mint<M>& rhs) { return mint<M>(lhs) -= rhs; }

template <int M, typename U> mint<M> operator*(const mint<M>& lhs, U rhs) { return mint<M>(lhs) *= rhs; }
template <int M, typename U> mint<M> operator*(U lhs, const mint<M>& rhs) { return mint<M>(lhs) *= rhs; }

template <int M, typename U> mint<M> operator/(const mint<M>& lhs, U rhs) { return mint<M>(lhs) /= rhs; }
template <int M, typename U> mint<M> operator/(U lhs, const mint<M>& rhs) { return mint<M>(lhs) /= rhs; }

const int mod = 9901;
using Mint = mint<mod>;
