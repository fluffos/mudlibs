// Cyanide fixed this, 21 Nov 98.

#include <mudlib.h>
inherit MONSTER ;

void create () {
    object ob1;
             
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "amnizu") ;
    set ("long", @EndLong
The amnizu looks like a short human with and elongated, bald head, stubby
legs and arms, and large, leathery wings. The fiend has a pug nose, large
eyes and a snarling mouth filled with jagged, razor-sharp teeth. 
EndLong
    );
    set ("id", ({ "amnizu", "baatezu" }) ) ;
    set("stat", ([
      "strength" : 18,
      "constitution" : 16,
      "dexterity" : 15,
      "intelligence" : 16,
      "wisdom" : 16,
      "charisma" : 4
    ]) );
    set_align("le");
    set_size(4);
    set_name ("amnizu") ;
    set ("race", "baatezu");
    set ("gender", "male") ;
    enable_commands() ;
    set_living_name("amnizu") ;
    set("resist_type",([ "cold":50, "fire":0, "poison":0]));
    set("magic_resist", 50);
    set("weap_resist", 2);
    set ("base_ac", -1);
    set ("armor_class", -1);
    set("CLASS", "wizard");
    set("mage_spells", ({ "bolt", "wilting", "fireball" }) );
    set("max_sp", 250);
    set ("spell_points", 250);
    set ("damage", ({ 2,8 }) ) ;
    set("damage_type", "force");
    set ("weapon_name", "energy touch") ;
    set_verbs( ({ "touch", "point at", "swipe at" }) ) ;
    set ("special", 5);

    ob1 = clone_object ("/d/class/wizard/general/obj/book") ;
    ob1 -> move (this_object()) ;
    ob1 -> set("invisible", 2);

    set_level(9);

    credit( query("hit_points") / 2 ); 
}


void special_attack() {
    //this is the spell function for raw excessive damage

    string *spells = query("mage_spells");

    if (this_object()->query("cast_delay")) {
	return 0;
    }else{	 
	command("cast "+
	  spells[ random(sizeof(spells)) ]
	);
    }
}

/* EOF */
