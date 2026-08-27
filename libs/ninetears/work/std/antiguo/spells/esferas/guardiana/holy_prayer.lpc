#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Holy Prayer"
#define	ESCUELA	({""})
#define	ESFERA	({"guardiana"})
#define	CANCION	"'dynis es rockis'"
#define	NIVEL	7

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);
  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);
  add_property_to_check("SymbolTrans_on");
  set_help_desc("This spell creates an aura of evil which enshrouds "
     "the caster and protects him/her from attacs.  The caster will "
     "also get a small bit of combat help from this spell as well.");
  set_gp_cost(NIVEL);
  set_casting_time(2);
  set_rounds(({"round1","round2"}));
  set_help_extras(0);
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet )
{
  tell_object(caster,"You pray to your diety for ultimate power.\n");
  tell_room(ENV(caster),caster->QCN+" looks to be praying to someone.\n",caster);
  return 0;
}
 
int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int level=caster->QL;

  if (target!=caster)
  {
    tell_object(caster,"You may not use this spell on anyone else.\n");
    return -1;
  }

  if (target->query_property("holy_prayer_on"))
  {
    tell_object(caster,"Sorry, not so fast, wait a bit and Grimbrand may respond.\n");
    return 0;
  }

  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }

  if (target==caster)
  { 
    tell_object(target,"Grimbrand inspires you for your loyalty.\n");
    tell_room(ENV(caster),caster->QCN+"chants in Duergar asking Grimbrand for inspiration "+
      target->query_objective()+"self.\n",caster);
  }

  caster->ATP("holy_prayer_on",1,100+level*10);
  target->adjust_tmp_tohit_bon(level);
  target->adjust_tmp_damage_bon(level/10);
  target->adjust_tmp_ac_bon(level*2);
  target->add_extra_look(TO);
  call_out("wear_off",100+level*10,target, level);
  return 0;
}

void wear_off(object target, int level)
{
  if (target)
  {
    tell_object(target,"You feel more vulnerable.\n");
    target->remove_extra_look(TO);
    target->remove_static_property("armour_on");
    target->adjust_tmp_tohit_bon(-level);
    target->adjust_tmp_damage_bon(-level/10);
    target->adjust_tmp_ac_bon(-level*2);
    tell_object(target,"Your Prayer of Holyness wears off.\n");
  }
}
 
string extra_look()
{
  return "%^BOLD%^BLACK%^Is enshrouded by a very dull, aura of evil.%^RESET%^\n";
}
