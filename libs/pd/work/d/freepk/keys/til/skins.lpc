#include <std.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("skins");
   set_short("human skins");
   set_long("An outfit of human skins, crudely sewn together.");
   set_ac(4);
   set_type("armour");
   set_weight(15);
    set_curr_value("gold", 5);
   set_id(({ "skin", "skins", "human skins" }));
}

int query_auto_load() { if (this_player()->query_level() >= 15)
   return 1; }
