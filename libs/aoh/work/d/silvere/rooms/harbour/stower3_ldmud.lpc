// Inside the tower. Stairs leading up
// created:          Sonic [26-May-1997]
// last changed:     Sonic [05-Jul-1997] added regions/coordinates

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <msgclass.h>
#include <nightday.h>
#include <regions.h>
#include <macros.h>
#include <moving.h>
#include <rooms.h>
inherit BASEROOM;

int SearchCmd(string str)
{
   notify_fail("Search what?\n", NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(strstr(lower_case(str),"ground")!=-1 ||
      strstr(lower_case(str),"floor")!=-1)
   {
      msg_write(CMSG_GENERIC,
         "You kneel down on the ground and search through "
         "the dirt and the dust lying around there. Except "
         "of the dirt on your hands you find nothing.\n");
      if(!({int})TP->Query(P_INVIS)) msg_room(TO, CMSG_ROOM,
         CAP(NAME(TP))+" kneels down and searches through the "
         "dirt and dust on the ground. Looking at "+HISHER(TP)+
         " face after "+HESHE(TP)+" stood up tells you, that "+
         HESHE(TP)+" hasn't found anything.\n");
      return 1;
   }
   if(strstr(lower_case(str),"dirt")!=-1)
   {
      msg_write(CMSG_GENERIC,
         "You kneel down and search through the dirt on the floor. "
         "Alas, you find nothing of interest there.\n");
      if(!({int})TP->Query(P_INVIS)) msg_room(TO, CMSG_ROOM,
         CAP(NAME(TP))+" kneels down and searches through the dirt. "
         "After a few moments, "+HESHE(TP)+" stands up with a "
         "dissapointed look on "+HISHER(TP)+" face.\n", ({TP}) );
      return 1;
   }
   if(strstr(lower_case(str),"dust")!=-1)
   {
      msg_write(CMSG_GENERIC,
         "You kneel down on the ground and search through the dust. "
         "Except of footprints which leads east, west and south you "
         "find nothing of interest. Somehow you can't surpress a "
         "deep sigh.\n");
      if(!({int})TP->Query(P_INVIS)) msg_room(TO, CMSG_ROOM,
         CAP(NAME(TP))+" kneels down on the ground and searches through "
         "the dirt. "+CAP(HESHE(TP))+" looks interested at some "
         "footprints there. After a few moments, "+HESHE(TP)+" stands "
         "up again and sighs deeply. Obviously "+HESHE(TP)+" was not "
         "successful in finding something.\n", ({TP}) );
      return 1;
   }
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,1);
   Set(P_INT_SHORT,"Tower basement, southern corner");
   Set(P_INT_LONG,
      "You are standing at the southern end of the room. A big "
      "stairway leads up to the higher levels of the tower. Next "
      "to it is a small, glowing globe. At the wall to the west "
      "is a huge, wooden wheel with a machine north of it. Directly "
      "to the north is an exit leading out on the harbour.\n");

   Set(P_INT_WIZMSG,
      " Up:    To the second floor of the tower\n"
      " West:  To the storeroom of the chains\n"
      " North: To the exit of the tower.\n");

   AddDetail( ({"place","here","level","room", "south end",
                "southern end","tower"}),
      SF(IntLong));

   AddVItem(
   ([ P_IDS:({"stairway"}),
      P_ADS:({"wooden","big"}),
      P_LONG:
         "The stairway is made out of wood and leads up to the higher "
         "levels of the tower. Some footprints on the stairs shows you "
         "that someone is using them frequently. On the other hand it "
         "tells you that the room need some professional cleaning "
         "service.\n",
   ]) );

   AddVItem(
   ([ P_IDS: ({"cleaning service"}),
      P_ADS: ({"professional"}),
      P_LONG:
         "This service should take care of the room. All over the "
         "floor is lots of dust and dirt. Footprints are leading "
         "to the north, south and up on the stairway. It looks "
         "really messy here.\n",
   ]) );

   AddVItem(
   ([ P_IDS:({"ground","floor"}),
      P_ADS:({"dirty","messy"}),
      P_LONG:
         "The floor is full of dirt and dust. It seems that nobody "
         "felt responsible for cleaning the room in a long time. "
         "There are lots of footprints, leading up the stairway. "
         "Some of the marks are leading to the north, west and up "
         "on the stairway.\n",
   ]) );

   AddDetail( "ceiling",
      "The ceiling high above you is made out of wooden beams.\n");

   AddVItem(
   ([ P_IDS: ({"beam","beams"}),
      P_ADS: ({"wooden"}),
      P_LONG:
         "The beams are building the ceiling of the rooms here at the "
         "basement of the tower. Every now and then you hear someone "
         "walking by above you.\n",
      P_NOISE:
         "Every now and then someone seems to walk around above you. "
         "On the other hand, this could be an hallucination or some "
         "kind of woodworms sitting in the beams.\n",
   ]) );

   AddDetail( ({"wall","walls"}),
      "Which wall do you want to look at? There are four walls around "
      "you, which look quite interesting. Maybe you could be a little "
      "bit more specific?\n");

   AddDetail( ({"north","northern wall","north wall"}),
      "To the north is the exit from the tower. At it's western end "
      "is also a small opening in the wall. Next to it is a large "
      "machine.\n");

   AddDetail( ({"south","southern wall","south wall"}),
      "The wall to the south is dominated by a large stairway, which "
      "leads up to the higher levels of the tower. There is also a "
      "small, glowing globe next to it.\n");

   AddDetail( ({"west","western wall","west wall"}),
      "There is a large, wooden wheel which stands at the western wall. "
      "A chain runs down from it through a machine north of the wheel. "
      "Except of that, there is nothing of interest there.\n");

   AddDetail( ({"east","eastern wall","east wall"}),
      "At the northern end of the eastern wall is the exit from the "
      "tower. Next to it is a small, glowing globe, which lights that "
      "part of the room.\n");

   AddDetail( ({"exit","exits"}),
      "You can see two exits here. To the north is the exit out of the "
      "tower to the harbour of Silvere. You see also an stairway, which "
      "leads up to the upper levels of the tower.\n");

   AddDetail( "harbour",
      "The harbour belongs to Silvere, one of the largest cities of the "
      "world. Ships arrive and depart from here.\n");

   AddDetail( "world",
      "You are there right now. Have fun, while you are here.\n");

   AddDetail( ({"city","silvere"}),
      "Silvere is one of the largest cities of the world. On the other "
      "hand, there is a good chance, that it is the largest city of the "
      "world. If you want to enter the city, just leave the tower and "
      "follow the quays to the east.\n");

   AddVItem(
   ([ P_IDS:({"globe"}),
      P_ADS:({"glowing","glass"}),
      P_LONG:
         "The globe is hanging on the wall, just next to the stairway. "
         "There is another globe at the exit to the north and at the "
         "northern wall, next to a small opening there. Their light "
         "doesn't reach this place, though. The globe is glowing in a "
         "friendly, yellow light and lights this corner of the room. "
         "It is made out of glass. There is also a small, locked box "
         "below the globe.\n",
      P_SMELL:
         "The globe doesn't smell. But from the flame you sense "
         "the odor of burned oil.\n",
      P_NOISE:
         "You hear a muted crackling from the small flame inside "
         "the globe.\n",
   ]) );

   AddVItem(
      ([ P_IDS:({"flame"}),
         P_LONG:"The flame is burning inside the globe.\n",
         P_SMELL:"From the flame you smell the odor of burned oil.\n",
         P_NOISE:
            "You hear a muted crackling from the small flame.\n",
      ]) );

   AddDetail( "symbol",
      "The symbol shows you a single flame. It is painted on the "
      "box below the globe.\n");

   AddVItem(
      ([ P_IDS:({"box"}),
         P_ADS:({"small","locked"}),
         P_LONG:
            "The box is directly connected to the globe. A small "
            "symbol, that resembles a flame is painted on it. There"
            "is also a small lock, where the box can be opened.\n",
         P_SMELL:
            "The box doesn' smell. At least you are not able "
            "to sense something from it.\n",
         P_NOISE:
            "There is nothing, you can hear from the box. It is "
            "silent there.\n",
      ]) );

   AddVItem(
   ([ P_IDS:({"levels"}),
      P_ADS:({"higher","upper"}),
      P_LONG:
         "If you follow the stairway up, you will reach them.\n",
   ]) );

   AddVItem(
   ([ P_IDS:({"opening"}),
      P_ADS:({"small"}),
      P_LONG:
         "The opening is in the northern wall. You can't see much "
         "of it from here. If you want to find out more about it, "
         "you should have a closer look on it...\n",
   ]) );

   AddVItem(
   ([ P_IDS:({"wheel"}),
      P_ADS:({"high","large","wooden"}),
      P_LONG:
         "The wheel can be found to the west. It is quite huge. "
         "Oh, and it is made out of wood. From your place that is "
         "all you can see. Maybe you should go a bit closer and "
         "have another look?\n",
   ]) );

   AddVItem(
   ([ P_IDS:({"machine"}),
      P_ADS:({"wooden"}),
      P_LONG:
         "The machine can be found at the western end of the room, "
         "just north of the wheel. You can't see any details from "
         "the place you are standing at the moment. Maybe it helps "
         "if you go closer and have another look...\n",
   ]) );

   AddDetail( ({"detail","details"}),
      "There are lots of details here. Maybe you should have a look "
      "to find all of them...\n");

   AddRoomCmd( "search",SF(SearchCmd));

   Set(P_INT_MAP,"harbour");
   Set(P_REGION, REGION_CITY|REGION_HARBOUR);
   Set(P_COORDINATES, ({ ({ -280,30,0 }), C_SILVERE }) );
   Set(P_NOWAY_MSG,"You run into a wall.\n");

   AddExit("west", SIL_HARBOUR("stower4"));
   AddExit("north",SIL_HARBOUR("stower1"));
   AddExit("up",   SIL_HARBOUR("stower5"));
}
