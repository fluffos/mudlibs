//Modificado por Dimmak.
//Ahora solo para las peleas con otros players, no con NPCS

#include <spells.h>
inherit BASE_SPELL;

#define	NOMBRE	"Pacificar"
#define	NIVEL	5
#define	ESCUELA	({""})
#define	ESFERA	({"vegetal"})
#define	CANCION	"'aztak pacifus'"
#define SHADOW	SHADOWS+"pacify_sh"
#define OMIQ_HAND "/global/omiq"

void setup()
{
  set_spell_name(NOMBRE);
  set_spell_level(NIVEL);
  set_sphere(ESFERA);
  set_school(ESCUELA);
  set_target_type("one");
  set_range(0);
  set_help_desc("Este hechizo pacifica a un objetivo, causando que este "
    "irradie un aura de buena-voluntad, por lo que ningun jugador podra atacar "
    "o atacarle. Todos los combates que sostenia el objetivo seran parados, "
    "sin poder volver a combatir con otro jugador hasta que el efecto del "
    "hechizo desaparezca. El combate con no-jugadores sera unicamente con "
    "armas, puesto que el afectado no podra utilizar comandos del guild o "
    "hechizos. La duracion de este hechizo es largo, y un Clerigo de Lummen "
    "tendra un bonus de duracion.\nEste hechizo se creo con el proposito de "
    "proteger a los indefensos del Pk, y frenar los ataques de un Player Killer."
    "\nNota: Este hechizo no es de defensa, por lo que no se podra utilizar "
    "contra un jugador que te este atacando, solo sera util antes de que ataque.");
  set_gp_cost(NIVEL);
  set_casting_time(2);
  set_rounds(({"round1","round2"}));
}

int round1(object caster, mixed target, mixed out_range, int time, int quiet)
{
  tell_room(ENV(caster),"Una sensacion de paz y serenidad invade este area.\n",);
  return 0;
}

int round2(object caster, mixed target, mixed out_range, int time, int quiet)
{
  int duration,i;
  object *atts_list,*call_outed,shad;

  if (OMIQ_HAND->flag_in_progress()) 
  {
    tell_object(caster,"No se puede utilizar este hechizo durante una Omiq.\n");
    return -1;
  }

  if (wrong_alignment(caster))
  {
    punish_align(caster);
    return 0;
  }

  if (!target || !interactive(target))
  {
    tell_object(caster,MSG_NO_TARGET);
    return -1;
  }

  if (target==caster)
  {
    tell_object(caster,"No puedes utilizar este hechizo en ti mismo.\n");
    return -1;
  }
  
  //Lummen '98
  atts_list=caster->query_attacker_list();
  for (i=0;i<sizeof(atts_list);i++)
  {
    if (atts_list[i]==target)
    {
      tell_object(caster,"No puedes usar este hechizo contra alguien "
        "con el que estas manteniendo una batalla.\n");
      return -1;
    }
  }
  
  if (target->query_hold_spell() || target->query_pacify_spell())
  {
    tell_object(caster,MSG_AFECTADO);
    return -1;
  }

  if (target->query_time_spell()) target->dispell_time_spell();

  if (!quiet)
  {
    tell_room(ENV(caster),MSG_CAN_R,caster);
    tell_object(caster,MSG_CAN_C);
  }

  tell_object(caster,"Pacificas a "+target->QCN+".\n");
  tell_object(target,"Sientes que la violencia sale de ti, llenandote un sentimiento de paz y calma.\n");
  tell_room(ENV(caster),caster->QCN+" termina de formular un hechizo con un gesto sobre "+target->QCN+
    ", y este parece tener una mirada de paz y serenidad.\n ",({caster,target}));

  duration=fix_damage(caster,target,50+caster->QL*POWER);
  target->ATP("pacify_on",1,duration);
  target->ATP("noguild"  ,1,duration);
  target->ATP("nocast"   ,1,duration);
  target->ATP("nosteal"  ,1,duration);
  
  shad=clone_object(SHADOW)->setup_shadow(target); 
  target->add_extra_look(shad);

  atts_list=target->query_attacker_list();

  for (i=0;i<sizeof(atts_list);i++)
  {
    if(atts_list[i]->is_player())
    {
      target->stop_fight(atts_list[i]);
      atts_list[i]->stop_fight(target);
    }  
  }

  call_outed=target->query_call_outed();

  for (i=0;i<sizeof(call_outed);i++)
  {
    if(call_outed[i]->is_player())
    {
      target->stop_fight(call_outed[i]);
      call_outed[i]->stop_fight(target);
    }  
  }
  return 0;
}
