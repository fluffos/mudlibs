/*
** File: disjunction.c
** Purpose: Mordenkainen's Disjunction
**    9th level version of dispel magic. Damn...
** Cost: 120 SP
** Credits:
**   26 July 97   Cyanide wrote the file.
*/

#include <magic.h>
#include <m_spells.h>

#define COST 120

inherit SPELL;

// Prototypes...
int cast_disjunction();
int disjunct_living (object, int);
int disjunct_thing(object, int);


int cast_disjunction() {
    object *obs;
    int i;

    if (!environment(TP)) {
	write("Disjunction cannot be cast in the void!\n");
	return 0;
    }

    if (!this_player()->cast_spell(COST)) {
	write(NOT_ENOUGH_SP);
	return 0;
    }

    write("You cast Mordenkainen's Disjunction!\n");
    say(TPN+" casts Mordenkainen's Disjunction!\n"); 

    obs = all_inventory(environment(TP));
    for (i=0; i<sizeof(obs); i++) {  
	if (living(obs[i])) {
	    if (obs[i] != TP) disjunct_living(obs[i], TP->query_level());
	} else {
	    disjunct_thing(obs[i], TP->query_level());
	}
    }
    return 1;
}


// This function handles the disjunction of living objects...

int disjunct_living (object ob, int level) {
    int x;
    object *stuff, thing;

    thing = present("#ANTIMAGIC_SHELL#", ob);

    x = query_caster_level(TP, "wizard");
    if (!check_magic_resist(x,ob,COST,0)) return MAGIC_RESISTANCE;

    if (thing) {
	if (random(100) < this_player()->query_level()) {
	    thing->remove();
	} else {
	    tell_object(ob, "Your anti-magic shell protects you from the "+
	      "disjunction.\n");
	    return 0;
	}
    }

    stuff = all_inventory(ob);

    for (x=0; x<sizeof(stuff); x++) 
	if(!ob->save_throw() || (!stuff[x]->query("short")))  disjunct_thing(stuff[x], level);

}


// This function handles the disjunction of non-living objects.

int disjunct_thing (object ob, int level) {
    int percy = 50, flag = 0; 
    object owner;

    if (!ob->query("enchantment") && !ob->query("magic")
      && !ob->query("bonus") && !ob->query_spell())
	return 0;

    if (!ob->query("short")) {
	ob->remove();
    } else {
	// if (ob->id("wand")) percy -= 30;
	// if (ob->id("staff")) percy -= 40;
	// if (ob->id("potion")) percy -= 60;
	// if (percy == 50) percy -= 60;

	// percy += (level * 5);

	percy = 100;
	if (ob->query("artifact")) percy = level;

	if (random(100) < percy) {
	    owner = environment(ob);
	    if (living(owner)) {
		tell_object(owner, capitalize(ob->query("short"))+
		  " crumbles to dust.\n");
		tell_room(environment(owner), wrap(capitalize(ob->query("short"))+
		    " in "+owner->query("cap_name")+"'s possession crunbles to dust."));
	    } else {
		tell_room(owner, capitalize(ob->query("short"))+
		  " crumbles to dust.\n");
	    }      
	    ob->remove();      
	}
    }
}
string spellcraft() {
    return (@EndSpell
Mordenkainen's Disjunction (Level IX Wizard Spell - Alteration, Enchantment)

Cost: 120 Spell Points

When this spell is cast, all magic and magical items within the
room, except those on the person of the spellcaster, are disjoined.
That is, spells being cast are separated into their individual 
components, usually spoiling the effect as a dispel magic spell does,
and permanent and enchanted magical items must successfully save
or be destroyed.
EndSpell
    );
}

/* EOF */
