// Inside the tower. The storeroom of the raised chains
// created:          Sonic [26-May-1997]
// last changed:     Sonic [05-Jul-1997] added regions/coordinates

#include <silvere.h>
#include <specialrooms.h>
#include <properties.h>
#include <coordinates.h>
#include <nightday.h>
#include <msgclass.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
inherit BASEROOM;

int rMachine;

int QueryMachine()   { return rMachine; }
int SetMachine(int nr)
{
   if(!nr) nr=0;
   rMachine=nr;
   return rMachine;
}

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

string CheckWheelDesc()
{
   int a;
   string desc;

   desc=
      "The wheel can be found at the corner of this place. It is "
      "a quite huge one. And, by the way, it is completely made out "
      "of wood. ";
   a=({int})SIL_SOUTH_MACHINEROOM->QueryChain();
   if(a==1) desc+="It is filled with a chain.\n";
   else desc+="It is empty, but an iron chain is attached to it.\n";
   return desc;
}

string CheckWheelNoise()
{
   int a;

   a=({int})SIL_SOUTH_MACHINEROOM->QueryMachine();
   if(a==1) return
      "You hear the wheel turning around.\n";
   else return
      "You can't hear any noise from the wheel.\n";
}

string CheckOpening()
{
   string desc;

   desc=
      "The opening is in the northern wall at the western end of "
      "the room. A large chain is running through it. ";
   switch(({int})NIGHTDAY->QueryState())
   {
      case ND_NIGHT:
         desc+=
            "Outside of the opening it's dark, as there is no "
            "light shining through it.\n";
         break;
      case ND_PREDAWN.. ND_SUNRISE:
      case ND_TWILIGHT..ND_EVENING:
         desc+=
            "Outside of the opening is some light. It shines "
            "through it and gives more light to some parts of "
            "the room near it.\n";
         break;
      case ND_EARLY_MORNING..ND_SUNSET:
         desc+=
            "It's day outside of the tower. Some light shines "
            "through the opening and sends a ray of full light "
            "into the room.\n";
         break;
      default:
         desc+=
            "There is something to the outside of the opening "
            "but you can't clearly define it.\n";
         break;
   }
   return desc;
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,1);
   Set(P_INT_SHORT,"Tower basement, western corner");
   Set(P_INT_LONG,
      "A large wooden wheel dominates the corner of the room. A long "
      "chain runs down from it into a machine to the north. To the east "
      "is a stairway leading up to the upper levels of the tower.\n");

   Set(P_INT_WIZMSG,
      " East:  the stairs to the upper floors\n"
      " North: the activation of the machine\n");

   AddDetail( ({"place","here","level","room","south end",
                "southern end","tower","corner"}),
      SF(IntLong));

   AddVItem(
   ([ P_IDS:({"stairway"}),
      P_ADS:({"wooden","big"}),
      P_LONG:
         "The stairway is made out of wood and leads up to the higher "
         "levels of the tower. Unfortunately, you are too far away from "
         "it to see much details. Maybe you should go closer and have "
         "another look?\n",
   ]) );

   AddVItem(
   ([ P_IDS:({"ground","floor"}),
      P_ADS:({"dirty","messy"}),
      P_LONG:
         "The floor is full of dirt and dust. It seems that nobody "
         "felt responsible for cleaning the room in a long time. "
         "Some footprints are leading north and east away from this "
         "corner of the room.\n",
   ]) );

   AddVItem(
   ([ P_IDS:({"cleaning service"}),
      P_ADS:({"professional"}),
      P_LONG:
         "This service should take care of the room. All over the "
         "floor you see lots of dust and dirt. Footprints are leading "
         "away from this corner of the room to the north and east. "
         "It looks really messy here and somehow you have the feeling "
         "that someone should clean up this room.\n",
   ]) );

   AddDetail( "ceiling",
      "The ceiling high above you is made out of heavy, wooden "
      "beams.\n");

   AddVItem(
   ([ P_IDS:({"beam","beams"}),
      P_ADS:({"wooden","heavy"}),
      P_LONG:
         "The beams are building the ceiling of the rooms here at the "
         "basement of the tower. Every now and then you hear someone "
         "walking by above you.\n",
      P_NOISE:
         "Every now and then someone seems to walk around above you. "
         "On the other hand, this could be an hallucination or some "
         "kind of woodworms sitting in the beams.\n",
   ]) );

   AddVItem(
   ([ P_IDS:({"wheel"}),
      P_ADS:({"large","high","wooden"}),
      P_LONG:SF(CheckWheelDesc),
      P_SMELL:"The wheel doesn't smell at all.\n",
      P_NOISE:SF(CheckWheelNoise),
   ]) );

   AddDetail( ({"exit","exits"}),
      "You can leave the corner of the room to the north and east. To "
      "the north is a wall with an opening. To the east is another wall "
      "where you can see a stairways leading up.\n");

   AddVItem(
   ([ P_IDS:({"chain"}),
      P_ADS:({"long","heavy","iron"}),
      P_LONG:
         "The chain is made from iron. It is very long and looks "
         "quite heavy. It comes from the wheel and runs through the "
         "machine to the north.\n",
      P_SMELL:
         "The chain doesn't smell very much. On the other hand, the "
         "scent of rust fills this corner...\n",
      P_NOISE:
         "There is nothing to be heard from the chain.\n",
   ]) );

   AddVItem(
   ([ P_IDS:({"machine"}),
      P_ADS:({"large","wooden"}),
      P_LONG:
         "The machine is placed at the western wall just north of here. "
         "It is very large and made out of wood. The chain runs through "
         "the machine from the wheel and vanishes in an small opening "
         "at the northern wall. On top of the machine is a small handle "
         "which looks quite interesting. If you want to find out more "
         "about it you have to go closer and have another look on it.\n",
      P_NOISE:
         "There is nothing to be heard from the machine at the moment. "
         "It doesn't move.\n",
   ]) );

   AddVItem(
   ([ P_IDS:({"opening"}),
      P_ADS:({"small"}),
      P_LONG:SF(CheckOpening),
   ]) );

   AddDetail( "stairway",
      "The stairway can be found to the east. You can reach the higher "
      "levels of the tower there.\n");

   AddDetail( ({"wall","walls"}),
      "Which wall do you want to look at? There are four walls around "
      "you, which look quite interesting. Maybe you could be a little "
      "bit more specific?\n");

   AddDetail( ({"north","north wall","northern wall"}),
      "At the wall to the north is a small opening, where the chain "
      "runs through. A small globe is attached to the wall and spends "
      "some light to the room.\n");

   AddDetail( ({"south","south wall","southern wall"}),
      "The wall to the south is blank. You can see only the bare "
      "stones from which it was built.\n");

   AddDetail( ({"west","west wall","western wall"}),
      "Directly to the west is a large wheel made from wood. Behind it "
      "is the wall, but there is nothing unusual.\n");

   AddDetail( ({"east","east wall","eastern wall"}),
      "To the east is a stairway leading up to the upper levels of the "
      "tower. Just next to it is a small globe which lights that part "
      "of the room.\n");

   AddVItem(
   ([ P_IDS:({"level","levels"}),
      P_ADS:({"higher","upper"}),
      P_LONG:
         "You can't see them from this place. If you want to know more "
         "about them, you should follow the stairway up.\n",
   ]) );

   AddVItem(
   ([ P_IDS:({"globe"}),
      P_ADS:({"glowing","glass"}),
      P_LONG:
         "The globe is hanging on the northern wall, just next to a "
         "small opening in the wall. There is another globe at the "
         "exit to the east and to the stairway south, but their "
         "light doesn't reach this place. The globe is glowing in a "
         "friendly, yellow light It is made out of glass. There is "
         "also a small, locked box below the globe.\n",
      P_SMELL:
         "There is nothing you can smell from this place. Maybe you "
         "should go a little bit closer and try again?\n",
      P_NOISE:
         "There is nothing you can hear from this corner of the room. "
         "Maybe you should go a little bit closer and try again?\n",
   ]) );

   AddVItem(
   ([ P_IDS:({"flame"}),
      P_LONG:"The flame is burning inside the globe.\n",
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

   AddRoomCmd( "search",SF(SearchCmd));

   Set(P_INT_MAP,"harbour");
   Set(P_REGION, REGION_CITY|REGION_HARBOUR);
   Set(P_COORDINATES, ({ ({ -290,30,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,"You run into a wall.\n");
   AddExit("east", SIL_HARBOUR("stower3"));
   AddExit("north",SIL_HARBOUR("stower2"));
}
