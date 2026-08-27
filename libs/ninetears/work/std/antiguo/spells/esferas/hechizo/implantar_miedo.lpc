#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Implantar el miedo"
#define	ESFERA	({"hechizo"})
#define	ESCUELA	({"abjuracion"})
#define	NIVEL	1
#define	CANCION	"''"

void setup()
{
  set_spell_name(NOMBRE);
  set_sphere(ESFERA);
  set_school(ESCUELA);
  set_spell_level(NIVEL);
  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_desc("");
  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object ob;

  if ( wrong_alignment(caster) )
  {
    punish_align(caster);
    return 0;
  }

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
  ob=clone_object(SHADOWS+"fear_sh");
  ob->setup_shadow(target);
  return 0;
}
