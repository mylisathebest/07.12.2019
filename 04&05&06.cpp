#include <iostream>

using namespace std;

struct LongInt {
    long long val = 0;


    LongInt &operator+=(const LongInt &b) {
        val += b.val;
        return *this;
    }

    friend LongInt operator+(const LongInt &rhs, const LongInt &lhs) {
        LongInt ret(rhs);
        return ret += lhs;
    }

    LongInt &operator-=(const LongInt &b) {
        if (val <= b.val) {
            throw "Cannot subtract!";
        }
        val -= b.val;
        return *this;
    }

    friend LongInt operator-(const LongInt &rhs, const LongInt &lhs) {
        LongInt ret(rhs);
        return ret -= lhs;
    }

    LongInt power(int x) {
        long long base = val;
        for (int i = 1; i < x; i++) {
            val = val * base;
        }
        return *this;
    }

    //Simple constructor
    explicit LongInt(long long x = 1) {
        if (x <= 0)
            throw "Cannot create Natural number with non-positive seed";
        this->val = x;
    }


    //Copy constructor
    LongInt(const LongInt &n) {
        val = n.val;
    }

    ~LongInt() {
        val = 0;
        //nothing to destruct
    }
};

ostream &operator<<(ostream &os, const LongInt &nt) {
    return os << nt.val;
}

istream &operator>>(istream &is, LongInt &nt) {
    cout << "Enter natural\n";
    is >> nt.val;
    return is;
}

int main() {
    try {
        LongInt n1, n2;
        cin >> n1;
        cin >> n2;

        LongInt c = n1 + n2;
        cout << n1 << " + " << n2 << " = " << c << endl;
        LongInt f = n1 - n2;
        cout << n1 << " - " << n2 << " = " << f << endl;
        cout << n1<<"^3 = " << n1.power(3).val;
    } catch (const char *msg) {
        cerr << msg << endl;
    }
    return 0;
}