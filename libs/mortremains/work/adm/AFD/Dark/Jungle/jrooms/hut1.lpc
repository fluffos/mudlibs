/*
** FILE:    hut1.c
** DATE:    21 Aug 1996
** PURPOSE: "A Clearing" - A Clearing in front of hut in jungle.
** 
**
** CHANGES:
**
** 21 Aug 1996    Gambit    Created the file.
**
**
*/


#include <mudlib.h>
#include "../defs.h"

inherit ROOM;


void create() { 
  seteuid(getuid());
  set("author", "Gambit");
  set("light", 1);
  set("short", "A Small Clearing");
  set_outside();
  set("long", @ENDLONG
Here, surrounded by the dense jungle, is a small clearing of sorts.  To the
south in the clearing sits a small, rickety old hut made from tree branches
and held together by vines.  It is so ragged that you wonder how it
is still standing.  You can only assume that the dense jungle around
the hut protects it from the elements.  There is a small opening
in the side of the hut and a hole in the foliage to the north.
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
    "north" : ROOMS(jpath4),
    "enter" : ROOMS(hut2),
  	        ]) );
  ::create();
}
