#include "path.h"
#include <properties.h>
#include <moving.h>
#include <rooms.h>
inherit "std/room";

#define ELEVATOR CITY("elevator")

int lamp_is_lit;

door() {
  string s;
  if (!(ELEVATOR)->query_door() && (ELEVATOR)->query_level())
    s = "The door is open.\n";
  else s = "The door is closed.\n";
  if (lamp_is_lit) s += "The lamp beside the door is lit.\n";
  return s;
}

int west() {
  if ((int)(ELEVATOR)->query_door() || ((int)(ELEVATOR)->query_level() != 3)) {
    write("The door is closed.\n");
    return 1;
  }
  if (!this_player()) return 0;
  this_player()->move(ELEVATOR,M_GO,"west");
  return 1;
}

int open(string str) {
  if (str != "door") return 0;
  if ((int)(ELEVATOR)->query_level() != 3) {
    write("You can't when the elevator isn't here.\n");
    return 1;
  }
  (ELEVATOR)->open_door("door");
  return 1;
}

int close(string str) {
  if (str != "door") return 0;
  (ELEVATOR)->close_door("door");
  return 1;
}

int push(string str) {
  if (str && str != "button") return 0;
  if ((int)(ELEVATOR)->call_elevator(3)) lamp_is_lit = 1;
  return 1;
}

int search(string str) {
  object ob;
  if (!str) {
    notify_fail("You should be more specific.\n");
    return 0;
    }
  str = lower_case(str);
  if (!this_player()) return 0;
  if (member(({"pile","bones","pile of bones","bone","skull",
		 "huge pile","huge pile of bones","the pile of bones"}),
	     str)!=-1)
    {
      write("You rummage through the bones, but find nothing.\n");
      // BEGONE write("You find one half of an elven skull.\n");
      // BEGONE show(this_player()->QueryName()+
      // BEGONE      " finds one half of an elven skull in the pile.\n");
      // BEGONE ob = clone_object("/d/shadows/common/obj/q_right-skull");
      // BEGONE ob->move(this_object());
      return 1;
    }
  else
    {
      notify_fail("What do you want to search?\n");
      return 0;
    }
}

void elevator_arrives() {
  say("The lamp on the button beside the elevator goes out.\n");
  lamp_is_lit = 0;
}

void create() {
  ::create();
  SetIntShort("The attic");
  SetIntLong(
"This is the attic above the church. Dust covers nearly the whole floor. "
"You wonder when the janitor has been here the last time. You see a huge pile "
"of bones in one corner. There is a door to the west.\n");
  AddDetail(({"floor","ground"}),"It is really dirty except that field.\n");
  AddDetail(({"wall","walls"}),"They are covered with dust.\n");
  AddDetail(({"huge pile","huge pile of bones","pile","bone","bones",
  "pile of bones"}),
"You may search the pile of bones.\n");
  AddDetail(({"corners"}),
"The room has four of them. In one there is a huge pile of bones.\n");
  AddDetail("corner","There is a huge pile of bones in it.\n");
  AddDetail("dust","Just dust.\n");
  AddDetail(({"janitor"}),
"It must have been long since the last one had been here.\n");
  AddDetail(({"field","magic field"}),
"Perhaps one could enter it?\n");
  AddDetail(({"church","nightfall city church","attic","room"}),QueryIntLong());
  AddExit("west",#'west);
  AddDetail("door",#'door);
  AddRoomCmd("open",#'open);
  AddRoomCmd("push",#'push);
  AddRoomCmd("press",#'push);
  AddRoomCmd("close",#'close);
  AddRoomCmd("search",#'search);
/* commented out by Cadra due to bugs in the area... 27-1-94
  AddItem("/players/killroy/quest/obj/field",REFRESH_REMOVE);
*/
}
