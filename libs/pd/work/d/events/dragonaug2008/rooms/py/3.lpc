#include <std.h>
#include <dragonevent.h>

#define SAY(x) message("info", x, this_object())

inherit DRAG_ROOMS"py/base";

int rock_cooldown = 0, vine_cooldown = 0;

void create() {
  ::create();
  set_property("forest", 1);
  set_short("%^GREEN%^A dense jungle.");
  set_long("%^GREEN%^A dense forest. A thick canopy of trees and vines block out the sky. Below is a large circular path made of %^ORANGE%^dirt%^GREEN%^ and %^RESET%^%^BOLD%^rock%^RESET%^%^GREEN%^, which leads northeast through the forest. The path is surrounded by large trees and bushes which are interwoven with vines.");
  set_exits( ([
    "northeast" : DRAG_ROOMS"py/4",
  ]) );
  set_items( ([
    "canopy" : "It blocks out the sky above.",
    "forest" : "You are standing in it.",
    "trees" : "Tall trees that completely surround the circular path.",
    "path" : "A large circular dirt clearing that has a small dirt offshoot which leads to the northeast.",
    "dirt" : "It litters the path below.",
    "clearing" : "You are standing in it.",
    "bushes" : "They are covered in vines.",
    ({"rocks", "rock"}) : "Loose rocks scatter the ground.",
    "vines" : "They are scattered throughout the area around you.",
  ]) );
  set_heart_beat(60);
}

int accept_player_into_instance(object play) { return 1; }

void init() {
  ::init();
  add_action("get_items", ({"get", "pick", "retrieve"}));
}

int get_items(string str) {
  if(present(str, this_object())) return 0;
  if(str == "vines" || str == "rocks") {
    SAY("Really? All of them?");
    return 1;
  }
  if(str != "vine" && str != "rock") return 0;
  if(str == "vine") {
    if(!vine_cooldown) {
      vine_cooldown = 5;
      SAY("You manage to pick a vine from the bushes around you.");
      new(DRAG_ITEMS"vine")->move(this_player());
    } else SAY("You cannot do that yet.");
  }
  else if(str == "rock") {
    if(!rock_cooldown) {
      rock_cooldown = 5;
      SAY("You pick up a stone from the ground below you.");
      new(DRAG_ITEMS"rock")->move(this_player());
    } else SAY("You cannot do that yet.");
  }
  return 1;
}

void heart_beat() {
  if(rock_cooldown) rock_cooldown--;
  if(vine_cooldown) vine_cooldown--;
}
