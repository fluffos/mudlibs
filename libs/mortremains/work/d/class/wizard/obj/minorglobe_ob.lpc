/*
** File: m_globe_ob.c (Minor Globe of Invulnerability)
** Purpose: Spell ob for 4th-level mage abjuration spell.
** Credits:
**   2 Aug 97  Cyanide wrote this spell and the supporting code.
*/

#define FIND find_player("cyanide")
#define DEBUG(x) if (FIND) tell_object(FIND, x)

#include <magic.h>
#include <m_spells.h>
#include <mudlib.h>

inherit OBJECT;

int active=0;

void create() {
  set("id", ({ "#GLOBE#", "#MAGIC_REFLEX#" }) );
  set("extra_look", "$N is surrounded by a green sphere of force.\n");
  set("enchantment", DIM);
  set("schools", ({ "abjuration" }) );
  set("prevent_drop", 1);
  set("dest_at_die", 1);
}

varargs int spell_reflex (object caster, object targ, int sp, int dam) {
  int max=25;
  
  if (dam) max /= 3;
  if (targ!=environment(this_object())) return 1;
  if (active && (!environment()->query_no_magic()) && (sp<=max) ) {
    tell_object(caster, "The shimmering sphere surrounding "+
    targ->query("cap_name")+" absorb your spell!\n");
    tell_object(targ, "Your globe absorbs "+caster->query("cap_name")+
      "'s spell.\n");
    return 0;
  }
  return 1;
}

void begin_spell (object caster) {
  int lvl;

  lvl = caster->query_level("wizard");
  active = 1;
  call_out("remove", 30*lvl);
}

int remove() {
  object ruum = 0, caster = 0;

  caster = environment(this_object());
  if (caster) ruum = environment(caster);
  if (ruum) {
    tell_room(ruum, wrap("The globe of force surrounding "+
      caster->query("cap_name")+" flickers and dies."), ({ caster }) );
    tell_object(caster, "Your Globe of Invulnerability flickers and "+
      "dies.\n");
  }
  ::remove();
  return 1;
}          
