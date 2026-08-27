//Paris. Nov '98

#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Extirpar Maldicion"
#define	NIVEL	5
#define	ESCUELA	({"wizwar"})
#define	ESFERA	({""})
#define	CANCION	""
#define	GP_COSTE	150
#define	MIN_LEVEL	30

void setup()
{
  set_spell_name(NOMBRE);
  set_school(ESCUELA);
  set_spell_level(NIVEL);
  set_target_type("item");
  set_range(0);
  set_line_of_sight_needed(0);
  set_help_desc("Un poderoso hechizo que permite al hechicero extirpar una "
                "maldicion que previamente estuviese maldita.\n");
                
  set_gp_cost(NIVEL);
  set_casting_time(4);
  set_rounds(({"round1","round2","round3","round4"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster,"Levantas tus brazos al aire para permitir que la energia entre en tu cuerpo.\n");
  tell_room(ENV(caster),caster->QCN+" levanta sus brazos al aire al tiempo que empieza a cantar haciendole "
    "estremecer de placer al recorrer la energia su cuerpo.\n",caster);
  return 0;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster,"La energia acumulada en tu cuerpo es canalizada hacia tus manos que adquieren un brillo rojizo.\n");
  tell_room(ENV(caster),"La energia acumulada por "+caster->QCN+" es redireccionada a sus manos que adquieren un brillo rojizo.\n",caster);
  return 0;
}

int round3(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_object(caster,"Estas en el punto alguido del hechizo, tu cantico se torna grave y te contoneas al son de la musica que tu mismo pronuncias.\n");
  tell_room(ENV(caster),caster->QCN+" cambia el tono de su cante a otro mas grave y empieza a irradiar calor debido a la energia que atesora.\n",caster);
  return 0;
}

int round4(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int j,encantamiento;
  object *ob;

  if (!target)
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  if (!target->query_weapon())
  {
    tell_object(caster, "Te das cuenta que estas intentando hechar sobre "
                        "un objeto que no es un arma, por lo que el hechizo "
                        "te falla.\n");
    tell_room(ENV(caster),caster->QCN+" se da cuenta que intentaba hechar "
                        "el hechizo sobre un objeto que no era un arma, por "
                        "lo que pierde toda la energia acumulada hasta ahora.\n");
    return -1;
  }

  if(!encantamiento=target->query_property("maldita"))
  {
     tell_object(caster, "El arma sobre la que intentas hechar el hechizo "
                         "no esta maldita por lo que tu hechizo falla.\n");
    return -1;
  }
  
  tell_object(caster,"Finalizas tu hechizo y el aura de oscuridad que "
                     "rodeaba el arma desaparece.\n");
  target->remove_property("maldita");
  target->adjust_enchant(encantamiento);

  return 1;
}
