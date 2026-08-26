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

int active=0, old_IV = 0;

void create() {
  set("prevent_drop", 1);
  set("dest_at_die", 1);
}

void begin_spell (object caster, int lvl) {
 
  set("id", ({ "#INFRAVISION#" }) );
  set("enchantment", DIM);
  set("schools", ({ "alteration" }) );
  set("level", lvl);
 
  old_IV = caster->query("infravision");
  if (!old_IV)  {
     caster->set("infravision", 1);
     tell_object(caster, 
      "The world around you takes on hues of reds and blues...\n");
 
     active = 1;
     call_out("remove", 30*lvl);
  } else {
     tell_object(caster, 
      "The spell has no effect upon you...\n");
     ::remove();
  }
}

int remove() {
  object ruum = 0, caster = 0;

  caster = environment(this_object());
  if (caster) {
    ruum = environment(caster);
    caster->set("infravision", old_IV);
  } else 
   return ::remove();

  tell_object(caster, "Your Infravision spell ends.\n");

  return ::remove();
}          
