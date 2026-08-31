inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("outdoors",1);
  set_property("light",0);
  set("short","Outside the gates of Tenebrae");
  set("long","Welcome to the city of Tenebrae.  The black iron gates "
    "are set into the wall to the east.  There are two torches on each side of the gate, "
    "casting flickering shadows, as if they had a life of their own...  "
    "A faint path trails off to the south.");
  set_pre_exit_functions(({"gates"}),({"go_gates"}));
  set_smell("default","The air is dry and odorless here.");
  set_listen("default","The wind is howling around you in this dark place.");
  set_items((["sky":"The sky is oppressively dark over the city.",
    "torch":"The torch flickers in the wind.",
    "gates":"The iron gate could be opened, if it weren't for those pesky guards.",
    "path":"The path is dry and worn."]));
  set_exits((["south":ROOMS "passell","north":ROOMS "thirtyeight","gates":ROOMS "first","west":ROOMS "landing"]));
  set_invis_exits(({"south"}));
}

void reset() {
  ::reset();
  if(!present("shadowguard")) {
    new(MOB "shadowguard")->move(this_object());
    new(MOB "shadowguard")->move(this_object());
  }
}

int go_gates() {
if (!present("pass", this_player())) {
  if(present("shadowguard")){
    write("The Shadowguard stops you and says \"You must have a pass!\"");
    return 0;
    }
    else return 1;
  }
  else {
    write("You show your pass and go through the gates.");
    return 1;
  }
}
