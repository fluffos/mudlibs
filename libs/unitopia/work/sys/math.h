// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/math.h
// Description: Nuetzliche Definitionen fuer mathematische Operationen
//
// $Log: math.h,v $
// Revision 1.3  2001/12/13 18:41:55  freaky
// Wenn vorhanden, die Driver-internen Defines nehmen.
//
// Revision 1.2  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef MATH_H
#define MATH_H 1

#define PI 3.141592654

#ifdef __INT_MAX__
#define MAX_INT __INT_MAX__
#define MIN_INT __INT_MIN__
#else
#define MAX_INT 2147483647
#define MIN_INT -2147483648
#endif

#endif // MATH_H
