#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
  ::create();
  set_properties( ([ "light" : 2, "indoors" : 0, "night light" : 2,
    "no teleport" : 1, "mountain" : 1]) );
  set_short("Surrounded by mountains");
  set_long(
   "The path splits three different ways. A tall mountain wall stret"
   "ches out of the ground directly to the east. The path runs north"
   "east, southeast and west. There is an opening in the north wall "
   "leading into a cave. Lots of shrubs grow outside of the opening, "
   "practically covering it up. Grass grows wildly off the path in "
   "each direction and several palm trees grow at random. Jagged "
   "rocks seem to grow out of the mountain. Lots of large footprints"
   " cover the ground outside of the cave opening.");
  set_items(([
    "mountain" : "The mountains stretch in all directions. A mountain "
    "wall stretches out of the ground directly to the east."
    " An opening to a cave lies within the north mountain"
    " wall.",
    "shrubs" : "Small shrubs grow at random upon the ground. Around "
    "the opening to the cave the shrubs grow more abundantly, "
    "practically covering the enterance.",
    "footprints" : "Large, reptilian footprints cover the ground here,"
    " both on and off of the path.",
    "rocks" : "Jagged rocks protrude from the walls of the mountain. "
    "Some of the rocks are covered in bird poop.",
    "trees" : "A few palm trees grow here, providing a little bit of "
    "shade from the elements.",
    "cave" : "A cave lies within the northern mountain wall.",
    "opening" : "The opening to a cave lies within the face of the "
    "northern mountain wall. It appears to be darker within the "
    "cave than out here. Many shrubs practically cover the hole.",
    "path" : "A dirt path runs west, northeast and southeast, cut out"
    " of the grass. Several large footprints cover the path.",
    "grass" : "Grass covers the ground just off of the path."
   ]));
  set_smell("default", "The air is crisp and the air is humid.");
  set_listen("default", "Occassionally a twig can be heard snapping from afar.");
  set_exits( ([ 
    "northeast" :  ROOMS "7",
    "enter cave" : ROOMS "cave2",
    "west" : ROOMS "5",
    "southeast" :  ROOMS "15"]));
}
