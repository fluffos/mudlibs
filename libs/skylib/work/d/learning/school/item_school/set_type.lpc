/*
* Function information room
* Feb 7 '02 by Avelan
*/

#include "defs.h"

inherit ROOM_OBJ;

void setup(){
    set_light(80);
    set_short("function room");
    set_long("set_type() is a function needed by armours and"
      " clothing items.  You can see a list of all the valid"
      " types by typing:\n 'exec return keys(CLOTHING_H->query_all"
      "_clothing_types());'\nSyntax: set_type(type);\nExample:\n"
      "set_type(\"byrnie\");\n");

    add_exit("back",ITEMSC+"basic_start","path");

} /* setup() */
