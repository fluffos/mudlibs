#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Shadow Sin"
#define	NIVEL	4
#define	ESCUELA	({"necromancia"})
#define	ESFERA	({"necromantica"})
#define	CANCION	""
#define	TIPO	"evil"
#define	SALV	100

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);
  set_target_type("one");
  set_range(0);
  set_help_desc("This spell summons a number of shadows from the Negative"
     " Material Plane.  These shadows swarm over the target,"
     " each draining a small amount of life and mental energy."
     "  A tiny portion of the life drained is funneled back to"
     " the caster.  The efforts of opening a gateway to the"
     " Negative Material Plane will exhaust the caster, wiping away"
     " all knowledge of the spell 'Heal'.\n");
  set_gp_cost(NIVEL);
  set_casting_time(2);
  set_rounds(({"round1","round2"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet )
{
  tell_object(caster, "A lightless gate appears before you.\n");
  tell_room(ENV(caster),"A lightless portal appears before "+caster->QCN+".\n",caster);
  return 0;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int DRAIN,NO_SHAD;

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  if (target==caster)
  {
     tell_object(caster,"You can't cast this spell on yourself.\n");
     return -1;
  }

  NO_SHAD=fix_damage(caster,target,-MIN(20,3+random(caster->QL)));
  DRAIN=fix_damage(caster,target,NO_SHAD*POWER);

  tell_object(caster,"The Darkness within the gate begins to move.\n");
  tell_object(caster,"You complete your spell, and "+NO_SHAD+" shadows rise out of the darkness, swarming over "+target->QCN+"!\n");
  tell_object(target,caster->QCN+" completes "+caster->query_possessive()+" spell, and "+NO_SHAD+" beings of shadow swarm over you, their cold touch draining you of energy!\n");
  tell_room(ENV(caster),caster->QCN+" completes "+caster->query_possessive()+" spell, and "+target->QCN+" is engulfed in shadows!\n",({caster, target}));

  target->spell_damage(DRAIN,TIPO,caster);
  target->adjust_gp(NO_SHAD);
  caster->spell_damage(-NO_SHAD,TIPO,query_sphere(),SALV,caster);
  target->attack_by(caster);
  caster->remove_spell("heal");
}
