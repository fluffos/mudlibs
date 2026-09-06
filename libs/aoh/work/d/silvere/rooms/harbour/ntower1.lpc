// This is the inside of the tower.
// created:          Sonic [26-May-1997]
// last changed:     Sonic [05-Jul-1997] added regions/coordinates
//                   Sonic [27-Jul-1997] added descriptions/details

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <msgclass.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <nightday.h>
#include <rooms.h>
inherit BASEROOM;

int leave_tower(string str)
{
   notify_fail("Leave what?\n",NOTIFY_ILL_ARG);
   if(!str) return 0;
   if(strstr(lower_case(str),"tower")!=-1 ||
      strstr(lower_case(str),"building")!=-1)
   {
      msg_write(CMSG_GENERIC,
         "You pass through the exit at the east and leave the "
         "tower to the harbour.\n");
      msg_say(CMSG_ROOM,
         CAP(NAME(TP))+" leaves the tower to the east.\n", ({TP}) );
      TP->move(SIL_HARBOUR("ntower_enter"),M_GO);
      return 1;
   }
   return 0;
}

string CheckOpening()
{
   string desc;

   desc=
      "The opening is in the southern wall, at the western end of the "
      "room. A large chain is running through it. ";
   switch(({int})NIGHTDAY->QueryState())
   {
      case ND_NIGHT:
         desc+=
            "Outside of the opening it's dark, as no light "
            "shines through it.\n";
         break;
      case ND_PREDAWN..ND_SUNRISE:
      case ND_TWILIGHT..ND_EVENING:
         desc+=
            "Outside of the opening is some light. It shines "
            "through it and gives more light to parts of the "
            "room.\n";
         break;
      case ND_EARLY_MORNING..ND_SUNSET:
         desc+=
            "It's day outside of the tower. Some light shines "
            "through the opening and sends a ray of full light "
            "into the room.\n";
         break;
      default:
         desc+=
            "There is something to the outside of the room, but "
            "you can't clearly define it.\n";
         break;
   }
   return desc;
}

