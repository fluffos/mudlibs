/*
** FILE:    jpath3.c
** DATE:    20 Aug 1996
** PURPOSE: "Jungle Path" - Entrance path to the Jungle area.
** 
**
** CHANGES:
**
** 20 Aug 1996    Gambit    Created the file.
**
**
*/


#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

object mon1, mon2, mon3;

void create() { 
  seteuid(getuid());
  set("author", "Gambit");
  set("light", 1);
  set("short", "Jungle Path");
  set_outside();
  set("long", @ENDLONG
The path forms a "T" type intersection here, with exits leaving to the east,
west and south.  Larger prints cover the ground here, obviously made by
something that walks on two legs.  The jungle becomes extremely dense to
the north, making it impossible to pass in that direction!
ENDLONG
  );
  set("item_desc", ([
  "trees" : "The trees are large and imposing with leaves of various shapes and sizes.\n\
Small, colorful birds fly back and forth in the treetops and drops of wet\n\
dew occasionally fall from the leaves.\n",
   "tracks" : "The tracks are predominantly of the large variety here, and obviously made\n\
by and animal that walks upright.\n",
  "path" : "The path continues to the east, west, and south here.\n",
		]) );
/*  set("smell", ([
**  "path" : "A narrow path.\n",
**  ]) );

*/
/*  set("listen", ([
**  "default" : "You can pick nothing unusual out against the background of noise.
**  ",
**  ]) );
*/

  set("exits", ([
    "east" : ROOMS(jpath4),
    "west" : ROOMS(jpath),
   "south" : ROOMS(jpath2),
  	        ]) );
  ::create();
}

void reset() {
  if (!mon1) {  mon1=clone_object(MON(gor_baby));
     mon1->move(this_object());
  }
  if (!mon2) { mon2 = clone_object(MON(gor_baby2));
   mon2->move(this_object());
}
  if (!mon3) {  mon3=clone_object(MON(gor_mother));
    mon3->move(this_object());
}
}
