#include <std.h>
#include <aciri.h>
inherit WEAPON;

void create() {
 ::create();
   set_name("saber");
   set_short("a saber");
   set_long("The short saber is the size of a dagger. It's sharp "
     "and shiney blade is used to encourage troops and strike fear "
     "into the enemy.");
   set_weight(7);
   set_id(({ "saber" }));
   set_wc(6);
   set_type("knife");
   set_value(120);
}

int query_auto_load() {
   if (this_player()->query_level() >= 19) return 0;
}
