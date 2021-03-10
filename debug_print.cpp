template<typename T, typename U>
ostream& operator <<(ostream &os, const pair<T, U> &p) {
    os << "<" << p.first << ", " << p.second << ">";
    return os;
}

template<typename T>
ostream& operator <<(ostream &os, const vector<T> &v) {
    int len = v.size();
    os << "{";
    for (int i = 0; i < len; ++i) {
        if (i > 0) {
            os << ", ";
        }
        os << v[i];
    }
    os << "}";
    return os;
}

template<typename T>
ostream& operator <<(ostream &os, const stack<T> &st) {
    stack<T> copy_st = st;
    int len = st.size();
    os << "top ";
    os << "{";
    for (int i = 0; i < len; ++i) {
        if (i > 0) {
            os << ", ";
        }
        os << copy_st.top();
        copy_st.pop();
    }
    os << "}";
    cout << " bottom";
    return os;
}

// copied from codeforces user neal
void debug_out() { cerr << endl; }
template<typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << ' ' << H; debug_out(T...); }
#ifdef LOCAL
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define debug(...)
#endif
