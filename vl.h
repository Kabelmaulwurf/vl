/*

                vl: vl.h (c) 2012 Kabelmaulwurf

    F16 is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    F16 is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/



#ifndef _VL_H_
#define _VL_H_

#include <math.h>


#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))
#define ABS(a)	 ((a)<0?-(a):(a))

#ifdef SSE
#define ADD3(a,b) (vl3AddSSE(a,b))
#define SUB3(a,b) (vl3SubSSE(a,b))
#define MUL3(a,b) (vl3MulSSE(a,b))
#define DIV3(a,b) (vl3DivSSE(a,b))
#else
#define ADD3(a,b) (vl3Add(a,b))
#define SUB3(a,b) (vl3Sub(a,b))
#define MUL3(a,b) (vl3Mul(a,b))
#define DIV3(a,b) (vl3Div(a,b))
#endif


typedef struct 
{
	float x,y;
}vec2;

typedef struct
{
	float x,y,z;
}__attribute__ ((__aligned__(16)))vec3;

typedef struct
{
	float x,y,z,w;
}vec4;

/*==============================================================================
	Vec2 Arithmetics 
==============================================================================*/
inline vec2 vl2Add(vec2 a,vec2 b)
{
	return (vec2) { a.x+b.x,a.y+b.y};
}

inline vec2 vl2Sub(vec2 a,vec2 b)
{
	return (vec2) { a.x-b.x,a.y-b.y};
}

inline vec2 vl2Mul(vec2 a,vec2 b)
{
	return (vec2) { a.x*b.x,a.y*b.y};
}

inline vec2 vl2Div(vec2 a,vec2 b)
{
	return (vec2) { a.x/b.x,a.y/b.y};
}

/*==============================================================================
	Vec2 Arithmetics (Scalar)
==============================================================================*/
inline vec2 vl2AddS(vec2 a,float s)
{
	return (vec2) { a.x+s,a.y+s};
}

inline vec2 vl2SubS(vec2 a,float s)
{
	return (vec2) { a.x-s,a.y-s};
}

inline vec2 vl2MulS(vec2 a,float s)
{
	return (vec2) { a.x*s,a.y*s};
}

inline vec2 vl2DivS(vec2 a,float s)
{
	return (vec2) { a.x/s,a.y/s};
}
/*==============================================================================
	Vec2 Utils
==============================================================================*/
inline vec2 vl2Min(vec2 a , vec2 b)
{
	return (vec2){ MIN(a.x,b.x) , MIN(a.y,b.y)};
}

inline vec2 vl2Max(vec2 a , vec2 b)
{
	return (vec2){ MAX(a.x,b.x) , MAX(a.y,b.y)};
}

inline vec2 vl2Abs(vec2 v)
{
	return (vec2) {ABS(v.x),ABS(v.y)};
}

inline float vl2Length(vec2 v)
{
	return sqrt(v.x*v.x+v.y*v.y);
}

inline float vl2Dot(vec2 a, vec2 b)
{
	return a.x*b.x+a.y*b.y;
}

inline float vl2Cross(vec2 a, vec2 b)
{
	return a.x*b.y-a.y*b.x;
}

inline vec2 vl2Normalize(vec2 v)
{
	float l = vl2Length(v);
	l = 1.0f/l;
	return vl2MulS(v,l);
}

/*==============================================================================
	Vec3 Arithmetics (SSE)
==============================================================================*/
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
/*==============================================================================
	Vec3 Arithmetics 
==============================================================================*/

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
/*==============================================================================
	Vec3 Arithmetics (Scalar)
==============================================================================*/

inline vec3 vl3AddS(vec3 a,float s)
{
    return (vec3) { a.x+s , a.y+s , a.z+s };
}

inline vec3 vl3SubS(vec3 a,float s)
{
    return (vec3) { a.x-s , a.y-s , a.z-s };
}

inline vec3 vl3MulS(vec3 a,float s)
{
    return (vec3) { a.x*s , a.y*s , a.z*s };
}

