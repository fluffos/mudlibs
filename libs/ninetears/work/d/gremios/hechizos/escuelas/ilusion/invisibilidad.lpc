// Invisibility Spell
// Taniwha '96

#include <spells.h>
inherit BASE_SPELL;
#define NOMBRE "Invisibilidad"
#define SHADOW SHADOWS+"invis_sh"
#define	ESCUELA	"ilusion"
#define	ESFERA	""
#define	NIVEL	3
#define	CANCION	"'illios effacious'"

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);
  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_desc("When cast the target may become invisible. "
    "Note that this spell breaks down if the target moves "
    "or talks emotes fights. "
    "In fact it's totally useless for doing anything other than lurking.\n");
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
    tell_object(caster,MSG_CAN_C,caster);
  }

  tell_object(target,(string)caster->QCN+" makes like a stain, and fades.\n");

  if (random(caster->QL*POWER)>10) new(SHADOW)->setup_shadow(target);
  return 0;
}
