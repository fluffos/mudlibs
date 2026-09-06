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
         if(exitkey[a]=="northeast")
         {
            load_object(exitdesc[a]);
            if(present("cat",find_object(exitdesc[a])))
               desc+="Something moves right to the northeast. ";
         }
         if(exitkey[a]=="south")
         {
            load_object(exitdesc[a]);
            if(present("cat",find_object(exitdesc[a])))
               desc+="There is some movement to the east. ";
         }
         if(exitkey[a]=="west")
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
"This is the path in the forest. To the northeast are some easy cats\
 to be killed, here are the medium ones. To the west are some medium\
 dogs.\n\
 West:      To the crossing with the dogs.\n\
 East:      To some more cats and the southern exit.\n\
 Northeast: To more easier animals (rats, bunnies, small cats.\n");

   Set(P_INT_LONG,
      "This path leads in from northeast and continues west. A fork "
      "leads to the east. Trees and bushes are growing everywhere.\n");

   /*
    * Add some details here. *grin*
    */

   Set(P_INT_MAP,"silvere2");
   Set(P_REGION, REGION_CITY|REGION_FOREST);
   Set(P_COORDINATES, ({ ({-110,110,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You bump into a tree like an idiot. If you do such things often, you\
 probably need a new face in a not too far future.\n");

   AddExit("west",      SIL_PARK("forest_south3"));
   AddExit("east",      SIL_PARK("forest_south6"));
   AddExit("northeast", SIL_PARK("forest_room9"));

   AddItem("/std/npc",REFRESH_REMOVE,
   ({
      ([ P_LONG:
"This is a big, black cat. He sits next to a bush and looks carefully at "
"a mousehole. The tail is moving furiously around. The cat is black with "
"white paws. One of the ears is missing, and there is a scar right under "
"the right eye, what gives the cat a somewhat evil face.\n",
         P_LEVEL:2,
         P_GENDER:GENDER_MALE,
         P_RACE:"cat",
         P_NAME:"cat",
         P_ALIGN:150,
         P_MSGIN:({"sneaks in"}),
         P_MSGOUT:({"sneaks out"}),
         P_MMSGIN:({
            "jumps out of the bushes and tries to catch a mouse. But the "
            "mouse enters a small hole near a bush and is gone, before the "
            "cat catches it"}),
         P_MMSGOUT:({"suddenly runs into the bushes and is gone"}),
         P_SHRUG_MSG:"The cat looks at you and says: MEEOOWWWW.\n",
      ]),
      ([ P_DEX:6,
         P_STR:4,
         P_SHORT:"a big, black cat",
      ])
   }),2);
}
