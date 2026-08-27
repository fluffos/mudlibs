#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Blade barrier"
#define	ESCUELA	({""})
#define	ESFERA	({"guardiana"})
#define	CANCION	"'Deus Clavius'"
#define	NIVEL	6

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);

  set_target_type("none");
  set_range(0);
  set_line_of_sight_needed(0);

  set_help_extras("Damage Type: Physical\nSaving Throw: Level Dexterity");
  set_help_desc("This spell will create a wall of blades around the caster."
    "Anyone in the room will take damage if they don't make the saving "
    "throw, and extra damage if they are attacking the caster. "
    "The spell lasts 1 round /level +3 , "
    "until it is dispelled, or until the caster dies or leaves the game. "
    "Also note the caster gets a 10* bonus save, not total immunity.");

  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object ob;

  if (caster->QP("blade_barrier_cast"))
  {
    tell_object(caster,"You cannot bring forth another blade barrier so soon.\n");
    return -1;
  }

  if (!quiet)
  {
    tell_object(caster,MSG_CAN_C);
    tell_room(ENV(caster),MSG_CAN_R,caster);
  }

  caster->ATP("blade_barrier_cast",1,30);
  ob = clone_object(OBJETOS+"blader");
  ob->move(ENV(caster));
  ob->set_spell(caster,3+caster->QL);
  tell_room(ENV(caster),"The ground rips open and a wall of blades springs up!\n");
}
