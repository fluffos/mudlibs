/* This is a fireplace.
** It is a simple thing with some added commands to prepare a fire
** and finally light it.
**
** created: Sonic       [01-May-1999]
** changed:
*/

#include <properties.h>
#include <macros.h>
#include <regions.h>
#include <config.h>
#include <moving.h>
#include <rooms.h>
inherit "/std/thing";

#define CALLSTEP 100

int pFuel, pBurning;

int QueryFuel()   {  return pFuel; }
int SetFuel(int fuel)
{
   if(!fuel) return 0;
   pFuel = fuel;
   return pFuel;
}

int AddFuel(int fuel)
{
   if(!fuel) return 0;
   pFuel+= fuel;
   return pFuel;
}

int QueryBurning()   { return pBurning; }
int SetBurning(int burn)
{
   if(!burn) return 0;
   pBurning = burn;
   return pBurning;
}

int RemoveFireplace()
{
   tell_room(environment(TO),
      "The last sign of the fireplace are gone now.\n");
   TO->remove();
   return 1;
}

mixed DisplayBurnMsg()
{
   mixed msg;

   msg=
   ({ "A piece of wood cracks in the fire, sending some glimmer in the "
      "sky.\n",
      "A sudden wind blows the flames in the fireplace around.\n",
   });
   return msg[random(sizeof(msg))];
}

int FireBurning()
{
   tell_room(environment(TO), DisplayBurnMsg());
   pFuel-=10;
   if(pFuel<10)
   {
      pFuel==0;
      tell_room(environment(TO),
         "The fireplace burns up.\n");
      call_out("RemoveFireplace",50);
   }
   else
      if(find_call_out("FireBurning")==-1)
         call_out("FireBurning",CALLSTEP);
   return 1;
}

int cmd_light(string str)
{
   notify_fail("Light what?\n", NOTIFY_ILL_ARG);
   if(!str || !TP) return 0;
   if(strstr(LOW(str),"fire")!=-1)
   {
      AddAdjective("burning");
      write("You light the firewood in the fireplace.\n");
      tell_room(environment(TO),
         CAP(NAME(TP))+" lights the wood in the fireplace. "
         "Soon a nice fire is burning there.\n", ({TP}) );
      Set(P_BRIGHT,20);
      call_out("FireBurning",CALLSTEP);
      pBurning = 1;
      return 1;
   }
}

int cmd_unlight(string str)
{
   notify_fail("Unlight what?\n", NOTIFY_ILL_ARG);
   if(!str || !TP) return 0;
   if(strstr(LOW(str), "fire")!=-1)
   {   
      if(pBurning)
      {
         write("You put the fire in the fireplace out.\n");
         tell_room(environment(TO),
            CAP(NAME(TP))+" puts out the fire in the fireplace.\n",
            ({ TP}) );
         if(find_call_out("FireBurning")) remove_call_out("FireBurning");
         RemoveAdjective("burning");
         Set(P_BRIGHT,0);
         return 1;
      }
      notify_fail("There is no fire in the fireplace.\n",
         NOTIFY_NOT_VALID);
   }
   return 0;
}

void init()
{
   ::init();
   add_action("cmd_light",    "light");
   add_action("cmd_unlight",  "unlight");
   add_action("cmd_unlight",  "extinguish");
}

varargs mixed QueryLong()
{
   string desc;

   desc =
      "This is a fireplace. Someone has cleaned the ground "
      "for it and put some firewood there. ";
   if(pBurning)
      desc+="A fire is burning there.\n";
   else
   {
      if(pFuel>0)
         desc+=
            "All you would need to do right now is put fire "
            "to it and you will have a nice and cosy fire for "
            "the night.\n";
      else desc+="The fireplace is burned up.\n";
   }
   return desc;
}

void create()
{
   ::create();
   Set(P_PROPERTIES,
   ([
      P_IDS:({"fireplace"}),
      P_SHORT:"a fireplace",
      P_HELP_MSG:
         "The fireplace can be used as a campfire. Use the following "
         "commands for that:\n"
         "\nlight fire\n"
         "\tStart a fire in the fireplace.\n"
         "extinguish fire (or unlight fire).\n"
         "\tPut the fire in the fireplace out.\n",
      P_NOGET:
         "Now, that's a funny idea.\n",
      P_NOSELL:
         "The shopkeeper refuses to buy this...\n",
      P_VALUE:0,
      P_WEIGHT:1000,
   ]) );
   pBurning = 0;  /* fireplace is not burning */
   pFuel = 1000;  /* initial fuel */
}
