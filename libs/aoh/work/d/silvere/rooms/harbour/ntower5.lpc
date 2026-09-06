// Inside the tower. Stairs leading down
// created:          Sonic [26-May-1997]
// last changed:     Sonic [05-Jul-1997] added regions/coordinates
//                   Sonic [29-Jul-1997] added description/details

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <msgclass.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
inherit BASEROOM;

varargs void create()
{
   ::create();
   Set(P_INDOORS,1);
   Set(P_INT_SHORT,"At a stairway");
   Set(P_INT_LONG,
"A stairway leads here down to the basement of the tower. To the south "
"you can enter a small room through an open door. A glowing globe hangs "
"at the wall, lighting the room.\n");

   Set(P_INT_WIZMSG,
" Down:  Stairs to the basement.\n"
" South: To a waiting room for the crew.\n");

   AddVItem(
   ([ P_IDS:({"globe"}),
      P_ADS:({"glowing"}),
      P_LONG:
         "The globe is hanging on the northern wall. It is made "
         "out of glass and a small flame burns there in a friendly, "
         "yellow light. Below the globe is a small locked box with "
         "a symbol on it.\n",
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

   AddDetail( ({"stair","stairs","stairway"}),
      "The stairs are leading down to the basement of the tower. They "
      "are made out of some wood.\n");

   AddDetail( ({"wood","some kind of wood"}),
      "The wood of the stairway looks quite old, but stable. It could "
      "be cedar, but that's not for sure.\n");

   AddDetail( "cedar",
      "The cedar is a tree, that grows in the warmer parts of the "
      "world. Some rumours say that this tree is growing in the north "
      "in a much colder climate too, but there it is much smaller "
      "than here.\n");

   AddDetail( ({"basement","lower level"}),
      "The basement of the tower can be found at the lower end of "
      "the stairway.\n");

   AddDetail( "lower end",
      "Walk down the stairway and you are there.\n");

   AddDetail( "ceiling",
      "The ceiling is made out of large wooden beams. They are very "
      "heavy.\n");

   AddDetail( ({"floor","ground"}),
      "The ground is made out of the same beams of wood as the "
      "ceiling. You can see some footprints in the dust there.\n");

   AddDetail( ({"footprint","footprints"}),
      "The footprints are leading down the stairs and to the south. "
      "It seems,that someone is frequently is walking by here.\n");

   AddVItem(
   ([ P_IDS:({"beam","beams"}),
      P_ADS:({"wooden","heavy"}),
      P_LONG:
         "The beams are building the floor and the ceiling of the "
         "rooms here at the tower. Every now and then you hear "
         "someone walking by above you.\n",
      P_NOISE:
         "Every now and then someone seems to walk around above "
         "you.\n",
   ]) );

   AddDetail( ({"tower","room","here","defense tower","north tower",
                "north defense tower","this level","place"}),
      "That's the place, you are standing at the moment. If you want "
      "to know more about it, have a look around.\n");

   AddDetail( ({"door","open door","wooden door"}),
      "The door is opened and leads from here to the south in a "
      "small room. The door looks rather heavy.\n");

   AddDetail( ({"stone","stones","grey stone","grey stones"}),
      "The stones are grey. There is nothing unusualy about them. "
      "The single stones are placed on each other to form the wall. "
      "After that was done, someone went over it and smoothed the "
      "wall to prevent people from hurting themself at the wall.\n");

   AddDetail( ({"wall","walls"}),
      "The walls around you are made out of stone. At the wall to the "
      "south is a glowing globe, lighting the room.\n");

   AddDetail( ({"north wall","northern wall"}),
      "At the northern wall of the room is a stairway leading down. "
      "The wall there is absolutely bare and you can only see the "
      "grey stone, from which the tower is built.\n");

   AddDetail( ({"south wall","southern wall"}),
      "A glowing globe hangs at the wall there next to a heavy wooden "
      "door.\n");

   AddDetail( ({"east wall","eastern wall","west wall","western wall"}),
      "The wall is made out of stone and totaly bare. There is "
      "absolutely nothing to be found there.\n");

   Set(P_INT_MAP,"harbour");
   Set(P_REGION, REGION_CITY|REGION_HARBOUR);
   Set(P_COORDINATES, ({ ({ -280,-10,10 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,"You run into a wall.\n");
   AddExit("south",SIL_HARBOUR("ntower6"));
   AddExit("down", SIL_HARBOUR("ntower3"));
}
