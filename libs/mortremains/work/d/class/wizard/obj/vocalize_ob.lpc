/*
** File: vocalize_ob.c (Vocalize)
** Purpose: Spell ob for 2nd-level mage universal spell.
** Credits:
**  06 Nov 97  Cyanide wrote this spell and the supporting code.
*/

#include "/u/c/cyanide/debug.h"
#define FIND find_player("cyanide")
#define DEBUG(x) if (FIND) tell_object(FIND, x)

#include <magic.h>
#include <m_spells.h>
#include <mudlib.h>

inherit SPELL;
inherit OBJECT;

int active=0;

void create() {
  set("enchantment", DIM);
  set("schools", ({ "abjuration" }) );
  set("prevent_drop", 1);
  set("dest_at_die", 1);
}

void begin_spell (object caster) {
  int lvl;

  set("id", ({ "#VOCALIZE_OB#" }) );
  lvl = query_caster_level(caster, "wizard");
  set("level", query_caster_level(TP, "wizard") );
  active = 1;
  call_out("remove", 60*lvl);
}

int remove() {
  object ruum = 0, caster = 0;

DEBUG("Removing vocalize ob\n");
  if (!caster) caster = this_object();
  if (living(caster)) ruum = environment(caster);
  if (ruum) {
    tell_object(caster, "Your vocalize spell has expired.\n");
  }
  return ::remove();
}          
