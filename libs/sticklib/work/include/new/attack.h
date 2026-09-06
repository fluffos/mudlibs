/*
 * /include/attack.h
 *
 * Standard types of damage (DT_...) and other attack defines.
 *
 * Copyright (c) 1993 The Stickmud Project,
 * All rights reserved.
 */

#ifndef _ATTACK_H
#define _ATTACK_H

/*
 *	DAMAGE TYPES (bitfield)
 *
 */

/* This can't be resisted by anyone, no matter what. */
#define DT_FORCE	(1)
#define DT_NONMASKABLE	(1)

/* Weapons, cuts, hits, crushing, falls, physical attacks in general */

#define DT_CUT		(1<<1)
#define DT_SLASH	(1<<1)
#define DT_EDGED	(1<<1)

#define DT_IMPALE	(1<<2)
#define DT_PIERCE	(1<<2)
#define DT_PUNCTURE	(1<<2)
#define DT_POINTED	(1<<2)

#define DT_CRUSH	(1<<3)
#define DT_BLUDGEON	(1<<3)
#define DT_BLUNT	(1<<3)

#define DT_IMPACT	(1<<4)
#define DT_FALL		(1<<4)

/* Bits 5..10 reserved for future expansions */

/* Special or magical attacks */

#define DT_POISON	(1<<11)
#define DT_EARTH	(1<<12)
#define DT_WATER	(1<<13)
#define DT_FIRE		(1<<14)
#define DT_AIR		(1<<15)
#define DT_COLD		(1<<16)
#define DT_ACID		(1<<17)
#define DT_ELECTRICITY	(1<<18)
#define DT_TIME		(1<<19)

#define DT_NETHER	(1<<20)
#define DT_NEXUS	(1<<20)

#define DT_PLASMA	(1<<21)
#define DT_DARK		(1<<22)
#define DT_NEGATIVE	(1<<23)
#define DT_LIGHT	(1<<24)
#define DT_POSITIVE	(1<<25)

/*
 * Constructed damage types and bitfields for testing
 *
 */
#define DT_BITE		(DT_PIERCE | DT_CRUSH)
#define DT_CLAW		(DT_SLASH)

#endif /* _ATTACK_H */
