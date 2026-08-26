/*
** File:  shield_ob.c
** Purpose: Spell object for 4st-level alteration/evocation spell,
**    "fireshield".
** Duration 20 seconds/level.
** Cost:  9 SP
** Credits:
**   28 Jul 97   Cyanide@Nightfall's Keep write the file.
*/

#include <m_spells.h>              
#include <magic.h>
#include <mudlib.h>

inherit OBJECT;
int armor_add = 0;
int offence_add = 0;
int force_resist = 0;
int hp_add = 0;



void create() {
    seteuid(getuid());
    set("id", ({ "#TRANSFORM_SPELL#" }) );
    set("prevent_drop", 1);
    set("dest_at_die", 1);
}

int begin_spell(object target) {
    set("level", target->query_level());

    set("enchantment", MODERATE);
    set("schools", ({ "alteration", "evocation" }) );

    armor_add = 4;
    target->add("magical_defense", armor_add);

    offence_add = ((target->query_level()) - (target->query_level()/3));
    target->add("magical_offence", offence_add);

    hp_add = target->query("max_hp");
    target->add("hit_points", hp_add);

    target->set("power_delay", target->query_level() * 10);
    call_out("remove", target->query_level() * 20 );
    return 1;
}



int remove() {
    object target = environment(this_object());

    if ((target) && living(target)) {
	tell_object(target, "Your transformation spell ends.\n");
	target->add("magical_offence", -1*offence_add);
	target->add("magical_defense", -1*armor_add);
	if (target->query("hit_points") > target->query("max_hp")){
	    target->set("hit_points", (target->query("max_hp")));
	}
    }
    ::remove();
    return 1;
}                                                  

/* EOF */
