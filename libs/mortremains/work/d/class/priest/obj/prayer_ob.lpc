/*
** File:  shield_ob.c
** Purpose: Spell object for 4st-level alteration/evocation spell,
**    "fireshield".
** Duration 50 seconds/level.
** Cost:  9 SP
** Credits:
**   28 Jul 97   Cyanide@Nightfall's Keep write the file.
*/

#include <m_spells.h>              
#include <magic.h>
#include <mudlib.h>

inherit OBJECT;
int armor_add = 0;
int offence_add = 0;
int save_add = 0;
int force_resist = 0;

void create() {
  seteuid(getuid());
  set("id", ({ "#PRAYER_SPELL#" }) );
  set("prevent_drop", 1);
  set("dest_at_die", 1);
}

int begin_spell(object caster, object target) {
  set("level", caster->query_level());

  set("enchantment", MODERATE);
  set("schools", ({ "enchantment" }) );

 
if ((int)caster->query("magical_defense")<2) {
    armor_add = 2 - (int)caster->query("magical_defense");
    caster->add("magical_defense", armor_add);
  }

if ((int)caster->query("magical_offence")<2) {
    offence_add = 2 - (int)caster->query("magical_offence");
    caster->add("magical_offence", offence_add);
  }
if ((int)caster->query("save_bonus")<2) {
    save_add = 2 - (int)caster->query("save_bonus");
    caster->add("save_bonus", save_add);
  }

  call_out("remove", caster->query_level() * 50 );
  return 1;
}



int remove() {
  object caster = environment(this_object());

  if ((caster) && living(caster)) {
    tell_object(caster, "Your prayer spell ends.\n");
     caster->add("magical_offence", -1*offence_add);
    caster->add("magical_defense", -1*armor_add);
     caster->add("save_bonus", -1*save_add);
  }
  ::remove();
  return 1;
}                                                  

/* EOF */
