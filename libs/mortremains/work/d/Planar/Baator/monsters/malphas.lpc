// By Ilzarion.

#include "baator.h"
#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Malphas") ;
    set ("long", wrap("Duke of Bel, leader of companies of "+
	"abishai. A powerful, dark-complexioned man dressed "+
	"in black velvet, studded with gems."));
    set ("id", ({ "malphas", "duke", "baatezu"}) ) ;
    set_size(6);
    set_name ("malphas") ;
    set ("gender", "male") ;
    set ("race", "baatezu");
    enable_commands() ;
    set_align("le");
    set_living_name("malphas") ;
    set("stat", ([
      "constitution" : 22,
      "strength" : 25,
      "charisma" : 20,
      "intelligence" : 18,
      "dexterity" : 20,
      "wisdom" : 15
    ]) );
    set ("base_ac", -3);
    set ("armor_class", -3);
    set ("damage", ({ 5,15 }) ) ;
    set ("weapon_name", "claws") ;
    set ("CLASS", "warrior");
    set ("class", "fighter");
    set ("weap_resist", 2);
    set ("magic_resist", 70);
    set ("resist_type", ([ "cold" : 50, "poison" : 0, "fire" : 0 ]) );
    set_skill("Long Blades", 5, "Strength") ;
    set_skill("One Weapon Style", 2, "Strength") ;
    set_skill("Ambidexterity", 1, "Strength") ;
    // arm(BAATOR+"items/malrobes") ;
    set_verbs( ({ "poke at", "swing at", "swipe at" }) ) ;
    set("prevent_summon", 1);
    set_level(20);
    arm(BAATOR+"items/flameblade") ;
}

/* EOF */
