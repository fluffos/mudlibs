/*
 * TLBB MUDLIB
 * $Header: /home/mud/cvsroot/tlbbmud/tlbb/tlbb_mudlib/include/std_room.h,v 1.1 2000/03/05 17:53:59 mud Exp $
 */
 
// std_room.h
// Created by cbra Jun-20-1998

#ifndef __STD_ROOM__
#define __STD_ROOM__

// for climate
#define	IN_DOOR		0	// default is indoor	
#define	OUT_DOOR	1
#define	MOUNTAIN	2
#define	SEA		4
#define	VALLEY		8

// light
#define	SIGHT_BLIND	1	// no see at all	
#define	SIGHT_TOO_DARK	2
#define SIGHT_DARK	4
#define	SIGHT_DIM	8
#define	SIGHT_CLEAR	16
#define	SIGHT_LIGHT	32
#define	SIGHT_BRIGHT	64
#define	SIGHT_TOO_BRIGHT	128	// to brigh to see

// invalid_combat

#define	NO_FIGHT	1
#define NO_MAGIC	2
#define	NO_STEAL	4
#define	NO_USER		8
#define	NO_EXERT	16
#define	NO_DEAD		32

#endif
