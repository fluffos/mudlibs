/*
** FILE:    jpath2.c
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
the path is littered with animal tracks of some sort.  You notice some
sort of commotion and movement further to the north and the path
seems to end in that direction.
ENDLONG
  );
  set("item_desc", ([
  "vines" : "Many thick green vines wind there way through the trees and whatever else\n\
gets in their way.  They make it impossible to walk far from the path.\n",
  "trees" : "The trees are large and imposing with leaves of various shapes and sizes.\n\
Small, colorful birds fly back and forth in the treetops and drops of wet\n\
dew occasionally fall from the leaves.\n",
  "tracks" : "The tracks have obviously been made by some sort of animal, but what type\n\
you can't quite figure out.  Some of them are fairly large though and you\n\
wonder whether you really want to meet the animal in person!\n",
"path" : "A narrow path winds its way north and south through the jungle.  It seems\n\
to have been formed by the roamings of the wildlife in the area.\n",
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
    "north" : ROOMS(jpath3),
   "south" : ROOMS(jpath1),
  	        ]) );
  ::create();
}
