/*
 * /include/resistance.h
 *
 * Standard types of resistance (RT_...) and other attack defines.
 *
 * Copyright (c) 1993 The StickMUD Project,
 * All rights reserved.
 */

#ifndef _RESISTANCE_H
#define _RESISTANCE_H

/*
 *	DAMAGE TYPES
 *
 */

/* Weapons, cuts, hits, crushing, falls, physical attacks in general */

#define RT_CUT		2
#define RT_SLASH	2
#define RT_EDGED	2
#define RT_CLAW		2

#define RT_IMPALE	3
#define RT_PIERCE	3
#define RT_PUNCTURE	3
#define RT_POINTED	3

#define RT_CRUSH	4
#define RT_BLUDGEON	4
#define RT_BLUNT	4

#define RT_IMPACT	5
#define RT_FALL		5

/* Bite is sort of a combined pierce & crush */
#define RT_BITE		8

/* And a resistance for ALL physical damage */

#define RT_PHYSICAL     10

/* Special or magical attacks */

#define RT_POISON	50
#define RT_EARTH	52
#define RT_WATER	54
#define RT_FIRE		56
#define RT_AIR		58
#define RT_SPIRIT	59
#define RT_COLD		60
#define RT_ACID		62
#define RT_ELECTRICITY	64
#define RT_TIME		66

#define RT_NETHER	70
#define RT_NEXUS	70

#define RT_PLASMA	72
#define RT_DARK		74
#define RT_NEGATIVE	76
#define RT_LIGHT	78
#define RT_POSITIVE	80
#define RT_MAGICAL	100

#endif /* _RESISTANCE_H */
