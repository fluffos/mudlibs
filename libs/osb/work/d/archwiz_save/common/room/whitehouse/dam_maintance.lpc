inherit "std/room";

#include <moving.h>
#include <rooms.h>
#include <config.h>
#include <properties.h>
#include "path.h"

#define DAMLOBBYROOM (WHITEHOUSE("dam_lobby"))

int lightstatus;

string show_green() {
  return DAMROOM->activated() ? "It is glowing.\n" : "It is dark.\n";
}

string show_red() {
  return DAMROOM->activated() ? "It is dark.\n" : "It is glowing.\n";
}

string show_yellow() {
  return lightstatus ? "It is dark.\n" : "It is glowing.\n";
}

string QueryIntNoise() {
  return DAMROOM->activated() ?
    "A faint humming sound can be heard from the northwest.\n" : 0;
}

int push_it(string str) {
  if (!str) return 0;
  if (!this_player()) return 0;
  if (!this_object()) return 0;
  if (str == "button") {
    return (int) notify_fail("which one do you mean?\n") && 0;
    }
  if (str == "yellow button" || str == "yellow") {
    write("You push the yellow button.\n");
    show(this_player()->QueryName()+" pushes the yellow button.\n",
      this_player());
    tell_room(this_object(),"The lights go ");
    lightstatus = 1-lightstatus;
    if (lightstatus) {
      tell_room(this_object(),"on.\n");
      SetBright(MAX_SUNBRIGHT/2);
      DAMLOBBYROOM->set_the_light(1);
      }
    else {
      tell_room(this_object(),"off.\n");
      SetBright(-10);
      DAMLOBBYROOM->set_the_light(0);
      }
    return 1;
    }
  if (str == "green button" || str == "green") {
    write("You push the green button.\n");
    show(this_player()->QueryName()+" pushes the green button.\n",
      this_player());
    if (DAMROOM->activated())
      write("Nothing happens.\n");
    else {
      tell_room(this_object(),"You hear a faint humming sound.\n");
      DAMROOM->set_active(1);
      }
    return 1;
    }
  if (str == "red button" || str == "red") {
    write("You push the red button.\n");
    show(this_player()->QueryName()+" pushes the red button.\n",
      this_player());
    if (!DAMROOM->activated())
      write("Nothing happens.\n");
    else {
      tell_room(this_object(),"There is sudden silence.\n");
      DAMROOM->set_active(0);
      }
    return 1;
    }
}

QueryIntLong() {
  return (
"This is what appears to have been the maintenance room for the dam. "
"Apparently this room has been vandalized recently, for most of the "
"valuable equipment is gone. There is a row of buttons here, colored "
"yellow, green and red. There is a doorway to the west.\n"+
  (DAMROOM->activated() ? "A faint humming sound can be heard.\n" : ""));
}

create() {
  ::create();
  SetIntShort("Maintenance Room");
  SetIndoors(1);
  SetBright(-10);
  AddDetail(({"room","maintenance room"}),#'IntLong);
  AddDetail(({"way","doorway"}),"The doorway leads west over the dam.\n");
  AddDetail("green button",#'show_green);
  AddDetail("red button",#'show_red);
  AddDetail("yellow button",#'show_yellow);
  AddDetail(({"button","buttons"}),"Which button do you mean?\n");
  AddRoomCmd(({"press","push"}),#'push_it);
  AddExit("west","./dam_lobby");
  AddItem("/std/thing",REFRESH_REMOVE,
    ([P_SHORT: "a screwdriver",
      P_LONG:  "A flathead screwdriver with a transparent green hilt.\n",
      P_IDS:   ({"screwdriver","driver","pen"}),
      P_WEIGHT: 43,
      P_VALUE: 31]));
  reset();
}

reset() {
  ::reset();
  lightstatus = 0;
}
