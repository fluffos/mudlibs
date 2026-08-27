#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Causar enfermedad"
#define	NIVEL	5
#define	ESCUELA	({"necromancia"})
#define	ESFERA	({"necromantica"})
#define	CANCION	"'illar camu enufus'"

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_target_type("one");
  set_range(1);
  set_line_of_sight_needed(1);
  set_help_desc("   This spell will cure most diseases, although plague and "
     "a few rare strains may be beyond the scope of this spell.\n"
     "  Clerics with more "
     "powerful healing spheres will have more success with this "
     "spell.\n");
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

  return 1;
}
