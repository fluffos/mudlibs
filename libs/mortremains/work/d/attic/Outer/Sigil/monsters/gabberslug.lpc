
// A generic monster.
// Comments on monster properties are found in /obj/foobird.c

#include <mudlib.h>
#include "../sigil.h"
inherit MONSTER ;


void create () {
    ::create() ;
    seteuid(getuid()) ;
    set ("short", "Judge Gabberslug") ;
    set ("long", "A Fat, Bloated Demon of the abyss.\n") ;
    set ("id", ({ "judge", "gabberslug", "tanar'i" }) ) ;
    set ("bulk", 250) ;
    set_name ("gabberslug") ;
    set ("race", "tanar'i");
    set ("gender", "male") ;
    enable_commands() ;
    set_living_name("gabberslug") ;
    set("resist_type",([ "cold":50, "fire":50, "poison":0, "electricity":0]));
    set("weap_resist", 2);
    set("magic_resist", 70);
    set ("stat/constitution", 20);
    set ("stat/strength", 20);
    set ("stat/charisma",8);
    set ("stat/intelligence", 15);
    set ("stat/dexterity", 13);
    set ("stat/wisdom", 14);
    set ("special", 2);
    set ("base_ac", -8);
    set ("armor_class", -8);
    set("natt", 3);
    set("damage_type", "slashing");
    set("CLASS", "warrior");
    set ("damage", ({ 1,4 }) ) ;
    set ("weapon_name", "claws") ;
    set_verbs( ({ "rip", "slash at", "swipe at" }) ) ;
    arm(SIGIL+"items/holdingbag", "an") ;
    set_level(11);
    set_size(10);
}

void special_attack() {
    //this is the spell function for raw excessive damage
    object ob, target;
    string  they_see, name;
    int sv, x, obj; 
    if (this_object()->query("cast_delay")) return 0;

    if (random(20) > 4) return 0;
    target = TP->query_current_attacker();


    write("You begin casting Color Spray...\n");
    say("Gabberslug begins uttering arcane words...\n");

    tell_room(environment(this_object()), wrap("A vivid spray of clashing colors"+
	" springs forth from Gabberslug toward "+
	target->query("cap_name")+"!"), ({ this_object(), target }) );

    tell_object(target, "A vivid spray of clashing colors springs "+
      "forth from Gabberslug toward you!\n");
    x=0;
    // x = query_save_mod(TP,target, ({"evocation"}) );
    x = target->save_throw(x);               // Roll a saving throw
    if (target->query_level() < 6) x = 0;    // No save if <6 HD/lvls.
    if (target->query("blind")) x = 1;       // Blind are immune.

    if (x) {
	if (target->query_skill("Evasion")) {
	    tell_room(environment(target), target->query("cap_name")+
	      " nimbly dodges the color spray!\n", ({ this_object(), target }) );
	    tell_object(target, "You manage to dodge the color spray!!\n");
	    write(target->query("cap_name")+" nimbly dodges the color spray!\n");
	    return 0;
	}

	tell_room(environment(target), target->query("cap_name")+" averts "+
	  possessive(target->query("gender"))+" eyes.\n", ({ target }) );
	tell_object(target, "You manage to avert your eyes!\n");
	return 0;
    } else {

	target->set("last_attacker", this_object());
	target->kill_ob(this_object());
	they_see = name+" is struck in the eyes by the color spray ";
	name = "You are struck in the eyes by the color spray ";
	obj = 11;
	obj = obj - target->query_level();

	switch(obj) {
	case -200..-3 :
	    they_see += "and is stunned!";
	    name += "and are stunned!";
	    target->set("stunned", 3);
	    break;
	case -2..-1 :
	    they_see += "and is blinded!";
	    name += "and are blinded!";
	    target->set("blind", random(5)+1);
	    break;
	default :
	    they_see += "and is struck unconscious!";
	    name += "and are stuck unconscious!";
	    target->set("rest", 3);
	    break;
	}

	tell_room(environment(target), wrap(they_see), ({ target }) );
	tell_object(target, wrap(name));
	target->kill_ob(this_object());
    }
}
