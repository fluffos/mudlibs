// Example npc for creator school
// October '01 by Avelan

#include "defs.h"
inherit NPC_OBJ;

void setup(){

    set_name("womble");
    set_short( "funny womble");
    add_adjective( "funny" );
    set_long("A funny but obviously crazy womble with"
      " long whiskers and a grey fur.  Her eyes are"
      " enough to make even the most battle-hardened"
      " warriors think twice before attacking the poor"
      " thing.\n");

    /**
    * There is no such race as womble so i chose dwarf for
    * it since it can hold weapons also.
    */

    basic_setup("dwarf", 10 + random(10), "female");

    adjust_money(100+random(100),choice(({"copper","silver","gold"})));


} /* setup() */





