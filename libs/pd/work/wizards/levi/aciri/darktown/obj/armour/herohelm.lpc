#include <std.h>
#include <aciri.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("helmet");
   set_short("%^BOLD%^%^WHITE%^a %^BLACK%^dark%^WHITE%^ silver helmet");
   set_long("The helmet comes around your forehead like a headband, than along "
     "the side of your face, down to the chin. It is made out of a dark greyish "
     "silver.");
   set_weight(23);
   set_id(({ "helm", "helmet", "silver helmet" }));
   set_ac(7);
   set_type("helmet");
   set_value(301);
   set_limbs(({ "head" }));
}

int query_auto_load() { if (this_player()->query_level() >= 30) return 3; }
