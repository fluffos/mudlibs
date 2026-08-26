/*
** FILE:    entrance.c
** DATE:    11 Aug 1996
** PURPOSE: "Jungle Entrance" - Entrance to the Jungle area.
** 
**
** CHANGES:
**
** 11 Aug 1996    Gambit    Created the file.
**
**
*/


#include <mudlib.h>
#include "../defs.h"

inherit ROOM;

void init()
{
    add_action("read","read");
}


void create() { 
  seteuid(getuid());
  set("author", "Gambit");
  set("light", 1);
  set("short", "Jungle Entrance");
  set_outside();
  set("long", @ENDLONG
You stand upon a narrow path just inside the perimeter of a dense jungle.
A soft wind rustles through the trees, vines and various other types of
foliage that adorn the area.  You can hear the faint murmur of a stream in
the distance as well as the sounds of various animals that inhabit this 
colorful and mysterious area.
There is a small sign partially hidden to the side of the path.
ENDLONG
  );
  set("item_desc", ([
  "vines" : "Many thick green vines wind there way through the trees and whatever else\n\
gets in their way.  They make it impossible to walk far from the path.\n",
    "sign" : "And very old small wooden sign is attached to a stake to the side of the\n\
path.  It is very faded and partialy hidden among the foliage but maybe\n\
you should read it!\n",
  "trees" : "The trees are large and imposing with leaves of various shapes and sizes.\n\
They tend to form a patchwork canopy overhead that gives the place a\n\
mysterious yet calming aura.  Wet drops of dew occasionally drip from\n\
the leaves.\n",
"path" : "A narrow path winds its way northward through the jungle.\n"
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
    "north" : ROOMS(jpath1),
    "south" : "/u/g/gambit/workroom"
  	        ]) );
  ::create();
}

int read(string what) {
     if(what == "sign") {
       write("The sign reads:\n\
\n\
Dear visitors:\n\
\n\
    This area is inhabited by some strange and wonderful critters and\n\
can be an exciting place to explore.  However, be warned that those less\n\
experienced adventurers should employ extra caution in this area!\n\
Good luck!\n\
\n\
    The Locals.\n");
      return 1;
}
}
