/*
* Function information room
* Feb 7 '02 by Avelan
*/

#include "defs.h"
#include <colour.h>

inherit ROOM_OBJ;

void setup(){
    set_light(80);
    set_short("function room");
    set_long("set_short() sets the short description of the"
      " item.  This is what you will see when you for example"
      " check your inventory. It's also used for messages when"
      " you for example pick the items up or drop them.\n"
      "Example:\nset_short(\"silver chainmail\");\nThe short"
      " description should only be a couple of words long."
      "And always in lowercase letters, the parser automatically"
      " add a determinate infront of it if you haven't set one"
      " yourself. More info about that in the set_determinate"
      " room.\n");

    add_exit("back",ITEMSC+"basic_start","path");

} /* setup() */
