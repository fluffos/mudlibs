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
         if(exitkey[a]=="south")
         {
            load_object(exitdesc[a]);
            if(present("dog",find_object(exitdesc[a])))
               desc+="There is a strange noise from the south. ";
         }
         if(exitkey[a]=="east")
         {
            load_object(exitdesc[a]);
            if(present("dog",find_object(exitdesc[a])))
               desc+="Something runs around to the east. "
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
   Set(P_INT_SHORT,"On a crossing in the forest.");
   Set(P_INT_WIZMSG,
"This is a small crossing. The path leads in from the east and continues\
 west. There is also another path, that goes to the south. There is some\
 barking from the clearing there, as there is a mad dog there, which waits\
 for a player to get killed :-)\n\
 South: To a somewhat dangerous dog for low-level players.\n\
 West:  The path leads there to the northern exit of the park.\n\
 East:  There you can find the cats and dogs.\n");

   Set(P_INT_LONG,
      "There is a small crossing here. The road comes in from the west "
      "and continues to the east. A small path leads to the south toward "
      "a rather small clearing.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"silvere2");

   Set(P_REGION, REGION_CITY|REGION_FOREST);
   Set(P_COORDINATES, ({ ({-120,110,0 }), C_SILVERE }) );
   Set(P_NOWAY_MSG,
"You bump into a tree like an idiot. If you do such things often, you\
 probably need a new face in a not too far future.\n");

   AddExit("east", SIL_PARK("forest_south5"));
   AddExit("west", SIL_PARK("forest_south2"));
   AddExit("south",SIL_PARK("forest_south4"));

   AddItem("/std/npc",REFRESH_HOME,
   ({
      ([ P_LEVEL:2,
         P_LONG:
"This is a ugly looking brown dog. It looks at you and growls with foam at his"
"rather sharp teeth.\n",
         P_RACE:"dog",
         P_NAME:"dog",
         P_ADS:({"brown","ugly"}),
         P_ALIGN:0,
         P_MMSGIN:({"runs in, chasing a cat. The cat vanishes in the bushes, and the dog looks at you"}),
         P_MMSGOUT:({"sees a cat and starts chasing it"}),
         P_GENDER:GENDER_MALE,
         P_HANDS:
            ({
               ({"left claw",0,1}),
               ({"right claw",0,1}),
            }),
         P_SHRUG_MSG:"The dog growls at you.\n",
      ]),
      ([ P_DEX:8,
         P_SHORT:"a ugly, brown dog",
      ])
   }),2);

}
