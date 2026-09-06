/*
 * /include/attack.h
 *
 * Standard types of damage (DT_...) and other attack defines.
 *
 * Copyright (c) 1993 The StickMUD Project,
 * All rights reserved.
 */

#ifndef _ATTACK_H
#define _ATTACK_H

/* This can't be resisted by anyone, no matter what. */
#define DT_FORCE	1
#define DT_NONMASKABLE	1

/* Weapons, cuts, hits, crushing, falls, physical attacks in general */

#define DT_CUT		2
#define DT_SLASH	2
#define DT_EDGED	2

#define DT_IMPALE	3
#define DT_PIERCE	3
#define DT_PUNCTURE	3
#define DT_POINTED	3

#define DT_CRUSH	4
#define DT_BLUDGEON	4
#define DT_BLUNT	4

#define DT_IMPACT	5
// IMO, Fall should be 'special', non-avoidable usually. -+ DD 13-Aug-98 +-
//#define DT_FALL		5

#define	DT_AXE		6
#define	DT_CLEAVE	6

/* Bite is sort of a combined pierce & crush */
#define DT_BITE		8
#define	DT_CLAW		9
// Real clawing; DT_SLASH == weapon hit, although similar to claw

#define	DT_STAB		10
// Nothing special as damage, but different hit type at least. -+ DD +-

#define DT_PHYSICAL     12  //Use this only for resistances

/* Special or magical attacks */

#define DT_POISON	50
#define DT_EARTH	52
#define DT_WATER	54
#define DT_FIRE		56
#define DT_AIR		58
#define DT_SPIRIT	58
#define DT_COLD		60
#define DT_ACID		62
#define DT_ELECTRICITY	64
#define DT_TIME		66
#define	DT_PSIONIC	67

#define DT_NETHER	70
#define DT_NEXUS	70

#define DT_PLASMA	72
#define DT_DARK		74
#define DT_NEGATIVE	76
#define DT_LIGHT	78
#define DT_POSITIVE	80
#define	DT_FALL		90
#define DT_MAGICAL	100

// Added 13-Aug-98, Doomdark: These _should_ be ORed (DT_xxx | DT_yy)
#define DT_AREA	0x0100

#define MAX_RES 900 //Max amount of resistance (in promille)

#endif /* _ATTACK_H */
