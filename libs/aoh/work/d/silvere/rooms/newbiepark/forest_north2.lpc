// A small place in the forest, where you can beat some rats :-)
// created:       Sonic    [07-Jun-1997]
// changed:       Sonic [05-Jul-1997] added region/coordinates

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
            if(present("rat",find_object(exitdesc[a])))
               desc+="There are squeaks from the east. ";
         }
         if(exitkey[a]=="west")
         {
            load_object(exitdesc[a]);
            if(present("rat",find_object(exitdesc[a])))
               desc+="Something moves to the west. ";
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
"Some rats are here. Just some nice and easy creatures to kill newbies\
 or get killed by them. The rats are a bit harder to kill here than to\
 the west.\n\
 West: To a crossing.\n\
 East: Follow the road to more encounters.\n");

   Set(P_INT_LONG,
      "The path leads in from the west and continues to the east. "
      "The area to the north and south is filled with trees, but the "
      "way is blocked by bushes, which grow to dense to pass through.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"silvere2");
   Set(P_REGION, REGION_CITY|REGION_FOREST);
   Set(P_COORDINATES, ({ ({-120,70,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You bump into a tree like an idiot. If you do such things often, you\
 probably need a new face in a not too far future.\n");

   AddExit("west", SIL_PARK("forest_north1"));
   AddExit("east", SIL_PARK("forest_north3"));

   AddItem("/std/npc",REFRESH_HOME,
   ({
      ([ P_LEVEL:2,
         P_LONG:
"This is a big rat. Is is a fat, ugly creature and hisses angrily. It "
"looks at you and seems to be a little bit unsure, if it should attack "
"or not.\n",
         P_RACE:"rat",
         P_NAME:"rat",
         P_ADS:({"big","fat","ugly"}),
         P_ALIGN:-200,
         P_MMSGIN:({"crawls out of a small hole in the ground."}),
         P_MMSGOUT:({"crawls in a small hole in the ground."}),
         P_GENDER:GENDER_MALE,
         P_HANDS:
            ({
               ({"left claw",0,1}),
               ({"right claw",0,2}),
            }),
         P_SHRUG_MSG:"The rat hisses at you.\n",
      ]),
      ([ P_DEX:4,
         P_SHORT:"a big, ugly rat",
      ])
   }),2 );
}
