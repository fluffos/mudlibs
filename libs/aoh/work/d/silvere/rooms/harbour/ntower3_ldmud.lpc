// Inside the tower. Stairs leading up
// created:          Sonic [26-May-1997]
// last changed:     Sonic [05-Jul-1997] added regions/coordinates
//                   Sonic [28-Jul-1997] added description/details

#include <silvere.h>
#include <properties.h>
#include <coordinates.h>
#include <msgclass.h>
#include <nightday.h>
#include <regions.h>
#include <moving.h>
#include <macros.h>
#include <rooms.h>
inherit BASEROOM;

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
      "A stairway leads up to the higher levels of the tower. At the "
      "wall to the west is a large wooden wheel, from which a heavy "
      "chain runs to the south along the wall. Directly to the south "
      "you see the exit from the tower.\n");

   Set(P_INT_WIZMSG,
" Up:    To the next level of the tower\n"
" West:  To the western end of the room\n"
" South: To the exit of the tower.\n");

   AddDetail( "ceiling",
      "The ceiling is made out of wooden beams. It looks very heavy.\n");

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

   AddDetail( ({"floor","ground"}),
      "The floor of the room is full of dirt. It seems, that nobody "
      "felt responsible for cleaning the room in a long time. There "
      "are lots of footprints, leading up the stairway. Some of the "
      "marks are leading to the west and south too.\n");

   AddDetail( "dirt",
      "The dirt is lying on the floor. In the dirt are some footprints "
      "leading to the west and south. There are also some footprints, "
      "which leads up on the stairway.\n");

   AddDetail( ({"footprints","footprint","mark","marks"}),
      "The footprints are leading to the south and east. Lots of beings "
      "walked here recently.\n");

   AddDetail( ({"stairway","stair","stairs","staircase"}),
      "The stairway is made out of wood and leads up to the higher "
      "levels of the tower. Some footprints on the stairs show you "
      "that someone is using them frequently. Or that room "
      "needs some professional cleaning service.\n");

   AddDetail( ({"wood","some kind of wood"}),
      "The wood is the same as the one from the wheel to the east. "
      "It could be cedar, but that's not for sure. It is also quite "
      "old, but still stable.\n");

   AddDetail( "cedar",
      "The cedar is a tree, that grows in the warmer parts of the "
      "world. Some rumour says, that this tree is growing to the north "
      "in a much colder climate too, but they are much smaller then.\n");

   AddDetail( "tree",
      "You can't see a tree in that room. The floor is made completely "
      "out of stone and there is not enough sunlight to let a tree "
      "grow. If you want to look for trees, go outside and search "
      "there.\n");

   AddDetail( ({"cleaning service","professional cleaning service"}),
      "The floor of the room is full of dirt. Unfortunately, nobody "
      "felt responsible for cleaning the room, so it is still lying "
      "there.\n");

   AddDetail( ({"tower","basement","this level","room","end","place",
                "defense tower","north defense tower","north tower"}),
      "That's the place you are standing at the moment. Just have a "
      "look, if you want to know more about this place.\n");

   AddVItem(
   ([ P_IDS:({"stone","stones"}),
      P_ADS:({"grey"}),
      P_LONG:
         "The stones are grey and there is nothing unusual about them. "
         "The single stones are placed on each other to form the wall. "
         "After that, the single pieces are smoothed to prevent someone "
         "from hurting himself on their surface.\n",
   ]) );

   AddDetail( ({"wall","walls"}),
      "Which wall do you mean? As you look around, you see four walls "
      "standing around you, made out of some grey stone. But that stone "
      "is the only thing, that is the same on all of them. You could be "
      "a little bit more specific and look at the northern, southern, "
      "eastern or western wall.\n");

   AddDetail( ({"north wall","northern wall"}),
      "A big stairway dominates the northern wall. It leads up to the "
      "higher levels of the tower and is made out of some kind of "
      "wood.\n");

   AddDetail( ({"south wall","southern wall"}),
      "At the southern wall is at it's western end a small opening, "
      "where a chain leads through. Next to the opening is a glowing "
      "globe which looks exactly like the one at the eastern wall.\n");

   AddDetail( "opening",SF(CheckOpening));

   AddDetail( ({"west wall","western wall"}),
      "There is a large wooden wheel at the western wall. A chain runs "
      "down from it to a machine to the south.\n");

   AddDetail( ({"east wall","eastern wall"}),
      "At the eastern wall is a glowing globe next to the stairway. "
      "Another globe can be seen to the south at the exit from the "
      "tower.\n");

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
            "The globe is hanging on the eastern wall. It glows in "
            "a friendly, yellow light. It is obviously made out of "
            "glass. Below of the globe is a small, locked box with "
            "a symbol on it.\n",
         P_SMELL:
            "The globe doesn't smell. But from the flame you sense "
            "the odor of burned oil.\n",
         P_NOISE:
            "You hear a muted crackling from the small flame inside "
            "the globe.\n",
      ]) );

   AddVItem(
   ([ P_IDS:({"level"}),
      P_ADS:({"higher","upper"}),
      P_LONG:
         "The upper level of the tower is on the top of the stairway. "
         "If you want to find out, what you can find there, just go up "
         "and have a look.\n",
   ]) );

   AddVItem(
   ([ P_IDS:({"chain"}),
      P_ADS:({"iron","large","heavy"}),
      P_LONG:
         "The chain looks very heavy. It is made out of iron and runs "
         "from the wheel through the machine into the opening.\n",
   ]) );

   AddVItem(
   ([ P_IDS:({"machine"}),
      P_LONG:
         "The machine can be found at the southwestern end of the "
         "room. If you want to know more, just go there and have "
         "a look.\n",
   ]) );

   AddDetail( "southwestern end",
      "At that end of the room stands a machine. A chain goes into "
      "the machine from the north and leaves it to the south. There "
      "it runs through an opening in the southern wall.\n");

   Set(P_INT_MAP,"harbour");
   Set(P_REGION, REGION_CITY|REGION_HARBOUR);
   Set(P_COORDINATES, ({ ({ -280,-10,0 }), C_SILVERE }) );

   Set(P_NOWAY_MSG,"You run into a wall.\n");
   AddExit("west", SIL_HARBOUR("ntower4"));
   AddExit("south",SIL_HARBOUR("ntower1"));
   AddExit("up",   SIL_HARBOUR("ntower5"));
}
