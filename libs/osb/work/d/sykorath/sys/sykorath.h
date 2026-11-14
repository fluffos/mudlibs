#ifndef _SYKORATH_SYS_SYKORATH_H_
#define _SYKORATH_SYS_SYKORATH_H_ 1

/*--------------------------------------------------------------------------
 * /d/sykorath/sys/sykorath.h -- Standard defines (properties...) for
 * /d/sykorath
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 */

// Standard room paths
#include "/d/sykorath/sys/path.h"
#include <rooms.h>
#include <secure/wizlevels.h>

/* P_INT_WIZMSG property temp. here */
#define P_INT_WIZMSG   "IntWizmsg"
#define P_INT_MAP      "IntMap"
#define P_TIME_MSG     "TimeMsg"

/* -------------------------------------------------------------------------
 * Additional properties for the Sykorath streets
 * -------------------------------------------------------------------------
 */

#define P_SKULL_NIGHT_MSG      "SkullNightMsg"
#define P_SKULL_DAY_MSG        "SkullDayMsg"

#define P_SKULL_NIGHT_EXTRA    "SkullNightExtra"
#define P_SKULL_DAY_EXTRA      "SkullDayExtra"

#define P_SKULL_NIGHT_DETAIL   "SkullNightDetail"
#define P_SKULL_DAY_DETAIL     "SkullDayDetail"

#define P_SKULL_BRIGHTNESS     "SkullBrightness"

/* -------------------------------------------------------------------------
 * this may be useful for showing maps.
 * If you need a tool, that checks this property, use
 * /players/sonic/obj/tester.c
 */
#define SetMap(x)  Set("IntMap",BASE+"doc/maps/"+x+".map")

/* -------------------------------------------------------------------------
 * define additional usefull macros
 */
#ifndef TP
#define TP     this_player()
#endif

#ifndef TI
#define TI     this_interactive()
#endif

#ifndef TO
#define TO     this_object()
#endif

#ifndef PO
#define PO     previous_object()
#endif

#ifndef NAME
#define NAME   this_player()->QueryName()
#endif

#ifndef RNAME
#define RNAME  this_player()->QueryRealName()
#endif

#ifndef ENV
#define ENV(x) environment(x)
#endif

#ifndef CAP
#define CAP(x) capitalize(x)
#endif

#ifndef HERE
#define HERE environment()
#endif

// some more or less useful things...
#ifndef LOW
#define LOW(x)        lower_case(x)
#endif

// do we need the following?
#define B_OBJ(x)   x->QueryObjective()
#define B_POSS(x)  x->QueryPossessive()
#define B_PRON(x)  x->QueryPronoun()
#define B_NAME(x)  x->QueryName()
#define B_RNAME(x) x->QueryRealName()


#endif /* _BEYOND_SYS_BEYOND_H_ */
