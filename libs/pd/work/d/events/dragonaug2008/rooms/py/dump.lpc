/*Players will be moved here when the instance is
 *completed. They will also end here should the instance
 *be destructed for some reason.*/
#include <std.h>
#include <dragonevent.h>

inherit DRAG_ROOMS"py/convo";
inherit ROOM;

void create() {
  room::create();
  convo::create();
  set_properties( ([ "light" : 1, "no teleport" : 1, "mountain" : 1, "indoors" : 1 ]) );
  set_short("a strange cave");
  set_long("%^BOLD%^%^BLACK%^The cave walls seem to be pressing in on all sides. There is nothing of distinction on the walls, they seem to be made out of bare rock. To the south, the tunnel opens up and expands greatly. A faint %^RESET%^%^ORANGE%^orange glow%^BOLD%^%^BLACK%^ can be seen covering the southern exit of the cave.");
  set_exits( ([
    "south" : DRAG_ROOMS"py/entrance",
  ]) );
}

void give_final_speech(object winner) {
  if(winner && present(winner)) winner->move(DRAG_ROOMS"py/winnerroom");
  this_object()->give_loser_speech(all_inventory(this_object()) - ({ winner }) );
}

void give_loser_speech(object* players) {
  players->set_paralyzed(44,
    "Time seems to have stopped", "Time seems to return to normal.");
  foreach(object plyr in players) {
    do_conversation(plyr, ({
      "%^BLACK%^%^BOLD%^Time suddenly seems to stop.", 2,
      "%^CYAN%^Daroq says:%^RESET%^ It's time for us to meet face to face.", 5,
      "%^GREEN%^The world coalesces around you into a pale green vortex.", 5,
      "%^WHITE%^%^BOLD%^You find yourself high in the sky, atop a small cloud.", 5,
      "A pale shape appears before you.", 2,
      "%^CYAN%^Daroq says:%^RESET%^ "+capitalize(plyr->query_name())+", our time together has come to an end.", 6,
      "%^CYAN%^Daroq says:%^RESET%^ One of you mortals has just completed my test. As such, your services are no longer required.", 7,
      "Daroq bows before you.", 3,
      "%^CYAN%^Daroq says:%^RESET%^ Goodbye.", 2,
      "%^ORANGE%^The world once again begins to spin before your eyes, giving you an extreme feeling of vertigo.", 6,
      "As reality begins to settle down again, you find yourself back within the ogre caves.", 0,
    }) );
  }
}
