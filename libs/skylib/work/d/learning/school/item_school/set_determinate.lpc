/*
* Function information room
* Feb 7 '02 by Avelan
*/

#include "defs.h"

inherit ROOM_OBJ;

void setup(){
    set_light(80);
    set_short("function room");
    set_long("set_determinate() sets the determinate of"
      " the item.  Note that you don't have to set this if"
      " the correct determinate of the object is 'a' or 'an',"
      " the parser adds these automatically.  Only if you want"
      " the item to have no determinate at all or 'the'"
      " determinate, you need to set it.\nSyntax:\n"
      "set_determinate(\"determinate \");\nNotice the space"
      " after the determinate, it's important.\nExample:\n"
      "set_determinate(\"the \");\n");

    add_exit("back",ITEMSC+"basic_start","path");

} /* setup() */
