/* Home Lobby */

#include "/players/mateese/mydefs.h"

#include <config.h>
#include <properties.h>
#include <moving.h>
#include <rooms.h>

inherit "/std/room";

string walldsc1, walldsc2;
object home;

string _wall();

create() {
  room::create();
  SetIntShort ("Mateese's Lobby");
  SetIntLong (
"You are in a north/south passage. It is dimly lit, and the walls are\n"+
"plain cold rock. In the northern wall you recognize the outlines of a door.\n"+
"To the south lights are visible every now and then, and doorway leads east\n"+
"into a dark room.\n"
              );
  AddExit ("east", MR+"guestbar");
  AddExit ("south", MR+"elevtop");
  AddDetail ( ({ "wall", "door" }), #'_wall);
  AddRoomCmd ("open", "fopen");
  AddRoomCmd ("north", "fnorth");
  AddRoomCmd ("knock", "fknock");
  Set(P_INDOORS, 1);
  SetBright (MAX_SUNBRIGHT/2);

  walldsc1 = "The door looks like being part of the wall.\n"+
             "However, it is closed.\n";
  walldsc2 = "There is an opening in the wall.\n";
}

_home() { 
  if (home) return home;
  if (catch(call_other(MR+"home", "???")))
    write ("You sense an anomaly in the fabric of space.\n");
  return home = find_object (MR+"home");
}

_wall() { 
  return (_home() && home->query_lobby_door()) ? walldsc2 : walldsc1; 
}

fopen (str) {
  if (!str || str != "door") return 0;
  if (!PL_WLEVEL) write ("Can't you unpolite folks knock first?\n");
  else if (!_home()) {}
  else if (home->query_lobby_door()) write ("The door is already open.\n");
  else home->lobby_open_door();
  return 1;
}

fclose (str) {
  if (!str || str != "door") return 0;
  if (!PL_WLEVEL) write ("It's not up to you to do that.\n");
  else if (!_home()) {}
  else if (!home->query_lobby_door()) write ("The door is already closed.\n");
  else home->lobby_close_door();
  return 1;
}

fnorth (str) {
  if (str) return 0;
  if (!_home()) return 1;
  if (!PL_WLEVEL && !home->query_lobby_door()) { 
    write ("Through a closed door?\n");
    return 1;
  }
  if (!home->query_lobby_door()) {
    write ("The door becomes immaterial to let you pass.\n");
    say ("The door becomes momentarily immaterial to let "+PL_NAME+" pass.\n");
  }
  PL->move(MR+"home", M_GO, "home");
  return 1;
}

fknock (str) {
  string foo;
  if (str && str != "door" && sscanf (str, "%s door", foo) != 1) return 0;
  if (!_home()) return 1;
  if (home->query_lobby_door()) {
    write ("Knock on what?\n");
    return 1;
  }
  write ("Knock Knock! You knock on the door.\n");
  say (PL_NAME+" knocks on the door.\n");
  if (!find_living ("mateese")) {
    tell_room (ME, 
"A hollow voice echoes through the room:\n"+
"  'Mateese is not in this dimension, you knock in vain.'\n"
              );
    return 1;
  }
  home->player_knocks();
  return 1;
}

door_opens () {
  tell_room (ME, "Silently the door glides into the wall.\n");
}
  
door_closes () {
  tell_room (ME, "The door silently shuts close.\n");
}
  
