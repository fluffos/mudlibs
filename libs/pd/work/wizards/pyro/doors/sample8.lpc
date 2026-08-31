#include <std.h>

inherit VAULT;

int deny_wall_action();
int deny_key_broken();
int break_key();

void create() {
  ::create();

  set("short", "Room");
  set("long", "Sample 8\nThe wall behind you cannot be moved from this side. "
             +"The door to the north looks pretty sturdy.");

  set_exits(([ "north"  : "/wizards/pyro/doors/sample11",
               "south" : "/wizards/pyro/doors/sample6", ]));
  cover_exit_with_door("southeast", "pyrodoor7");
  cover_exit_with_door("north", "pyrodoor9");
  set_door_name("pyrodoor7", "wall");

  set_locked("pyrodoor9", 1);
  set_key("pyrodoor9", "pyrokey9");

  //do not allow the player to mess with the southern wall
  //note: in this implementation, if the doors were to be reset, the player
  //would be trapped in this and the next room until somebody came by and opened
  //the wall from the other side. Not recommended for regular mud rooms unless
  //you make sure they have a way out.
  set_door_func("pyrodoor7", "open", (:deny_wall_action:));
  set_door_func("pyrodoor7", "close", (:deny_wall_action:));
  set_door_func("pyrodoor7", "lock", (:deny_wall_action:));
  set_door_func("pyrodoor7", "unlock", (:deny_wall_action:));

  set_door_func("pyrodoor9", "unlock", (:break_key:));
  //prevent the preset environment and player messages from being displayed
  //for the "default" door status so that our break_key function can handle it
  set_door_msg("pyrodoor9", "unlock", "NO_MESSAGE");
  set_door_env_msg("pyrodoor9", "unlock", "NO_MESSAGE");

  set_door_func("pyrodoor9", "lock", (:deny_key_broken():), "key broken in lock");
}

int deny_wall_action() {
  write("You have no influence over the wall from this side.");
  return 0;
}

int break_key() {
  object key = present("pyrokey9", this_player());
  if(!key) {
    //let the door take care of deciding if the door should be able to be
    //opened or not -- the player could have a master key or something.
    //we only want to break the key if it's this specific key.
    return 1;
  }

  write("You manage to unlock the door, but the key breaks off in the lock.");
  message("info", this_player()->query_cap_name()+" curses as their key breaks "
               +"off in the door's lock.", this_object(), this_player());
  set_door_status("pyrodoor9", "key broken in lock");
  key->remove();

  //because the key has been deleted, the door must be unlocked manually
  set_locked("pyrodoor9", 0);
  return 1;
}

int deny_key_broken() {
  write("There is a key broken off inside of the lock.");
  return 0;
}
