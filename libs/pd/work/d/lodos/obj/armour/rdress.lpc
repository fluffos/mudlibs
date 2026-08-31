#include <std.h>
inherit ARMOUR;

void create() {
 ::create();
   set_name("dress");
   set_short("a ruby red dress");
   set_id(({ "dress", "ruby red dress" }));
   set_long("The luxurious ruby red dress has been specially "
     "tailored for someone with money, by the shape and size of "
     "the dress, pretty good looking, too. Rubys have been hemmed "
     "into the collar of the dress, almost like a necklace.");
   set_weight(3);
    set_curr_value("gold", 25);
   set_type("dress");
   set_limbs(({ "torso" }));
   set_ac(1);
}

 int query_auto_load() { if (this_player()->query_gender() == "female") return 1; }
