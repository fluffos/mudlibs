#include <std.h>
#include <aciri.h>
inherit WEAPON;

void create() {
 ::create();
   set_name("dagger");
   set_short("%^RESET%^%^BLUE%^Sh%^BOLD%^%^BLACK%^adow Sta%^RESET%^%^BLUE%^ff%^RESET%^");
   set_long("A long, glossy hard staff of condensed shadows. The staff is as "
     "hard as any metal, but very heavy.");
   set_weight(22);
   set_id(({ "staff", "shadow staff" }));
   set_wc(9);
   set_type("blunt");
   set_value(330);
   set("skill level", 25);
}

int query_auto_load() {
   if (this_player()->query_level() >= 30) return 0;
}
