#include <std.h>
#include <tirun.h>

inherit ROOM;

int safe;

void create() {
    ::create();
    set_smell("default", "Thick dust makes breathing difficult.");
    set_listen("default", "Water drips from the ceiling of this hole.");
    set_properties((["light":1, "no teleport":1, "indoors":1]));
    set_short("Haunted House");
    set_long(
        "This stone hole in the ground looks to have been poorly carved out by hand.  It has "
        "rounded, chipped corners and holes covering the walls.  Water drips from the ceiling "
        "as the moisture condenses.  There is little in this room except a passage west, and a "
        "large safe embedded in the opposite wall.  The way back up is to the south.");
    set_items(
        ([({"walls", "corners", "holes"}) : "The walls have small chips in them, along with tiny holes where dripping water has eroded the stone away.",
          "passage" : "The passage leads into a small, smelly room."]) );
    set_exits( ([ "south" : ROOMS"hhouse/elevator",
                  "west" : ROOMS"hhouse/finalroom" ]) );
    safe = 0;
    set_no_clean(1);
}

void init() {
  ::init();
  add_action("open", "open");
  add_action("look", "look");
}

int open(string str) {
  if(!str)
    return 0;
  if(str != "safe")
    return 0;

  if(safe)
    return notify_fail("The safe sits open, it's shelves empty.\n");

  write("Reaching for the handle, you notice four moveable numbers.  What do you set them to? (Example: 1234)\n");
  input_to("checkit");
  return 1;
}

void checkit(string str) {
  if(str != ""+(string)get_object(ROOMS"hhouse/outside")->query_code()+"") {
    write("You input the numbers and pull the handle.  It wont budge.");
    say(this_player()->query_cap_name()+" fiddles with the safe, but has no luck with it.");
    return;
  }
  write("You input the code, and the safe opens easily.  Inside, you find two bottles.");
  say(this_player()->query_cap_name()+" opens the safe and removes two bottles.");
  new(ROOMS"hhouse/potion")->move(this_player());
  new(ROOMS"hhouse/antidote")->move(this_player());
  safe = 1;
}

int look(string str) {
  if(!str)
    return 0;
  if(str != "safe")
    return 0;

  if(safe)
    write("The safe sits open, it's shelves empty.");
  else
    write("The safe is securely closed, the lock consisting of four numbers.");
  say(this_player()->query_cap_name()+" looks over the safe.");
  return 1;
}
