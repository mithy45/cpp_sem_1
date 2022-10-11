#include "vector.hh"

Vector::Vector(void)
{
    for (size_t size = 0; size != NDIM; ++size)
    {
        this->tab[size] = 0;
    }
}

Vector::Vector(std::initializer_list<value> elements)
{    
    std::initializer_list<value>::iterator it = elements.begin();
    for (size_t size = 0; size != NDIM; ++size, ++it)
    {
        this->tab[size] = *it;
    }
}

Vector& Vector::operator+=(const Vector& other)
{
    for (size_t size = 0; size != NDIM; ++size)
    {
        this->tab[size] += other.tab[size];
    }
    return *this;
}

Vector& Vector::operator+=(const value val)
{
    for (size_t size = 0; size != NDIM; ++size)
    {
        this->tab[size] += val;
    }
    return *this;
}

Vector Vector::operator+(const Vector& vec)
{
    Vector new_vec = Vector();
    for (size_t size = 0; size != NDIM; ++size)
    {
        new_vec.tab[size] = this->tab[size] + vec.tab[size];
    }
    return new_vec;
}


Vector& Vector::operator-=(const Vector& vec)
{
    for (size_t size = 0; size != NDIM; ++size)
    {
        this->tab[size] -= vec.tab[size];
    }
    return *this;
}

Vector& Vector::operator*=(const value val)
{
    for (size_t size = 0; size != NDIM; ++size)
    {
        this->tab[size] *= val;
    }
    return *this;
}

Vector Vector::operator*(const value val)
{
    Vector new_vec = Vector();
    for (size_t size = 0; size != NDIM; ++size)
    {
        new_vec.tab[size] = this->tab[size] * val;
    }
    return new_vec;
}

value Vector::operator*(const Vector& vec)
{
    value res = 0;
    for (size_t size = 0; size != NDIM; ++size)
    {
        res += this->tab[size] * vec.tab[size];
    }
    return res;
}

value& Vector::operator[](const size_t size)
{
    return this->tab[size];
}

value Vector::get_val(size_t size) const
{
    return this->tab[size];
}

std::ostream& operator<<(std::ostream& out, const Vector& vec)
{
    std::initializer_list<value>::iterator it;
    out << "{";
    for (size_t size = 0; size != NDIM - 1; ++size)
    {
        out << vec.get_val(size) << ",";
    }
    out << vec.get_val(NDIM - 1);
    out << "}";
    return out;
}

value operator+=(value val, const Vector& vec)
{
    value res = 0;
    for (size_t size = 0; size != NDIM; ++size)
    {
        res += vec.get_val(size);
    }
    return res;
}