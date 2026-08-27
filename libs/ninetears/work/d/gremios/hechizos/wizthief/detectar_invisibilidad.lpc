#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Detectar invisibilidad"
#define	ESCUELA	({"adivinacion"})
#define	ESFERA	({"adivinacion"})
#define	NIVEL	2
#define	CANCION	"'ethos deus beleah'"

void setup()
{
  set_spell_name(NOMBRE);
  set_sphere(ESFERA);
  set_school(ESCUELA);
  set_spell_level(NIVEL);
  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_desc("Este hechizo detecta seres invisibles.\n");
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
    tell_object(caster,MSG_CAN_C);
    tell_room(ENV(caster),MSG_CAN_R,caster);
  }

  return 0;
}
