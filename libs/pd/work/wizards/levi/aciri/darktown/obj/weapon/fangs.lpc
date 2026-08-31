#include <std.h>
#include <aciri.h>
inherit WEAPON;

void create() {
 ::create();
   set_name("fangs");
   set_short("%^BOLD%^%^BLACK%^sn%^WHITE%^ak%^RESET%^e %^BOLD%^%^BLACK%^fa%^WHITE%^ng%^RESET%^s");
   set_long("Sharp, curved snake fangs. They may have been deadly at one time, "
     "but the poison has dried up. Though they have no poison in them, the fangs "
     "can still be used as a knife.");
   set_weight(7);
   set_id(({ "fangs" }));
   set_wc(5);
   set_type("knife");
   set_value(125);
   set("skill level", 30);
}

int query_auto_load() {
   if (this_player()->query_level() >= 18) return 0;
}
