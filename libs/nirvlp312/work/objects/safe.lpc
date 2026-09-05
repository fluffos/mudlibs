/* a real safe */

inherit "inherit/container";

#include "/include/fn/i_to_str.h"

#define REAL (string)this_player()->query_name(1)


object cracker;          /* current user of safe */
object stethoscope;      /* to crack the safe    */
int *code;               /* code numbers         */
int *direction;          /* 0 right, 1 left      */
int *current_position;
int *current_direction;
mixed *safe_crackers;

int safe_difficulty;
status safe_lock;

string current_tumbler_position();


void reset(status arg) {
  current_position = ({});
  current_direction = ({});
  safe_crackers = ({});
  if (arg) return;
  set_name("safe");
  set_short("Safe");
  set_long("It is a rather small safe, formed as a cube.  On the\n" +
           "safe is a numbered tumbler.  Next to the tumbler is a\n" +
           "handle.  Below the handle is a small key hole.\n");
  set_key_id("no_key");
  set_closed(1);
  safe_lock = 1;

  /* combination can be made larger */

  code = ({ random(9)+1, random(9)+1, random(9)+1, });
  direction = ({ random(2), random(2), random(2), });
  safe_difficulty = 5;
}


status set_safe_lock(status i) { safe_lock = i;            }
int set_safe_difficulty(int i) { safe_difficulty = i;      }

status query_safe_lock()       { return safe_lock;         }
int query_safe_difficulty()    { return safe_difficulty;   }

int *query_code()              { return code;              }
int *query_direction()         { return direction;         }
int *query_current_position()  { return current_position;  }
int *query_current_direction() { return current_direction; }
mixed *query_safe_crackers()   { return safe_crackers;     }

status look_at(string str) {
  if (str == "tumbler" || str == "dial" || str == "brass dial") {
    write("The tumbler is a small brass dial on the front of the " +
          query_name() + ".\n" +
          "There are numbers from 1 to 9 marked on it.\n" +
          "You can turn the tumbler.\n");
    write(current_tumbler_position());
    return 1;
  }
  if (str == "handle") {
    write("You turn the  handle to open the safe.\n");
    return 1;
  }
  if (str == "key hole" || str == "key") {
    if (query_key_id() == "no_key") {
      write("The key hole is a dummy!\nIt doesn't need a key.\n");
      return 1;
    }
    else {
      return ::look_at(query_lock_id());
    }
  }
  return ::look_at(str);
}

void init() {
  ::init();
  add_action("turn", "turn");
  add_action("safe_crack", "safecrack");
}


void container_open(string verb) {
  if (closed == 1) {
    if (safe_lock) {
      write("The safe tumbler is still locked.\n");
      return;
    }
  }
  ::container_open(verb);
}

status turn(string str) {
  int number;
  status wheel_direction;
  object ob;
  string safe;

  if (cracker && cracker != this_player()) {
    if (environment() == cracker || environment() == environment(cracker)) {
      write(cracker->query_name() + " is currently using the " + query_name() +
            ".\n");
      return 1;
    }
  }
  cracker = this_player();
  if (!str) {
    notify_fail("Turn what?\n");
    return 0;
  }
  if (sscanf(str, "handle on %s", safe)) {
    if (!(ob = present(safe, environment(this_player())))) {
      if (!(ob = present(safe, this_player()))) {
        write("There is no " + safe + " here.\n");
        return 1;
      }
    }
    if (ob != this_object()) {
      notify_fail("You can't do that!\n");
      return 0;
    }
    if (is_locked && query_key_id() != "no_key") {
      write("The " + safe + " is locked.  You need a " + query_key_id() +
            " to unlock it.\n");
      return 1;
    }
    if (closed == 1) container_open("open");
    else container_open("closed");
    return 1;
  }
  if (sscanf(str, "handle%s", str)) {
    notify_fail("Turn handle on what?\n");
    return 0;
  }
  if (sscanf(str, "tumbler left %d on %s", number, safe)) wheel_direction = 1;
  sscanf(str, "tumbler right %d on %s", number, safe);
  if (!number) {
    notify_fail("Turn tumbler left|right <number> on <item>?\n");
    return 0;
  }
  if (!(ob = present(safe, environment(this_player())))) {
    if (!(ob = present(safe, this_player()))) {
      write("There is no " + safe + " here.\n");
      return 1;
    }
  }
  if (ob != this_object()) {
    notify_fail("You can't do that!\n");
    return 0;
  }
  current_position += ({ number, });
  current_direction += ({ wheel_direction, });
  if (sizeof(current_position) == sizeof(code)) {
    int i;

    for (i = 0; i < sizeof(code); i++) {
      if (current_position[i] == code[i] &&
          current_direction[i] == direction[i]) continue;
      write("The tumbler swings around to the zero position.\n");
      current_position = ({});
      current_direction = ({});
      return 1;
    }
    write("Click! You hear the " + query_name() + " 's lock bars slide.\n");
    safe_lock = !safe_lock;
    if (safe_lock) write("The safe locks.\n");
    else write("The safe unlocks.\n");
  }
  else {
    write("You turn the tumbler " + int_to_str(number) + " " +
          ((wheel_direction) ? "left" : "right") + ".\n");
  }
  return 1;
}


