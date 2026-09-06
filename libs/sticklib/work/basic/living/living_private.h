#ifndef _LIVING_PRIVATE_H
#define _LIVING_PRIVATE_H

#define	F_LIV_UNDEAD		(1 << 0)
#define	F_LIV_JUST_MOVED	(1 << 1)
#define	F_LIV_IS_FLEEING	(1 << 2)
#define	F_LIV_IS_NPC		(1 << 3)
#define	F_LIV_IS_PLAYER		(1 << 4)
#define	F_LIV_SITTING		(1 << 5)
#define	F_LIV_RESTING		(1 << 6)
#define	F_LIV_OK_TO_PK		(1 << 7)
#define	F_LIV_NIGHT		(1 << 8)

#define	LIV_FLAGS		10

#define	_FIRST_LIV_VALUE	1000
#define	_LAST_LIV_VALUE		1999

#define	HPS(i)	(70 + (i) * 10)
#define	SPS(i)	(16 + (i) * 9)
#define	FPS(i,j)	(60 + (i+j) * 9 / 2)

#endif
