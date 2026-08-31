#include <std.h>
#include <aciri.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("helmet");
   set_short("%^BOLD%^%^WHITE%^helm of force%^RESET%^");
   set_long("This helmet was mystically formed of pure force of creation. "
     "It is semi-translucent and a mirky white colour to the eye. When looked "
     "at closely all the colors of the rainbow can be seen, swirling about.");
   set_weight(20);
   set_id(({ "helm", "helmet", "helm of force" }));
   set_ac(4);
   set_type("helmet");
   set_value(195);
   set_limbs(({ "head" }));
}

int query_auto_load() { if (this_player()->query_level() >= 21) return 3; }
