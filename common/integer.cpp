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

Integer Integer::operator +(const Integer &other)
{
    mpz_t sum;
    mpz_init(sum);
    mpz_add(sum, _value, other._value);
    return sum;
}

Integer Integer::operator -(const Integer &other)
{
    mpz_t dif;
    mpz_init(dif);
    mpz_sub(dif, _value, other._value);
    return dif;
}

Integer Integer::operator *(const Integer &other)
{
    mpz_t prod;
    mpz_init(prod);
    mpz_mul(prod, _value, other._value);
    return prod;
}

Integer Integer::operator /(const Integer &other)
{
    mpz_t q;
    mpz_init(q);
    mpz_div(q, _value, other._value);
    return q;
}

Integer Integer::operator %(const Integer &other)
{
    mpz_t mod;
    mpz_init(mod);
    mpz_mod(mod, _value, other._value);
    return mod;
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
