/*
	math.c: this file contains the math efunctions called from
	inside eval_instruction() in interpret.c.
    -- coded by Truilkan 93/02/21
*/

#include <math.h>
#ifdef LATTICE
#include "/lpc_incl.h"
#else
#include "../lpc_incl.h"
#include "../efun_protos.h"
#endif

#ifdef F_COS
void
f_cos PROT((void))
{
    sp->u.real = cos(sp->u.real);
}
#endif

#ifdef F_SIN
void
f_sin PROT((void))
{
    sp->u.real = sin(sp->u.real);
}
#endif
#ifdef F_TAN
void
f_tan PROT((void))
{
    /*
     * maybe should try to check that tan won't blow up (x != (Pi/2 + N*Pi))
     */
    sp->u.real = tan(sp->u.real);
}
#endif

#ifdef F_ASIN
void
f_asin PROT((void))
{
    if (sp->u.real < -1.0) {
        error("math: asin(x) with (x < -1.0)\n");
        return;
    } else if (sp->u.real > 1.0) {
        error("math: asin(x) with (x > 1.0)\n");
        return;
    }
    sp->u.real = asin(sp->u.real);
}
#endif

#ifdef F_ACOS
void
f_acos PROT((void))
{
    if (sp->u.real < -1.0) {
        error("math: acos(x) with (x < -1.0)\n");
        return;
    } else if (sp->u.real > 1.0) {
        error("math: acos(x) with (x > 1.0)\n");
        return;
    }
    sp->u.real = acos(sp->u.real);
}
#endif

#ifdef F_ATAN
void
f_atan PROT((void))
{
    sp->u.real = atan(sp->u.real);
}
#endif

#ifdef F_SQRT
void
f_sqrt PROT((void))
{
    if (sp->u.real < 0.0) {
        error("math: sqrt(x) with (x < 0.0)\n");
        return;
    }
    sp->u.real = sqrt(sp->u.real);
}
#endif

#ifdef F_LOG
void
f_log PROT((void))
{
    if (sp->u.real <= 0.0) {
        error("math: log(x) with (x <= 0.0)\n");
        return;
    }
    sp->u.real = log(sp->u.real);
}
#endif

#ifdef F_LOG10
void
f_log10 PROT((void))
{
    if (sp->u.real <= 0.0) {
        error("math: log10(x) with (x <= 0.0)\n");
        return;
    }
    sp->u.real = log10(sp->u.real);
}
#endif

#ifdef F_POW
void
f_pow PROT((void))
{
    (sp - 1)->u.real = pow((sp - 1)->u.real, sp->u.real);
    sp--;
}
#endif

#ifdef F_EXP
void
f_exp PROT((void))
{
    sp->u.real = exp(sp->u.real);
}
#endif

#ifdef F_FLOOR
void
f_floor PROT((void))
{
    sp->u.real = floor(sp->u.real);
}
#endif

#ifdef F_CEIL
void
f_ceil PROT((void))
{
    sp->u.real = ceil(sp->u.real);
}
#endif

// 絕對值 Add by Clode@RW
#ifdef F_ABS
void
f_abs PROT((void))
{
    if (sp->u.real <= 0.0)
    sp->u.real = - sp->u.real;
}
#endif

// 小數位之四捨五入 Add by Clode@RW
#ifdef F_ROFF
void
f_roff PROT((void))
{
    if( sp->u.real - floor(sp->u.real) > 0.5 )
    	sp->u.real = ceil(sp->u.real);
    else
    	sp->u.real = floor(sp->u.real);
}
#endif

// 畢式定理 Add by Clode@RW
#ifdef F_PYTHAGOREAN_THM
void
f_pythagorean_thm PROT((void))
{
    (sp - 1)->u.real = sqrt(sp->u.real*sp->u.real + (sp - 1)->u.real*(sp - 1)->u.real);
    sp--;
}
#endif