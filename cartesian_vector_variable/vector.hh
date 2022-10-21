#pragma once

#include <ostream>
#include <initializer_list>
#include <cassert>
#include <memory>

#include "config.h"

class Vector
{
public:
// Constructors
    Vector(const Vector& rhs);
    Vector(size_t N);
    Vector(std::initializer_list<value> list);
    ~Vector() = default;

// Public Member functions operator
    Vector& operator=(const Vector& rhs);

    Vector& operator+=(const Vector& rhs);
    Vector& operator+=(value val);
    Vector operator+(const Vector& rhs) const;
    Vector operator+(value val) const;

    Vector& operator-=(const Vector& rhs);

    Vector& operator*=(value val);
    value operator*(const Vector& rhs) const;
    Vector operator*(value val) const;

    value& operator[](size_t idx);
    value operator[](size_t idx) const;

// Public Member functions getter
    size_t size() const;

private:
// Private Member functions here
    void check_size(const Vector& rhs) const;
    void assign_vector_value(const Vector& rhs) const;

// Member variables are ALWAYS private, and they go here
    std::unique_ptr<value[]> _tab;
    size_t _size;
    
};

// Nonmember function operators
Vector operator*(const value& val, const Vector& rhs);
Vector operator+(const value& val, const Vector& rhs);
std::ostream& operator<<(std::ostream& out, const Vector& rhs);