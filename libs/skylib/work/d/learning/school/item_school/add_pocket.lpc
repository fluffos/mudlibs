/*
* Function information room
* Feb 7 '02 by Avelan
*/

#include "defs.h"

inherit ROOM_OBJ;

void setup(){
    set_light(80);
    set_short("function room");
    set_long("add_pocket() adds a pocket to the"
      " item.  The string is the pockets name, 'side'"
      " in this case and the value determines how much"
      " the pocket can hold.\nSyntax:\nadd_pocket("
      "\"name\",value);\nExample:\nadd_pocket(\"side\","
      "20);\n");

    add_exit("back",ITEMSC+"clo_start","path");

} /* setup() */
