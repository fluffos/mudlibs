/*
** File:  shield_ob.c
** Purpose: Spell object for 4st-level alteration/evocation spell,
**    "fireshield".
** Duration 50 seconds/level.
** Cost:  9 SP
** Credits:
**   28 Jul 97   Cyanide@Nightfall's Keep write the file.
*/

#include <m_spells.h>              
#include <magic.h>
#include <mudlib.h>

inherit SPELL;
inherit OBJECT;

int force_resist = 0;
int armor_add = 0;

void create() {
    seteuid(getuid());
    set("id", ({ "#SHIELD_SPELL#", "#REFLEXIVE_SPELL#", "shield" }) );
    set("long", "A glowing white plane of force.\n"+ 
      "It can be dispelled by typing \"dispel shield\".\n");
    set("prevent_drop", 1);
    set("dest_at_die", 1);
}

int begin_spell(object caster) {
    set("level", caster->query_level());

    set("enchantment", DIM);
    set("schools", ({ "evocation" }) );

    tell_object(caster, "You create a magical shield to protect you.\n");
    tell_room(environment(caster), caster->query("cap_name") +
      " creates a magical plane of force.\n", ({ caster }) );
    set("extra_look", "$N is protected by a glowing magical shield.\n");

    if ((int)caster->query("magical_defense")<6) {
	armor_add = 4;
	caster->add("magical_defense", armor_add);

	if (member_array("force", keys(caster->query("resist_type")) ) == -1 ) {
	    force_resist=100;
	    caster->set("resist_type/force", 100);
	} else
	    force_resist = caster->query("resist_type/force");

	caster->add("resist_type/force", -1 * force_resist);
    }
    caster->calc_amor_class();

    call_out("remove", caster->query_level() * 50 );
    return 1;
}

int reflex(int damage, string type, object ob) {
    string done;

    if (ob && living(ob) && (damage>0) && (type=="magic")) {
	tell_object(environment(), "You spell absorbs "+
	  ob->query("cap_name")+"'s magics!\n");
	tell_room(environment(environment()), environment()->query("cap_name")+
	  "'s shield absorbs "+ob->query("cap_name")+"'s magics!\n",
	  ({ ob, environment() }) );
	tell_object(ob, "Your spell gets absorbed by "+
	  environment()->query("cap_name")+"'s shield.\n");
	return 0;    
    }

    return damage;
}

int remove() {
    object caster = environment(this_object());

    if ((caster) && living(caster)) {
	tell_object(caster, "Your shield spell flickers and dissapears.\n");
	tell_room(environment(caster), caster->query("cap_name") +
	  "'s magical shield flickers and dissapears.\n", ({ caster }) );
	caster->add("magical_defense", -1*armor_add);
	caster->add("resist_type/force", force_resist);
	caster->calc_armor_class();
    }
    ::remove();
    return 1;
}                                                  

/* EOF */
