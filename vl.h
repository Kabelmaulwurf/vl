#ifndef _VL_H_
#define _VL_H_

#include <math.h>


#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define AB(a)	 ((a)<0?-(a):(a))

#ifdef SSE
#define ADD3(a,b) (vl3AddSSE(a,b))
#define SUB3(a,b) (vl3SubSSE(a,b))
#define MUL3(a,b) (vl3MulSSE(a,b))
#define DIV3(a,b) (vl3DivSSE(a,b))
#else
#define ADD3(a,b) (vl3Add(a,b))
#define SUB3(a,b) (vl3Sub(a,b))
#define MUL3(a,b) (vl3Mul(a,b))
#define DIvl(a,b) (vl3Div(a,b))
#endif

typedef struct
{
	float x,y,z,w;
}vec4;

typedef struct
{
	float x,y,z;
}__attribute__ ((__aligned__(16)))vec3;


//==============================================================================
//	Vec3 Utils
//==============================================================================

inline vec3 vl3Min(vec3 a , vec3 b)
{
	return (vec3){ MIN(a.x,b.x) , MIN(a.y,b.y) , MIN(a.z,b.z)  };
}

inline vec3 vl3Max(vec3 a , vec3 b)
{
	return (vec3){ MIN(a.x,b.x) , MIN(a.y,b.y) , MIN(a.z,b.z)  };
}

inline float vl3Length(vec3 v)
{
	return sqrt(v.x*v.x+v.y*v.y+v.z*v.z);
}

inline float vl3Dot(vec3 a, vec3 b)
{
    return a.x*b.x+a.y*b.y+a.z*b.z;
}

inline vec3 vl3Cross(vec3 a, vec3 b)
{
    vec3 r;

    r.x = a.y*b.z-b.y*a.z;
    r.y = a.z*b.x-b.z*a.x;
    r.z = a.x*b.y-b.x*a.y;

    return r;
}

inline vec3 vl3Normalize(vec3 v)
{
	float l = vl3Length(v);
	l = 1.f/l;
	return vlMulS(v,l);
}
//==============================================================================
//	Vec4 Utils
//==============================================================================

inline vec4 vl4Min(vec4 a , vec4 b)
{
	return (vec4){ MIN(a.x,b.x) , MIN(a.y,b.y) , MIN(a.z,b.z) , MIN(a.w,b.w)  };
}

inline vec4 vl4Max(vec4 a , vec4 b)
{
	return (vec4){ MIN(a.x,b.x) , MIN(a.y,b.y) , MIN(a.z,b.z) , MIN(a.w,b.w) };
}

inline float vl4Length(vec4 v)
{
	return sqrt(v.x*v.x+v.y*v.y+v.z*v.z+v.w*v.w);
}

inline float vl4Dot(vec4 a, vec4 b)
{
    return a.x*b.x+a.y*b.y+a.z*b.z+a.w*b.w;
}

inline void v4Normalize(vec4 *v)
{
    float l  = v4Length(*v);
    l = 1.f/l;
    v->x *= l;
    v->y *= l;
    v->z *= l;
}
//==============================================================================
// Vec3 Arithmetics (SSE)
//==============================================================================
inline vec3 vl3AddSSE(vec3 a,vec3 b)
{
	vec3 r;
	asm(
		"movups xmm0, %1;"
		"movups xmm1, %2;"
		"addps xmm0,xmm1;"
		"movups %0,xmm0;"
		: "=m"(r)
		: "m" (a),"m"(b)
		);
	return r;
}

inline vec3 vl3SubSSE(vec3 a,vec3 b)
{
	vec3 r;
	asm(
		"movups xmm0, %1;"
		"movups xmm1, %2;"
		"subps xmm0,xmm1;"
		"movups %0,xmm0;"
		: "=m"(r)
		: "m" (a) , "m"(b)
	);
	return r;
}

inline vec3 vl3MulSSE(vec3 a,vec3 b)
{
	vec3 r;
	asm(
		"movups xmm0, %1;"
		"movups xmm1, %2;"
		"mulps xmm0,xmm1;"
		"movups %0,xmm0;"
		: "=m"(r)
		: "m" (a) , "m"(b)
	);
	return r;
}
inline vec3 vl3DivSSE(vec3 a,vec3 b)
{
	vec3 r;
	asm(
		"movups xmm0, %1;"
		"movups xmm1, %2;"
		"divps xmm0,xmm1;"
		"movups %0,xmm0;"
		: "=m"(r)
		: "m" (a) , "m"(b)
	);
	return r;
}
//==============================================================================
// Vec3 Arithmetics 
//==============================================================================

