/*
** File:  enlarge_ob.c
** Purpose:  Spell object for "enlarge" spell.
** Credits:
**    21 Jul 97  Cyanide created the spell.
*/

#include <magic.h>
#include <mudlib.h>

int shrink_wrap();

inherit SPELL;
inherit OBJECT;

int size = 6, called = 0;
object subject = this_object();

void create() {
    called = 0;
    seteuid(getuid());
    set("enchantment", DIM);
    set("schools", ({ "alteration" }) );
    set("id", ({ "#ENLARGE_OB#" }) );
    set("prevent_drop", 1);
    set("dest_at_die", 1);
}

int begin_spell(int level) {
    if (level > 15) level = 15;

    set("level", level);

    subject = environment(TO);
    if (!subject) {
	destruct(TO);
	return 0;
    }

    size = (int)subject->query("size");
    size = (((level*10)+100)*size)/100 - size;
    if (size < 1) size = 1;
    subject->add("size", size);

    tell_object(subject, "You grow by "+size+" feet!\n");
    tell_room(environment(subject), subject->query("cap_name") +
      " grows by "+size+" feet!\n", subject);
    set("extra_look", "$N stands an incredible "+(size +
	(int)subject->query("SIZE")) + " feet tall!\n");
    call_out("remove", 30*level);
    return 1;
}

int remove() {
    if (environment() && living(environment()) && (called==0)) {    
	environment()->add("size", (-1 * size));
	shrink_wrap();
    }
    ::remove();
    return 1;
}


int shrink_wrap() {
    if (subject && environment()==subject) {
	if (called==0) {
	    tell_object(environment(), "You shrink to your original height.\n");
	    tell_room(environment(environment()), subject->query("cap_name")+
	      " shrinks to "+possessive(subject->query("gender")) + 
	      " original height.\n", subject);
	    called++;
	}
    }
    return 1;
}                                                           
