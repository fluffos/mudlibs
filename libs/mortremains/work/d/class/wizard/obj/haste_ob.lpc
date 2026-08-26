/*
** File: globe_ob.c ( Globe of Invulnerability)
** Purpose: Spell ob for 5th-level mage abjuration spell.
** Credits:
**   2 Aug 97  Cyanide wrote this spell and the supporting code.
**  10 Oct 97  Cyanide corrupted minorglobe_ob.c into globe_ob.c
*/

#define FIND find_player("cyanide")
#define DEBUG(x) if (FIND) tell_object(FIND, x)

#include <magic.h>
#include <m_spells.h>
#include <mudlib.h>

inherit OBJECT;

int active=0;

void create() {
  set("id", ({ "#HASTE#" }) );
  set("extra_look", "$N is just a blur of movement.\n");
  set("prevent_drop", 1);
  set("dest_at_die", 1);
}

void begin_spell (object caster, int lvl) {
  int percy = 100;

  set("enchantment", 2);
  set("schools", ({ "alteration" }) );
  set("level", lvl);
  set("caster", caster->query("cap_name"));


/*
  percy = PROPERTY_D->query_system_shock(caster);
  if (random(100) > percy) {
    write("Your heart suddenly bursts with the strain!\n");
    say(TPN+" suddenly grabs "+possessive(caster->query("gender"))+
      " chest and drops to the ground, dead!\n");
    caster->set("hit_points", -30);
    return;
  }
*/
  active = 1;
  caster->set("hasted", 1);
  call_out("remove", 6*lvl);

  return;
}

int remove() {
  object ruum = 0, caster = 0;

  caster = environment(this_object());
  if (caster) ruum = environment(caster);
  if (ruum) {
    tell_room(ruum, wrap(caster->query("cap_name")+
     " slows a bit."), ({ caster }) );
    tell_object(caster, "You are exhausted as your Haste ends suddenly.\n");
    caster->delete("hasted");
  }
  ::remove();
  return 1;
}          
