#include <std.h>
#include <shadow.h>

inherit ROOM;

int blah;

void create() {
  ::create();
  set_property("outdoors",1);
  set_property("light",0);
  set("short","North Alley");
  set("long","This alley heads north amongst a variety of houses.  "
    "The houses are all grey with old shingles on top.  The houses "
    "look like they're really old. The wall of the city is on the left, "
    "but there seems to be something hiding in the corner.");
  set_smell("default","The air is dry and odorless here.");
  set_listen("default","Conversation can be heard coming from a few houses.");
  set_search("corner", (: this_object(), "search_corner" :));
  set_items((["sky":"The sky is dark as ever.","road":"The cobblestone road heads east, and south.",
    "house":"The house is old and run down.  You try the door, but it is locked.",
    "corner":"The corner is dark and hard to see in.  Perhaps if you made a "
      "more through search, you would find something.",
    "wall":"The wall to the city is old and is growing a bit "
      "of %^GREEN%^moss%^WHITE%^, but still intact.",
    "moss":"What a cute little plant!",
    "stone":"The cobblestones are black and grey.  Like the sky."]));
  set_exits((["east":ROOMS "tene03","south":ROOMS "tene01"]));
  blah = 1;
}
 
void reset() {
  ::reset();
  blah = 1;
}
 
void init() {
  ::init();
  add_action("search_corner","search");
}

int search_corner(string str) {
  if(str != "corner")
    return 0;
  if(blah == 1) {
    write("You find Little Jack Horner, sitting with his thumb in a pie!");
    say(this_player()->query_cap_name()+" finds Jack Horner!");
    new(MOB "jack")->move(this_object());
    blah = 0;
    return 1;
  }
  write("It seems like whatever was here has already been found.");
  return 1;
}
