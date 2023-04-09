template <typename T, T MOD>
class ModInt {
   public:
    T val;
    ModInt(int64_t num = 0) : val(num % MOD) { if (val < 0) val += (MOD < 0) ? -MOD : MOD; }
    template <typename U> operator U() const { return static_cast<U>(val); }
    friend ModInt pow(ModInt a, int64_t b) { ModInt res = 1; while (b) { if (b & 1) res *= a; a *= a; b >>= 1; } return res; }

    ModInt& operator+=(const ModInt& rhs) { if ((val += rhs.val) >= MOD) val -= MOD; return *this; }
    ModInt& operator-=(const ModInt& rhs) { if ((val += MOD - rhs.val) >= MOD) val -= MOD; return *this; }
    ModInt& operator*=(const ModInt& rhs) { val = ((uint64_t)val * rhs.val) % MOD; return *this; }
    ModInt& operator/=(const ModInt& rhs) { assert(rhs.val != 0); return (*this) *= pow(rhs, MOD - 2); }

    friend ModInt operator+(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) += rhs; }
    friend ModInt operator-(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) -= rhs; }
    friend ModInt operator*(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) *= rhs; }
    friend ModInt operator/(const ModInt& lhs, const ModInt& rhs) { return ModInt(lhs) /= rhs; }

    ModInt operator-() const { return ModInt(-val); }
    ModInt& operator++() { return *this += 1; }
    ModInt& operator--() { return *this -= 1; }
    ModInt operator++(int) { ModInt res(*this); *this += 1; return res; }
    ModInt operator--(int) { ModInt res(*this); *this -= 1; return res; }

    friend bool operator==(const ModInt& lhs, const ModInt& rhs) { return lhs.val == rhs.val; }
    friend bool operator!=(const ModInt& lhs, const ModInt& rhs) { return lhs.val != rhs.val; }
    friend bool operator<(const ModInt& lhs, const ModInt& rhs) { return lhs.val < rhs.val; }
    friend bool operator<=(const ModInt& lhs, const ModInt& rhs) { return lhs.val <= rhs.val; }
    friend bool operator>(const ModInt& lhs, const ModInt& rhs) { return lhs.val > rhs.val; }
    friend bool operator>=(const ModInt& lhs, const ModInt& rhs) { return lhs.val >= rhs.val; }

    friend std::ostream& operator<<(std::ostream& os, const ModInt& a) { os << a.val; return os; }
    friend std::istream& operator>>(std::istream& is, ModInt& a) { is >> a.val; return is; }
};
using mint = ModInt<int32_t, 998244353>;
