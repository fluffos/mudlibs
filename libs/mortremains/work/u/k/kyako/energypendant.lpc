// A standard piece of armor, heavily commented to explain what all the
// properties are.
// Created by Mobydick@TMI-2, 9-30-92

#include <mudlib.h>

inherit ARMOR ;

void create() {
       set ("id", ({ "amulet","pendant" }) ) ;
        set ("short", "pendant of protection") ;
        set ("long", "A powerful defensive spell is held within.\n") ;
        set ("bulk", 1) ;
        set ("mass", 1) ;
        set("size", -1);
        set_armor_type("amulet") ;
	set("bonus", 4);
set("value",   4000);
}

void init() {
add_action("activate", "activate");
}

int activate() {
  TP -> set("theurgy_points", TP -> query("max_tp"));
  return 1;
}
