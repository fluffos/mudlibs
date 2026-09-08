// This is the inside of the tower.
// created:          Sonic [26-May-1997]
// last changed:     Sonic [05-Jul-1997] added regions/coordinates

// TODO: add a chance to open the box of the globe and light the oil
// TODO: inside... maybe it could explode and burn the skin of the player

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <nightday.h>
#include <msgclass.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
inherit BASEROOM;

int leave_tower(string str)
{
   notify_fail("Leave what?\n", NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(strstr(lower_case(str),"tower")!=-1 ||
      strstr(lower_case(str),"building")!=-1)
   {
      msg_write(CMSG_GENERIC,
         "You pass through the exit at the east and leave the "
         "tower to the harbour.\n");
      if(!({int})TP->Query(P_INVIS)) msg_room(TO, CMSG_ROOM,
         CAP(NAME(TP))+" leaves the tower to the east.\n", ({TP}) );
      TP->move(SIL_HARBOUR("stower_enter"),M_GO,"east");
      return 1;
   }
   return 0;
}

int search_dirt(string str)
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

string CheckOpening()
{
   string desc;

   desc=
      "The opening is in the northern wall, at the western end of the "
      "room. A large iron chain is running through it. ";
   switch(({int})NIGHTDAY->QueryState())
   {
      case ND_NIGHT:
         desc+=
            "Outside it's completely dark. There is no light shining "
            "through...\n";
         break;
      case ND_PREDAWN..ND_SUNRISE:
      case ND_TWILIGHT..ND_EVENING:
         desc+=
            "Outside is some light. It shines through the opening and "
            "lights some parts of the room more than the globes are "
            "able to do...\n";
         break;
      case ND_EARLY_MORNING..ND_SUNSET:
         desc+=
            "Outside it's day. Some light shines through the opening "
            "and sends a ray of full light into the room.\n";
         break;
      default:
         desc+=
            "There is something outside the room, but you are not "
            "able to clearly define it.\n";
         break;
   }
   return desc;
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,1);
   Set(P_INT_SHORT,"in the tower");
   Set(P_INT_LONG,
      "This is a large room at the basement of the tower. At the moment "
      "you are standing at it's northeastern edge. A large machine is "
      "standing to the east and a stairway leads up to the south. An "
      "exit leads out of the tower to the east.\n");

   Set(P_INT_WIZMSG,
      " East:  leave the tower\n"
      " West:  the machinery with the chains\n"
      " South: up to the other floors.\n");

   AddDetail( ({"basement","room","place","here"}),
      "You are standing at this place right now. Just have a look if "
      "you find something of interest. It could be something important "
      "(or not).\n");

   AddVItem(
   ([ P_IDS:({"machine"}),
      P_ADS:({"big","huge"}),
      P_LONG:
         "The machine is placed at the western wall. It is really huge "
         "and somehow looks important. A large iron chain runs from a "
         "wooden wheel to the south through the machine and vanishes in "
         "a small opening in the northern wall. If you want to find out "
         "more about the machine, just go west and have a closer look "
         "at it.\n",
   ]) );

   AddVItem(
   ([ P_IDS:({"tower"}),
      P_ADS:({"high","defense"}),
      P_LONG:
         "The tower, in which you find yourself at the moment, is "
         "standing at the western end of the quay. It's purpose is "
         "to defend the harbour and the city of Silvere from enemies "
         "and unwanted guests which may come one day.\n",
   ]) );

   AddDetail( ({"enemies","unwanted guests","guests"}),
      "There are none here at the moment. If that would be the case, "
      "would be in big trouble...\n");

   AddVItem(
   ([ P_IDS:({"wheel"}),
      P_ADS:({"big","wooden"}),
      P_LONG:
         "The wheel is standing south of the machine to the west. It "
         "is connected with a large iron chain with it. The chain runs "
         "through the machine and vanishes in a small opening in the "
         "northern wall. If you want to know more about it, you should "
         "go west and check it again.\n",
   ]) );

   AddDetail( "ceiling",
      "The ceiling is made out of wooden beams. It looks very heavy.\n");

   AddVItem(
   ([ P_IDS:({"beam","beams"}),
      P_ADS:({"wooden","heavy"}),
      P_LONG:
         "The beams are building the ceiling of the room here at the "
         "basement of the tower. Every now and then you hear someone "
         "walking by above you.\n",
      P_NOISE:
         "Every now and then someone seems to walk around above you.\n",
   ]) );

   AddDetail( ({"ground","floor"}),
      "The floor is the place, you are standing at the moment. It seems "
      "that noone felt responsible for cleaning the ground for a long "
      "time, as there is lots of dust and dirt here. Footprints are "
      "leading to the east, west and south.\n");

   AddDetail( "dust",
      "The dust is lying on the floor. Footprints can be seen there, "
      "leading to the east, west and south.\n");

   AddDetail( "dirt",
      "There is some dirt lying on the ground. It seems that someone "
      "dropped some useless stuff there.\n");

   AddDetail( ({"footprint","footprints"}),
      "The footprints are leading to the east, west and south. Lots "
      "of beings walked here recently and it seems, that most of them "
      "were going to the south, where they could reach the upper levels "
      "of the tower.\n");

   AddVItem(
   ([ P_IDS:({"being","beings"}),
      P_ADS:({"lots of "}),
      P_LONG:
         "Their footprints are marked into the dust on the floor. "
         "There are several different marks here though. Some small, "
         "some big and some medium sized marks can be seen on the "
         "ground.\n",
   ]) );

   AddVItem(
   ([ P_IDS:({"mark","marks"}),
      P_ADS:({"medium","small","big"}),
      P_LONG:
         "That marks are footprints, that are leading to the east, west "
         "and south.\n",
   ]) );

   AddDetail( ({"wall","walls"}),
      "Which wall do you want to check? You can see the northern, "
      "southern, eastern and the western wall here. You should be "
      "a little bit more specific.\n");

   AddDetail( ({"south wall","southern wall"}),
      "At the wall to the south is a stairway leading up to the higher "
      "levels of the tower. Next to it is a small globe at the wall, "
      "which spends a friendly light.\n");

   AddDetail( ({"north wall","northern wall"}),
      "There is nothing unusual here at that wall. To the west is a "
      "small opening, though. You could take a look out on the harbour "
      "there. A long iron chain runs through the opening too.\n");

   AddDetail( ({"west wall","western wall"}),
      "At the western wall on the other end of the room is a big "
      "machine with a handle on it. On a big wheel south of the "
      "machine is a large iron chain, that runs through the machine "
      "and vanishes into the opening in the northern wall. That's all "
      "you can see from here. If you want to find out more, you should "
      "have a closer look.\n");

   AddDetail( ({"east wall","eastern wall"}),
      "At the eastern wall is the exit out of the tower. A glowing "
      "globe is hanging there too, that lights the room.\n");

   AddVItem(
   ([ P_IDS:({"globe"}),
      P_ADS:({"glowing","glass"}),
      P_LONG:
         "The globe is hanging on the eastern wall, just next to the "
         "the exit from the tower. To the south at the stairway is "
         "another one. They glow in a friendly, yellow light and light "
         "the room here. The globe itself is made out of glass. Below "
         "it is a small, locked box with a symbol on it.\n",
      P_SMELL:
         "The globe doesn't smell. But from the flame you sense the "
         "odor of burned oil.\n",
      P_NOISE:
         "You hear a muted crackling from the small flame inside the "
         "globe.\n",
   ]) );

   AddVItem(
   ([ P_IDS:({"box"}),
      P_ADS:({"small"}),
      P_LONG:
         "The box is directly connected to the globe. A small symbol, "
         "that resembles a flame is painted on it. There is also a "
         "small lock, where the box can be opened.\n",
      P_SMELL:
         "The box doesn't smell. At least you are not able to sense "
         "anything from it.\n",
      P_NOISE:
         "There is nothing you can hear from the box. It is absolutely "
         "silent.\n",
   ]) );

   AddDetail( "symbol",
      "The symbol is a small picture of a single flame. It is painted "
      "on the box below the globe.\n");

   AddDetail( "picture",
      "The picture is painted on the box below the globe. It looks like "
      "a single flame.\n");

   AddVItem(
   ([ P_IDS:({"flame"}),
      P_LONG:"The flame is burning inside the globe.\n",
      P_SMELL:"From the flame you smell the odor of burned oil.\n",
      P_NOISE:"You hear a muted crackling from the small flame.\n",
   ]) );

   AddDetail( "handle",
      "The handle is placed on the machine which stands directly at the "
      "western wall. If you want to know more about it, you should go "
      "closer and have another look on it.\n");

   AddVItem(
   ([ P_IDS:({"opening"}),
      P_ADS:({"small"}),
      P_LONG:#'CheckOpening /*'*/,
   ]) );

   AddVItem(
   ([ P_IDS:({"machine"}),
      P_ADS:({"big","huge"}),
      P_LONG:
         "The machine is placed at the eastern wall. It is something "
         "huge. A chain runs from a large wooden wheel to the south "
         "through the machine and leaves the tower through the small "
         "opening in the northern wall. A small handle is attached to "
         "the machine too. If you want to find out more about the "
         "machine, you should go to the west and have a closer look "
         "at it.\n",
      P_NOISE:
         "There is nothing to be heard from the machine at the moment. "
         "It doesn't even move something there.\n",
      P_SMELL:
         "You can't smell anything from the machine here. Maybe you "
         "should go closer and try again?\n",
   ]) );

   AddVItem(
   ([ P_IDS:({"wheel"}),
      P_ADS:({"big","wooden"}),
      P_LONG:
         "The wheel is standing south of the machine at the western "
         "wall. A big chain runs from it through a machine into the "
         "opening in the northern wall. If you want to find out more "
         "about it, just go closer and look again.\n",
      P_NOISE:
         "At the moment, there is no noise to be heard from the "
         "wheel. It doesn't move.\n",
   ]) );

   AddVItem(
   ([ P_IDS:({"chain"}),
      P_ADS:({"long","heavy","iron"}),
      P_LONG:
         "The chain seems to be very heavy. It is made out of iron and "
         "runs down from the wheel through the machine int othe opening "
         "at the northern wall.\n",
      P_NOISE:
         "There is no noise from the chain at the moment.\n",
      P_SMELL:
         "From here you can't sense anything from the chain. But there "
         "is anyways a faint scent of rust in the air.\n",
   ]) );

   AddDetail( ({"stair","stairs","stairway"}),
      "The stairs to the south are leading up to the other levels of "
      "the tower. From here you can't see much of it, so it may be a "
      "good idea to have a closer look...\n");

   AddVItem(
   ([ P_IDS:({"level"}),
      P_ADS:({"next","higher","other","upper"}),
      P_LONG:
         "The next level is right above you, on top of the ceiling. "
         "If you want to see it you have to go south and follow the "
         "stairway up.\n",
   ]) );

   AddDetail( ({"city","silvere"}),
      "The city of Silvere is just outside the tower. If you want to "
      "go there, you should leave the tower.\n");

   AddDetail( "harbour",
      "The harbour of Silvere is just outside the tower. If you want "
      "to go there, you should leave the tower.\n");

   AddRoomCmd("leave",#'leave_tower);
   AddRoomCmd("search",#'search_dirt);

   Set(P_INT_MAP,"harbour");
   Set(P_REGION, REGION_CITY|REGION_HARBOUR);
   Set(P_COORDINATES, ({ ({ -280,20,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,"You run into a wall.\n");
   AddExit("west", SIL_HARBOUR("stower2"));
   AddExit("east", SIL_HARBOUR("stower_enter"));
   AddExit("south",SIL_HARBOUR("stower3"));
}
