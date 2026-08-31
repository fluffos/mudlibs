#include <std.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("helm");
   set_short("%^BOLD%^acrili%^RESET%^te hel%^BOLD%^m%^RESET%^");
   set_long("The helm is made of the rare white metal, acrilite. It has "
     "been shaped to provide protection without hiding the wearer's face. "
     "Horns line the center of the helm, leading down the length of it.");
   set_limbs(({ "head" }));
   set_id(({ "helm", "acrilite helm" }));
   set_weight(13);
   set_ac(2);
   set_type("helmet");
    set_curr_value("gold", 60);
}

int query_auto_load() {
   if (this_player()->query_level() >= 25) return 1;
}
