/*
** File: Feeblemind_ob.c
** Purpose: Spell object for 5th level enchantment spell, feeblemind.
** Cost: 44 SP
** Credits:
**    29 Sept 97   Cyanide rewrote the file.
*/

#include <mudlib.h>

inherit OBJECT;

int int_change = 0, wis_change = 0;

void create() {
    set("id", ({ "#FEEBLEMIND#" }) );
    set("prevent_drop", 1);
    set("prevent_get", 1);
}

void begin_spell (object ob) {
    tell_object(ob, "A fog fills your brain, dulling your thoughts.\n");
    tell_room(environment(ob), ob->query("cap_name")+" begins to drool "+
      "slightly.\n", ({ ob }) );

    set("extra_look", "$N seems to be drooling slightly.\n");  
    int_change = (int)ob->query("stat/intelligence") - 3;
    wis_change = (int)ob->query("stat/wisdom") - 3;
    ob->set("stat/intelligence", 3);
    ob->set("stat/wisdom", 3);
    return;
}

void remove() {
    object caster = environment(this_object());  

    if (caster && living(caster)) {
	caster->add("stat/intelligence", int_change);
	caster->add("stat/wisdom", wis_change);
    }
    ::remove();
}

/* EOF */
