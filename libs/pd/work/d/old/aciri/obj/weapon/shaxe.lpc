#include <std.h>
#include <aciri.h>
inherit WEAPON;

void create() {
 ::create();
   set_name("axe");
   set_short("%^RESET%^%^BLUE%^S%^BOLD%^%^BLACK%^hadow Ax%^RESET%^%^BLUE%^e%^RESET%^");
   set_long("The axe is made and coated in shadows of evil. The shadow axe's "
     "blade provides for a deadly clean cut. The now magically solidified "
     "shadow axe is strangely heavy for shadows.");
   set_weight(17);
   set_id(({ "fangs" }));
   set_wc(7);
   set_type("axe");
   set_value(325);
   set("skill level", 24);
}

int query_auto_load() {
   if (this_player()->query_level() >= 30) return 0;
}
