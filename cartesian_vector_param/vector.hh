#pragma once

#include <ostream>
#include <initializer_list>
#include <cassert>

#include "config.h"

class Vector
{
public:
// DO NOT CHANGE THIS
    Vector(const Vector&) = default;
    Vector& operator=(const Vector&) = default;
    ~Vector() = default;
//

// Add suitable constructors
    Vector();
    Vector(std::initializer_list<value> list);
    // possibly more

// Public Member functions here
    Vector& operator+=(const Vector& vec);
    Vector& operator+=(const value val);
    Vector operator+(const Vector& vec);

    Vector& operator-=(const Vector& vec);

    Vector& operator*=(const value val);
    Vector operator*(const value val);
    value operator*(const Vector& vec);

    value& operator[](const size_t size);
    // More to go
    value get_val(size_t size) const;

private:
// Private Member functions here (if necessary)

// Member variables are ALWAYS private, and they go here
    value tab[NDIM];

};

// Nonmember function operators go here
std::ostream& operator<<(std::ostream& out, const Vector& vec);
value operator+=(value val, const Vector& vec);
