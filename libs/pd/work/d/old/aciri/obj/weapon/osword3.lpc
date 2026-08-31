#include <std.h>
#include <aciri.h>
inherit WEAPON;

void create() {
 ::create();
   set_name("sword");
   set_short("a master orcish sword");
   set_long("The orcish blade was made by orcs using ancient dwarven "
     "forge secrets. Although a dwarven smith using the same techniques "
     "would have produced a deadly weapon, almost unmatched by any "
     "other, the orcish smith forged a weapon slightly better than "
     "average blade. This is a master orcish blade.");
   set_weight(18);
   set_id(({ "sword", "master orcish sword", "orcish sword",
             "blade" }));
   set_wc(9);
   set_type("blade");
   set_value(350);
}

int query_auto_load() {
   if (this_player()->query_level() >= 25) return 1;
}
