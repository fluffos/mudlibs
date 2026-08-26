/*
** File: wraithform_ob.c (Wraithform)
** Purpose: Spell ob for 3rd-level mage alteration/illusion spell.
** Credits:
**   9 Nov 97  Cyanide wrote this spell and the supporting code.
*/

#define FIND find_player("cyanide")
#define DEBUG(x) if (FIND) tell_object(FIND, x)

#include <magic.h>
#include <m_spells.h>
#include <mudlib.h>

inherit OBJECT;

int active=0;
int no_att_old=0, no_cast_old=0, weap_old=0;

void create() {
  set("prevent_drop", 1);
  set("dest_at_die", 1);
}

void begin_spell (object caster, int lvl) { 

  set("id", ({ "#WRAITHFORM#" }) );
  set("extra_look", "$N appears to be an incorporeal wraith.\n");
  set("enchantment", DIM);
  set("schools", ({ "illusion", "alteration" }) );
  set("level", lvl);

  no_att_old = caster->query("prevent_attack");
  if (!no_att_old)  caster->set("prevent_attack", 1);

  no_cast_old = caster->query("no_cast");
  if (!no_cast_old)  caster->set("no_cast", 1);

  weap_old = caster->query("weap_resist");
  if (!weap_old)  caster->set("weap_resist", 3);

  active = 1;
  call_out("remove", 30*lvl);
}

int remove() {
  object ruum = 0, caster = 0;

  caster = environment(this_object());
  if (caster){
    caster->set("no_cast", no_cast_old);
    caster->set("weap_resist", weap_old);
    caster->set("prevent_attack", no_att_old);
    ruum = environment(caster);
  }

  if (ruum) {
    tell_room(ruum, "The form of "+wrap(caster->query("cap_name")+
      " coalesces and becomes solid one again."), ({ caster }) );
    tell_object(caster, "Your Wraithform spell ends, and "+
      "you become corporeal again.\n");
  }
  return ::remove();
}          
