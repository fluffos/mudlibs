// A small path with cats, leading east and southeast
// created:       Sonic    [15-Jun-1997]
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
   string desc,wizmsg;    // wismsg is temporary until P_WIZ_MSG is no longer needed
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
            if(present("cat",find_object(exitdesc[a])))
               desc+="Every now and then something moves just right to the west. ";
         }
         if(exitkey[a]=="east")
         {
            load_object(exitdesc[a]);
            if(present("cat",find_object(exitdesc[a])))
               desc+="Something big is to the east. There are also some noises from that direction. ";
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
   Set(P_INT_SHORT,"on a path in the forest");
   Set(P_INT_WIZMSG,
"This is a small path in the forest. To the east is a big and mean cat\
 which is a rather hard target for a newbie. To the west are some medium\
 sized cats.\n\
 West:      Go and find some cats on the crossing there.\n\
 East:      A mean and ugly cat is to the east (hard target).\n\
 Southeast: To the southern exit of the park.\n");

   Set(P_INT_LONG,
      "This is a small path in the crossing. The path leads in from "
      "west and continues to the southeast.  There is an opening in the "
      "bushes to the east, where you can pass through.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"silvere2");
   Set(P_REGION, REGION_CITY|REGION_FOREST);
   Set(P_COORDINATES, ({ ({-100,110,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You bump into a tree like an idiot. If you do such things often, you\
 probably need a new face in a not too far future.\n");

   AddExit("southeast", SIL_PARK("forest_south7"));
   AddExit("west",      SIL_PARK("forest_south5"));
   AddExit("east",      SIL_PARK("forest_south8"));
}
