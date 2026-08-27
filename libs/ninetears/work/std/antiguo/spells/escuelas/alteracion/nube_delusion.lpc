/*** Cloud of Delusion ***/
/*** Created by Taniwha ***/
/*** Adapted to base spell by Wonderflug ***/

#include <spells.h>
inherit BASE_SPELL;
#define	NOMBRE	"Nube de delusion"
#define	ESCUELA	"alteracion"
#define	ESFERA	""
#define	NIVEL	3
#define	CANCION	"'cumulous chaosium'"
#define LOCKOUT "cloud_of_delusion"

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);

  set_target_type("none");
  set_range(0);
  set_line_of_sight_needed(0);

  add_property_to_check(LOCKOUT);

  set_help_desc("This spell will fill a room with a cloud of narcotic "
    "vapour.  Effects are varied, and the spell lasts 1 round/level +2, "
    "until it is dispelled, or until the caster dies or leaves the game.  "
    "Also note the caster gets a large bonus to save, not total immunity.");
  set_help_extras(0);

  set_casting_time(1);
  set_gp_cost(NIVEL);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object ob;

  if (!quiet)
  {
    tell_object(caster,MSG_CAN_C);
    tell_room(ENV(caster),MSG_CAN_R,caster);
  }

  caster->ATP(LOCKOUT,1,40-10*POWER);
  ob=clone_object(OBJETOS+"delude");
  ob->move(environment(caster));
  ob->set_spell(caster,2+(int)caster->QL);
  tell_room(ENV(caster),"Una nube de vapores narcoticos invade la habitacion!\n");
}
