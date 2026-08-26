/*
** File:  aid_ob.c
** Purpose: Spell object for 1st-level priest spell, "aid".
** Duration 30 seconds/level.
** Cost:  12 SP
** Credits:
**   28 Jul 97  Cyanide@Nightfall's Keep write the file.
**   ?? ??? ??  Ilzarion used it to make Aid.
**   16 Dec 98  Cyanide repaired.
*/

#include <m_spells.h>              
#include <magic.h>
#include <mudlib.h>

inherit OBJECT;
inherit SPELL;

int armor_add = 0;
int offence_add = 0;
//int force_resist = 0;
int hp_add = random(8)+random(8)+random(8)+3;

void create() {
    seteuid(getuid());
    set("id", ({ "#AID_SPELL#" }) );
    set("prevent_drop", 1);
    set("dest_at_die", 1);
}

int begin_spell(object caster, object target) {
    set("level", caster->query_level());
    set("caster", caster->query("name"));

    set("enchantment", DIM);
    set("schools", ({ "enchantment" }) );

    if ((int)target->query("magical_defense")<1) {
	armor_add = 1 - (int)target->query("magical_defense");
	target->add("magical_defense", armor_add);
    }

    if ((int)target->query("magical_offence")<1) {
	offence_add = 1 - (int)target->query("magical_offence");
	target->add("magical_offence", offence_add);
    }

    target->add("hit_points", hp_add);
    call_out("remove", caster->query_level() * 30 );
    return 1;
}

int remove() {
    object target = environment(this_object());

    if ((target) && living(target)) {
	tell_object(target, "Your aid spell ends.\n");
	target->add("magical_offence", -1*offence_add);
	target->add("magical_defense", -1*armor_add);
	if (target->query("hit_points") > target->query("max_hp")){
	    target->set("hit_points", (target->query("max_hp")));
	}
    }
    return ::remove();
}                                                  

/* EOF */
