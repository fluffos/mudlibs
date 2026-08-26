
#include <mudlib.h>
#include "baator.h"

inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Levistus, the Prince of Stygia") ;
    set ("long", wrap("Levistus is a darkly handsome, brooding "+
	"man dressed in fancy clothes and adorned with finery.") );
    set("author", "ilzarion");
    set ("id", ({ "levistus", "lord", "baatezu"}) ) ;
    set_name ("levistus") ;
    set ("gender", "male") ;
    set ("race", "baatezu");
    enable_commands() ;
    set("prevent_summon", 1);
    set_living_name("levistus") ;
    set ("stat/constitution", 16);
    set ("stat/strength", 19);
    set ("stat/charisma", 21);
    set ("stat/intelligence", 23);
    set ("stat/dexterity", 24);
    set("prevent_summon", 1);
    credit(10000);
    set ("stat/wisdom", 22);
    set_size(7);
    set ("base_ac", 4);
    set ("armor_class", 4);
    set ("damage", ({ 1,4 }) ) ;
    set ("weapon_name", "fists") ;
    set ("CLASS", "rogue");
    set ("weap_resist", 4);
    set ("magic_resist", 80);
    set_skill("Short Blades", 3, "Strength");
    set_skill("One Weapon Style", 2, "Strength");
    set ("resist_type", ([ "cold" : 2, "poison" : 2, "fire" : 2 ]) );
    set_verbs( ({ "slash at", "swing at", "swipe at" }) ) ;
    set_level(46);
    wear("/d/class/rogue/std/obj/belt") ;
    arm(BAATOR+"items/woundsword") ;
}

void init(){
    ::init();
    command ("Hide");
    command ("backstab "+TP->query("name") );
}

/* EOF */
