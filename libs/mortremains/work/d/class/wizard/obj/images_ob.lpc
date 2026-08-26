/*
** File: images.c  (Level 2 wizard illusion spell)
** Cost: 12 Spellpoints
** Credits:
**   09 Feb 98   Cyanide created the spell.
*/

#include <magic.h>

inherit OBJECT;

int images = 0, active = 0;

void create() {
    seteuid(getuid());
    set("extra_look", "@@query_extra_look");
    set("prevent_drop", 1);
    set("dest_at_die", 1);
}


void init() {
    add_action("dispel", "dispel");
}


void begin_spell ( object caster, int lvl ) {
    if (!caster || !lvl) remove();
    active = 1;

    images = lvl / 8;
    images += (random(4) + 1);

    tell_room(environment(caster), TPN + " suddenly splits into "+
      images + " indentical copies!\n", ({ caster }) );
    tell_object(environment(), "You split yourself into "+images+" selves.\n");
    set("schools", ({ "illusion" }) );
    set("enchantment", 1);
    set("caster", caster->query("name"));
    set("level", lvl);
    set("id", ({ "#IMAGES#", "#REFLEXIVE_SPELL#" }) );

    call_out("remove", 60 * lvl);
    return;
}


int dispel( string str ) {
    if (str!="images") return 0;

    write("You choose to end your Mirror Image spell.\n");
    remove();
    return 1;
}


string query_extra_look() {
    return "There are "+(images + 1)+" identical $N's here!\n";
}

varargs int reflex(int dam, string type, object prev, int weap) {
    object env = environment();

    if (random(images) && prev) {
	tell_object(env, "An image gets dispelled!\n");
	tell_room(environment(env), "One of "+env->query("cap_name")+
	  "'s images is dispelled!\n", env);
	images--;
	if (images == 1) remove();
	return 0;
    }
    return dam;
}

void remove() {
    object env = environment();

    if (env && living(env) && active) {
	tell_object(env, "Your images wink out one by one.\n");
	tell_room(environment(env), env->query("cap_name")+
	  "'s images wink out, one by one.\n", ({ env }) );
    }

    ::remove();
}

/* EOF */
