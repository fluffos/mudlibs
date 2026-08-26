/*
ilz stole this from cyanide
*/

#include <m_spells.h>              
#include <magic.h>
#include <mudlib.h>

inherit OBJECT;

int armor_add = 0;
int offence_add = 0;
int force_resist = 0;
int save_add = 0;

void create() {
    seteuid(getuid());
    set("id", ({ "#BLESS_SPELL#" }) );
    set("prevent_drop", 1);
    set("dest_at_die", 1);
}

int begin_spell(object caster, object target) {
    set("level", caster->query_level());

    set("enchantment", DIM);
    set("schools", ({ "enchantment" }) );

    if ((int)caster->query("magical_defense")<1) {
	armor_add = 1 - (int)caster->query("magical_defense");
	caster->add("magical_defense", armor_add);
    }

    if ((int)caster->query("magical_offence")<1) {
	offence_add = 1 - (int)caster->query("magical_offence");
	caster->add("magical_offence", offence_add);
    }
    if ((int)caster->query("save_bonus")<1) {
	save_add = 1 - (int)caster->query("save_bonus");
	caster->add("save_bonus", save_add);
    }

    call_out("remove", caster->query_level() * 20 );
    return 1;
}



int remove() {
    object caster = environment(this_object());

    if ((caster) && living(caster)) {
	tell_object(caster, "Your bless spell ends.\n");
	caster->add("magical_offence", -1*offence_add);
	caster->add("magical_defense", -1*armor_add);
	caster->add("save_bonus", -1*save_add);
    }
    return ::remove();
}                                                  

/* EOF */
