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
         if(exitkey[a]=="east")
         {
            load_object(exitdesc[a]);
            if(present("rabbit",find_object(exitdesc[a])))
               desc+="Every now and then something moves just to the east. ";
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
"This is a small path in the forest. To the east are rabbits, which\
 may be killed, to the west is a crossing.\n\
 West: A crossing (nw/sw)\n\
 east: Slay some rabbits there.\n");

   Set(P_INT_LONG,
      "This is a small path in the crossing. The path leads in from "
      "west and continues to the east. To the north and south are lots "
      "of trees, but no way, where you can enter them, as bushes block "
      "the entrance there.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"silvere2");
   Set(P_REGION, REGION_CITY|REGION_FOREST);
   Set(P_COORDINATES, ({ ({-120,90,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You bump into a tree like an idiot. If you do such things often, you\
 probably need a new face in a not too far future.\n");

   AddExit("west", SIL_PARK("forest_room6"));
   AddExit("east", SIL_PARK("forest_room8"));
}
