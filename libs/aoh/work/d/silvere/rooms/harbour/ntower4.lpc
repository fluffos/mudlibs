// The tower-basement. A large wheel is here, where the chain is stored
// created:          Sonic [26-May-1997]
// last changed:     Sonic [05-Jul-1997] added regions/coordinates
//                   Sonic [28-Jul-1997] added description/details

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

string CheckWheelDesc()
{
   int a;
   string desc;

   desc="The wheel is very big and fills the room nearly to the "
        "ceiling. ";
   a=({int})SIL_NORTH_MACHINEROOM->QueryChain();
   if(a==1) desc+="It is filled with a chain.\n";
   else desc+="It is empty.\n";
   return desc;
}

string CheckWheelNoise()
{
   int a;

   a=({int})SIL_NORTH_MACHINEROOM->QueryMachine();
   if(a==1) return
      "You hear the wheel turning around.\n";
   else return
      "You can't hear any noise from the wheel.\n";
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
   Set(P_INT_SHORT,"Tower basement, northern end");
   Set(P_INT_LONG,
      "A large wheel dominates this corner of the room. It stands at "
      "the western wall and looks really huge. A long chain runs down "
      "from it into a machine to the south. To the east is a stairway "
      "leading up to the next level of the tower.\n");

   Set(P_INT_WIZMSG,
" East:  the stairs up to the next level\n"
" South: the activation of the machine\n");

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

   AddVItem(
      ([ P_IDS:({"globe"}),
         P_ADS:({"glowing","glass"}),
         P_LONG:
            "The globe is hanging on the northern wall, just next to "
            "the big wheel. It glows in a friendly, yellow light. "
            "The globe is obviously made out of glass. Below of the "
            "globe is a small, locked box with a symbol on it.\n",
         P_SMELL:
            "The globe doesn't smell. But from the flame you sense "
            "the odor of burned oil.\n",
         P_NOISE:
            "You hear a muted crackling from the small flame inside "
            "the globe.\n",
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

   AddDetail( ({"room","place","tower","basement","level","north tower",
                "north defense tower","defense tower","corner",
                "northern end","end"}),
      "That's the place you are standing at the moment. Just have "
      "a look if you want to know more about it.\n");

   AddVItem(
      ([ P_IDS:({"machine"}),
         P_ADS:({"big","huge"}),
         P_LONG:
            "The machine is placed at the western wall just south "
            "of here. It is something huge. The chain runs through "
            "it on it's way from the wheel to the opening in the "
            "south wall. On the machine is a small handle. If you "
            "want to find out more about it, go closer and look "
            "again.\n",
         P_NOISE:
            "There is nothing to be heard from the machine at the "
            "moment. It doesn't move.\n",
      ]) );

   AddDetail( "opening", SF(CheckOpening));

   AddDetail( "handle",
      "The handle can be found on the machine to the south. If you "
      "want to know more about it, just go south and look again.\n");

   AddDetail( ({"wall","walls"}),
      "Which wall do you mean? As you look around, you see four walls "
      "standing around you. They are made all from stone, but that is "
      "the only thing, that is true for each of them. You could be a "
      "little bit more specific and look at the northern, the southern, "
      "the eastern or the western wall, if you want to get more "
      "informations.\n");

   AddVItem(
   ([ P_IDS:({"stone","stones"}),
      P_ADS:({"grey"}),
      P_LONG:
         "The stones are grey and there is nothing unusual about them. "
         "The single stones are placed on each other to form the wall. "
         "After that, the single pieces are smoothed to prevent someone "
         "from hurting himself on their surface.\n",
   ]) );

   AddDetail( ({"west wall","western wall"}),
      "At the western wall is a big, wooden wheel. A heavy chain leads "
      "from it to a machine just to the south.\n");

   AddDetail( ({"east wall","eastern wall"}),
      "To the east, you can see a stairway leading up to the next level "
      "of the tower. At the southern end of that wall is the exit from "
      "the tower.\n");

   AddDetail("southern end",
      "The exit from the tower can be found there. If you want to leave "
      "this tower, that is the right place to go.\n");

   AddDetail( ({"north wall","northern wall"}),
      "At the northern wall hangs a glowing globe, spending some light "
      "to the room. A small box is attached to it. If you follow the "
      "wall to the east, you will find a stairway, that leads up to "
      "the higher levels of the tower.\n");

   AddDetail( ({"stair","stairs","stairway","stairways"}),
      "The stairway can be found to the east. You can reach the "
      "higher levels of the tower there.\n");

   AddDetail( ({"levels","higher levels","higher level","next level"}),
      "Just go to the stairway and follow it up to the next level. "
      "When you arrived there, just have a look to find out about "
      "them.\n");

   AddDetail( ({"south wall","southern wall"}),
      "At the southern wall is an opening with another glowing globe. "
      "The chain leads there outside the tower. Except of that you "
      "can't see anything else from here.\n");

   AddVItem(
   ([ P_IDS:({"chain"}),
      P_ADS:({"long","heavy","iron"}),
      P_LONG:
         "The chain is made from iron. It is very long and looks heavy. "
         "It comes from the wheel runs through machine to the south and "
         "leaves through the opening in the southern wall.\n",
      P_SMELL:
         "The chain doesn't smell. The odor of rust hangs in the air "
         "though.\n",
      P_NOISE:
         "There is nothing to be heard from the chain.\n",
   ]) );

   AddDetail( ({"iron","metal"}),
      "The iron is a metal, that is used for strong things. The chain "
      "is made out of it.\n");

   AddDetail( ({"ground","floor"}),
      "The floor of the room is full of dirt. It seems, that nobody "
      "felt responsible for cleaning the room in a long time. In the "
      "dirt are some footprints, leading to the south and east.\n");

   AddDetail( "dirt",
      "The dirt is lying on the floor. In the dirt are some footprints "
      "leading to the south and east.\n");

   AddDetail( ({"footprints","footprint","mark","marks"}),
      "The footprints are leading to the south and east. Lots of beings "
      "walked here recently.\n");

   AddVItem(
      ([ P_IDS:({"being","beings"}),
         P_ADS:({"lots of"}),
         P_LONG:
            "Their footprints are marked into the dirt on the floor. "
            "There are several different marks here though. Some small, "
            "some big and some medium sized marks can be seen on the "
            "ground.\n",
      ]) );

   AddVItem(
      ([ P_IDS:({"wheel"}),
         P_ADS:({"big","huge","wooden"}),
         P_LONG:SF(CheckWheelDesc),
         P_SMELL:
            "The wheel doesn't smell at all.\n",
         P_NOISE:SF(CheckWheelNoise),
      ]) );

   Set(P_INT_MAP,"harbour");
   Set(P_REGION, REGION_CITY|REGION_HARBOUR);
   Set(P_COORDINATES, ({ ({ -290,-10,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,"You run into a wall.\n");
   AddExit("east", SIL_HARBOUR("ntower3"));
   AddExit("south",SIL_HARBOUR("ntower2"));
}
