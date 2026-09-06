// A small place in the forest, where you can beat some rabbits :-)
// created:       Sonic    [07-Jun-1997]
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
         if(exitkey[a]=="northwest")
         {
            load_object(exitdesc[a]);
            if(present("rat",find_object(exitdesc[a])))
               desc+="There are squeaks coming from the northwest. ";
         }
         if(exitkey[a]=="east")
         {
            load_object(exitdesc[a]);
            if(present("rabbit",find_object(exitdesc[a])))
               desc+="Something strange is going on to the east. ";
         }
         if(exitkey[a]=="southwest")
         {
            load_object(exitdesc[a]);
            if(present("rabbit",find_object(exitdesc[a])))
               desc+="Something moves to the southwest every now and then. ";
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
"Some rabbits are here. This ones are a bit harder to kill than the\
 bunnies to the southwest.\n\
 East:      The room with the insane hare.\n\
 Northwest: The path with the rats.\n\
 Southeast: to a small crossing.\n");

   Set(P_INT_LONG,
      "The path leads in from the west and continues to the southeast. "
      "The area to the north and south is filled with trees, but the "
      "way is blocked by bushes, which grow to dense to pass through.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"silvere2");
   Set(P_REGION, REGION_CITY|REGION_FOREST);
   Set(P_COORDINATES, ({ ({-100,80,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You bump into a tree like an idiot. If you do such things often, you\
 probably need a new face in a not too far future.\n");

   AddExit("east",      SIL_PARK("forest_north5"));
   AddExit("northwest", SIL_PARK("forest_north3"));
   AddExit("southwest", SIL_PARK("forest_room8"));

   AddItem("/std/npc",REFRESH_REMOVE,
   ({
      ([ P_LONG:
"This is a rabbit. It sits here at the path and looks dubiously at "
"the grass. It's fure is brown and the eyes are black. It looks "
"rather shy, but it seems to watch you carefully and without fear.\n",
         P_LEVEL:2,
         P_GENDER:GENDER_FEMALE,
         P_RACE:"rabbit",
         P_NAME:"rabbit",
         P_ADS: ({"brown"}),
         P_ALIGN:100,
         P_MSGIN:({"hops in"}),
         P_MSGOUT:({"hops out"}),
         P_MMSGIN:({"suddenly runs out of the bushes and looks surprised at you"}),
         P_MMSGOUT:({"suddenly runs into the bushes and is gone"}),
         P_SHRUG_MSG:"The bunny looks at you and says nothing.\n",
      ]),
      ([ P_DEX:4,
         P_SHORT:"a brown rabbit"
      ])
   }),2);
}
