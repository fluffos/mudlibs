
/*
 *  This is the first part of the standard include file of the
 *  Nightfall Flightdragon Airways (C) Randyandy@Nightfall 1992
 *  You must also include plane.h . Look at a dragon.c for correct
 *  including.
 */

#include <properties.h>
#include <moving.h>
#define PRIZE 100 
#define MOVE_PLAYER(str1, str2) \
  this_player()->move(str2, M_GO, str1); \
  return 1
inherit "/std/container/restrictions";
inherit "/std/thing/description";
inherit "std/room";   /* The Dragon is a room with env */
inherit "/std/thing/moving";
inherit "lib/money";
string stationnames;
int numstations;

int doors_open;
int stationnr, maxstation;
int state;
string station, name, alias, long, intlong, signtext;
#ifndef SPEED
#define SPEED 20
#endif

