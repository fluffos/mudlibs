/* Hide in shadows.
 * Finally screwed Taniwha 1995
 */

#include "tweaks.h"

#define DISAPEAR_COST 20
#define COST DISAPEAR_COST
#define SHADOW "/d/gremios/comandos/shadows/dishad"


int disappear(string str,object hider)
{
  object me;
  object ob;
  object *call_outed,*atts_list,target;
  int i,j;

  if (hider) 
    me = hider;
  else 
    me = this_player();

  if ((int)me->query_gp() < COST)
  {
    tell_object(me,"No tienes suficientes puntos de gremio para desaparecer.\n");
    return 0;
  }
  me->adjust_gp(-COST);
   if(me->query_guild_name() == "ranger" && !environment(me)->query_outside())
   {
       tell_object(me,"Hmm, no hay nada interesante a tu alrededor para esconderte.\n");
      return 1;
   }

  if( !me->query_hide_shadow())
  {
    atts_list = me->query_attacker_list();
    for (j=0;j<sizeof(atts_list);j++)
      if(atts_list[j])
      {
        me->stop_fight(atts_list[j]);
        atts_list[j]->stop_fight(me);
      }

    call_outed = me->query_call_outed();
    for (j=0;j<sizeof(call_outed);j++)
      if(call_outed[j])
      {
        me->stop_fight(call_outed[j]);
        call_outed[j]->stop_fight(me);
      }

    tell_room(environment(me),(string)me->query_cap_name()+
      " de repente se pone a correr y desaparece!\n",({me}));

    ob = clone_object(SHADOW);
    ob->setup_shadow(me);
    ob->add_timed_property("backstabing",1,100);
  }

  /* Always give the message or they'll know when hide fails */
  tell_object(me, "Desapareces entre las sombras.\n");

  return 1;
}

string help()
{
  return "Sintaxi: Desaparecer\n\n"
    "Te permite desaparecer. Hace que escapes de los ojos de los otros "
    "Si estas luchando con otros players paras las peleas automaticamente "
    "y aunque te busquen nunca te encontraran.\n"
    "Todos los comandos se suprimen mientras estas desaparecido "
    "y el apunyalar estara bloqueado durante un tiempo. "
    "Desaparecer cuesta "+ COST +" puntos de guild."
    "\n\nEjemplo:\n> desaparecer\nIntentas desaparecer entre las sombras.\n";
    
}

