// The mainroad to the southgates
// created:       Sonic    [19-Jun-1997]
// last changed:  Sonic    [05-Jul-1997] added region/coordinates

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <msgclass.h>
#include <regions.h>
#include <moving.h>
#include <rooms.h>
#include <macros.h>
inherit SILBASEROOM;

int climb3()
{
   msg_write(CMSG_GENERIC,
"The skin on your hands becomes bright red. You loose your grip on the ivy "
"and fall on the ground.\n");
   show( CAP(NAME(TP))+" falls to the ground. "+CAP(HISHER(TP))+" hands are bright red.\n");
   // *** maybe some damage can be done too...
   return 1;
}

int climb2()
{
   object *weapons;

   weapons=({object *})TP->Query(P_WEAPONS);
   if(sizeof(weapons)!=0)
   {
      int a;

      msg_write(CMSG_GENERIC,"Your hands starting to itch badly.\n");
      for(a=0; a<sizeof(weapons); a++)
      {
         /* I'm not sure, if this will work properly for two-handed
          * weapons too.
          */
         weapons[a]->Unwield();
         weapons[a]->move(TO,M_DROP);
         msg_write(CMSG_GENERIC,"A "+strip_a(({string})weapons[a]->Query(P_SHORT))+" falls to the ground.\n");
         msg_say(CMSG_GENERIC,"A weapon falls down from the ivy, where "+CAP(NAME(TP))+"climbs higher.\n");
      }
   }
   else msg_write(CMSG_GENERIC,"Your hands start to itch.\n");
   call_out("climb3");
   return 1;
}

int climb_ivy(string str)
{
   notify_fail("Climb what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"wall")!=-1 ||
      strstr(lower_case(str),"ivy")!=-1)
   {
      /* If you are here, you will start to climb up the wall, using the
       * poison ivy as help. Your hands will itch after a short time, you
       * will loose grip of your weapons and the sides of your hands will
       * become red and wounded. Depending on the climbing skill and
       * maybe dexterity, you will fall to the ground.
       *
       * Once you touched the ivy, you will get poisoned by it. The
       * poison is not deadly, but makes it impossible for you to wield
       * anything until you have visited a healer. That feature will be
       * added later, when the druid of Eilan is done or when i had some
       * sleep :-)
       *
       * Sonic, 19-June-1997 (very late)
       */
      msg_write(CMSG_GENERIC,"You grab the ivy and start climbing up the wall.\n");
      msg_say(CMSG_GENERIC,CAP(NAME(TP))+" climbs up the ivy, toward the top of the wall.\n");
      call_out("climb2",3);
      return 1;
   }
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"On a road at Silvere");
   Set(P_INT_LONG,
"This are the southern gates of Silvere. During daytime, the gates are "
"opened, but guarded. At night, they are closed and a player has to find "
"other places to leave the city. All over the wall is growing ivy, hanging "
"down from the battlements.\n");

   Set(P_INT_WIZMSG,
" North: to the citypark, deeper into the city.\n"
" South: to the surrounding area of the city.\n");

   AddDetail( "ivy",
"The ivy is hanging down from the battlements of the wall. There are "
"shiny, three-parted leaves there. The ivy looks quite climbable.\n");

   AddDetail( ({"wall","city wall","wall of silvere","citywall"}),
"The wall surrounds the city of Silvere. From the battlements you see "
"lots of ivy growing down. The ivy looks strong and it shouldn't be "
"much of a problem to climb up there.\n");

   /*
    * Add some details here. *grin*
    */

   AddRoomCmd("climb",#'climb_ivy /*'*/);

   Set(P_INT_MAP,"silvere3");
   Set(P_REGION, REGION_CITY);
   Set(P_COORDINATES, ({ ({0,160,0 }), C_SILVERE }) );
   Set(P_NOWAY_MSG,
"You walk into a wall like an idiot. Somehow you have the feeling, that\
 everyone laughs at you.\n");

   AddExit("north",   SIL_SOUTH("mainroad11"));
   AddExit("south",   SIL_SOUTH("wilderness1"));
}
