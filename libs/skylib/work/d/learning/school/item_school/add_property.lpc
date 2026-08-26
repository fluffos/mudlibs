/*
* Function information room
* Feb 7 '02 by Avelan
*/

#include "defs.h"

inherit ROOM_OBJ;

void setup(){
    set_light(80);
    set_short("function room");
    set_long("add_property() is a function that is used widely"
      " but in this case, the add_property(\"group object\",1);"
      " tells the parser whether or not the object is a group "
      "object, ie. if it should be handled with 'is' or 'are' and"
      " 'it' or 'them', so the condition message when looking at"
      " a group object might say 'They are a complete wreck.' instead"
      " of 'It is a complete wreck.'\nNote that you should only use"
      " this property if the object is a group object.\n");

    add_exit("back",ITEMSC+"basic_start","path");

} /* setup() */
