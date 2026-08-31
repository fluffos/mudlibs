#include <std.h>

inherit VAULT;

void create() {
  ::create();

  set("short", "Room");
  set("long", "Sample 5\nThe manhole to the next room blends in with "
             +"the floor here, it's impossible to locate it. You can "
             +"jump down through the hole. The corridor north leads to "
             +"a wide open chamber. The chamber is sectioned off by a "
             +"large grate");

  set_exits(([ "down" : "/wizards/pyro/doors/sample4",
               "north"  : "/wizards/pyro/doors/sample6" ]));
  //the bottom exit is not covered with a door from this room
  cover_exit_with_door("north", "pyrodoor6");
  set_key("pyrodoor6", "pyrokey9");
  set_locked("pyrodoor6", 1);
  set_door_name("pyrodoor6", "grate");
  set_door_msg("pyrodoor6", "unlock",
        "As you place the key in the lock, your pulse seems to quicken and your "
       +"skin seems to tighten. You turn the key in the lock and place it back "
       +"in your inventory, not sure what to expect.");
  set_door_msg("pyrodoor6", "lock", "You are relieved to have the grate locked again.");
  set_door_msg("pyrodoor6", "open", "After much straining, you slide the grating open.");
  set_door_msg("pyrodoor6", "close", "You carefully put the grating back in its place.");
  set_door_msg("pyrodoor6", "enter", "You step through the grating, unsure what to expect.");
  set_door_env_msg("pyrodoor6", "open", "The grate creaks to life and slowly slides open.");
  set_door_env_msg("pyrodoor6", "close", "With a great woosh, the grating slides back into place.");
  set_door_env_msg("pyrodoor6", "lock", "The grating shudders as it is locked in place.");
  set_door_env_msg("pyrodoor6", "unlock", "Oh no! somebody unlocked the greating!");
}

void reset() {
  ::reset();
  if(!present("pyrokey6")) {
    object key;
    key = new("/wizards/pyro/doors/blank_key");
    key->move(this_object());
    key->initialize_key("pyrokey9");
    key->set_short("A weak key");
    key->set_long("This key does not look very sturdy, it seems like it could break at any time.");
  }
}
