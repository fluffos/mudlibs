// Tyrael - Jun'02

#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Piel robliza"
#define	NIVEL	4
#define	ESCUELA	({"alteracion"})
#define	ESFERA	({"proteccion"})
#define	CANCION	"'daelereon amudran ozoihe'"
#define	SHADOW	SHADOWS+"robliza_sh"

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);
  set_target_type("one");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_desc("Este hechizo hace que tu piel tome la dureza y aparienza del "
     "roble de tal forma que incrementa tu defensa natural a los "
     "golpes. La Dureza de tu piel aumenta con tu habilidad para "
     "comprender la naturaleza de este hechizo.\n");
  set_gp_cost(NIVEL);
  set_casting_time(2);
  set_rounds(({"round1","round2"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
 tell_object(caster,"Empiezas a adquirir energia para transformar tu "
             "piel.\n");
 tell_room(environment(caster),caster->query_cap_name()+" se concentra en transformar su piel.\n", caster);
 return 1;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  //int j,w;
  object ob;

  if (caster->query_stoneskin_spell())
  {
    // tell_object(caster,MSG_AFECTADO); kaska, tal vez target->QCN
	tell_object(caster, "Ya estas afectado por el hechizo Piel robliza.\n");
    return -1;
  }

  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }

  tell_object(caster,"Endureces tu piel y esta adquiere un tono rojizo!\n");
  tell_room(ENV(caster),caster->QCN+" sufre una mutacion y su piel adquiere un tono rojizo!\n",caster); 
  
  caster->ATP("stoneskin_on",1,caster->QL*POWER*10);
  //w=5 + random(MAX(7,MIN(caster->QL/4,12))-5);
//	w=5+random(7);
//  tell_object(caster,"Tu piel esta formada por "+ w + " capas de piedra.\n");
  ob=clone_object(SHADOW);
  ob->setup_shadow(caster,random(3)+6);
  return 0;
}

string extra_look()
{
  return "Su piel tiene color rojizo.\n";
}
