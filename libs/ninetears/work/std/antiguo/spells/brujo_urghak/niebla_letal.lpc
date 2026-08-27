// Niebla Letal

#include <spells.h>
inherit BASE_SPELL;
 
#define LOCKOUT "cloud_kill_cast"
#define	NOMBRE	"Niebla letal"
#define	ESCUELA	({"alteracion","invocacion"})
#define	ESFERA	""
#define	NIVEL	6
#define	CANCION	"'cumulous letum'"

void setup()
{
  set_spell_name("Niebla Letal");
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);

  set_target_type("none");
  set_range(0);
  set_line_of_sight_needed(0);

  add_property_to_check(LOCKOUT);

  set_help_desc("This spell will fill a room with a lethal cloud of gas. "
    "Players other than the caster are forced to flee.  The cloud lasts "
    "1 round/level, until it is dispelled, or until the caster dies or "
    "leaves the game.  Also note the caster gets a large bonus to save, "
    "not total immunity.  The spell will earn you kill XP IF you stay in "
    "the room.");
  set_help_extras("Damage Type: Poison\nSaving Throw: Level + Resist Poison");

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

  tell_room(ENV(caster),"Una niebla de vapores letales invade la habitacion!\n");

  caster->add_timed_property(LOCKOUT,1,50-10*POWER);

  ob=clone_object(OBJETOS+"ckiller");
  ob->move(ENV(caster));
  ob->set_spell(caster,caster->QL+POWER);
  return 1;
}
