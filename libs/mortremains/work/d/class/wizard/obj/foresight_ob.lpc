/*
** File: foresight_ob.c (Foresight)
** Purpose: Spell ob for 9th-level mage divination spell.
** Credits:
**   9 Nov 97  Cyanide wrote this spell and the supporting code.
*/

#define FIND find_player("cyanide")
#define DEBUG(x) if (FIND) tell_object(FIND, x)

#include <magic.h>
#include <m_spells.h>
#include <mudlib.h>

inherit OBJECT;

int active=0;
object owner;

void create() {
    set("prevent_drop", 1);
    set("dest_at_die", 1);
}

void init() {
    add_action("change_action", "foresight");
    add_action("dispel", "dispel");
}

void begin_spell (object caster, int lvl) { 
    owner = caster;

    if (!owner) {
	remove();
	return;
    }

    tell_object(caster, wrap("You are bestowed with the gift of "+  
	"foreknowledge. Use 'foresight' to change you pre-determined "+
	"action.") );
    set("id", ({ "#FORESIGHT#" }) );
    set("action", "@@query_action");
    set("enchantment", OVERWHELMING);
    set("schools", ({ "divination" }) );
    set("level", lvl);
    active = 1;
    call_out("remove", 60*lvl);
}

int remove() {
    object ruum = 0, caster = 0;

    caster = environment(this_object());
    if (caster) {
	ruum = environment(caster);

	tell_object(caster, "Your Foresight spell ends.\n");
    }
    return ::remove();
}          

string query_action() {
    owner->run_away();

    return "hp";
}

int dispel(string str) {
    if (!str) return 0;
    if (str=="foresight") {
	write("You choose to end your foresight spell.\n");
	remove();
	return 1;
    }

    return 0;
}

int change_action(string str) {
    if (!str) {
	write("Change your foresight action to what?\n");
	str = "Your current action is: ";
	if (active==1)
	    str += "hp";
	else
	    str += (string)query("action");

	write(wrap(str));
	return 1;
    }

    set("action", str);
    write("You set your foresight to: "+str+"\n");
    active = 2;
    return 1;
}
