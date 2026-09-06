/*
 * "Outdoors", ie. weather description types.
 */
/*
 * HOW TO USE WD TYPES:
 * if (!environment(playerob)->query(ROOM_WD) & WD_OUTDOORS)
 *	playerob -> tell_me("Is under cover.");
 */
 
#ifndef WEATHERDESC_H
#define WEATHERDESC_H

#define WD_NONE         1       /* 1 << 0; */
				/* No weather descriptions for this room.
				   F.Ex. very deep in caves. */
#define WD_INDOORS	2	/* 1 << 1; */
				/* Indoors, for example inside a house. */
#define WD_OUTDOORS	4	/* 1 << 2; */
				/* Outdoors, outside, only sky as a limit. */
#define	WD_CITY	8
#define WD_ALL		7	/* (WD_INDOORS | WD_OUTDOORS | WD_NONE) */
 
#endif
 
