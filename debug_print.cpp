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