string current_tumbler_position() {
  string str;
  int i;

  str = "The tumbler position is at ";
  if (!sizeof(current_position)) str += "zero";
  for (i = 0; i < sizeof(current_position); i++) {
    if (i && i != sizeof(current_position)-1)
      str += ", ";
    else if (i)
      str += " and ";
    str += int_to_str(current_position[i]);
    if (current_direction[i])
      str += " left";
    else
      str += " right";
  }
  return str + ".\n";
}

string query_combination() {
  string str;
  int i;

  str = "The tumbler combination is ";
  for (i = 0; i < sizeof(code); i++) {
    if (i && i != sizeof(code)-1)
      str += ", ";
    else if (i)
      str += " and ";
    str += int_to_str(code[i]);
    if (direction[i])
      str += " left";
    else
      str += " right";
  }
  return str;
}


/***************************************************************************/

status safe_crack(string str) {
  int number, i;
  string safe;
  status wheel_direction;
  object ob;

  if (cracker && cracker != this_player()) {
    if (environment() == cracker || environment() == environment(cracker)) {
      write(cracker->query_name() + " is currently using the " + query_name() +
            ".\n");
      return 1;
    }
  }
  cracker = this_player();
  if (!this_player()->query_locks()) {
    write("You are not skilled at safe cracking.\n");
    return 1;
  }
  if (!stethoscope || !present(stethoscope, this_player())) {
    write("You need to apply a stethoscope to the " + query_name() + ".\n");
    return 1;
  }
  if (!str) {
    notify_fail("Safecrack tumbler left|right <number> on <item>?\n");
    return 0;
  }
  if (sscanf(str, "tumbler left %d on %s", number, safe)) wheel_direction = 1;
  sscanf(str, "tumbler right %d on %s", number, safe);
  if (!number) {
    notify_fail("Turn tumbler left|right <number> on <item>?\n");
    return 0;
  }
  if (!(ob = present(safe, environment(this_player())))) {
    if (!(ob = present(safe, this_player()))) {
      write("There is no " + safe + " here.\n");
      return 1;
    }
  }
  if (ob != this_object()) {
    notify_fail("You can't do that!\n");
    return 0;
  }
  if (code[sizeof(current_position)] != number) {
    write("You hear a low clicking noise.\n");
    return 1;
  }
  if (direction[sizeof(current_position)] != wheel_direction) {
    write("You hear a low clicking noise.\n");
    return 1;
  }
  if ((i = member(safe_crackers, REAL)) == -1) {
    safe_crackers += ({ REAL, ({}), });
    i = member(safe_crackers, REAL);
  }
  while (sizeof(current_position) > sizeof(safe_crackers[i+1])) {
    safe_crackers[i+1] += ({ 0, });
  }
  if (sizeof(safe_crackers[i+1]) != sizeof(current_position)) {
    if (safe_crackers[i+1][sizeof(current_position)])
      write("You hear a small thunk noise again.\n");
    else
      write("You hear a low clicking noise.\n");
    return 1;
  }
  if (random((int)this_player()->query_locks() + 1) >=
      random(safe_difficulty + 1)) {
    write("You hear a small thunk noise.\n");
    safe_crackers[i+1] += ({ 1, });  /* successful */
  }
  else {
    write("You hear a low clicking noise.\n");
    safe_crackers[i+1] += ({ 0, }); /* failed */
  }
  return 1;
}


/* can use stethoscope on this */

status use_stethoscope(object arg) {
  stethoscope = arg;
  return 1;
}

  
