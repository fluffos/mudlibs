#ifndef _COORDINATES_
#define _COORDINATES_

/*--------------------------------------------------------------------------
 * /sys/coordinates.h -- Definition of some basic coordinates and heights
 *
 * Copyright (C) 1997 by One Step Beyond.
 * All Rights Reserved.
 * Permission granted for non-commercial use.
 *--------------------------------------------------------------------------
 *
 * this file is used to give some basic coordinate settings.
 * right now, that is not much, except of some fixed locations
 * as relative settings and some defines for the height.
 *
 * Sonic [23-Jun-1997]
 */


/* the H_* defines are used to give some basic values for 
 * height-levels.
 */

#define H_SEAGROUND -1000
#define H_COAST         0
#define H_MOUNTAIN   1000

/* the C_* defines are used as some absolute coordinates
 * for cities or other famous locations, from which then
 * offsets can derived.
 * the coordinates are an array of ({x,y,z}), where 
 *    x= X-Position,
 *    y= Y-Position and
 *    z= Height
 * are the koordinates of the spot.
 */

/* the coordinates are right now just some basic values...
 * so that we have something to work with.

/* the koordinates for silvere. */
#define C_SILVERE  ({ 50000,50000,0 })
/* the coordinates for the city in the mountains.
 * maybe the name can changed later, when you decided on a name
 */
#define C_S_FOREST  ({ 35000,35000,10})
/* the coordinates for a subarea of Silvere, the forest 
 * southeast of silvere
 */
#define C_SYKORATH ({ 450000,330000,2000 })

/* The coordinates of the login domain */
#define C_LOGIN ({ 0,0,10000 })

/* the following defines can be used for standard distances
 * e.g. in a city
 */
#define C_DEFAULT_XYZ 10

/* more to follow :-) */

#endif
