/*
ilz stole from cyanide's shield.c
Cyanide cleaned up, 11 July 2000
*/

#include <p_spells.h>              
#include <magic.h>
#include <mudlib.h>

inherit OBJECT;

int armor_add = 0;
int force_resist = 0;

void create() {
    seteuid(getuid());
    set("id", ({ "#BARKSKIN_SPELL#" }) );
    set("prevent_drop", 1);
    set("dest_at_die", 1);
}

int begin_spell(object caster, object target) {
    set("level", caster->query_level());
    force_resist += (caster->query_level("priest")/4);
    set("enchantment", DIM);
    set("schools", ({ "alteration" }));

    set("extra_look", "$N has bark for skin.\n");  
    if ((int)caster->query("magical_defense")<force_resist) {
	armor_add = force_resist - (int)caster->query("magical_defense");
	caster->add("magical_defense", armor_add);
    }

    message("spell", "Your skin turns into a thick layer of bark.\n",
      target);
    message("spell", target->query("cap_name")+"'s skin turns into "+
      "a thick layer of bark.\n", all_inventory(environment(target)),
      target);

    call_out("remove", (80 + (caster->query_level() * 20)) );
    return 1;
}

int remove() {
    object caster = environment(this_object());

    if ((caster) && living(caster)) {
	tell_object(caster, "You skin returns to normal flesh.\n");
	caster->add("magical_defense", -1*armor_add);

    }
    ::remove();
    return 1;
}                                                  

/* EOF */