inline vec3 vl3DivS(vec3 a,float s)
{
    return (vec3) { a.x/s , a.y/s , a.z/s };
}


/*==============================================================================
	Vec4 Arithmetics (SSE)
==============================================================================*/

inline vec4 vl4AddSSE(vec4 a,vec4 b)
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

inline vec4 vl4SubSSE(vec4 a,vec4 b)
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

inline vec4 vl4MulSSE(vec4 a,vec4 b)
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
inline vec4 vl4DivSSE(vec4 a,vec4 b)
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

/*==============================================================================
	Vec4 Arithmetics
==============================================================================*/

inline vec4 vl4Add(vec4 a,vec4 b)
{
    return (vec4) { a.x+b.x , a.y+b.y , a.z+b.z , a.w+b.w };
}

inline vec4 vl4Sub(vec4 a,vec4 b)
{
    return (vec4) { a.x-b.x , a.y-b.y , a.z-b.z , a.w-b.w };
}

inline vec4 vl4Mul(vec4 a,vec4 b)
{
    return (vec4) { a.x*b.x , a.y*b.y , a.z*b.z , a.w*b.w };
}

inline vec4 vl4Div(vec4 a,vec4 b)
{
    return (vec4) { a.x/b.x , a.y/b.y , a.z/b.z , a.w/b.w };
}

/*==============================================================================
	Vec4 Arithmetics (Scalar)
==============================================================================*/

inline vec4 vl4AddS(vec4 v,float s)
{
    return (vec4) { v.x+s , v.y+s , v.z+s , v.w+s };
}

inline vec4 vl4SubS(vec4 v,float s)
{
    return (vec4) { v.x-s , v.y-s , v.z-s , v.w-s };
}

inline vec4 vl4MulS(vec4 v,float s)
{
    return (vec4) { v.x*s , v.y*s , v.z*s , v.w*s };
}

inline vec4 vl4DivS(vec4 v,float s)
{
    return (vec4) { v.x/s , v.y/s , v.z/s , v.w/s };
}

/*==============================================================================
	Vec3 Utils
==============================================================================*/

inline vec3 vl3Min(vec3 a , vec3 b)
{
	return (vec3){ MIN(a.x,b.x) , MIN(a.y,b.y) , MIN(a.z,b.z)  };
}

inline vec3 vl3Max(vec3 a , vec3 b)
{
	return (vec3){ MAX(a.x,b.x) , MAX(a.y,b.y) , MAX(a.z,b.z)  };
}

inline vec3 vl3Abs(vec3 v)
{
	return (vec3){ ABS(v.x) , ABS(v.y) , ABS(v.z)  };
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
	return vl3MulS(v,l);
}
/*==============================================================================
	Vec4 Utils
==============================================================================*/

inline vec4 vl4Min(vec4 a , vec4 b)
{
	return (vec4){ MIN(a.x,b.x) , MIN(a.y,b.y) , MIN(a.z,b.z) , MIN(a.w,b.w)  };
}

inline vec4 vl4Max(vec4 a , vec4 b)
{
	return (vec4){ MAX(a.x,b.x) , MAX(a.y,b.y) , MAX(a.z,b.z) , MAX(a.w,b.w) };
}

inline vec4 vl4Abs(vec4 v)
{
	return (vec4){ ABS(v.x) , ABS(v.y) , ABS(v.z) , ABS(v.w) };
}

inline float vl4Length(vec4 v)
{
	return sqrt(v.x*v.x+v.y*v.y+v.z*v.z+v.w*v.w);
}

inline float vl4Dot(vec4 a, vec4 b)
{
    return a.x*b.x+a.y*b.y+a.z*b.z+a.w*b.w;
}

inline void vl4Normalize(vec4 *v)
{
    float l  = vl4Length(*v);
    l = 1.f/l;
    v->x *= l;
    v->y *= l;
    v->z *= l;
}


#endif

