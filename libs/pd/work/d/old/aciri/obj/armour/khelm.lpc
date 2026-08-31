#include <std.h>
#include <aciri.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("helmet");
   set_short("a knight's helm");
   set_long("The helmet was built like a gladiator's helmet, but this "
     "one is far too thin to withstand that sort of punishment. The "
     "helm was made to fit a human head.");
   set_weight(10);
   set_id(({ "helmet", "knights helmet", "helm", "knights helm" }));
   set_ac(3);
   set_type("helmet");
   set_value(130);
   set_limbs(({ "head" }));
}

int query_auto_load() { if (this_player()->query_level() >= 12) return 3; }
