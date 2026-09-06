/*
** materials.h
**
** To be used with /complex/room. Documented elsewhere.
*/

#ifndef MATERIALS_H
#define MATERIALS_H
 
/* NOTICE: Max number of materials = 32, since it is the lenght of (int) */
/* CAN BE FIXED LATER IF THERE IS NEED */
 
#define WATER		(1<<0)
#define EARTH		(1<<1)
 
#define MUD		(1<<5)
#define SAND		(1<<8)
#define ROCK		(1<<6)
#define MOREN		(1<<7)
 
#define WOOD		(1<<9)
 
#define FLOWERS		(1<<12)
#define FLOWERS2	(1<<13)
 
#define GRASS		(1<<15)
 
#define GRAIN		(1<<17)
#define WHEAT		(1<<18)
 
#define HERBS1		(1<<20)
#define HERBS2		(1<<21)
 
/* Please, add to the list, it is far from complete */
 
 
 /* Speedup with materials to standardize */
 
#define LAKE		WATER
#define SEA		WATER
#define PLAINS		(GRASS + EARTH)
#define FOREST		(WOOD + FOREST + FLOWERS + GRASS + EARTH)

#endif

