#include <std.h>

inherit VAULT;

int deny_wall_action();
int electrocute_user();
int defuse_door(string str);

void create() {
  ::create();

  set("short", "Room");
  set("long", "Sample 9\nThe wall behind you cannot be moved from this side. "
       +"Stop! Take a moment to observe your surroundings."
           +"\nYou can see an electric current running through the door! Try <defuse>ing it before touching it!");

  set_exits(([ "north"  : "/wizards/pyro/doors/sample12",
              "southwest" : "/wizards/pyro/doors/sample6", ]));
  cover_exit_with_door("southwest", "pyrodoor7");
  cover_exit_with_door("north", "pyrodoor10");
  set_door_name("pyrodoor7", "wall");

  //do not allow the player to mess with the southern wall
  //note: in this implementation, if the doors were to be reset, the player
  //would be trapped in this and the next room until somebody came by and opened
  //the wall from the other side. Not recommended for regular mud rooms unless
  //you make sure they have a way out.
  set_door_func("pyrodoor7", "open", (:deny_wall_action:));
  set_door_func("pyrodoor7", "close", (:deny_wall_action:));
  set_door_func("pyrodoor7", "lock", (:deny_wall_action:));
  set_door_func("pyrodoor7", "unlock", (:deny_wall_action:));

  set_door_func("pyrodoor10", "open", (:electrocute_user:));
  set_door_func("pyrodoor10", "close", (:electrocute_user:));
  set_door_func("pyrodoor10", "open", "return 1", "defused");
  set_door_func("pyrodoor10", "close", "return 1", "defused");

}

int deny_wall_action() {
  write("You have no influence over the wall from this side.");
  return 0;
}

int electrocute_user() {
  write("You grab onto the door handle and are thrown backwards, %^YELLOW%^electrocuted%^RESET%^."
      +" The shock is not powerful enough to kill you, but perhaps you should try another way?");
  message("info", this_player()->query_cap_name()+" grabs"
                 +" onto the door and is suddenly thrown backwards, smoke rising from their body.",
                   this_object(), this_player());
  this_player()->add_hp(-50);
  if(this_player()->query_hp() < 1)
    this_player()->set_hp(1);
  return 0;
}

void init() {
  ::init();
  add_action("defuse_door", "defuse");
}

int defuse_door(string str) {
  if(str != "door")
    return 0;
  if(query_door_status("pyrodoor10") == "defused") {
    return notify_fail("The door is already defused.\n");
  }
  write("You urinate on the door handle, disrupting the electric current and defusing the door.");
  message("say", this_player()->query_cap_name()+" wanders over to the door and urinates on the handle.",
          environment(this_player()), this_player());
  set_door_status("pyrodoor10", "defused");
  return 1;
}
