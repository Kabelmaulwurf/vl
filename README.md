#vl - vec3/vec4 Library#

vl is a vec3/4 Library with focus on being small and fast.<br>
It is made with the usage of gcc in mind using inline ASM for SSE<br>
and tries to mimic the OpenGL codestyle to blend in well.

##Features:##

* Basic Arithmetic Add,Sub,Mul,Div
* Vector Arithmetic Length,Dot,Cross,Normalize
* Util Functions Min,Max,Abs

##Notes:##
For compiling under gcc use -masm=intel -lm<br>
There are macro-defines for the basic arithmetics which can be toggled to use SSE by #define SSE <br>


