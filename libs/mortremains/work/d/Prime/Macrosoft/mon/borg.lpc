/*
** FILE: borg.c
** PURPOSE: The primary monster on floor 6 of the Macrosoft 
**      Building. They act like ST-TNG borg, becoming resistant to 
**      attack types after a couple of exposures, and assimilating 
**      players they defeat in combat.
** CREDITS/CHANGES:
**  23 Aug 1999     Cyanide's depraved mind created this file.
*/

#include "/u/c/cyanide/debug.h"
#include "macrosoft.h"

#define THRESHHOLD 2

inherit MONSTER;

object msd;

object find_msd();

void create() {
    ::create();

    seteuid(getuid());
    find_msd();

    set("prevent_summon", 1);
    set("author", "cyanide");
    set("last_dam", "");
    set("damage", ({ 8, 15 }) );
    set("short", "a borg drone");
    set("long", @Assimilated
This appears to have once been a perfectly normal person, but has since
had most of its body replaced. It has artificial limbs, sensory 
enhancements, and many items of unknown purpose.
Assimilated
    );
    set("race", "borg");
    set("gender", "neuter");
    set_name("borg drone");
    set("id", ({ "borg", "drone" }) );
    set("weapon_name", "steel claw");
    set_verbs( ({ "slash at" }) );
    set_skill("Unarmed", 3, "strength");

    // I like to think their stats are enhanced with borg technology.
    set("stat", ([
      "strength" : 18,
      "constitution" : 18,
      "dexterity" : 18
    ]) );

    set("chat_chance", 10);
    set("chat_output", ({   
      "The borg says [to you]: Resistance is futile.\n",
      "The borg says [to you]: You will be assimilated.\n",
    }));
    set("att_chat_output", ({
      "The borg says [to you]: Resistance is futile.\n",
      "The borg says [to you]: You will be assimilated.\n",
    }));

    set("special", 2);
    // Make a query xpv function, which calls the normal xpv
    // calc dynamically, so the xpv isn't fixed at the create.

    set_level(12);
    credit( query("max_hp") / 2 );
}


varargs int receive_damage( int damage, string type, object camel, int weap) {
    object *allhere, here;
    string msg;
    mapping damages = find_msd()->query_resistance();


    if ( (!weap) && ((int)damages[type] >= THRESHHOLD) ) {
	switch(type) {
	case "fire" : case "cold" : 
	    msg = "The borg's sensitive systems have "+
	    "been insulated against the temperature extreme."; 
	    break;

	case "force" : msg = "A force shield surrounding the "+
	    "borg absorbs the effect.";
	    break;

	case "acid" : msg = "The borg's exoskeleton secretes a "+
	    "basic solution, protecting it from the acid."; 
	    break;

	case "necromancy" : msg = "The borg seems to have activated "+
	    "some kind of positive-energy field!";
	    break;

	case "slashing" : case "piercing" : case "bludgeoning" :
	    msg = "Some kind of inertia field absorbs the blow!";
	    break;

	default : 
	    msg = "The borg seems to have developed resistance to that!";
	    break;
	}

	damage = 0;
	message("combat", wrap(msg), all_inventory( environment(TO) ) );
    } else {
	set("last_dam", type);
	damage = ::receive_damage(damage, type, camel, weap);
    }

    return damage;
}

void die() {
    object *borg;

    if (find_msd()) {    
	msd->add_resistance(query("last_dam"));
    }

    ::die();
}

object find_msd() {
    if (msd) return msd;

    else msd = find_object_or_load(MS_D);

    if (msd) return msd;
    else return 0;
}


/* EOF is irrelevant, you will be assimilated */
