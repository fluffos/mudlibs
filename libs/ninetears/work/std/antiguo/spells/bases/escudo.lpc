#include <spells.h>
inherit BASE_SPELL;

string	NOMBRE=		"Escudo de fuego";
mixed	ESCUELA		= ({"alteracion","invocacion"});
mixed	ESFERA		= ({"llamada"});
string	CANCION=	"'rizzaz armoum protestus'";
string	RES=		"frio";
string	TIPO=		"fuego";
#define	NIVEL		4
#define	resist		TP->QL+POWER
#define SHIELDPATH OBJETOS+"shield"

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);
  set_target_type("none");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_desc("Este hechizo crea un escudo magico. Este parece proporciona "
     "proteccion al tipo "+tipo(RES)+" de ataques. La duracion "
     "del escudo depende del nivel del hechicero. Para que "
     "la proteccion funcione, el escudo debe ser sostenido.\n");
  set_gp_cost(NIVEL);
  set_casting_time(1);
  set_rounds(({"round1"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  object shield;

  if (caster->QP("shield_spell_on"))
  {
    tell_object(caster,"Es demasiado pronto para usar este hechizo de nuevo.\n");
    return -1;
  }

  if (!quiet)
  {
    tell_object(caster,MSG_CAN_C);
    tell_room(ENV(caster),MSG_CAN_R,caster);
  }
  caster->ATP("shield_spell_on",1,caster->QL*20);
  shield=clone_object(SHIELDPATH);
  shield->setup_spell(caster,100*POWER+caster->QL*8,RES,TIPO,resist);
  shield->move(caster);
  return 400;
}
