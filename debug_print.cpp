template<typename T>
ostream& operator <<(ostream &os, const pair<T, T> &p) {
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

#ifdef LOCAL
#define debug(...) cout << "[" << #__VA_ARGS__ << "]:" << (__VA_ARGS__) << '\n'
#else
#define debug(...)
#endif