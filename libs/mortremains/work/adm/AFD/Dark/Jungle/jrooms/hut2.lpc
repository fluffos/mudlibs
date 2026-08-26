/*
** FILE:    hut2.c
** DATE:    25 Aug 1996
** PURPOSE: "A Hermit's Hut" -  A hut in the jungle.
** 
**
** CHANGES:
**
** 21 Aug 1996    Gambit    Created the file.
** 18 Sep 1996    Gambit    Finished file.
**
*/


#include <mudlib.h>
#include "../defs.h"

inherit ROOM;


void create() { 
  seteuid(getuid());
  set("author", "Gambit");
  set("light", 1);
  set("short", "Inside a Small Hut");
  set("long", @ENDLONG
You stand inside a small, crude hut.  It is fairly neat, from what you can
see in the dim light coming through the branches that form the walls.
ENDLONG
  );
  set("item_desc", ([
  "trees" : "The trees here seem to form a protective barrier around this small\n\
clearing, lending it shelter from wind and rain.\n",
  "clearing" : "This is a small clearing, with a soft bed of cushion like grass.  The\n\
clearing is about 5 meters in diameter and is completely surrounded by\n\
a protective ring of trees and lush foliage.\n",
  "hut" : "It is a small scraggly old made from branches and vines.  The area\n\
around it is kept fairly clean, so you assume someone must be living\n\
in this shamble!\n",
  ]) );

/*  set("listen", ([
**  "default" : "You can pick nothing unusual out against the background of noise.
**  ",
**  ]) );
*/

  set("exits", ([
    "out" : ROOMS(hut1),
  	        ]) );
  ::create();
}
