template <typename T, T MOD>
class ModInt {
   public:
    T x;
    ModInt(int64_t sig = 0) : x(sig % MOD) { if (x < 0) x += (MOD < 0) ? -MOD : MOD; }
    template <typename U> operator U() const { return static_cast<U>(x); }
    friend ModInt pow(ModInt a, T b) { ModInt res = 1; while (b) { if (b & 1) res *= a; a *= a; b >>= 1; } return res; }

    ModInt& operator+=(const ModInt& rhs) { if ((x += rhs.x) >= MOD) x -= MOD; return *this; }
    ModInt& operator-=(const ModInt& rhs) { if ((x += MOD - rhs.x) >= MOD) x -= MOD; return *this; }
    ModInt& operator*=(const ModInt& rhs) { x = ((uint64_t)x * rhs.x) % MOD; return *this; }
    ModInt& operator/=(const ModInt& rhs) { assert(rhs.x != 0); return (*this) *= pow(rhs, MOD - 2); }

    friend ModInt operator+(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) += rhs; }
    friend ModInt operator-(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) -= rhs; }
    friend ModInt operator*(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) *= rhs; }
    friend ModInt operator/(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) /= rhs; }

    ModInt operator-() const { return ModInt(-x); }
    ModInt& operator++() { return *this += 1; }
    ModInt& operator--() { return *this -= 1; }
    ModInt operator++(int) { ModInt res(*this); *this += 1; return res; }
    ModInt operator--(int) { ModInt res(*this); *this -= 1; return res; }

    friend bool operator==(const ModInt& lhs, const ModInt& rhs) { return lhs.x == rhs.x; }
    friend bool operator!=(const ModInt& lhs, const ModInt& rhs) { return lhs.x != rhs.x; }
    friend bool operator<(const ModInt& lhs, const ModInt& rhs) { return lhs.x < rhs.x; }
    friend bool operator<=(const ModInt& lhs, const ModInt& rhs) { return lhs.x <= rhs.x; }
    friend bool operator>(const ModInt& lhs, const ModInt& rhs) { return lhs.x > rhs.x; }
    friend bool operator>=(const ModInt& lhs, const ModInt& rhs) { return lhs.x >= rhs.x; }

    friend std::ostream& operator<<(std::ostream& os, const ModInt& a) { os << a.x; return os; }
    friend std::istream& operator>>(std::istream& is, ModInt& a) { is >> a.x; return is; }
};
using mint = ModInt<int32_t, 998244353>;
