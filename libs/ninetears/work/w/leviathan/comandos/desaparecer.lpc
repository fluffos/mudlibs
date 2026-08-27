/* Hide in shadows.
 * Finally screwed Taniwha 1995
 */
/* Tradusio por Oskuro, patron de los Ladrones */

// Ya no se puede desaparecer en combate. Iolo 5-2000
//#include "tweaks.h"

#define DISAPEAR_COST 20
#define COST DISAPEAR_COST
#define SHADOW "/std/commands/shadows/dishad"


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

   if (me->query_desafio_shadow())
   {
      return 0;
   }

if (me->query_hide_shadow()) {
  tell_object(me,"Ya estas bastante escondido, no te hara falta.\n");
  return 1;
}

if (sizeof(me->query_attacker_list())) {
  tell_object(me,"Pretendes desaparecer al mismo tiempo que combates??.\n");
  return 1;
}

  if ((int)me->query_gp() < COST)
  {
    tell_object(me,"Ahora estas demasiado cansado como para esconderte.\n");
    return 0;
  }
  me->adjust_gp(-COST);
   if(me->query_guild_name() == "ranger" && !environment(me)->query_outside())
   {
       tell_object(me,"Hmm, no hay ningun sitio donde un ranger se pueda "
           "esconder.\n");
      return 1;
   }

  if( !me->query_hide_shadow())
  {
    atts_list = me->query_call_outed();
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
      " sale corriendo rapidamente y desaparece!\n",({me}));

    ob = clone_object(SHADOW);
    ob->setup_shadow(me);
ob->add_timed_property("backstabing",1,15);
  }

  /* Always give the message or they'll know when hide fails */
  tell_object(me, "Te escondes entre las sombras...\n");

  return 1;
}

string help()
{
  return "Sintaxis: Desaparecer\n\n"
    "Te permite desaparecer de la vista de los demas. El exito esta "
    "garantizado y al contrario que con el esconderse, las peleas "
    "se detienen y el buscar no siempre te encuentra. Por otro lado "
    "no podras utilizar NINGUN otro comando mientras estes desaparecido "
    "y el apunyalar no podra ser usado durante un tiempo despues de "
    "salir del desaparecer. Cuesta "+COST+" puntos de gremio.\n\n"
    "Ejemplo: Desaparecer. Te escondes entre las sombras...\n"
    "El desaparecer no se rompe por salir de la habitacion.\n";
}
