// This file is part of UNItopia Mudlib.
// ----------------------------------------------------------------
// File:	/sys/game.h
// Description:	Defines fuer Spiele in UNItopia
//
// $Log: game.h,v $
// Revision 1.3  2001/03/14 20:32:37  freaky
// CVS-log eingebaut.
//

#ifndef GAME_H
#define GAME_H 1

#define GAME_ROOM "/room/rathaus/raetsel"
#define G_AUTH_NAME "spiele"

#define G_ALL		0x01
#define G_NOT_NECESSARY	0x02
#define G_NECESSARY	0x04
#define G_TEST		0x08

#define G_SOLVED	-1
#define G_NOT_INSTALLED -1

#define G_NAME		0
#define G_OBJ		1
#define G_PROGRAMMERS	2
#define G_PARAMETERS	3
#define G_REMARKS	4
#define G_CAP_NAME      5

// Flags
#define GF_TEST		0x01
#define GF_REQUIRED	0x02
#define GF_RENOVATE	0x04

// Parameters
#define GP_FLAGS	0

#endif // GAME_H
