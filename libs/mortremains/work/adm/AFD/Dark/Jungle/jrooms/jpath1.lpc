/*
** FILE:    jpath1.c
** DATE:    13 Aug 1996
** PURPOSE: "Jungle Path" - Entrance path to the Jungle area.
** 
**
** CHANGES:
**
** 13 Aug 1996    Gambit    Created the file.
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
  set("short", "Jungle Path");
  set_outside();
  set("long", @ENDLONG
You stand upon a narrow path inside a dense portion of the jungle.  The
path here is surrounded to the east and west by a tangled mass of vines,
trees and other types of colorful foliage.  The moist brown dirt of 
the path is littered with animal tracks of some sort.
ENDLONG
  );
  set("item_desc", ([
  "vines" : "Many thick green vines wind there way through the trees and whatever else\n\
gets in their way.  They make it impossible to walk far from the path.\n",
  "trees" : "The trees are large and imposing with leaves of various shapes and sizes.\n\
They tend to form a patchwork canopy overhead that gives the place a\n\
mysterious yet calming aura.  Wet drops of dew occasionally drip from\n\
the leaves.\n",
"tracks" : "A wide variety of tracks run along the path to the north and south.\n\
This area is obviously widely inhabitant by wildlife!  The largest of the\n\
prints looks almost like a human foot...but not quite...\n",
"path" : "A narrow path winds its way northward through the jungle.  It has\n\
tracks running along it to the north and south.\n",
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
    "north" : ROOMS(jpath2),
   "south" : ROOMS(entrance),
  	        ]) );
  ::create();
}
