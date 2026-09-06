// A small path, leading east to west. To the east are rabbits, which may
// be killed
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
         if(exitkey[a]=="southwest")
         {
            load_object(exitdesc[a]);
            if(present("cat",find_object(exitdesc[a])))
               desc+="Something moves to the southwest. ";
         }
         if(exitkey[a]=="northwest")
         {
            load_object(exitdesc[a]);
            if(present("rabbit",find_object(exitdesc[a])))
               desc+="Every now and then something moves just to the northwest. ";
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
"This is a small path in the forest. To the nortwest are rabbits, which\
 may be an easy kill, here are usually some small cats\n\
 Northwest: Some rabbits to be slain (easy prey)\n\
 Southwest: Some bigger cats (medium targets)\n");

   Set(P_INT_LONG,
      "The road leads here through the forest. There are lots of "
      "trees and bushes to both sides of the path. To the north "
      "and south are some crossings.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"silvere2");
   Set(P_REGION, REGION_CITY|REGION_FOREST);
   Set(P_COORDINATES, ({ ({-100,100,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You bump into a tree like an idiot. If you do such things often, you\
 probably need a new face in a not too far future.\n");

   AddExit("northwest", SIL_PARK("forest_room8"));
   AddExit("southwest", SIL_PARK("forest_south5"));

   AddItem("/std/npc",REFRESH_REMOVE,
   ({
      ([ P_LONG:
"This is a small cat. It sits next to a bush and looks carefully at "
"a mousehole. The tail is moving furiously around. The cat is grey "
"with some black spots all over the fur.\n",
         P_LEVEL:2,
         P_GENDER:GENDER_FEMALE,
         P_RACE:"cat",
         P_NAME:"cat",
         P_ALIGN:200,
         P_MSGIN:({"sneaks in"}),
         P_MSGOUT:({"sneaks out"}),
         P_MMSGIN:({
            "jumps out of the bushes and tries to catch a mouse. But the "
            "mouse enters a small hole near a bush and is gone, before the "
            "cat catches it"}),
         P_MMSGOUT:({"suddenly runs into the bushes and is gone"}),
         P_SHRUG_MSG:"The cat looks at you and says: MEEOOWWWW.\n",
      ]),
      ([ P_DEX:2,
         P_SHORT:"a small cat",
      ])
   }),2);
}
