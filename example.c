#include <stdio.h>

#include "vec2.h"
#include "vec3.h"

int main(void)
{

    vec3 a;
    a.x = 1.0;
    a.y = 2.0;
    a.z = 3.0;

    vec3 b;
    b.x = 4.0;
    b.y = 5.0;
    b.z = 6.0;

    a = a + b;
    a += b;
    printf("A: %f B:  %f C: %f\n", a.x, a.y, a.z);
    a -= b;
    printf("A: %f B:  %f C: %f\n", a.x, a.y, a.z);
    a *= b;
    printf("A: %f B:  %f C: %f\n", a.x, a.y, a.z);
    a /= b;
    printf("A: %f B:  %f C: %f\n", a.x, a.y, a.z);

    a *= 2.0;
    printf("A: %f B:  %f C: %f\n", a.x, a.y, a.z);
    a = max(a, b);
    printf("A: %f B:  %f C: %f\n", a.x, a.y, a.z);
    a = normalize(a);
    a = min(a, b);
    printf("A: %f B:  %f C: %f\n", a.x, a.y, a.z);
    b = normalize(b);
    float d = dot(a, b);
    printf("dot :%f\n", d);
    
    return 1;
}
