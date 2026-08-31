#include <std.h>
#include <aciri.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("helmet");
   set_short("a horned helm");
   set_long("The helmet is made of a thick and hard grey substance. "
     "Outlining the helmet are long, wicked horns. The horns look "
     "almost like those of a demon.");
   set_weight(18);
   set_id(({ "helm", "helmet", "horned helm" }));
   set_ac(6);
   set_type("helmet");
   set_value(295);
   set_limbs(({ "head" }));
}

int query_auto_load() { if (this_player()->query_level() >= 25) return 3; }