varargs void create()
{
   ::create();
   Set(P_INDOORS,1);
   Set(P_INT_SHORT,"Tower entrance");
   Set(P_INT_LONG,
"This is a large room at the basement of the tower and you are "
"standing at is eastern end. There is nothing special here, except "
"for the exit out of the tower. A big machine is standing to the "
"west and to the north is a stairway leading up to the next level "
"of the tower.\n");

   Set(P_INT_WIZMSG,
" East:  Leave the tower to the harbour.\n"
" West:  Go to the handle in the wall.\n"
" North: To a stair leading up.\n");

   AddDetail( ({"basement","room","level"}),
      "You are standing here. Just have a look and you may find out "
      "some interesting things.\n");

   AddVItem(
      ([ P_IDS: ({"tower"}),
         P_ADS: ({"high","defense"}),
         P_LONG:
            "This tower is standing at the western end of the northern "
            "quay of Silvere. It is here to defend the harbour and the "
            "city from enemy ships.\n",
      ]) );

   AddDetail( ({"ground","floor"}),
      "There is some dirt on the floor. It seems, that nobody "
      "takes care about the cleaning of the room here. Footprints "
      "are leading to the north, west and east.\n");

   AddDetail( "dirt",
      "The dirt is lying on the floor. There you can see some "
      "footprints, leading to the north, west and east.\n");

   AddDetail( ({"footprint","footprints"}),
      "The footprints are leading to the north, east and west. "
      "Lots of beings walked here recently and it seems, that "
      "most of them are going to the next level of the tower.\n");

   AddVItem(
      ([ P_IDS:({"being","beings"}),
         P_ADS:({"lots of"}),
         P_LONG:
            "Their footprints are marked into the dirt on the floor. "
            "There are several different marks here though. Some small, "
            "some big and some medium sized marks can be seen on the "
            "ground.\n",
      ]) );

   AddDetail( "ceiling",
      "The ceiling is made out of wooden beams. It looks "
      "very heavy.\n");

   AddVItem(
      ([ P_IDS:({"beam","beams"}),
         P_ADS:({"wooden","heavy"}),
         P_LONG:
            "The beams are building the ceiling of the rooms here at "
            "the basement of the tower. Every now and then you hear "
            "someone walking by above you.\n",
         P_NOISE:
            "Every now and then someone seems to walk around above "
            "you.\n",
      ]) );

   AddDetail( ({"wall","walls"}),
      "There are lots of walls around you. They are made out of some "
      "grey stone. If you want to know more about the walls, be a "
      "little bit more specific about the wall you want to look at. "
      "How about the northern, southern, eastern or western wall?\n");

   AddVItem(
   ([ P_IDS:({"stone","stones"}),
      P_ADS:({"grey"}),
      P_LONG:
         "The stones are grey and there is nothing unusual about them. "
         "The single stones are placed on each other to form the wall. "
         "After that, the single pieces are smoothed to prevent someone "
         "from hurting himself on their surface.\n",
   ]) );

   AddDetail( ({"south wall","southern wall"}),
      "There is nothing unusual about the southern wall here, but if "
      "you go west, you can find an opening, where you can look out "
      "on the harbour, if you want to do that. A long and heavy chain "
      "leads through that opening out of the tower.\n");

   AddDetail( ({"north wall","northern wall"}),
      "At the northern wall is a stairway, that leads up to the "
      "higher levels of the tower. Except of that, you can't see "
      "more from this place.\n");

   AddDetail( ({"west wall","western wall"}),
      "At the western wall on the other end of the room is a big "
      "machine with a handle on it. On a big wheel is a large and "
      "heavy chain, that runs through the machine and leaves through "
      "the opening in the southern wall. That's all what you can see "
      "from here, but if you go closer, you may see some more.\n");

   AddDetail( ({"east wall","eastern wall"}),
      "At the eastern wall is the exit out of that tower. A glowing "
      "globe is hanging there too, that spends some light.\n");

   AddVItem(
      ([ P_IDS:({"globe"}),
         P_ADS:({"glowing","glass"}),
         P_LONG:
            "The globe is hanging on the eastern wall, just next to "
            "the exit from the tower. It glows in a friendly, yellow "
            "light. The globe is obviously made out of glass. Below "
            "of the globe is a small, locked box with a symbol on it.\n",
         P_SMELL:
            "The globe doesn't smell. But from the flame you sense "
            "the odor of burned oil.\n",
         P_NOISE:
            "You hear a muted crackling from the small flame inside "
            "the globe.\n",
      ]) );

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

   AddDetail( "symbol",
      "The symbol shows you a single flame. It is painted on the "
      "box below the globe.\n");

   AddVItem(
      ([ P_IDS:({"flame"}),
         P_LONG:"The flame is burning inside the globe.\n",
         P_SMELL:"From the flame you smell the odor of burned oil.\n",
         P_NOISE:
            "You hear a muted crackling from the small flame.\n",
      ]) );

   AddDetail( "handle",
      "The handle is placed on the machine, directly at the western "
      "wall. If you want to know more about it, just go closer and "
      "have a look at it.\n");

   AddDetail( "opening",#'CheckOpening);

   AddVItem(
      ([ P_IDS:({"machine"}),
         P_ADS:({"big","huge"}),
         P_LONG:
            "The machine is placed at the western wall. It is "
            "something huge. The chain runs through it on it's way "
            "from the wheel to the opening. A handle is placed on "
            "the machine. If you want to find out more about it, go "
            "closer and look again.\n",
         P_NOISE:
            "There is nothing to be heard from the machine at the "
            "moment. It doesn't move.\n",
      ]) );

   AddVItem(
      ([ P_IDS:({"wheel"}),
         P_ADS:({"big","wooden"}),
         P_LONG:
            "The wheel is standing next to the machine to the west. "
            "It is somehow connected to it. A big chain runs from the "
            "wheel through the machine into the opening. If you want "
            "to know more about it, just go closer and look again.\n",
         P_NOISE:
            "At the moment, there is no noise to be heard from the "
            "wheel. It doesn't move.\n",
      ]) );

   AddVItem(
      ([ P_IDS:({"chain"}),
         P_ADS:({"long","heavy","iron"}),
         P_LONG:
            "The chain looks very heavy. It is made out of iron "
            "and runs from the wheel through the machine into the "
            "opening.\n",
         P_NOISE:
            "There is no noise from the chain. At least not at the "
            "moment.\n",
         P_SMELL:
            "From that place you can't sense something from the "
            "chain. Anyways, there is a faint smell of rust in "
            "the air.\n",
      ]) );

   AddDetail( ({"stairway","stairs","stair"}),
      "The stairs at the northern wall leads up to the next level "
      "of the tower. Just go closer and climb up, if you want to "
      "find out about the rooms there.\n");

   AddDetail( "next level",
      "The next level is right above you, on top of the ceiling. Just "
      "go north to the stairs and climb up there, if you are curious "
      "about the rooms there.\n");

   AddRoomCmd("leave",#'leave_tower);

   Set(P_INT_NOISE,
      "The only noise is the sound of the water, which hurls "
      "against the towerwalls.\n");
   Set(P_INT_SMELL,
      "The odor of harbour hangs in the air. You can smell dead fish, "
      "old seaweed and such things.\n");

   Set(P_INT_MAP,"harbour");
   Set(P_REGION, REGION_CITY|REGION_HARBOUR);
   Set(P_COORDINATES, ({ ({ -280,0,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,"You run into a wall.\n");
   AddExit("west", SIL_HARBOUR("ntower2"));
   AddExit("east", SIL_HARBOUR("ntower_enter"));
   AddExit("north",SIL_HARBOUR("ntower3"));
}
