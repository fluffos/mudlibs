inherit ROOM;
#include <std.h>;
#include <shadow.h>;

void create() {
  ::create();
  set_property("outdoors",1);
  set_property("light",0);
  set("short","Side Path");
  set("long","This small side path travels along the wall of the city.  "
    "It seems to lead to nothing, but is fairly well used.  There are "
    "a few trees here and there, and a sickly looking bush to the west.");
  set_smell("default","The air is dry and odorless here.");
  set_listen("default","The wind is howling around you in this dark place.");
  set_items((["sky":"The sky seems to darken as you head east.",
    "tree":"Just your run of the mill trees.",
    "bush":"This bush has been moved around a bit...  perhaps you could enter it.",
    "trees":"Just your run of the mill trees."]));
  set_exits((["north":ROOMS "gate"]));
}

void init() {
  ::init();
  add_action("enter_it","enter");
}

int enter_it(string str) {
  if(!str) {
    notify_fail("Enter what?\n");
    return 0;
  }
  if(str != "bush") {
    notify_fail("You can't enter that!\n");
    return 0;
  }
  else {
    this_player()->move_player(ROOMS "counterfeit", "into the bush");
    return 1;
  }
}
