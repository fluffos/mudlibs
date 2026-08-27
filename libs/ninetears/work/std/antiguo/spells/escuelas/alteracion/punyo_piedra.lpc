// Guldan Jul'98

#define NOMBRE	"Punyo de piedra"
#define NIVEL	1
#define	ESCUELA	({"alteracion"})
#define	ESFERA	({})
#define	CANCION	"'groez us marj'"

#include <spells.h>
inherit BASE_SPELL;

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);

  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_desc("Este hechizo aumenta temporalmente el tamanyo de un objetivo.");

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
  
  if (target->QP("agrandado"))
  {
    tell_object(caster,MSG_AFECTADO);
    return -1;
  }
   
  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }
  
  return 0;
}

void wear_off(object target,int fuerza)
{
  if (target)
  {
  }
}
