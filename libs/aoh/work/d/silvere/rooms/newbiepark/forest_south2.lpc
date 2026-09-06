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
         if(exitkey[a]=="east")
         {
            load_object(exitdesc[a]);
            if(present("dog",find_object(exitdesc[a])))
               desc+="Something runs around to the east. "
                     "You hear also some barking from there. ";
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
"This is a small path in the forest. To the east is a small crossing,\
 where the road leads to the south on a small clearing. The road leads\
 to the east deeper into the forest.\n\
 Northeast: The path leads there to the northern exit of the park.\n\
 East:      There you can find the cats and dogs.\n");

   Set(P_INT_LONG,
      "This is a small path through the forest. Directly to the west "
      "is the wall of the city. Some bushes are growing at the base "
      "of the wall. To the east is a small crossing, where the path "
      "leads to the south on a small clearing.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"silvere2");
   Set(P_REGION, REGION_CITY|REGION_FOREST);
   Set(P_COORDINATES, ({ ({-130,110,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You bump into a tree like an idiot. If you do such things often, you\
 probably need a new face in a not too far future.\n");

   AddExit("northwest", SIL_PARK("forest_south1"));
   AddExit("east",      SIL_PARK("forest_south3"));
}
