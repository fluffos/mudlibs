#include <std.h>
#include <aciri.h>
inherit WEAPON;

void create() {
 ::create();
   set_name("blade");
   set_short("%^BOLD%^%^WHITE%^an %^BLACK%^unholy%^WHITE%^ blade%^RESET%^");
   set_long("The weapon of choice for the Aciri, this blade was forged "
     "of a black steel by dwarven slaves. The blade was enchanted by dark "
     "priests of the Aciri's unholy order and bathed in the blood of the "
     "slain.");
   set_weight(11);
   set_id(({ "unholy blade", "blade" }));
   set_wc(6);
   set_type("blade");
   set_value(194);
}

int query_auto_load() { if (this_player()->query_level() >= 24) return 3; }
