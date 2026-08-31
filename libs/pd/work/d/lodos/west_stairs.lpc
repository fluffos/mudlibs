// - Inferno -  The bread and board inn =) =) =)
// NOTE: add search for a book

#include <std.h>
#include <lodos.h>
inherit ROOM;

void create() {
 ::create();
   set_short("inside Lodos Inn");
   set_long("The hallway ends here.  Doors are on both sides of the hallway.  One of the doors seems "
     "cracked open here.  A small light comes from the crack of the room.  The window at the end of the "
     "hall has been boarded up, looking as if something recently fell out of it.");
   set_exits(([
      "east" : ROOMS"stairs"
   ]));
}

void init() {
   ::init();
   add_action("open_door", "open");
   add_action("close_door", "close");
}

int open_door(string s) {
   if(!s || s != "door") return notify_fail("Open what?\n");
   if(query_exit("door") != "/d/nopk/standard/void") return notify_fail("The door is already open!\n");
   add_exit(ROOMS"inn_room", "door");
   say(this_player()->query_cap_name()+" swings the door open to the room.");
   write("You open the door.");
   return 1;
}

int close_door(string s) {
   if(!s || s != "door") return notify_fail("Close what?\n");
   if(query_exit("door") == "/d/nopk/standard/void") return notify_fail("The door is already closed!\n");
   remove_exit("door");
   say(this_player()->query_cap_name()+" swings the door closed to the room.");
   write("You close the door.");
   return 1;
}


