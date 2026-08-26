// Minauros.  Originally coded (badly) by Ilzarion.
// Completely redone by Cyanide (correctly).

#include <mudlib.h>

inherit MONSTER ;

void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Minauros, the Viscount of the 3rd Layer of Baator") ;
    set ("long", wrap("Minauros the Serpent dwells in the "+
	"Sinking City, his bulk writhing and spasming through "+
	"the fetid water of his layer. He appears as a "+
	"gargantuan snake with a humanoid torso where the head "+
	"would be. His eyes are slitted and yellow, his tongue is"+
	"forked, and he speaks in a sibilant whisper.") );
    set ("id", ({ "minauros", "lord", "baatezu"}) ) ;
    set_name ("minauros") ;
    set ("gender", "male") ;
    set ("race", "baatezu");
    set("author", "cyanide");
    enable_commands() ;
    set_living_name("minauros") ;
    set ("stat", ([
      "constitution" : 21,
      "strength" : 19,
      "charisma" : 18,
      "intelligence" : 21,
      "dexterity" : 23,
      "wisdom" : 19,
    ]) );
    set_size(30);
    credit(8500 + random(4000));
    set ("base_ac", 5);
    set ("armor_class", 5);
    set ("damage", ({ 4,12 }) ) ;
    set ("weapon_name", "claws") ;
    set ("CLASS", "warrior");
    set ("weap_resist", 4);
    set ("magic_resist", 80);
    set ("resist_type", ([ "cold" : 50, "poison" : 0, "fire" : 0 ]) );
    set ("special", 18);
    set_verbs( ({ "slash at", "swing at", "swipe at" }) ) ;
    set_skill("Unarmed", 5, "strength");
    set("prevent_summon", 1);
    set_level(64);
}

void special_attack() {
    object ob;

    ob = this_object()->query_current_attacker();

    if (query_hit(ob) && 
        ob->receive_damage(random(8)+15, "piercing", TO, 1)) {    
    	tell_object(ob, "Minauros sinks his gaping jaws into you, "+
    	  "filling the wounds \nwith poison!\n");
    	say("Minauros sinks his gaping jaws into "+
    	  ob->query("cap_name")+". filling the \nwounds "+
    	  "with poison!\n", ({ ob }) );

    	if (!ob->save_throw())
    	    ob->receive_damage(random(50)+101, "poison");
    } else {    
    	tell_object(ob, "Minauros misses you with his massive jaws.\n");
    	say("Minauros misses "+ob->query("cap_name")+
    	  " with his massive jaws!\n", ({ ob }));
    }
}

/* EOF */
