/*
** File: item.c  (Level 3 wizard alteration spell)
** Cost: 20 SP
** Credits:
**   09 Feb 98   Cyanide created the spell.
*/

#include <m_spells.h>

#define COST 20
#define SYNTAX "Syntax: cast item at <object> <#>\n"

inherit SPELL;

object which_one(string, object);

int cast_item (string str, int obj) {
    object item, target;
    int flag = 1;

    seteuid(getuid());

    if (!str) { 
	write(SYNTAX);
	return 0;
    }

    target = which_one(str, TP);
    if (!target) target = which_one(str, environment(TP));
    if (!target) {
	write("You don't see any \""+str+"\" around!\n"); 
	return 0;
    }

    if (living(target)) {
	write("You cannot cast that at a living thing!\n");
	return 0;
    }

    if (target->query("prevent_get") ||
      target->query("prevent_drop") ) {
	write("The spell has no effect on that item.\n");
	return 1;
    }

    if (!obj) {
	obj = query_caster_level(TP, "wizard");
	if (!cast_spell(TP, COST)) return 0;
    }

    if (target->query("enchanted")) flag = 0;
    if ((int)target->query("mass") > (10 * obj)) flag = 0;
    if (target->query("prevent_get")) flag = 0;

    if (!flag) {
	write("That is not a valid target.\n");
	return 0;
    }

    write("You begin casting Item at "+target->query("short")+"\n");
    say(TPN+" begins weaving a spell over "+target->query("short")
      +"\n");
    item = clone_object(M_OBJ(item_ob));
    if (!item) {
	write("Spell failed. Please notify Cyanide.\n");
	return 0;
    }

    item->begin_spell(TP, target, obj);
    item->move(TP);

    return 1;
}


object which_one (string str, object where) {
    object *stuff, thing = 0;
    int i, index = 1, counter = 0;

    sscanf(str, "%s %d", str, index);
    if (!index) index = 1;

    stuff = all_inventory(where);
    for (i=0; i<sizeof(stuff) && counter > -1; i++) {
	if (stuff[i]->id(str)) {
	    counter++;
	    if (counter == index) {
		thing = stuff[i];
		counter = -1;
	    }
	}
    }

    return thing;
}


string spellcraft() {
    return (@EndCraft
Item (Level III | Wizard | Alteration)

Range: Touch				Cost: 20 SP
Area of Effect: 1 object

	By means of this spell, the wizard is able to shrink one 
nonmagical item (if it is within the size limit) to 1/12 of its
normal size and change its composition to a clothlike one. Objects
changed by an item spell can be returned to normal composition and
size merely by dropping them or by a word of command from the 
original spellcaster. Even a burning fire and its fuel can be shrunk
by this spell.
EndCraft
    );
}

/* EOF */
