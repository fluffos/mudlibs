#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Regeneration"
#define	ESCUELA	({""})
#define	ESFERA	({"curadora"})
#define	NIVEL	6
#define	CANCION	"'in mani timus'"
#define OBJETO	OBJETOS+"regeneration_obj"
#define	REGEN_NUM_HB	2

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);
  set_target_type("one");
  set_range(0);
  set_help_desc("This spell makes the recipient recover from wounds much much "
    "faster.  Poisoned or other special wounds cannot be regenerated "
    "by this spell.  The spell will last for 3 rounds per level of the caster.\n"
    "     Overuse of this spell has known to be permanently damaging.  "
    "Much like trolls born with the ability to regenerate innate, "
    "the recipient will become very susceptible to attacks from fire. "
    "Even once the spell has worn off, it is believed some residue is "
    "left over.  One notable high priest who used the spell regularly was "
    "known, after several years' use, to actually catch fire from "
    "the smallest campfire sparks.");
  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object ob;
  int amount, duration;

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  if (target->query_armour_spell() || target->query_mirror_spell() || target->QP("regen_on"))
  {
    tell_object(caster, "Magic surrounding your target disrupts your spell.\n");
    return -1;
  }

  if (!quiet)
  {
    tell_object(caster,MSG_CAN_C);
    tell_room(ENV(caster),MSG_CAN_R,caster);
  }

  duration=fix_damage(caster,target,caster->QL*(POWER+1));
  amount=duration/10;

  ob=clone_object(OBJETO);
  ob->set_spell(target,amount);
  ob->set_get();
  ob->move(target);
  ob->reset_get();
  ob->reset_drop();
  target->add_extra_look(ob);
  target->ATP("regen_on",1,duration);

  /* Fire resistance hit.  Every three times it drops 1% */
  if (target->QP("regen_fire_counter")==2)
  {
    target->ASP("fire",target->QSP("fire")-1);
    target->ASP("regen_fire_counter",0);
    tell_object(target,"You feel more susceptible to fire.\n");
  }
  else target->ASP("regen_fire_counter",target->QP("regen_fire_counter")+1);

  if ( target!=caster) tell_object(caster,"You cast Regeneration on "+target->QCN+", and "+target->query_possessive()+" skin glows with health.\n");
  tell_room(ENV(caster),caster->QCN+"'s skin starts to glow with health.\n",caster);
  tell_object(target,"You feel health flow through you, and your skin starts to glow.\n");
  return 0;
}
