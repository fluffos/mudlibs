/*
** FILE:    jpath4.c
** DATE:    21 Aug 1996
** PURPOSE: "Jungle Path" - Eastern path to the Jungle Basin.
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
  set("short", "East Jungle Path");
  set_outside();
  set("long", @ENDLONG
The path here doesn't seem to be traveled much, although there are still 
occasional tracks to be found.  Funny, not many of them seem to be headed
to the west, as if those who travel to the east do not return.  The sky to
the north seems to be much darker than the surrounding area, as if a  
relentless aura of despair has taken hold of the region.  There seems
to be a small opening in the foliage to the south.
ENDLONG
  );
  set("item_desc", ([
  "trees" : "The trees are large and imposing with leaves of various shapes and sizes.\n\
Small, colorful birds fly back and forth in the treetops and drops of wet\n\
dew occasionally fall from the leaves.\n",
  "tracks" : "The tracks are sparse and covered up pretty well, as if they were\n\
fairly old or someone took plenty of time to cover them up.  They appear\n\
to be humanoid in nature.  You notice one or two seem to be headed in\n\
the direction of the opening to the south.\n",
  "path" : "There is a narrow path here running to the east and west.\n",
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
    "east" : ROOMS(jpath5),
    "south" : ROOMS(hut1),
    "west" : ROOMS(jpath3),
  	        ]) );
  ::create();
}
