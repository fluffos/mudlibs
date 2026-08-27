// Guldan Jul'98

#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Inaudibilidad"
#define	ESCUELA	({"abjuracion"})
#define	ESFERA	({""})
#define	CANCION	"'hush'"
#define	NIVEL	1

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);
  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_desc("Este hechizo hace que un objetivo sea inaudible. Esto "
     "hace que sus canticos sean inaudibles durante un corto periodo de "
     "tiempo.\n");
  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_of_range, int time, int quiet)
{
  if (!objectp(target))
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }
  tell_object(target,caster->QCN+" formula un hechizo sobre ti.\n");
  if (random(caster->QL*(POWER+1))>10) target->ASP(INAUDIBLE,1);
  return NIVEL*3;
}
