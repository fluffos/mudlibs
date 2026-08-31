#include <std.h>
#include <aciri.h>
inherit WEAPON;

void create() {
 ::create();
   set_name("eveningstar");
   set_short("%^RESET%^%^MAGENTA%^Ev%^BOLD%^%^BLACK%^ening St%^RESET%^%^MAGENTA%^ar%^RESET%^");
   set_long("The morning star is made completely of solidified shadow. The "
     "shadowy morning star is gloss and has earned the nickname of the evening "
     "star.");
   set_weight(20);
   set_id(({ "evening star", "star", "eveningstar" }));
   set_wc(9);
   set_type("flail");
   set_value(379);
   set("skill level", 20);
}

int query_auto_load() {
   if (this_player()->query_level() >= 30) return 0;
}
