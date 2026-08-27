// Guldan Jul'98

#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Globo mayor de invulnerabilidad"
#define	ESCUELA	({"resistencia"})
#define	ESFERA	({""})
#define	CANCION	"'marj secry sphyre'"
#define	NIVEL	6

void do_dispell(object);

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);
  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_desc("Este hechizo crea una esfera de invulnerabilidad entorno al "
    "lanzador, que impide que penetren en ella los efectos de cualquier "
    "conjuro de nivel 1, 2, 3 y 4. Los conjuros de mayor nivel no resultan afectados.\n");
  set_casting_time(1);
  set_gp_cost(NIVEL);
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

  target->ASP("invulnerable_hechizos",4);
  call_out("wear_off",caster->QL*10*POWER,target);
  return NIVEL*100;
}

void wear_off(object pl)
{
  pl->RSP("invulnerable_hechizos");
  pl->remove_extra_look(TO);
  tell_object(pl,"Tu globo de proteccion se desvanece.\n");
}

string extra_look()
{
  return "Esta rodeado por un pequenyo globo de energia";
}
