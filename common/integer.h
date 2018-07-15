#include <iostream>
#include <vector>
#include <memory>
#include <gmp.h>


class Integer
{
public:
    Integer();
    Integer(unsigned int value);
    Integer(signed int value);
    Integer(unsigned long value);
    Integer(signed long value);
    Integer(double value);
    Integer(const std::string &value, int base = 10);
    Integer(const Integer &other);
    Integer(Integer &&other);
    Integer(mpz_t other);
    virtual ~Integer();

    Integer &operator =(const Integer &other);

    Integer operator -() const;
    Integer operator ~() const;

    Integer operator +(const Integer &other) const;
    Integer operator -(const Integer &other) const;
    Integer operator *(const Integer &other) const;
    Integer operator /(const Integer &other) const;
    Integer operator %(const Integer &other) const;
    Integer operator ^(const Integer &other) const;
    Integer operator &(const Integer &other) const;
    Integer operator |(const Integer &other) const;

    Integer &operator +=(const Integer &other);
    Integer &operator -=(const Integer &other);
    Integer &operator *=(const Integer &other);
    Integer &operator /=(const Integer &other);
    Integer &operator %=(const Integer &other);
    Integer &operator ^=(const Integer &other);
    Integer &operator &=(const Integer &other);
    Integer &operator |=(const Integer &other);

    Integer &operator ++();
    Integer operator ++(int);

    Integer &operator --();
    Integer operator --(int);

    bool operator ==(const Integer &other) const;
    bool operator !=(const Integer &other) const;
    bool operator <(const Integer &other) const;
    bool operator >(const Integer &other) const;
    bool operator <=(const Integer &other) const;
    bool operator >=(const Integer &other) const;

    Integer pow(unsigned long a) const;
    static Integer pow(unsigned long a, unsigned long b);

    std::string get_string() const;

    friend std::ostream &operator <<(std::ostream &os, Integer &other);
    void operator <<(std::ostream &ostr);

private:
    mpz_t _value;
};

