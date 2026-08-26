/*
** File:  light_ob.c
** Purpose: Spell object for 1st-level alteration spell, "light".
** Duration About 1.5 minutes per level.
** Cost:  12 SP
** Credits:
**   21 Jun 96   Chronos@Against the Fall of Darkness wrote the file.
**   23 Jul 97   Cyanide@Nightfall's Keep borrowed and improved the spell
**                from a now-defunct mud.
*/

#include <magic.h>
#include <m_spells.h>
#include <mudlib.h>

inherit OBJECT;

void create() {
    seteuid(getuid());
    set("id", ({ "#LIGHT_OBJECT#" }) );
    set("light", 1);
    set("enchantment", DIM);
    set("schools", ({ "alteration" }) );
    set("prevent_drop", 1);
}

int start_spell(int level, int person) { // 1 if it's on a person.
    if (!level) level = 1;
    level = 10;
    set("level", level);

    if (person && environment() ) {
	set("extra_look", environment()->query("cap_name") +
	  " is surrounded by a glowing aura.\n");
	set("dest_at_die", 1);
    }
    call_out("burn_out", 90*level);
    return 1;
}

int burn_out() {
    tell_object(environment(), "The light spell fades.\n");
    if (userp(environment()))  message("spell", 
	  "The aura of light around "+environment()->query("cap_name")+
	  " slowly fades away.\n", environment(environment()),
	  ({ environment() }) );
    remove();
}

