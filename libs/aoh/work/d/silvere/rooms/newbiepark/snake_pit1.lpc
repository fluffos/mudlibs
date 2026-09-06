// A small area in the bushes. There are some snakes here, easy prey
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
   string desc,wizmsg;    // wizmsg is temporary until P_WIZ_MSG is no longer needed
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
         if(exitkey[a]=="southeast")
         {
            load_object(exitdesc[a]);
            if(present("snake",find_object(exitdesc[a])))
               desc+="Something rattles from time to time to the southeast. ";
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
   Set(P_INT_SHORT,"In a snake pit");
   Set(P_INT_WIZMSG,
"The area here is full of bushes, with an opening to the east. "
"There are some harmless snakes here, which can be killed.\n"
" East:       back on the road.\n"
" southeast:  Enter the snakepit with a poisonous snake.\n");

   Set(P_INT_LONG,
      "You are standing between some bushes. There is an opening to the "
      "east, which leads back to the forest. To the southeast, a small path "
      "leads deeper into the bushes.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"silvere2");
   Set(P_REGION, REGION_CITY|REGION_FOREST);
   Set(P_COORDINATES, ({ ({-100,140,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You run in one of the bushes. Unfortunately, there are lots of thorns "
"there and you get lots of scratches on your bare skin.\n");

   AddExit("east",      SIL_PARK("forest_south10"));
   AddExit("southeast", SIL_PARK("snake_pit2"));

   AddItem("/std/npc",REFRESH_REMOVE,
   ({
      ([ P_LONG:
            "The snake crawls around on the floor. It doesn't even pretend "
            "to look dangerous. Instead it has a brown color, which makes "
            "it pretty unobtrusive.\n",
         P_LEVEL:1,
         P_GENDER:GENDER_MALE,
         P_RACE:"snake",
         P_NAME:"snake",
         P_ADS: ({"brown","small"}),
         P_ALIGN:0,
         P_HANDS:({ ({"bite",0,1}),({"bite",0,1}) }),
         P_MSGIN:({"crawls in"}),
         P_MSGOUT:({"crawls out"}),
         P_MMSGIN:({"crawls out under a bush"}),
         P_MMSGOUT:({"crawls under a bush and is gone"}),
         P_SHRUG_MSG:"The snake seems to have difficulties to understand you.\n",
      ]),
      ([ P_DEX:2,
         P_SHORT:"a small, brown snake",
      ]),
   }),4);
}
