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
    tell_object(me,"Te encuentras muy cansado para desaparecer.\n");
    return 0;
  }
  me->adjust_gp(-COST);
   if(me->query_guild_name() == "ranger" && !environment(me)->query_outside())
   {
       tell_object(me,"Hmm, nada aqui para que un Ranger se pueda esconder.\n");
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
      " sale corriendo y desaparece!\n",({me}));

    ob = clone_object(SHADOW);
    ob->setup_shadow(me);
    ob->add_timed_property("backstabing",1,30); // Antes estaba a 100, pero es muchisimo... 
  }

  /* Always give the message or they'll know when hide fails */
  tell_object(me, "Te escondes entre las sombras...\n");

  return 1;
}

string help()
{
  return "Sintaxis: Desaparecer\n\n"
    "Allows you to disappear.  This allows "
    "you to escape glancing eyes. Success is assured and unlike "
    "hide, other players you are currently "
    "fighting lose you and "
    "searches will not always find you.\n"
    "HOWEVER all guild commands are supressed "
    "while you have disappeared, and backstab may remain locked out for some "
    "time after it wears off. "
    "It costs "+ COST +" guild points."
    "\n\nExample:\n> Disappear\nYou try to hide in the shadows.\n"
    "Note that disappear does not \"break\" just because you leave a room "
    "but the exit messages are not supressed either. "
    "Use sneak to move silently!\n";
}
