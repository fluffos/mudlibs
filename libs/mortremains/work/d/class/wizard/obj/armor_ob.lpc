/*
** FILE:        armor_ob.c
** PURPOSE:     Spell object for mages' "armor" spell.
** COST:        10 SP
** EFFECTS:     Gives the caster up to 6 magical points of armor.
** DURATION:    35 seconds/level.
** CREDITS: 
**    24 Nov 97  Cyanide wrote the spell.
**    26 Nov 98  Cyanide fixed an old bug.
*/               

#include <mudlib.h>

#define ENV environment()
#define ENAME ENV->query("cap_name")

inherit OBJECT;

object caster;

void create() {
    seteuid(getuid());
    set("id", ({ "#ARMOR_OB#" }) );
    set("prevent_drop", 1);
    set("dest_at_die", 1);
}

int begin_spell(object master, int level, int flag) {
    int num;

    caster = master;
    if (!level) destruct(this_object());
    set("enchantment", 1);
    set("level", level);

    set("extra_look", "$N is protected by a transluscent armor for force.\n");

    num = 6;

    caster->add("magical_defense", num);
    set("armor_added", num);
    caster->calc_armor_class();

    call_out("remove", (35*level));
    return 1;
}

int remove() {
    int num = query("armor_added");

    if ((caster) && living(caster) && num) {
	tell_object(caster, "Your armor spell flickers and dissapears.\n");
	tell_room(environment(caster), caster->query("cap_name") +
	  "'s magical armor flickers and dissapears.\n", ({ caster }) );
	caster->add("magical_defense", -1*num);
	caster->calc_armor_class();
    }
    ::remove();
    return 1; 
}



