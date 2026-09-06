// The entrance to the city park.
// created:       Sonic    [15-Jun-1997]
// last changed:  Sonic [05-Jul-1997] added region/coordinates

#include <silvere.h>
#include <properties.h>
#include <msgclass.h>
#include <coordinates.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
inherit BASEROOM;

int leave_park(string str)
{
   notify_fail("Leave what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"park")!=-1)
   {
      msg_write(CMSG_GENERIC,"You leave the citypark.\n");
      TP->move(SIL_SOUTH("parkenter"),M_GO,"east");
      return 1;
   }
   return 0;
}

int enter_city(string str)
{
   notify_fail("Enter what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"city")!=-1)
   {
      msg_write(CMSG_GENERIC,"You enter the city.\n");
      TP->move(SIL_SOUTH("parkenter"),M_GO,"east");
      return 1;
   }
   return 0;
}

int check_ground(string str)
{
   notify_fail("Search what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(!TP)  return 0;
   if(strstr(lower_case(str),"ground")!=-1)
   {
      msg_say(CMSG_GENERIC,CAP(NAME(TP))+" searches the ground.\n");
      msg_write(CMSG_GENERIC,
         "Sorry "+CAP(RNAME(TP))+", but as everything here is under "
         "construction, you find nothing at the moment. How about "
         "if you try again later?\n");
      return 1;
   }
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,0);
   Set(P_INT_SHORT,"Citypark entrance");
   Set(P_INT_WIZMSG,
"There should be an important looking sign, which gives some\
 instructions on how to fight, how to use the whimpy mode and\
 some other things. Maybe we can also equip the player with a\
 basic knife and armour, which is worth nearly nothing, but\
 should be sufficient to be used against the npcs in that area.\n\
North: (or 'enter city'/'leave park') the road leads back to Silvere.\n\
East:  walk deeper into the citypark\n");

   Set(P_INT_LONG,
      "You are standing at the border of a nice little forestal area "
      "inside the city wall. Some harmless animals are supposed to "
      "run around here for recreational purposes and nice roads can "
      "be found between the trees. There is also an important looking "
      "sign here.\n");

   AddDetail( ({"sign","important sign"}),
      "This sign looks important. There are lots of words written "
      "on its wooden surface.\n");
   AddDetail( ({"words","word","text"}),
      "The text that is written on the sign seems to be important. "
      "Maybe you should read it?\n");

   AddReadMsg( ({"sign","important sign","word","words","text"}),
      "This area is the citypark of the town of Silvere. If you "
      "walk further to the east you will find some creatures "
      "that shouldn't be too dangerous for a low level player. "
      "That is, if you set your wimpy mode to a somewhat decent "
      "level (for example wimpy 20).\nIf you encounter a creature "
      "inside that area it is always good to have a look at it. "
      "Then, if you still think that you are strong enough to attack "
      "it, try to kill it (e.g. kill rabbit).\nIf you lack of killing "
      "equipment, search the ground here and you may find something "
      "more or less useful (if you are still a new player here).\n");

   /*
    * Add some details here. *grin*
    */

   AddRoomCmd("enter", #'enter_city /*'*/);
   AddRoomCmd("leave", #'leave_park /*'*/);
   AddRoomCmd("search", #'check_ground /*'*/);

   Set(P_INT_MAP,"silvere2");
   Set(P_REGION, REGION_CITY|REGION_FOREST);
   Set(P_COORDINATES, ({ ({-80,140,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,
"You walk into the wall like an idiot. Somehow you have the feeling that\
 everyone laughs at you.\n");

   AddExit("west", SIL_PARK("forest_south10"));
   AddExit("east", SIL_SOUTH("parkenter"));
}
