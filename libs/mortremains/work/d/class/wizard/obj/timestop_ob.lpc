/*
** File: timestop_ob.c
** Purpose: The spell object for the timestop spell.
** Credits:
**   22 Nov 97  Cyanide created the file.
*/

#include <magic.h>
#include <mudlib.h>
#include <m_spells.h>
#include "/u/c/cyanide/debug.h"

inherit OBJECT;

int active = 0, triggered = 0;
object owner, *hook_list = ({});

void create() {
   set("level", 18);
   set("enchantment", 5);
   set("schools", ({ "alteration" }) );
   set("id", ({ "#TIME_STOP#" }) );

   active = 0;
   triggered = 0;
}

void activate(object caster, int lvl) {
   set("level", lvl);
   set("caster", caster);
   owner = caster;
   active = 1;
}


// For now the init ceases all attacks when triggered.
// In the future, attacks will resume after the spell has expired.

void init() {
   int ran;
   object stopper;

   if (TP!=owner && !wizardp(TP)) {
      stopper = clone_object(M_OBJ(timestop_ob2.c));
      stopper->move(TP);
      stopper->check_attackers(TP);
      hook_list += ({ stopper });
    //TP->cease_all_attacks();
   }

   if (!triggered) {
      ran = random(6)+2;
      call_out("remove", ran);
      triggered = 1;
   }
}


void remove() {
   int i;
   object tmp_ob, player;

   for (i=0;i<sizeof(hook_list);i++) {
      tmp_ob = hook_list[i];
      if (tmp_ob) {
         tmp_ob->remove();
      }
   }
   ::remove();
}
