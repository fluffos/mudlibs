/*** Traducido por Lummen 3-7-97 ***/
 
#include <spells.h>
inherit BASE_SPELL;
#define	LOCKOUT		"cloud_of_confuse_cast"
#define	NOMBRE	"Confusion"
#define	ESCUELA	"encantamiento"
#define	ESFERA	""
#define	NIVEL	4
#define	CANCION	"'cumulous confendre'"

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

  set_help_desc("Este hechizo llena una habitacion con una nube de vapor "
    "narcotico. Los efectos son variados, y la nube dura 1 round/nivel "
    "+ 2, hasta que sea neutralizada, o hasta que el hechicero muera o se vaya del "
    "juego. El hechicero tiene un gran bonus en la tirada de salvacion, pero no una total "
    "inmunidad a los efectos.\n");
  set_help_extras("Tirada de Salvacion: Nivel");

  set_casting_time(1);
  set_gp_cost(NIVEL);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out, int time, int quiet)
{
  object ob;

  if ( !quiet )
  {
    tell_object(caster,MSG_CAN_C);
    tell_room(ENV(caster),MSG_CAN_R,caster);
  }

  caster->ATP(LOCKOUT,1,40-10*POWER);

  ob=clone_object(OBJETOS+"confuse");
  ob->move(ENV(caster));
  ob->set_spell(caster,POWER*2+caster->QL);
  tell_room(ENV(caster),"Una niebla de vapor narcotico invade la habitacion!\n");
  return 1;
}
