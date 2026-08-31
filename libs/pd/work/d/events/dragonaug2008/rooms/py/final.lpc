#include <std.h>
#include <dragonevent.h>

inherit DRAG_ROOMS"py/base";

void create() {
  ::create();
  set_long("A large, open chamber. To the east, the walls and ceiling of the chamber expand even further, underneath which is a great platform. The platform is made of a sturdy white rock-like substance. To the west, the walls of the chamber give way to an unrefined tunnel which appears to have been bored through a solid rock wall. Small pieces of rock and wall litter the floor underneath the tunnel entrance.");
  set_exits( ([
    "west" : DRAG_ROOMS"py/10",
  ]) );
  set_items( ([
    "chamber" : "You are standing within a giant chamber made out of gigantic white stones. The walls around the tip of the ceiling are banded with long ornate golden plates.",
    "plates" : "They depict a series of events, in which a small figure makes its way through a frozen mountain, falls through the sky, trecks through the forest, and finally comes face to face with a terrible beast.",
    "platform" : "A large platform stationed in the center of the room. It is a rock plateau, hemmed with a thick golden metal.",
    "metal" : "The plates are formed of it.",
    "walls" : "The pristine white rock walls surround the cave. A large hole has been born into the side of the wall to the west, but given the immense size of the chamber, the hole is extremely small in comparison.",
    "pieces" : "Combined fragments from the western wall of the chamber and the cave that seems to have bored through it.",
  ]) );

  if(DRAG_D->query_data("canProveCourage") && !present("finalboss"))
    new(DRAG_MOBS"cavefinalboss")->move(this_object());
}
