#include <std.h>
#include <aciri.h>
inherit WEAPON;

void create() {
 ::create();
   set_name("tuck");
   set_short("a slender bladed tuck");
   set_long("The sword's short, slender blade is much like that of a "
     "rapier's, save the tuck has both edges of the blade sharpened, "
     "not only the point.");
   set_weight(8);
   set_id(({ "tuck", "sword" }));
   set_wc(7);
   set_type("blade");
   set_value(100);
}

int query_auto_load() {
   if (this_player()->query_level() >= 19) return 0;
}
