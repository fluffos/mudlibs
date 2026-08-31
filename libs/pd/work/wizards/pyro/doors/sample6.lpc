#include <std.h>

inherit VAULT;

int push_button(string str);
int wall_open();
int wall_close();
int can_toggle_door();

int doorStuck;

void create() {
  ::create();

  set_short("Room");
  set_long("Sample 6\nA large corridor. There is a wall to "
          +"the north of you that blocks all three exits to "
          +"the north. There is a button right in front of "
          +"you, perhaps you could <push> it? You may also "
          +"be able to <open wall>.");

  set_exits(([ "northwest" : "/wizards/pyro/doors/sample7",
               "north"  : "/wizards/pyro/doors/sample8",
               "northeast" : "/wizards/pyro/doors/sample9",
               "south" : "/wizards/pyro/doors/sample5", ]));
  cover_exit_with_door("south", "pyrodoor6");
  cover_exit_with_door("north", "pyrodoor7");
  cover_exit_with_door("northwest", "pyrodoor7");
  cover_exit_with_door("northeast", "pyrodoor7");
  set_door_name("pyrodoor7", "wall");

  if(query_closed("pyrodoor7")) {
    add_invis_exit("north");
    add_invis_exit("northwest");
    add_invis_exit("northeast");
  }

  set_door_msg("pyrodoor6", "unlock", "Now that you're on the other side of the wall, "
           +"you have no qualms about unlocking the grating and accomplish it with ease.");
  set_door_msg("pyrodoor6", "open", "You move the grating aside.");
  set_door_msg("pyrodoor6", "enter", "You step confidently through the grating.");
  set_door_env_msg("pyrodoor6", "open", "Somebody has opened the grating.");
  set_door_env_msg("pyrodoor6", "lock", "You notice somebody lock the grating.");
  set_door_env_msg("pyrodoor6", "unlock", "As the grating's lock is disengaged you shiver in
anticipation.");

  set_door_func("pyrodoor7", "open", (: wall_open :) );
  set_door_func("pyrodoor7", "close", (: wall_close :) );
  set_door_msg("pyrodoor7", "open", "You place your hands on the wall and drag it down into the
floor, revealing the passageways to the north.");
  set_door_msg("pyrodoor7", "close", "You dig your hands into the floor and drag the northern wall
back up, blocking off the passageways to the north.");
  set_door_env_msg("pyrodoor7", "open", "The wall to the north slides into the ground, revealing
three passageways.");
  set_door_env_msg("pyrodoor7", "close", "The floor separates and a wall slides out of the ground,
blocking off the passageways to the north.");
  doorStuck = 1;
}

void init() {
  ::init();
  add_action("push_button", "push");
}

int push_button(string str) {
  if (str != "button")
    return 0;
  write("You push the button and hope for the best.");
  message("info", this_player()->query_cap_name()+" pushes the mysterious button.", this_object(),
this_player());
  doorStuck = !doorStuck;
  return 1;
}

int can_toggle_door() {
  if(doorStuck) {
    write("The door is being held in place by some mechanism and cannot be moved.");
    message("info", this_player()->query_cap_name()+" tries to move the wall out of the way and
fails.", this_object(), this_player());
    return 0;
  }
  return 1;
}

int wall_open() {
  if(!can_toggle_door()) return 0;
  remove_invis_exit("north");
  remove_invis_exit("northwest");
  remove_invis_exit("northeast");
  return 1;
}

int wall_close() {
  if(!can_toggle_door()) return 0;
  add_invis_exit("north");
  add_invis_exit("northwest");
  add_invis_exit("northeast");
  return 1;
}
