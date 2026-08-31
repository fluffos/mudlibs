#include <std.h>
#include <aciri.h>
inherit WEAPON;

void create() {
 ::create();
   set_name("dagger");
   set_short("%^BOLD%^%^BLACK%^A Sh%^RESET%^%^BLUE%^adow dag%^BOLD%^%^BLACK%^ger%^RESET%^");
   set_long("The dagger is made of shadow; the slickest surface possible for "
     "a dagger, allowing the knife to slice into it's opponent with no trouble.");
   set_weight(12);
   set_id(({ "knife", "shadow dagger", "dagger" }));
   set_wc(8);
   set_type("knife");
   set_value(299);
   set("skill level", 25);
}

int query_auto_load() {
   if (this_player()->query_level() >= 30) return 0;
}
