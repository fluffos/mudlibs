/*
 * File:		directions.h
 *
 * Contains:	Cheasy's direction rotation system
 *				Cheasy's position control system (not yet implemented!)
 *
 * History:
 *	96-03-25	cps		moved direction-specific defines into this file
 */

#ifndef __DIRECTIONS__
#define __DIRECTIONS__ 19960325
/* use the date as version number, thus we may check for versions in the
 * files including this one
 */

/* Direction rotating system *
 *****************************
 * This system works as follows: Each direction is encoded as a number, starting 
 * withN(orth) as 1. Here's a simple rosetta of directions:
 *
 *     ED4 ED5 ED6          NB: EXn stands for Exit Direction
 *        \ | /			This system allows the direction of any map to 
 *     ED3- * -ED7		be simply rotated simply by changing a header
 *        / | \			file. The only thing to pay attention to is ED1 
 *     ED2 ED1 ED8		has to be the opposite direction of ED5 .
 *
 * In the actual rooms the directions should be put into variables 
 * before using them in actual strings, this way a direction changing 
 * system may be used to make scripting harder than usual, if not
 * impossible.
 */

#define ED2 "sueden"
#define ED3 "suedwesten"
#define ED4 "westen"
#define ED5 "nordwesten"
#define ED6 "norden"
#define ED7 "nordosten"
#define ED8 "osten"
#define ED1 "suedosten"

#define ED2OB "suedoben"
#define ED3OB "suedwestoben"
#define ED4OB "westoben"
#define ED5OB "nordwestoben"
#define ED6OB "nordoben"
#define ED7OB "nordostoben"
#define ED8OB "ostoben"
#define ED1OB "suedostoben"

#define ED2U "suedunten"
#define ED3U "suedwestunten"
#define ED4U "westunten"
#define ED5U "nordwestunten"
#define ED6U "nordunten"
#define ED7U "nordostunten"
#define ED8U "ostunten"
#define ED1U "suedostunten"

/*
 * for the sake of completeness, there's also defines for up and down.
 */

#define EDo oben
#define EDu unten


/* Direction position control system *
 *************************************
 * The following defines may be changed into something useful someday.

//#define POS(x,y,z)	/* [x, y, z] */
//#define POS(x,y)	POS(x,y,0)

#endif
