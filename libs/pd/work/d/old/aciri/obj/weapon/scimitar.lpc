#include <std.h>
#include <aciri.h>
inherit WEAPON;

void create() {
 ::create();
   set_name("scmitar");
   set_short("a sharp scimitar");
   set_long("The long, curved, shapened blade of the scimitar is always warm "
     "to the touch. You sharpen your finger on the blade. Ouch, that hurt! "
     "The blade and hilt are connected as one piece of metal.");
   set_weight(12);
   set_id(({ "scimitar", "sharp scimitar" }));
   set_wc(7);
   set_type("blade");
   set_value(320);
}

int query_auto_load() {
   if (this_player()->query_level() >= 23) return 0;
}
