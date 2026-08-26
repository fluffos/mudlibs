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
    set_long("set_long() sets the long description of the object."
      "  This description is what you will see when you look at it.\n"
      "Example:\nset_long(\"The blade of this sword is crafted with \"\n"
      "\"care, the surface is smooth and polished and the\"\n"
      "\" edge is sharp as a razor.\\n\");\nNote that you should keep"
      " the length of the description somewhat sensible, it's not"
      " nice to look at an object an get a 3 page long description"
      " of it.  But also not descriptions like \"This is a sword.\\n\"\n"); 

    add_exit("back",ITEMSC+"basic_start","path");

} /* setup() */
