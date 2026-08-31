#include <std.h>
#include <zexor.h>
inherit ARMOUR;

create() {
   ::create();
   set_name("armour");
   set_short("%^GREEN%^Bra%^BOLD%^%^WHITE%^m%^RESET%^%^GREEN%^bl%^BOLD%^%^WHITE%^e an%^RESET%^%^GREEN%^d T%^BOLD%^%^WHITE%^h%^RESET%^%^GREEN%^o%^BOLD%^%^WHITE%^rn%^RESET%^ armour");
   set_long("This is a full body armour, which is made up of "
       "intertwining thorns, brambles, and grass");
   set_id(({"armour", "thorns", "bramble and thorn armour", "thorn armour"}));
   set_ac(5);
   set_wear("As you don the armour you recieve cuts, and scrapes of all sizes.");
   set_remove("As the thorns, and brambles pull out of your body "
       "you scream in pain.");
   set_weight(15);
   set_value(145);
   set_type("body armour");
   set_limbs(({"torso", "right arm", "left arm", "left leg", "right leg"}));
}

int query_auto_load() { return 1; }
