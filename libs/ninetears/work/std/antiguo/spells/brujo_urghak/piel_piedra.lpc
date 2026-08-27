// Paris. Jun'98

#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Piel de piedra"
#define	NIVEL	4
#define	ESCUELA	({"alteracion"})
#define	ESFERA	({"proteccion"})
#define	CANCION	"'aerdikor amudran ozoihe'"
#define	SHADOW	SHADOWS+"stoneskin_sh"

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_sphere(ESFERA);
  set_spell_level(NIVEL);
  set_target_type("none");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_desc("Este hechizo hace que tu piel tome la dureza y aparienza de "
     "la roca de tal forma que incrementa tu defensa natural a los "
     "golpes. La Dureza de tu piel aumenta con tu habilidad para "
     "comprender la naturaleza de este hechizo.\n");
  set_gp_cost(NIVEL);
  set_casting_time(2);
  set_rounds(({"round1","round2"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
 tell_object(caster,"Comienzas a concentrarte en las palabras que convocan "
             "esta ancestral mutacion.\n");
 tell_room(environment(caster),caster->query_cap_name()+" comienza a concentrarse en un nuevo conjuro.\n", caster);
 return 1;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int j,w;
  object ob;

  if (caster->query_stoneskin_spell())
  {
    // tell_object(caster,MSG_AFECTADO); kaska, tal vez target->QCN
	tell_object(caster, "Ya estas afectado por el hechizo Piel de piedra.\n");
    return -1;
  }

  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }

  tell_object(caster,"Conviertes tu piel en piedra!.\n");
  tell_room(ENV(caster),caster->QCN+" sufre una mutacion y su piel se convierte en Roca!.\n",caster); 
  
  caster->ATP("stoneskin_on",1,caster->QL*POWER*10);
  //w=5 + random(MAX(7,MIN(caster->QL/4,12))-5);
	w=5+random(7);
  tell_object(caster,"Tu piel esta formada por "+ w + " capas de piedra.\n");
  ob=clone_object(SHADOW);
  ob->setup_shadow(caster,w);
  return 0;
}

string extra_look()
{
  return "Su piel tiene el color y textura de la roca.\n";
}
