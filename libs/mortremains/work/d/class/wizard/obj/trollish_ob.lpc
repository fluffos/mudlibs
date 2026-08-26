//ilz
// Cyanide fixed the hell out of it.

#include <m_spells.h>              
#include <magic.h>
#include <mudlib.h>

inherit OBJECT;

void create() {
    seteuid(getuid());
    set("id", ({ "#TROLLISH_SPELL#" }) );
    set("prevent_drop", 1);
    set("dest_at_die", 1);
}

int begin_spell(object target) {
    object env;

    if (target) 
	env = environment(target);
    else
	return 0;

    if (env) {
	tell_room(env, wrap(target->query("cap_name")+"'s "+
	    " skin becomes thick and rubbery."), ({ target }) );
	tell_object(target, "Your skin becomes very thick and rubbery.\n");
    }
    set("level", target->query_level());
    set("extra_look", "$N's skin is thick and rubbery.\n");
    set("enchantment", OVERWHELMING);
    set("schools", ({ "necromancy" }) );

    target->add("regeneration", 20);

    write("You begin to regenerate.\n");

    call_out("remove", target->query_level("wizard") * 20 );
    return 1;
}



int remove() {
    object target;
    object env;

    target = environment();
    if ((target) && living(target)) {
	env = environment(target);
	if (env) {
	    tell_room(env, target->query("cap_name")+"'s "+
	      " skin returns to normal.\n", ({ target }) );
	    tell_object(target, "Your skin returns to normal as your "+
	      "Trollish Fortitude spell expires.\n");
	}

	target->add("regeneration", -20);
    }
    ::remove();

    return 1;
}                                                  

/* EOF */
