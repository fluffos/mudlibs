/*
* Function information room
* Feb 7 '02 by Avelan
*/

#include "defs.h"

inherit ROOM_OBJ;

void setup(){
    set_light(80);
    set_short("function room");
    set_long("set_name() sets the name for the item."
      "  The name of the item is _always_ a one word name."
      "  If you haven't set a short description for the item,"
      " the name will be used as one.  Also a plural of the name"
      " is added automatically so you don't need to add it.\n\n"
      "Syntax:\nset_name(\"name\");\nExample:\nset_name(\"sword\");\n");

    add_exit("back",ITEMSC+"basic_start","path");

} /* setup() */
