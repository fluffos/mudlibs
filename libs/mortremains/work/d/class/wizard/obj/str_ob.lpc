/*
** File: Strength_ob.c
** Purpose: Spell object for 2nd level alteration spell, strength.
** Cost: 12 SP
** Credits:
**    29 Sept 97   Cyanide rewrote the file.
*/

#include <mudlib.h>
#include <m_spells.h>

inherit OBJECT;

int str_change = 0;

void create() {
    set("id", ({ "#STRENGTH_OB#" }) );
    set("extra_look", "$N is a ripped stud mother fucker!.\n");
    set("dest_at_die", 1);
    set("prevent_drop", 1);
}

void begin_spell (object ob) {
    int str_curr;
    string c_str;

    tell_object(ob, "You feel suddenly stronger!\n");
    tell_room(environment(ob), ob->query("cap_name")+" suddenly "+
      "grows in muscle mass!\n", ({ ob }) );

    c_str = ob->query_class();
    switch(c_str) {
    case "warrior" : str_change = random(8) + 4; break;
    case "wizard" : str_change = random(4) + 4; break;
    case "rogue" : str_change = random(6) + 4; break;
    case "priest" : str_change = random(6) + 4; break;
    default : str_change = random(6) + 1; break;
    }

    str_curr = (int)ob->query("stat/strength");
    if ((str_curr + str_change) > 18)
	str_change = 18 - str_curr;

    ob->add("stat/strength", str_change);
    call_out("remove", 500);
    return;
}

int remove() {
    object caster = environment(this_object());

    if ((caster) && living(caster)) {
	tell_object(caster, "You feel weaker.\n");
	caster->add("stat/strength", (-1 * str_change));  
    }
    ::remove();
    return 1;
}

/* EOF */
