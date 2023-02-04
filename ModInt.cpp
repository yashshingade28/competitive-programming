template<int MOD>
class ModInt {
public:
  int32_t x;
  ModInt(int64_t sig = 0) : x(sig % MOD) { if (x < 0) x += (MOD < 0) ? -MOD : MOD; }
  explicit operator int() const { return x; }
  ModInt pow(int64_t p) { ModInt res = 1, a = *this; while (p) { if (p & 1) res *= a; a *= a; p >>= 1; } return res; }

  ModInt &operator+=(const ModInt& that) { if ((x += that.x) >= MOD) x -= MOD; return *this; }
  ModInt &operator-=(const ModInt& that) { if ((x += MOD - that.x) >= MOD) x -= MOD; return *this; }
  ModInt &operator*=(const ModInt& that) { x = (uint64_t)x * that.x % MOD; return *this; }
  ModInt &operator/=(const ModInt& that) { assert(that.x != 0); return (*this) *= that.pow(MOD - 2); }

  ModInt operator+(const ModInt& that) const { return ModInt(*this) += that; }
  ModInt operator-(const ModInt& that) const { return ModInt(*this) -= that; }
  ModInt operator*(const ModInt& that) const { return ModInt(*this) *= that; }
  ModInt operator/(const ModInt& that) const { return ModInt(*this) /= that; }

  ModInt operator-() const { return ModInt(-x); }
  ModInt& operator++() { return *this += 1; }
  ModInt& operator--() { return *this -= 1; }
  bool operator==(const ModInt& o) const { return x == o.x; }
  friend bool operator!=(const ModInt& a, const ModInt& b) { return !(a == b); }

  friend std::ostream& operator<<(std::ostream &os, const ModInt& a) { os << a.x; return os; }
};
using mint = ModInt<998244353> ;
