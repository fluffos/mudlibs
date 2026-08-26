/*
* Function information room
* Feb 7 '02 by Avelan
*/

#include "defs.h"

inherit ROOM_OBJ;

void setup(){
    set_light(80);
    set_short("function room");
    set_long("set_main_plural() sets the main plural for"
      " the item.  You should only use this if the pluralized"
      " form of the short description the parser makes "
      "isn't correct.Syntax:\nset_main_plural(\"plural\");\n"
      "Example:\nset_main_plural(\"green skirts\");\n"
      "So, remember to only use it if the plural the parser"
      " offers isn't correct.\n");

    add_exit("back",ITEMSC+"basic_start","path");

} /* setup() */
