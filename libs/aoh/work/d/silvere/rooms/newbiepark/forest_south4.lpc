// This is a little crossing. To the northeast you can find some rabbits,
// to the southeast are some bigger creatures (dogs or cats)
// created:       Sonic    [14-Jun-1997]
// last changed:  Sonic [05-Jul-1997] added region/coordinates

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
inherit BASEROOM;

varargs mixed IntLong()
{
   string desc,wizmsg;    // wizmsg is temporary until P_WIZ_MSG
                          // is no longer needed
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
         if(exitkey[a]=="north")
         {
            load_object(exitdesc[a]);
            if(present("dog",find_object(exitdesc[a])))
               desc+="Something runs around to the north. "
                     "You hear also some barking from there. ";
         }
      }
   }
   desc+="\n";

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
   Set(P_INT_SHORT,"On a small clearing in the forest.");
   Set(P_INT_WIZMSG,
"This is a small clearing. The path leads through some bushes to the\
 north toward a crossing. A rather big dog is here, waiting for players\
 to kill.\n\
 North:  Back to the rest of the forest.\n");

   Set(P_INT_LONG,
      "There is a small clearing here. The road comes in from the north. "
      "The wall of the city is right to the west and trees are growing "
      "at the edge of the clearing. There are lots of bushes between the "
      "trees.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"silvere2");
   Set(P_REGION, REGION_CITY|REGION_FOREST);
   Set(P_COORDINATES, ({ ({-120,120,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You bump into a tree like an idiot. If you do such things often, you\
 probably need a new face in a not too far future.\n");

   AddExit("north", SIL_PARK("forest_south3"));

   AddItem("/std/npc",REFRESH_HOME,
   ({
      ([ P_LEVEL:4,
         P_LONG:
"This is a big, black dog. It looks at you and growls with foam at his"
"rather sharp teeth.\n",
         P_RACE:"dog",
         P_NAME:"dog",
         P_ADS:({"big","black"}),
         P_ALIGN:0,
         P_MMSGIN:({"runs in, chasing a cat. The cat vanishes in the bushes, and the dog looks at you"}),
         P_MMSGOUT:({"sees a cat and starts chasing it"}),
         P_AGGRESSIVE:1,
         P_ATTACK_CHANCE:700,
         P_GENDER:GENDER_MALE,
         P_HANDS:
            ({
               ({"left claw",0,1}),
               ({"right claw",0,1}),
            }),
         P_SHRUG_MSG:"The dog growls at you.\n",
      ]),
      ([ P_DEX:8,
         P_SHORT:"a big, black dog",
      ])
   }) );

}
