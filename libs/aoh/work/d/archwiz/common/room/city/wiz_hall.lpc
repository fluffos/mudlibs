/* modified by Cadra 03-10-1994 
 *
 * Another entry is from /d/archwiz/common/room/pirate/downch3.
 */
#include <rooms.h>
#include <moving.h>
#include "path.h"

inherit "/std/room";

#define ELEVATOR CITY("elevator")

int lamp_is_lit;
object northroom;

QueryIntLong() {return ::QueryIntLong()+_lamp();}

string _door() {
 return process_string(
"A surprisingly modern door. It is @@_door2@@. Besides to it are a button and "
"a @@_lamp2@@lamp.\n");
}

string _lamp() {return lamp_is_lit?"There is a lit lamp besides the door.\n":"";}

string _lamp2() { return lamp_is_lit ? "lit " : ""; }

string _door2() { return (ELEVATOR)->query_door() ? "closed":"open"; }

open(string str) {
  if (str != "door") return 0;
  if ((ELEVATOR)->query_level() != 1) {
    write("You can't when the elevator isn't here.\n");
    return 1;
  }
  (ELEVATOR)->open_door("door");
  return 1;
}

close(string str) {
  if (str != "door") return 0;
  (ELEVATOR)->close_door("door");
  return 1;
}

west() {
  if ((ELEVATOR)->query_door() || (ELEVATOR)->query_level() != 1) {
    write("The door is closed.\n");
    return 1;
  }
  if (!this_player()) return 0;
  this_player()->move(ELEVATOR,M_GO,"west");
  return 1;
}

push(string str) {
  if (str && str != "button") return 0;
  if ((ELEVATOR)->call_elevator(1)) lamp_is_lit = 1;
  return 1;
}

elevator_arrives() {
  say("The lamp on the button beside the elevator goes out.\n");
  lamp_is_lit = 0;
}

notify_enter(o, m, e) {
  ::notify_enter(o, m, e);
  if (living(previous_object()) && !interactive(previous_object())) {
    log_file("LEO", (objectp(previous_object()) ? object_name(previous_object())
                                                : previous_object())+
            " from "+(objectp(o)?object_name(o):o)+" method "+m+"\n");
  }
}

int do_north() {
  if (!this_player()) return 0;
  if (!query_once_interactive(this_player())) return 0;
  if (this_player()->QueryRealLevel() < 20) return notify_fail(
    "Only high level players are allowed to enter the northern "
    "room.\n"),0;
  return this_player()->move(CITY("wiz_north"),M_GO,"north");
}
  
void create() {
  ::create();
  SetIntShort("Wizards Hall");
  SetIntLong(
"You are in the Hall of the Wizards.\n"
"It's a medium sized comfortable room, the home of Archwizard Leo. "
"In the former days apprentice wizards came here to receive full wizardhood "
"or just to chat with Leo. But now it seems that noone has been here for a "
"long time. There is a door to the west and a doorway to the north. "
"A dark hole is right above your head in one of the walls.\n");
  AddDetail(({"doorway","dark opening","opening"}),
"The doorway is a dark opening in the wall. Every now and then a dark glow "
"is perceptable, like the remains of a formerly strong magic field.\n");
  AddDetail("door", #'_door);
  AddDetail(({"strong magic field","field","magic field","remains of a magic field",
  "remains","strong magic"}),
"Every now and then you see a dark glow.\n");
  AddDetail(({"glow","dark glow"}),
"It looks as if the magic lost power.\n");
  AddDetail(({"medium sized room","room","comfortable room","home",
  "home of leo","medium sized comfortable room","hall","hall of the wizards"}),
QueryIntLong());
  AddDetail(({"walls","wall"}),
"A dark hole is in one of them.\n");
  AddDetail("ceiling","It is high above you.\n");
  AddDetail(({"floor","ground"}),
"You stand on it.\n");
  AddDetail(({"hole","dark hole"}),
(PIRATE("downch3"))->QueryIntLong()+(PIRATE("downch3"))->Content());
  AddExit("north",#'do_north);
  AddExit("west", #'west);
  AddRoomCmd("open", #'open);
  AddRoomCmd("close", #'close);
  AddRoomCmd("push", #'push);
  AddRoomCmd("press", #'push);
  AddItem("/obj/leo",REFRESH_HOME);
}