inline vec3 vl3Add(vec3 a,vec3 b)
{
    return (vec3) { a.x+b.x , a.y+b.y , a.z+b.z };
}

inline vec3 vl3Sub(vec3 a,vec3 b)
{
    return (vec3) { a.x-b.x , a.y-b.y , a.z-b.z };
}

inline vec3 vl3Mul(vec3 a,vec3 b)
{
    return (vec3) { a.x*b.x , a.y*b.y , a.z*b.z };
}

inline vec3 vl3Div(vec3 a,vec3 b)
{
    return (vec3) { a.x/b.x , a.y/b.y , a.z/b.z };
}
//==============================================================================
// Vec3 Arithmetics (Scalar)
//==============================================================================

inline vec3 vl3Addf(vec3 a,float s)
{
    return (vec3) { a.x+s , a.y+s , a.z+s };
}

inline vec3 vl3Subf(vec3 a,float s)
{
    return (vec3) { a.x-s , a.y-s , a.z-s };
}

inline vec3 vl3Mulf(vec3 a,float s)
{
    return (vec3) { a.x*s , a.y*s , a.z*s };
}

inline vec3 vl3Divf(vec3 a,float s)
{
    return (vec3) { a.x/s , a.y/s , a.z/s };
}


//==============================================================================
// Vec4 Arithmetics (SSE)
//==============================================================================

inline vec4 v4AddSSE(vec4 a,vec4 b)
{
	vec4 r;
	asm(
		"movups xmm0, %1;"
		"movups xmm1, %2;"
		"addps xmm0,xmm1;"
		"movups %0,xmm0;"
		: "=m"(r)
		: "m" (a),"m"(b)
		);
	return r;
}

inline vec4 v4SubSSE(vec4 a,vec4 b)
{
	vec4 r;
	asm(
		"movups xmm0, %1;"
		"movups xmm1, %2;"
		"subps xmm0,xmm1;"
		"movups %0,xmm0;"
		: "=m"(r)
		: "m" (a) , "m"(b)
	);
	return r;
}

inline vec4 v4MulSSE(vec4 a,vec4 b)
{
	vec4 r;
	asm(
		"movups xmm0, %1;"
		"movups xmm1, %2;"
		"mulps xmm0,xmm1;"
		"movups %0,xmm0;"
		: "=m"(r)
		: "m" (a) , "m"(b)
	);
	return r;
}
inline vec4 v4DivSSE(vec4 a,vec4 b)
{
	vec4 r;
	asm(
		"movups xmm0, %1;"
		"movups xmm1, %2;"
		"divps xmm0,xmm1;"
		"movups %0,xmm0;"
		: "=m"(r)
		: "m" (a) , "m"(b)
	);
	return r;
}

//==============================================================================
// Vec4 Arithmetics
//==============================================================================

inline vec4 v4Add(vec4 a,vec4 b)
{
    return (vec4) { a.x+b.x , a.y+b.y , a.z+b.z , a.w+b.w };
}

inline vec4 v4Sub(vec4 a,vec4 b)
{
    return (vec4) { a.x-b.x , a.y-b.y , a.z-b.z , a.w-b.w };
}

inline vec4 v4Mul(vec4 a,vec4 b)
{
    return (vec4) { a.x*b.x , a.y*b.y , a.z*b.z , a.w*b.w };
}

inline vec4 v4Div(vec4 a,vec4 b)
{
    return (vec4) { a.x/b.x , a.y/b.y , a.z/b.z , a.w/b.w };
}

//==============================================================================
// Vec4 Arithmetics (Scalar)
//==============================================================================

inline vec4 v4AddS(vec4 v,float s)
{
    return (vec4) { v.x+s , v.y+s , v.z+s , v.w+s };
}

inline vec4 v4SubS(vec4 v,float s)
{
    return (vec4) { v.x-s , v.y-s , v.z-s , v.w-s };
}

inline vec4 v4MulS(vec4 v,float s)
{
    return (vec4) { v.x*s , v.y*s , v.z*s , v.w*s };
}

inline vec4 v4DivS(vec4 v,float s)
{
    return (vec4) { v.x/s , v.y/s , v.z/s , v.w/s };
}

#endif

