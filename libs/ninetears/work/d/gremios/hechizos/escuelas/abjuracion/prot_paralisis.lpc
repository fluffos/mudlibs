// Guldan Jul'98

#include <spells.h>
inherit BASE_SPELL;
#define	NOMBRE	"Proteccion contra paralisis"
#define	ESCUELA	({"abjuracion"})
#define	ESFERA	({})
#define	CANCION	"''"
#define	NIVEL	2

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);
  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_desc("");
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
  target->ATP("imparable",1,caster->QL*10*POWER);
  return 0;
}
