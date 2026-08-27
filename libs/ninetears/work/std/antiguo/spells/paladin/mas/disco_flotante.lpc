#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Disco flotante"
#define	ESCUELA	"invocacion"
#define	ESFERA	""
#define	NIVEL	1
#define	CANCION	"'dyscik ivnis'"

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);
  set_target_type("one");
  set_range(2);
  set_line_of_sight_needed(1);
  set_help_desc("Este hechizo crea un disco flotante en el que se puede poner carga.\n");
  
  set_casting_time(1);
  set_rounds(({"round1"}));

  set_gp_cost(NIVEL);
}


int round1(object caster,mixed target,mixed out_of_range,int time,int quiet)
{
  object disco;
  
  if (!quiet)
  {
    tell_object(caster,MSG_CAN_C);
    tell_room(ENV(caster),MSG_CAN_R,caster);
  }

  tell_object(caster,"Formulas el hechizo "+NOMBRE+" y un disco flotante aparece!\n");
  tell_room(ENV(caster),caster->QCN+" formula un hechizo, y un disco flotante aparece!\n",caster);
  
  disco=clone_object(OBJETOS+"disco");
  disco->move(ENV(caster));
  disco->configure(caster);
  return NIVEL*100;
}
