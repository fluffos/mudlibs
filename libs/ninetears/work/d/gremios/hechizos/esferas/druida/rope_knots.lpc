#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Rope Knots"
#define	NIVEL	2
#define	ESFERA	({"proteccion"})
#define	ESCUELA	({""})
#define	CANCION	"'tannyum rizupis'"
#define	PROPERTY	"skill_rope_knots"
#define	VALUE	50

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);
  set_target_type("one");
  set_range(0);
  set_help_desc("Add one.\n");
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

  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }

  tell_object(target,"You feel more skilled.\n");
  tell_object(caster,"You cast "+NOMBRE+" on "+target->QCN + ".\n");
  tell_room(ENV(caster),target->QCN+" seems tied up in thoughts for a while, but manages to sort it all out\n",({caster,target}));
  target->ATP(PROPERTY,50+VALUE,20*caster->QL);
  return 0;
}
