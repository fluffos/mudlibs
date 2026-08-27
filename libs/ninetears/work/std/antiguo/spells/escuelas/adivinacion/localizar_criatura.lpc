#include <spells.h>
inherit BASE_SPELL;

#define NOMBRE	"Localizar criatura"
#define	ESCUELA	({"adivinacion"})
#define	ESFERA	({"adivinacion"})
#define	NIVEL	4
#define	CANCION	"'magius powers into me'"

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);
  set_target_type("none");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_desc("Este hechizo te permite leer magia durante un tiempo determinado.\n");
  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(target,MSG_CAN_C);
  }

  return 0;
}
