#include <math.h>

#ifndef _VEC3_H_
#define _VEC3_H_

struct vec3
{
    float x;
    float y;
    float z;
} __attribute__((__aligned__(16)));

// Binary Operation
inline vec3 operator+(const vec3 a, const vec3 b)
{
    return {a.x + b.x, a.y + b.y, a.z + b.z};
}

inline vec3 operator-(const vec3 a, const vec3 b)
{
    return {a.x - b.x, a.y - b.y, a.z - b.z};
}

inline vec3 operator*(const vec3 a, const vec3 b)
{
    return {a.x * b.x, a.y * b.y, a.z * b.z};
}

inline vec3 operator/(const vec3 a, const vec3 b)
{
    return {a.x / b.x, a.y / b.y, a.z / b.z};
}

// Unary Operation
inline void operator+=(vec3 &a, const vec3 b)
{
    a.x += b.x;
    a.y += b.y;
    a.z += b.z;
}

inline void operator-=(vec3 &a, const vec3 b)
{
    a.x -= b.x;
    a.y -= b.y;
    a.z -= b.z;
}

inline void operator*=(vec3 &a, const vec3 b)
{
    a.x *= b.x;
    a.y *= b.y;
    a.z *= b.z;
}

inline void operator/=(vec3 &a, const vec3 b)
{
    a.x /= b.x;
    a.y /= b.y;
    a.z /= b.z;
}

// Unary Operation Scalar
inline void operator+=(vec3 &a, const float b)
{
    a.x += b;
    a.y += b;
    a.z += b;
}

inline void operator-=(vec3 &a, const float b)
{
    a.x -= b;
    a.y -= b;
    a.z -= b;
}

inline void operator*=(vec3 &a, const float b)
{
    a.x *= b;
    a.y *= b;
    a.z *= b;
}

inline void operator/=(vec3 &a, const float b)
{
    a.x /= b;
    a.y /= b;
    a.z /= b;
}

// Vector *  Scalar
inline vec3 operator+(const vec3 a, const float b)
{
    return {a.x + b, a.y + b, a.z + b};
}

inline vec3 operator-(const vec3 a, const float b)
{
    return {a.x - b, a.y - b, a.y - b};
}

inline vec3 operator*(const vec3 a, const float b)
{
    return {a.x * b, a.y * b, a.y * b};
}

inline vec3 operator/(const vec3 a, const float b)
{
    return {a.x / b, a.y / b, a.y / b};
}

//  Scalar * Vector
inline vec3 operator+(const float a, const vec3 b)
{
    return {a + b.x, a + b.y, a + b.z};
}

inline vec3 operator-(const float a, const vec3 b)
{
    return {a - b.x, a - b.y, a - b.z};
}

inline vec3 operator*(const float a, const vec3 b)
{
    return {a * b.x, a * b.y, a * b.z};
}

inline vec3 operator/(const float a, const vec3 b)
{
    return {a / b.x, a / b.y, a / b.z};
}


inline vec3 max(const vec3 a, const vec3 b)
{
    return {
        fmax(a.x, b.x),
        fmax(a.y, b.y),
        fmax(a.z, b.z)};
}

inline vec3 min(const vec3 a, const vec3 b)
{
    return {
        fmin(a.x, b.x),
        fmin(a.y, b.y),
        fmin(a.z, b.z)};
}

inline float length(const vec3 a)
{
    return sqrt(a.x * a.x + a.y * a.y + a.z * a.z);
}

inline vec3 cross(const vec3 a, const vec3 b)
{

    return {
        a.y * b.z - b.y * a.z,
        a.z * b.x - b.z * a.x,
        a.x * b.y - b.x * a.y
    };
}

inline vec3 normalize(const vec3 v)
{
    float l = length(v);
    l = 1.0f / l;
    return v * l;
}

inline float dot(const vec3 a, const vec3 b)
{
    return a.x * b.x + a.y * b.y + a.z * b.z;
}

#endif
