#include <spells.h>
inherit BASE_SPELL;

#define LOCKOUT "stinking_cloud_cast"
#define	NOMBRE	"Nube hedionda"
#define	ESCUELA	"invocacion"
#define	ESFERA	""
#define	NIVEL	2
#define	CANCION	"'cumulous nasueous'"

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
  set_help_extras("Tipo de Danyo: Veneno\nTirada de Salvacion: Nivel de Constitucion y Resistencia a Veneno");
  set_help_desc("Este hechizo hace que recubra una habitacionl una nube de vapor "
    "nauseavundo. Los efectos son variados, hasta hacer vomitar a la gente. "
    "Este hechizo dura 1 turno/nivel + 2, "
    "hasta que desaparezca, o hasta que el hechicero muera o salga del juego. "
    "El hechicero no es inmune total a la nube, tiene x10 al bonus de salvacion.");
  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object ob;

  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }

  caster->ATP(LOCKOUT,1,40-10*POWER);
  ob=clone_object(OBJETOS+"stinker");
  ob->move(ENV(caster));
  ob->set_spell(caster,caster->QL+POWER);
  tell_room(ENV(caster),"Una nube de podedumbre recubre la habitacion!\n");
  return NIVEL*100;
}
