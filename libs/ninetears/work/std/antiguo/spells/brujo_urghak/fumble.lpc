#include <spells.h>
inherit BASE_SPELL;
inherit	BASES+"useful_stuff";

#define	NOMBRE	"Fumble"
#define	ESCUELA	({"necromancia"})
#define	ESFERA	({"necromantica"})
#define	NIVEL	4
#define	CANCION	"'digitis mali failus'"

void setup() 
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_school(ESCUELA);
  set_sphere(ESFERA);

  set_target_type("one");
  set_range(2);
  set_line_of_sight_needed(1);

  set_help_desc("This spell causes the target to immediately fumble "
    "whatever is in their hand.  Depending on the skill of the caster, "
    "wielded weapons get either unwielded or dropped, and possibly other "
    "equipment as well.  Fast and experienced targets will not be "
    "affected as much.\n");

  set_casting_time(1);
  set_gp_cost(NIVEL);
  set_rounds(({"round1"}));
}


int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int caster_roll,target_roll;

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }

  caster_roll = random(POWER*(caster->QL+caster->query_int()))+POWER;
  target_roll = target->QL+random(2*target->query_dex());

  if (caster_roll>target_roll)
  {
    tell_object(caster, "You cast Fumble on "+target->QCN+", who is momentarily clumsy.\n");
    tell_object(target, caster->QCN+" completes his gestures, and you suddenly feel very clumsy, and can't hold on to your equipment.\n");
    tell_room(ENV(target), caster->QCN+" finishes a spell with a gesture at "+target->QCN+".\n",({caster,target}));
  }
  else
  {
    tell_object(caster, "You cast Fumble on "+target->QCN+", but nothing seems to happen.\n");
    tell_object(target, caster->QCN+" points at you, but nothing happens.\n");
    tell_room(ENV(target), caster->QCN+" gestures at "+target->QCN+", but nothing seems to happen.\n", ({ caster, target}) );
    return 1;
  }

  switch (caster_roll-target_roll)
  {
    case 21..1000:
      force_drop_everything(target);
    case 16..20:
      force_drop_one(target);
    case 11..15:
      force_unwear_armour(target);
    case 6..10:
      force_drop_one(target);
    case 1..5:
      force_unhold_weapons(target);
  }

  if (!interactive(target) && random(4)) target->attack_by(caster);
  return 0;
}
