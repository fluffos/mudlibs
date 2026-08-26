/*
** File:  dark_ob.c
** Purpose: Spell object for 1st-level alteration spell, "darkness".
** Duration About 30 seconds per level.
** Cost:  12 SP
** Credits:
**   21 Jun 96   Chronos@Against the Fall of Darkness wrote the file.
**   23 Jul 97   Cyanide@Nightfall's Keep borrowed and improved the spell
**                from a now-defunct mud.
**   20 Jan 98   Cyanide@NK converted to a parallel darkness spell.
*/

#include <magic.h>
#include <m_spells.h>
#include <mudlib.h>

inherit OBJECT;
inherit SPELL;

void create() {
  seteuid(getuid());
  set("id", ({ "#DARKNESS_OBJECT#" }) );
  set("light", -10);
  set("enchantment", DIM);
  set("schools", ({ "alteration" }) );
  set("prevent_drop", 1);
}

int start_spell(int level, int person) { // 1 if it's on a person.
  if (!level) level = 1;
  set("level", level);

  if (person) {
    set("extra_look", environment()->query("cap_name") +
      " is surrounded by inpenetrable darkness.\n");
    set("dest_at_die", 1);
  }
  call_out("burn_out", 30*level);
  return 1;
}

int burn_out() {
  tell_object(environment(), "The darkness spell fades.\n");
  if (userp(environment()))  message("spell", 
    "The aura of darkness around "+environment()->query("cap_name")+
    " slowly fades away.\n", environment(environment()),
    ({ environment() }) );
  remove();
}

