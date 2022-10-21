#include "vector.hh"

// Constructors
Vector::Vector(const Vector& rhs)
{
    this->_tab = std::make_unique<value[]>(rhs.size());
    this->_size = rhs.size();

    for (size_t i = 0; i != this->size(); ++i)
    {
        this->_tab[i] = rhs._tab[i];
    }
}

Vector::Vector(size_t N)
{
    this->_tab = std::make_unique<value[]>(N);
    this->_size = N;

    for (size_t i = 0; i != this->size(); ++i)
    {
        this->_tab[i] = 0;
    }
}

Vector::Vector(std::initializer_list<value> list)
{
    this->_tab = std::make_unique<value[]>(list.size());
    this->_size = list.size();

    std::initializer_list<value>::iterator it = list.begin();
    for (size_t i = 0; i != this->size() && it != list.end(); ++i, ++it)
    {
        this->_tab[i] = *it;
    }
}

// Public Member functions operator
Vector& Vector::operator=(const Vector& rhs)
{
    this->_tab = std::make_unique<value[]>(rhs.size());
    this->_size = rhs.size();

    for (size_t i = 0; i != rhs.size(); ++i)
    {
        this->_tab[i] = rhs._tab[i];
    }

    return *this;
}

Vector& Vector::operator+=(const Vector& rhs)
{
    this->check_size(rhs);

    for (size_t i = 0; i != this->size(); ++i)
    {
        this->_tab[i] += rhs._tab[i];
    }

    return *this;
}

Vector& Vector::operator+=(value val)
{
    for (size_t i = 0; i != this->size(); ++i)
    {
        this->_tab[i] += val;
    }

    return *this;
}

Vector Vector::operator+(const Vector& rhs) const
{
    this->check_size(rhs);

    Vector res = Vector(this->size());

    for (size_t i = 0; i != this->size(); ++i)
    {
        res._tab[i] = this->_tab[i] + rhs._tab[i];
    }

    return res;
}

Vector Vector::operator+(value val) const
{
    Vector res = Vector(this->size());

    for (size_t i = 0; i != this->size(); ++i)
    {
        res._tab[i] = this->_tab[i] + val;
    }

    return res;
}

Vector& Vector::operator-=(const Vector& rhs)
{
    check_size(rhs);

    for (size_t i = 0; i != this->size(); ++i)
    {
        this->_tab[i] -= rhs._tab[i];
    }

    return *this;
}

Vector& Vector::operator*=(value val)
{
    for (size_t i = 0; i != this->size(); ++i)
    {
        this->_tab[i] *= val;
    }

    return *this;
}

value Vector::operator*(const Vector& rhs) const
{
    check_size(rhs);

    value val = 0;

    for (size_t i = 0; i != this->size(); ++i)
    {
        val += this->_tab[i] * rhs._tab[i];
    }

    return val;
}

Vector Vector::operator*(value val) const
{
    Vector res = Vector(this->size());

    for (size_t i = 0; i != this->size(); ++i)
    {
        res._tab[i] += this->_tab[i] * val;
    }

    return res;
}

value& Vector::operator[](size_t idx)
{
    if (idx >= this->size())
        throw std::runtime_error("Out of size");
    return this->_tab[idx];
}

value Vector::operator[](size_t idx) const
{
    if (idx >= this->size())
        throw std::runtime_error("Out of size");
    return this->_tab[idx];
}

// Public Member functions getter
size_t Vector::size() const
{
    return this->_size;
}

// Private Member functions here
void Vector::check_size(const Vector& rhs) const
{
    if (this->size() != rhs.size())
        throw std::runtime_error("Incompatible size");
}

void Vector::assign_vector_value(const Vector& rhs) const
{
    for (size_t i = 0; i != rhs.size(); ++i)
    {
        this->_tab[i] = rhs._tab[i];
    }
}

// Nonmember function operators
Vector operator*(const value& val, const Vector& rhs)
{
    return rhs * val;
}

Vector operator+(const value& val, const Vector& rhs)
{
    return rhs + val;
}

std::ostream& operator<<(std::ostream& out, const Vector& rhs)
{
    out << "{";
    for (size_t i = 0; i != rhs.size() - 1; ++i)
    {
        out << rhs[i] << ",";
    }
    out << rhs[rhs.size() - 1] << "}";

    return out;
}
