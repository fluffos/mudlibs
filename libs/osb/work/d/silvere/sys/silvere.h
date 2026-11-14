#ifndef _SILVERE_H_
#define _SILVERE_H_ 1

/*--------------------------------------------------------------------------
 * /d/silvere/sys/silvere.h -- Standard defines for use at /d/silvere
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 */

// Standard room paths
#include "/d/silvere/sys/path.h"
#include <secure/wizlevels.h>
#include <rooms.h>

/* P_INT_WIZMSG property temp. here */
#define P_INT_WIZMSG   "IntWizmsg"
#define P_INT_MAP      "IntMap"
#define P_TIME_MSG     "TimeMsg"
#define P_SEASON_MSG    "SeasonMsg"

/* -------------------------------------------------------------------------
 * this may be useful for showing maps.
 * If you need a tool, that checks this property, use
 * /obj/tool/tester.c
 */

#endif /* _SILVERE_H_ */
