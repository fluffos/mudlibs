
#include <std.h>
inherit ARMOUR;

void create() {
   ::create();
   set_name("pauldron");
   set_id( ({ "pauldron" }) );
   set_short("Kythos Pauldron");
   set_long(
     "A simple pauldron made of the fae-metal, kythos. "
     "It extends from the shoulder to the elbow and down the "
     "side of the torso for minimal, but helpful defense. "
     "The pauldron is worn usually on the arm most engaged in combat. "
   );
   set_ac(3);
   set_mass(15);
   set_curr_value("gold", 25);
   set_type("bracers");
   set_limbs( ({ "right arm","torso" }) );
}

int query_auto_load() {
   if(this_player()->query_level() >= 10)
   return 1;
}

