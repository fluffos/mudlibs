// Between some bushes. Exit to the east, dangerous snake here
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
         if(exitkey[a]=="northwest")
         {
            load_object(exitdesc[a]);
            if(present("snake",find_object(exitdesc[a])))
               desc+="Something moves to the east. ";
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
"The area here is full of bushes, with an opening to the northwest. "
"There is a big poisonous snake here. At the northern exit is "
"a healer, if a player is unlucky and gets poisoned.\n"
" Northwest:  Back to the entrance of the pit.\n");

   Set(P_INT_LONG,
      "You are standing between some bushes. There is an opening to the "
      "northwest, where you entered that place.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"silvere2");
   Set(P_REGION, REGION_CITY|REGION_FOREST);
   Set(P_COORDINATES, ({ ({-90,150,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You run in one of the bushes. Unfortunately, there are lots of thorns "
"there and you get lots of scratches on your bare skin.\n");

   AddExit("northwest", SIL_PARK("snake_pit1"));

   AddItem("/std/npc",REFRESH_REMOVE,
   ({
      ([ P_LONG:
            "The snake crawls around on the ground. It has two dangerous "
            "looking fangs and a rattle at the back end. It sits on a "
            "stone and let the sun shine on it.\n",
         P_LEVEL:4,
         P_GENDER:GENDER_MALE,
         P_RACE:"snake",
         P_NAME:"rattlesnake",
         P_ADS: ({"dangerous"}),
         P_ALIGN:0,
         P_HANDS:({ ({"bite",0,1}),({"bite",0,1}) }),
         P_MSGIN:({"crawls in"}),
         P_MSGOUT:({"crawls out"}),
         P_MMSGIN:({"crawls out under a bush"}),
         P_MMSGOUT:({"crawls under a bush and is gone"}),
         P_SHRUG_MSG:"The snake seems to have difficulties to understand you.\n",
      ]),
      ([ P_DEX:7,
         P_SHORT:"a rattlesnake",
      ]),
   }),1);
}
