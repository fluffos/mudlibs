// A small place in the forest, where you can beat a rather dangerous hare :-)
// created:       Sonic    [07-Jun-1997]
// changed:       Sonic [05-Jul-1997] added region/coordinates

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <macros.h>
#include <rooms.h>
inherit BASEROOM;

varargs mixed IntLong()
{
   string desc,wizmsg;    // w is temporary until P_WIZ_MSG is no longer needed
   mapping exits;
   mixed exitkey, exitdesc;

   desc=::Query(P_INT_LONG);
   if(-1 != member("\n",desc[<1])) desc[<1]=' ';
   exits=({mapping})TO->Query(P_EXITS);
   if(exits)
   {
      int a;

      exitkey= m_indices(exits);
      exitdesc=m_values(exits);
      for(a=0;a<sizeof(exitkey); a++)
      {
         if(exitkey[a]=="west")
         {
            load_object(exitdesc[a]);
            if(present("rabbit",find_object(exitdesc[a])))
               desc+="Every now and then something moves. ";
         }
      }
      desc+="\n";
   }

/* this is a little temporary action, until P_WIZ_MSG is not needed anymore.
 * Or better, if it is not that urgent anymore
 */
   if((TP) && (query_user_level(TP)) && (!({int})TP->Query(P_NOWIZ))
           && (wizmsg=Query(P_INT_WIZMSG))) desc+="\n"+wizmsg;
   return desc;
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"In a dimly lit forest.");
   Set(P_INT_WIZMSG,
"This is the place with the insane rabbit. It is a rather strong enemy\
 for an newbie. There are no windows at the backside of the house, as\
 the inhabitants fear the rabbit here. *grin*\n\
 West: Back to the rest of the forest.\n");

   Set(P_INT_LONG,
      "This is a small clearing. Directly to the east is the backside of "
      "one of the houses of the south part of Silvere. To the north and "
      "south are lots of trees and bushes, which block the way in that "
      "directions.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"silvere2");
   Set(P_REGION, REGION_CITY|REGION_FOREST);
   Set(P_COORDINATES, ({ ({-90,80,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You bump into a tree like an idiot. If you do such things often, you\
 probably need a new face in a not too far future.\n");

   AddExit("west",   SIL_PARK("forest_north4"));

   AddItem("/std/npc",REFRESH_REMOVE,
   ({
      ([ P_LONG:
"This is a hare. It sits here at the wall and looks at you with reddish "
"eyes. Somehow you have the feeling, that this creature is something "
"that a lower player should rather avoid than to attack. Just as you "
"have finished that thought, the rabbit jumps toward you and attacks "
"you.\n",
         P_LEVEL:4,
         P_GENDER:GENDER_MALE,
         P_RACE:"rabbit",
         P_NAME:"hare",
         P_ADS: ({"brown","insane"}),
         P_ALIGN:0,    // rabbits are usually cute, this one is not :-)
         P_MSGIN:({"hops in"}),
         P_MSGOUT:({"hops out"}),
         P_MMSGIN:({"suddenly runs out of the bushes and looks surprised at you"}),
         P_MMSGOUT:({"suddenly runs into the bushes and is gone"}),
         P_SHRUG_MSG:"The hare seems to growl at you.\n",
         P_AGGRESSIVE:1,
         P_ATTACK_CHANCE:1000,
      ]),
      ([ P_DEX:7,
         P_SHORT:"an insane hare",
      ]),
   }) );
}
