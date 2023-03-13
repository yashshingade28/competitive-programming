template<typename T, T MOD>
class ModInt {
public:
    T x;
    ModInt(int64_t sig = 0) : x(sig % MOD) { if (x < 0) x += (MOD < 0) ? -MOD : MOD; }
    template <typename U> operator U() const { return static_cast<U>(x); }
    ModInt pow(int64_t p) const { ModInt res = 1, a = *this; while (p) { if (p & 1) res *= a; a *= a; p >>= 1; } return res; }

    ModInt& operator+=(const ModInt& rhs) { if ((x += rhs.x) >= MOD) x -= MOD; return *this; }
    ModInt& operator-=(const ModInt& rhs) { if ((x += MOD - rhs.x) >= MOD) x -= MOD; return *this; }
    ModInt& operator*=(const ModInt& rhs) { x = ((uint64_t)x * rhs.x) % MOD; return *this; }
    ModInt& operator/=(const ModInt& rhs) { assert(rhs.x != 0); return (*this) *= rhs.pow(MOD - 2); }

    friend ModInt operator+(const ModInt& a, const ModInt& b) { return ModInt(a) += b; }
    friend ModInt operator-(const ModInt& a, const ModInt& b) { return ModInt(a) -= b; }
    friend ModInt operator*(const ModInt& a, const ModInt& b) { return ModInt(a) *= b; }
    friend ModInt operator/(const ModInt& a, const ModInt& b) { return ModInt(a) /= b; }

    ModInt operator-() const { return ModInt(-x); }
    ModInt& operator++() { return *this += 1; }
    ModInt& operator--() { return *this -= 1; }
    ModInt operator++(int32_t) { ModInt res(*this); *this += 1; return res; }
    ModInt operator--(int32_t) { ModInt res(*this); *this -= 1; return res; }

    friend bool operator==(const ModInt& a, const ModInt& b) { return a.x == b.x; }
    friend bool operator!=(const ModInt& a, const ModInt& b) { return a.x != b.x; }
    friend bool operator<(const ModInt& a, const ModInt& b) { return a.x < b.x; }
    friend bool operator<=(const ModInt& a, const ModInt& b) { return a.x <= b.x; }
    friend bool operator>(const ModInt& a, const ModInt& b) { return a.x > b.x; }
    friend bool operator>=(const ModInt& a, const ModInt& b) { return a.x >= b.x; }

    friend std::ostream& operator<<(std::ostream& os, const ModInt& a) { os << a.x; return os; }
    friend std::istream& operator>>(std::istream& is, ModInt& a) { is >> a.x; return is; }
};
using mint = ModInt<int32_t, 998244353> ;
