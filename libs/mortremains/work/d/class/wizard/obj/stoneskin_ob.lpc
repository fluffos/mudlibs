/*
** File:  stoneskin_ob.c
** Purpose: Spell object for 4st-level alteration spell, "stoneskin"
** Duration 50 seconds/level.
** Cost:  30 SP
** Credits:
**   27 Sep 97   Cyanide@Nightfall's Keep write the file.
*/

#include <m_spells.h>              
#include <magic.h>
#include <mudlib.h>

inherit OBJECT;

int hits_left = 0;

void create() {
    seteuid(getuid());
    set("id", ({ "#STONESKIN#", "#REFLEXIVE_SPELL#" }) );
    set("prevent_drop", 1);
    set("dest_at_die", 1);
}

int begin_spell(object caster, int lvl) {

    hits_left = (lvl/2) + (random(4)) + 1;
    set("level", lvl);

    set("enchantment", FAINT);
    set("schools", ({ "alteration" }) );

    tell_object(caster, "You feel your skin harden and transform into solid"+
      " stone.\n");
    tell_room(environment(caster), caster->query("cap_name") +
      "'s skin transforms into solid granite.\n", ({ caster }) );  
    set("extra_look", "$N has the appearance of solid granite.\n");
    caster->add("magical_defense", -100);
    return 1;
}

void init() {
    if (!living(environment())) remove();
}

varargs int reflex(int damage, string type, object ob, int weap) {

    if (hits_left) {
	hits_left--;

	switch(type) {
	case "slashing" : case "piercing" : case "bludgeoning" :
	    tell_object(environment(), "Sparks fly as your stoneskin absorbs "+
	      "the force of the blow!\n");
	    tell_room(environment(environment()), "Sparks fly as "+
	      environment()->query("cap_name")+"'s stoneskin absorbs the force "+
	      "of the blow!\n", ({ environment() }) );
	    damage = 0;
	    break;
	}

	if (!hits_left) remove();
    }

    return damage;
}

int remove() {
    object caster = environment(this_object());

    if ((caster) && living(caster)) {
	tell_object(caster, "Your stoneskin is completely chipped away.\n");
	tell_room(environment(caster), caster->query("cap_name") +
	  "'s stoneskin chips away completely.\n", ({ caster }) );
	caster->add("magical_defense", 100);
    }
    ::remove();
    return 1;
}                                                  

/* EOF */
