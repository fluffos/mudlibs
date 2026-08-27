// Paris. Jun'98

#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Proteccion contra armas no magicas"
#define	NIVEL	8
#define	ESCUELA	({"alteracion","wizwar"})
#define	ESFERA	({""})
#define	CANCION	""
#define	SHADOW	SHADOWS+"proteccion_anm_sh"

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_target_type("none");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_desc("Este hechizo le confiere al hechicero una gran proteccion "
     "contra las armas no magicas. La proteccion depende del nivel "
     "del hechicero, y el danyo ,sin llegar a ser nunca cero, "
     "se reducira paulatinamente segun el Mago aumenta de nivel\n");
  set_gp_cost(NIVEL);
  set_casting_time(2);
  set_rounds(({"round1","round2"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster,"Haces pases a tu alrededor creando un aura protectiva sobre ti.\n");
  tell_room(ENV(caster),caster->QCN+" hace unos pases a su alrededor creando un aura transparente que lo envuelve en una especie de proteccion mistica.\n", caster);
  return 0;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object ob;

  if (caster->query_proteccion_armas_no_magicas())
  {
    tell_object(caster,MSG_AFECTADO);
    return -1;
  }
  if(caster->query_proteccion_armas_magicas())
  {
    tell_object(caster,"Ya posees un aura de proteccion contra armas.\n");
    return -1;
  }   

  tell_object(caster,"El aura que te rodeaba se torna de un amarillo brillante que es capaz de parar el ataque de las armas magicas.\n");
  tell_room(ENV(caster),"Al final el hechizo, el aura transpartente que rodeaba a "+caster->QCN+" se torna de un color amarillo intenso que le hace parecer casi invulnerable.\n", caster);
  ob=clone_object(SHADOW);
  ob->setshadow(caster);
  caster->add_extra_look(TO);
  caster->ATP("propiedad_proteccion_armas_no_magicas",1,150+20*15);
  return 0;
}

string extra_look()
{
  return "Esta rodeado por un Aura %^BOLD%^YELLOW%^Amarilla%^RESET%^.\n";
}
