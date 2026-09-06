// MorgenGrauen MUDlib
//
// sys/thing/util.h -- Headerfile fuer /std/thing/util.c
//
// $Id: util.h 4707 2006-09-23 10:18:15Z root $

#ifndef __THING_UTIL_H__
#define __THING_UTIL_H__

#endif // __THING_UTIL_H__

#ifdef NEED_PROTOTYPES

#ifndef __THING_UTIL_H_PROTO__
#define __THING_UTIL_H_PROTO__

public void ShowPropList(string *props);
nosave void PrettyDump(mixed x);
nosave void DumpArray(mixed *x);
nosave void DumpMapping(mapping x);
nosave void DumpKeyValPair(mapping x, mixed key, int size);

#endif // __THING_UTIL_H_PROTO__

#endif // NEED_PROTOTYPES