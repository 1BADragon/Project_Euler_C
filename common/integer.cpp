#include <integer.h>

Integer::Integer()
{
    mpz_init(_value);
}

Integer::Integer(unsigned int value)
{
    mpz_init_set_ui(_value, value);
}

Integer::Integer(signed int value)
{
    mpz_init_set_si(_value, value);
}

Integer::Integer(unsigned long value)
{
    mpz_init_set_ui(_value, value);
}

Integer::Integer(signed long value)
{
    mpz_init_set_si(_value, value);
}

Integer::Integer(double value)
{
    mpz_init_set_d(_value, value);
}

Integer::Integer(const std::string &value, int base)
{
    mpz_init_set_str(_value, value.c_str(), base);
}

Integer::Integer(const Integer &other)
{
    mpz_init_set(_value, other._value);
}

Integer::Integer(Integer &&other)
{
    mpz_init_set(_value, other._value);
    mpz_set_ui(other._value, 0);
}

Integer::Integer(mpz_t other)
{
    mpz_swap(_value, other);
}

Integer::~Integer()
{
    mpz_clear(_value);
}

Integer &Integer::operator =(const Integer &other)
{
    mpz_set(_value, other._value);
    return *this;
}

Integer Integer::operator -() const
{
    mpz_t neg;
    mpz_init(neg);
    mpz_neg(neg, _value);
    return neg;
}

Integer Integer::operator ~() const
{
    mpz_t not_ret;
    mpz_init(not_ret);
    mpz_com(not_ret, _value);
    return not_ret;
}

Integer Integer::operator +(const Integer &other) const
{
    mpz_t sum;
    mpz_init(sum);
    mpz_add(sum, _value, other._value);
    return sum;
}

Integer Integer::operator -(const Integer &other) const
{
    mpz_t dif;
    mpz_init(dif);
    mpz_sub(dif, _value, other._value);
    return dif;
}

Integer Integer::operator *(const Integer &other) const
{
    mpz_t prod;
    mpz_init(prod);
    mpz_mul(prod, _value, other._value);
    return prod;
}

Integer Integer::operator /(const Integer &other) const
{
    mpz_t q;
    mpz_init(q);
    mpz_div(q, _value, other._value);
    return q;
}

Integer Integer::operator %(const Integer &other) const
{
    mpz_t mod;
    mpz_init(mod);
    mpz_mod(mod, _value, other._value);
    return mod;
}

Integer Integer::operator ^(const Integer &other) const
{
    mpz_t xor_ret;
    mpz_init(xor_ret);
    mpz_xor(xor_ret, _value, other._value);
    return xor_ret;
}

Integer Integer::operator &(const Integer &other) const
{
    mpz_t and_ret;
    mpz_init(and_ret);
    mpz_and(and_ret, _value, other._value);
    return and_ret;
}

Integer Integer::operator |(const Integer &other) const
{
    mpz_t or_ret;
    mpz_init(or_ret);
    mpz_ior(or_ret, _value, other._value);
    return or_ret;
}

Integer &Integer::operator +=(const Integer &other)
{
    mpz_add(_value, _value, other._value);
    return *this;
}

Integer &Integer::operator -=(const Integer &other)
{
    mpz_sub(_value, _value, other._value);
    return *this;
}

Integer &Integer::operator *=(const Integer &other)
{
    mpz_mul(_value, _value, other._value);
    return *this;
}

Integer &Integer::operator /=(const Integer &other)
{
    mpz_div(_value, _value, other._value);
    return *this;
}

Integer &Integer::operator %=(const Integer &other)
{
    mpz_mod(_value, _value, other._value);
    return *this;
}

Integer &Integer::operator ^=(const Integer &other)
{
    mpz_xor(_value, _value, other._value);
    return *this;
}

Integer &Integer::operator &=(const Integer &other)
{
    mpz_and(_value, _value, other._value);
    return *this;
}

Integer &Integer::operator |=(const Integer &other)
{
    mpz_ior(_value, _value, other._value);
    return *this;
}

Integer &Integer::operator ++()
{
    mpz_add_ui(_value, _value, 1);
    return *this;
}

Integer Integer::operator ++(int)
{
    return ++(*this);
}

Integer &Integer::operator --()
{
    mpz_sub_ui(_value, _value, 1);
    return *this;
}

Integer Integer::operator --(int)
{
    return --(*this);
}

bool Integer::operator ==(const Integer &other) const
{
    return mpz_cmp(_value, other._value) == 0;
}

bool Integer::operator !=(const Integer &other) const
{
    return mpz_cmp(_value, other._value) != 0;
}

bool Integer::operator <(const Integer &other) const
{
    return mpz_cmp(_value, other._value) < 0;
}

bool Integer::operator >(const Integer &other) const
{
    return mpz_cmp(_value, other._value) > 0;
}

bool Integer::operator <=(const Integer &other) const
{
    return mpz_cmp(_value, other._value) <= 0;
}

bool Integer::operator >=(const Integer &other) const
{
    return mpz_cmp(_value, other._value) >= 0;
}

Integer Integer::pow(unsigned long a) const
{
    mpz_t ret;
    mpz_init(ret);
    mpz_pow_ui(ret, this->_value, a);
    return ret;
}

Integer Integer::pow(unsigned long a, unsigned long b)
{
    mpz_t ret;
    mpz_init(ret);
    mpz_ui_pow_ui(ret, a, b);
    return ret;
}

std::string Integer::get_string() const
{
    std::size_t digit_count = mpz_sizeinbase(_value, 10) + 1;
    std::vector<char> digits;
    digits.reserve(digit_count);

    gmp_snprintf(digits.data(), digit_count, "%Zd", _value);

    return std::string(digits.data());
}

std::ostream &operator <<(std::ostream &os, Integer &other)
{
    os << other.get_string();

    return os;
}

void Integer::operator <<(std::ostream &ostr)
{
    ostr << get_string();
}
