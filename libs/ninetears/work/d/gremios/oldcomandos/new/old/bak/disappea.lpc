#include "tweaks.h"
/* Hide in shadows.
   Finally screwed Taniwha 1995
*/
#define DISAPEAR_COST 50
#define COST DISAPEAR_COST
#define SHADOW "/d/gremios/comandos/shadows/dishad"
object me;

int disappear(string str,object hider)
{
  int sk_bon;
  object ob;
   object *call_outed,*atts_list,target;
  int i,j;

  if(hider) me = hider;
  else me = this_player();

   target = me; /* lazy demi */
  if ((int)me->query_gp() < COST)
  {
    tell_object(me,"Not enough guild points to hide.\n");
    return 0;
  }
  me->adjust_gp(-COST);

  if( !me->query_hide_shadow())
  {
  atts_list = target->query_attacker_list();
  for (j=0;j<sizeof(atts_list);j++)
  {
    if(atts_list[j])
    {
	    target->stop_fight(atts_list[j]);
	    atts_list[j]->stop_fight(target);
   }
  }

  call_outed = target->query_call_outed();
  for (j=0;j<sizeof(call_outed);j++)
  {
      if(call_outed[j])
      {
	    target->stop_fight(call_outed[j]);
	    call_outed[j]->stop_fight(target);
      }
  }
  tell_object(me,"You fade into the shadows.\n");
   tell_room(environment(me),(string)me->query_cap_name()+" suddenly runs off and disappears!\n",({me}));
        /* they succeeded. */
        ob = clone_object(SHADOW);
        ob->setup_shadow(me);
        ob->add_timed_property("backstabing",1,100);
   }
  return 1;
}

string help()
  {
  return "Syntax: Disappear\n\nAllows you to disappear.  This allows "
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

