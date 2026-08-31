// breatplate
#include <std.h>
#include <rain.h>
inherit ARMOUR;

create() {
   ::create();
   set_short("Gold embroidered breastplate");
   set_long("This is a strong steal breastplate with 2 golden "
            "dragons embroideded into it. The dragons seem to "
            "%^BOLD%^%^YELLOW%^glow%^RESET%^");
   set_name("breastplate");
   set_ac(6);
   set_weight(60);
   set_curr_value("gold", 50);
   set_type("armour");
   set_limbs(({"torso"}));
   set_id(({"breastplate", "plate"}));
   set_wear("You feel power emit from the dragons into yourself.");
}

int query_auto_load() { if(this_player()->query_level() >=15) return 1; } 
