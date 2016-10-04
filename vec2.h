#ifndef _VEC2_H_
#define _VEC2_H_

struct vec2
{
    float x;
    float y;
};

// Binary Operation
inline vec2 operator+(const vec2 a, const vec2 b)
{
    return {a.x + b.x, a.y + b.y};
}

inline vec2 operator-(const vec2 a, const vec2 b)
{
    return {a.x - b.x, a.y - b.y};
}

inline vec2 operator*(const vec2 a, const vec2 b)
{
    return {a.x * b.x, a.y * b.y};
}

inline vec2 operator/(const vec2 a, const vec2 b)
{
    return {a.x / b.x, a.y / b.y};
}

// Unary Operation
inline void operator+=(vec2 &a, const vec2 b)
{
    a.x += b.x;
    a.y += b.y;
}

inline void operator-=(vec2 &a, const vec2 b)
{
    a.x -= b.x;
    a.y -= b.y;
}

inline void operator*=(vec2 &a, const vec2 b)
{
    a.x *= b.x;
    a.y *= b.y;
}

inline void operator/=(vec2 &a, const vec2 b)
{
    a.x /= b.x;
    a.y /= b.y;
}


// Unary Operation Scalar
inline void operator+=(vec2 &a, const float b)
{
    a.x += b;
    a.y += b;
}

inline void operator-=(vec2 &a, const float b)
{
    a.x -= b;
    a.y -= b;
}

inline void operator*=(vec2 &a, const float b)
{
    a.x *= b;
    a.y *= b;
}

inline void operator/=(vec2 &a, const float b)
{
    a.x /= b;
    a.y /= b;
}



// Vector *  Scalar
inline vec2 operator+(const vec2 a, const float b)
{
    return {a.x + b, a.y + b};
}

inline vec2 operator-(const vec2 a, const float b)
{
    return {a.x - b, a.y - b};
}

inline vec2 operator*(const vec2 a, const float b)
{
    return {a.x * b, a.y * b};
}

inline vec2 operator/(const vec2 a, const float b)
{
    return {a.x / b, a.y / b};
}



//  Scalar * Vector
inline vec2 operator+(const float a, const vec2 b)
{
    return {a + b.x, a + b.y};
}


inline vec2 operator-(const float a, const vec2 b)
{
    return {a - b.x, a - b.y};
}


inline vec2 operator*(const float a, const vec2 b)
{
    return {a * b.x, a * b.y};
}


inline vec2 operator/(const float a, const vec2 b)
{
    return {a / b.x, a / b.y};
}

#endif
