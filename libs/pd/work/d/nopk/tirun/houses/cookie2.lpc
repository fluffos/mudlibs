#include <std.h>
#include <tirun.h>

inherit ROOM;

void create() {
  ::create();
  set_properties(([ "light" : 2,
                  "indoors" : 1
                 ]));
  set_short("Stairs Room");
  set_long("You've ventured deeper into Cookie's house now. Right infront of you leads a "
           "circling staircase into the unknown upstairs. The floors creak queitly under "
           "the wieght of your feet. The only decoration in this room is a single, large, "
           "black and white painting on the eastern wall.");
  set_smell("default","Oak and spices.");
  set_exits((["west" : ROOMS"houses/cookie4",
              "south" : ROOMS"houses/cookie1",
              "up" : ROOMS"houses/cookie5"]));
  set_items((["painting" : "On a background of all white, a Cartoon looking male figure in old \"mobster\" "
                           "like clothing, toating a stylish Tommy-gun poses in black. A small inscription "
                           "gleams on the golden plaquered on the base of the frame. Perhaps you can read "
                           "it."]));
}

void init() {
  ::init();
  add_action("read", "read");
}

int read(string str) {
  if(!str) return 0;
  if(str != "inscription") return 0;
  write("%^YELLOW%^~Dedicated forever, MMSS%^RESET%^");
  say(this_player()->query_cap_name()+" reads the inscription on the painting.");
  return 1;
}
