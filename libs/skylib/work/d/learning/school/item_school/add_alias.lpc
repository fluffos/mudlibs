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
    set_long("add_alias() is a function that adds aliases"
      " for the object.  Aliases are alternative names you"
      " can use to handle the object.  This works also with the"
      " add_adjective() function which will add an adjective for"
      " the object.\nExample:\nset_name(\"sword\");\n"
      "set_short(\"blue long sword\");\nadd_alias(\"longsword\");\n"
      "add_adjective(\"blue\");\nadd_adjective(\"long\");\n"
      "Now this object could be handled in many ways, "
      "atleast as blue sword, blue longsword, long sword,"
      "blue long sword, blue longsword, longsword, sword,"
      " long longsword, blue long longsword, long blue"
      " longsword, perhaps others, might have missed some"
      " but i'm sure you get the idea.\n");

    add_exit("back",ITEMSC+"basic_start","path");

} /* setup() */
