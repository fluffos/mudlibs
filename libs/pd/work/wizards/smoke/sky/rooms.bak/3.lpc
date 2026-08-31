#include <std.h>
#include <cp.h>
inherit ROOM;

void create() {
  ::create();
  set_properties( ([ "light" : 2, "indoors" : 0, "night light" : 2,
    "no teleport" : 1, "mountain" : 1]) );
  set_short("Surrounded by mountains");
  set_long(
   "The path runs north and south through the mountains. An opening "
   "to a cave is in the western mountain wall. Several plants and "
   "shrubs cover the ground on both sides of the path. Several palm "
   "trees also stand off the path. Jagged rocks protrude from the "
   "walls of the mountain. Large reptilian footprints cover the "
   "ground on and off of the path.");
  set_items(([
    "mountain" : "The mountains stretch in all directions. A mountain "
    "wall prevents access to the east and west of here."
    " An opening to a cave lies within the west mountain "
    "wall.",
    "shrubs" : "Small shrubs grow at random upon the ground.",
    "footprints" : "Large, reptilian footprints cover the ground here,"
    " both on and off of the path.",
    "rocks" : "Jagged rocks protrude from the walls of the mountain. "
    "Some of the rocks are covered in bird poop.",
    "trees" : "A few palm trees grow here, providing a little bit of "
    "shade from the elements.",
    "cave" : "A cave lies within the western mountain wall.",
    "opening" : "The opening to a cave lies within the face of the "
    "western mountain wall. It appears to be darker within the"
    " cave than out here.",
    "path" : "A dirt path runs north and south, cut out of the grass."
    " Several large footprints cover the path.",
    "grass" : "Grass covers the ground just off of the path."
   ]));
  set_smell("default", "The air is crisp and the air is humid.");
  set_listen("default", "Occassionally a twig can be heard snapping from afar.");
  set_exits( ([ 
    "north" :  ROOMS "4",
    "enter cave" : ROOMS "cave1",
    "south" :  ROOMS "2"]));
}
