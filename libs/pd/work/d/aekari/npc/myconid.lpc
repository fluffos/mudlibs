
#include <std.h>
inherit MONSTER;

void create() {
   ::create();
   set_name("myconid");
   set_id( ({ "myconid","fungus","mushroom","shroom" }) );
   set_short("Myconid");
   set_long(
     "An apparently very happy mushroom-creature, it hops around and glows from time to time. Like most subterrainean fungi, they live in darkness and dank. There must be water here somewhere. "
   );
   set_overall_ac(5);
   set_gender("neuter");
   set_level(14);
   set_class("fighter");
   set_spell_chance(8);
   set_spells( ({ "jab" }) );
   set_stats("strength", 30);
   set_stats("constitution", 30);
   set_stats("dexterity", 15);
   set_skill("defense", 75);
   set_skill("melee", 75);
   set_hp(420);
   set_max_hp(420);
   set_race("myconid");
   add_limb("right arm","", 60, 0, 5);
   add_limb("left arm","", 60, 0, 5);
   add_limb("right root","", 60, 0, 5);
   add_limb("left root","", 60, 0, 5);
   add_limb("cap","FATAL", 265, 0, 7);
   add_limb("stalk","FATAL", 265, 0, 7);
   set_emotes(3, ({"Myconid spins around playfully.",
     "Myconid hops around.",
     "%^BOLD%^%^GREEN%^Myconid glows bright green for a moment.%^RESET%^"
   }), 0);
   set_emotes(5, ({"Myconid releases a cloud of spores.",
     "Myconid spins at you." }), 1);
   //set_exp(12000);
}


