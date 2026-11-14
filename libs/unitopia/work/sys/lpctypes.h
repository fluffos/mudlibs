// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/lpctypes.h
// Description: Defines fuer functionlist()
// Author:	Driver
//
// $Log: lpctypes.h,v $
// Revision 1.9  2006/10/18 20:14:32  gnomi
// Auf 3.3.714 aktualisiert.
//
// Revision 1.8  2004/07/19 21:40:01  gnomi
// Typo.
//
// Revision 1.7  2004/04/22 16:22:15  freaky
// Vom aktuellen Driver (3.2.10-dev-635) eingebaut
//
// Revision 1.6  2002/11/28 13:07:49  freaky
// Aenderungen von ldmud-3.2.9dev496 eingebaut
//
// Revision 1.5  2001/10/25 17:19:30  freaky
// von ldmud-3.2.9dev355 eingespielt
//
// Revision 1.4  2001/09/02 11:44:06  freaky
// von ldmud-3.2.9-dev.332 eingespielt
//
// Revision 1.3  2001/08/23 09:21:54  freaky
// angepasst an ldmud-3.2.9dev323
//
// Revision 1.2  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef LPC_LPCTYPES_H
#define LPC_LPCTYPES_H

/* compile time types, from functionlist() */

#define TYPE_UNKNOWN    0       /* This type must be casted */
#define TYPE_NUMBER     1
#define TYPE_STRING     2
#define TYPE_VOID       3
#define TYPE_OBJECT     4
#define TYPE_MAPPING    5
#define TYPE_FLOAT      6
#define TYPE_ANY        7       /* Will match any type */
#define TYPE_CLOSURE    8
#define TYPE_SYMBOL     9
#define TYPE_QUOTED_ARRAY 10
#if defined(USE_STRUCTS) || defined(__LPC_STRUCTS__)
#define TYPE_STRUCT     11
#endif

#define TYPE_MOD_POINTER        0x0040  /* Pointer to a basic type        */

/* runtime types, from typeof() */

#define T_INVALID       0x0
#define T_LVALUE        0x1
#define T_NUMBER        0x2
#define T_STRING        0x3
#define T_POINTER       0x4
#define T_OBJECT        0x5
#define T_MAPPING       0x6
#define T_FLOAT         0x7
#define T_CLOSURE       0x8
#define T_SYMBOL        0x9
#define T_QUOTED_ARRAY  0xa
#if defined(USE_STRUCTS) || defined(__LPC_STRUCTS__)
#define T_STRUCT        0xb
#endif

/* Closure types, stored as secondary type info */

#ifndef __DRIVER_SOURCE__

#define CLOSURE_LFUN            0  /* lfun in an object */
#define CLOSURE_ALIEN_LFUN      1  /* lfun in an other object */
/* CLOSURE_ALIEN_LFUN is not used anymore. */
#define CLOSURE_IDENTIFIER      2  /* variable in this object */
#define CLOSURE_PRELIMINARY     3
    /* Efun closure used in a nosave initialization */
#define CLOSURE_BOUND_LAMBDA    4  /* Bound unbound-lambda closure */
#define CLOSURE_LAMBDA          5  /* normal lambda closure */
#define CLOSURE_UNBOUND_LAMBDA  6  /* unbound lambda closure. */

#define CLOSURE_OPERATOR        (0xe800)
#define CLOSURE_EFUN            (0xf000)
#define CLOSURE_SIMUL_EFUN      (0xf800)

#define CLOSURE_IS_LFUN(x)		(((x)&~1) == 0)
#define CLOSURE_IS_IDENTIFIER(x)	((x) == CLOSURE_IDENTIFIER)
#define CLOSURE_IS_BOUND_LAMBDA(x)	((x) == CLOSURE_BOUND_LAMBDA)
#define CLOSURE_IS_LAMBDA(x)		((x) == CLOSURE_LAMBDA)
#define CLOSURE_IS_UNBOUND_LAMBDA(x)	((x) == CLOSURE_UNBOUND_LAMBDA)
#define CLOSURE_IS_SIMUL_EFUN(x) (((x) & 0xf800) == CLOSURE_SIMUL_EFUN)
#define CLOSURE_IS_EFUN(x)	 (((x) & 0xf800) == CLOSURE_EFUN)
#define CLOSURE_IS_OPERATOR(x)	 (((x) & 0xf800) == CLOSURE_OPERATOR)

#endif /* __DRIVER_SOURCE__ */

#endif /* LPC_LPCTYPES_H */
