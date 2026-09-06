// A small place in the forest, where you can beat a big and mean cat
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
         if(exitkey[a]=="west")
         {
            load_object(exitdesc[a]);
            if(present("cat",find_object(exitdesc[a])))
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
   Set(P_INT_SHORT,"Between some bushes.");
   Set(P_INT_WIZMSG,
"This is the place, where a big and mean cat hides. It is a rather "
"hard target for a newbie.\n\
 West: Back to the forest.\n");

   Set(P_INT_LONG,
      "You are standing right between some bushes, as the path suddenly "
      "stops. Right before you sits a really big cat with the meanest "
      "face you have ever seen on that kind of animal. To the west is "
      "a small opening between the bushes, where you can leave this "
      "place.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"silvere2");
   Set(P_REGION, REGION_CITY|REGION_FOREST);
   Set(P_COORDINATES, ({ ({-90,110,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You run in one of the bushes. Unfortunately, there are lots of thorns "
"there and you get lots of scratches on your bare skin.\n");

   AddExit("west",   SIL_PARK("forest_south6"));

   AddItem("/std/npc",REFRESH_REMOVE,
   ({
      ([ P_LONG:
            "This is a big cat. It has the meanest face, you have ever "
            "seen on that kind of animal. Something has bitten off one "
            "of the ears of that cat, the tail has vanishes except of a "
            "little piece and the whole body is covered with scars and "
            "bloodstains. This cat seems to get involved in lots of "
            "fights and seems to be quite experienced.\n",
         P_LEVEL:5,
         P_GENDER:GENDER_MALE,
         P_RACE:"cat",
         P_NAME:"cat",
         P_ADS: ({"big","black","mean"}),
         P_ALIGN:-200,
         P_MSGIN:({"sneaks in"}),
         P_MSGOUT:({"sneaks out"}),
         P_MMSGIN:({"suddenly runs out of the bushes and looks angrily at you"}),
         P_MMSGOUT:({"suddenly runs into the bushes and is gone"}),
         P_SHRUG_MSG:"The cat meows.\n",
         P_AGGRESSIVE:1,
         P_ATTACK_CHANCE:1000,
      ]),
      ([ P_DEX:7,
         P_SHORT:"a big and ugly cat",
      ]),
   }) );
}
