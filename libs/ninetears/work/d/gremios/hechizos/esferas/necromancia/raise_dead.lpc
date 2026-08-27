#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Raise Dead"
#define	NIVEL	5
#define	ESFERA	({"necromantica","lummen"})
#define	ESCUELA	({"necromancia"})
#define	CANCION	""

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);
  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_desc("This spell raises a ghost from the dead.  It removes "
    "one of their constitution points, unlike resurrect, and turns them "
    "back from being a ghost. If the ghost does not wish to return from "
    "the Halls of the Dead, the spell will fail.");
  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  } 

  if (!target->query_dead())
  {
    tell_object(caster,target->QCN+" is not dead ... yet.\n");
    return -1;
  }

  if (target->QP("noregen"))
  {
    tell_object(caster, "Death tells you: HOLD ON, I'M NOT FINISHED WITH THEM YET.\n");
    return -1;
  }

  if (!target->query_consent("resurrection"))
  {
    tell_object(caster,"The ghost does not wish to return to the Realms of the living yet. (see 'help consent')\n");
    return -1;
  }

  tell_object(caster,"You call upon the gods to restore "+target->QCN+" from "+target->query_possessive()+" immaterial state by hitting "+target->query_objective()+" with a lightning bolt..\n");
  tell_object(target,caster->QCN +" summons the gods for you, and incidently hits you with a lightning bolt. It doesn't seem to hurt.\n");
  tell_room(ENV(caster),caster->QCN+" stares intently into space, and you hear a vage rumbling in the distance. Suddenly a lightning bolt sears through the sky and hits "+target->QCN+", restoring "+target->query_objective()+" from the dead.\n",({caster,target}));
  target->remove_ghost();
  return NIVEL*100;
}
