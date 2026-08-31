#include <std.h>

inherit VAULT;

int deny_wall_action();
int deny_door_broken();
int break_door(string str);

void create() {
  ::create();

  set("short", "Room");
  set("long", "Sample 7\nThe wall behind you cannot be moved from this side. "
             +"Keep on moving. The door to the north is made out of wood. It "
             +"is locked but the key hole is fused shut. You're going to have "
             +"to break it down.");

  set_exits(([ "north"  : "/wizards/pyro/doors/sample10",
              "southeast" : "/wizards/pyro/doors/sample6", ]));
  cover_exit_with_door("southeast", "pyrodoor7");
  cover_exit_with_door("north", "pyrodoor8");
  set_door_name("pyrodoor7", "wall");
  //normally you should not call this without also setting a key, but the player
  //is not supposed to be able to open this door without breaking it down
  set_locked("pyrodoor8", 1);

  //do not allow the player to mess with the southern wall
  //note: in this implementation, if the doors were to be reset, the player
  //would be trapped in this and the next room until somebody came by and opened
  //the wall from the other side. Not recommended for regular mud rooms unless
  //you make sure they have a way out.
  set_door_func("pyrodoor7", "open", (:deny_wall_action:));
  set_door_func("pyrodoor7", "close", (:deny_wall_action:));
  set_door_func("pyrodoor7", "lock", (:deny_wall_action:));
  set_door_func("pyrodoor7", "unlock", (:deny_wall_action:));

  set_door_func("pyrodoor8", "close", (:deny_door_broken:), "broken");
}

int deny_wall_action() {
  write("You have no influence over the wall from this side.");
  return 0;
}

int deny_door_broken() {
  write("Try as you might, you can't seem to move the door. It's broken.");
  return 0;
}

void init() {
  ::init();
  add_action("break_door", "break");
}

int break_door(string str) {
  if(str != "door" && str != "down door")
    return 0;
  if(query_door_status("pyrodoor8") == "broken") {
    return notify_fail("The door is already broken.\n");
  }
  write("You place a firm kick in the center of the door and snap it off of its hinges.");
  message("say", this_player()->query_cap_name()+" breaks the door off its hinges.",
          environment(this_player()), this_player());
  set_door_status("pyrodoor8", "broken");
  set_closed("pyrodoor8", 0);
  set_locked("pyrodoor8", 0);
  return 1;
}
