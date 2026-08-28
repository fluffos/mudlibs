//	A virtual object server that handles rooms in an inn.
//	Players can save their stuff there.

#include <std.h>
#include <security.h>
#include <daemons.h>
#define INN_ROOM "/d/damned/inn/main_room"

inherit "/std/vault_locker_room";
inherit "/std/virtual/compile";

nosave int has_error;

int query_is_locker_room() {
  if(has_error) return 0;
  return 1;
}

void create() {
  ::create();
    set_property("indoors", 1);
    set_property("light", 2);
    return;
}

void init() {
  ::init();
  if((string)this_player()->query_name() == (string)
     INN_ROOM->query_owner(file_name(this_object())))
    add_action("change_desc", "describe");
  add_action("pre_open", "open");
}

int pre_open(string str) {
  if(str) set_locked(str, 0);
  return ::OpenDoor(str);
}

void virtual_setup(string arg) {
  string room, file;
  int room_num;
  string hall_exit, owner;

  if(!sscanf(arg, "inn_%s", room)) {
    write("BUG in the inn server!");
    has_error = 1;
    return;
  }
  has_error = 0;
  set("short", "Inn room #"+room);
  set("long", "Upon entering this room, you can see it is of "+
	"appreciable quality.  While you stay here, you may customize "+
	"the room description, and that description will save for all "+
	"further stays in the inn.  You may also store chests, safes, "+
	"etc. in here for your items.  Also, if you're worried about "+
	"thieves, guards and certain monsters will save here over "+
	"reboots.\n"+
        "To customize the description, type 'describe room'.\n");
  if(!sscanf(room, "%d", room_num)) {
    write("BUG in the inn server!");
    return;
  }
  owner = (string)INN_ROOM->query_owner(sprintf("/d/damned/virtual/inn_%d.inn",
						room_num));
  seteuid(getuid());
  if(owner && file_exists(file = ("/open/inn_descs/"+owner)))
    set("long", read_file(file));
  hall_exit = sprintf("/d/damned/inn/hall_%d", (room_num / 10));
  set_door("door "+room, hall_exit, "out", "key "+room);
  set_lock_level("door "+room, 15);
  add_exit(hall_exit,"out");
  set_items(([ "door" : "It appears to be a sturdy door." ]));
  if(!stringp(base_name(this_object())) ||
     sscanf(base_name(this_object()), "%*sinn_%*s.inn") != 2)
    call_out("re_create", 2, arg);
  return;
}

void re_create(string arg) {
  this_object()->create();
  this_object()->virtual_setup(arg);
  return;
}

int change_desc(string str) {
  string file;
  
  if(str != "room") return 0;
  write("Enter your desired description (10 lines max).\n"+
	"When you are finished, type a period on a blank line.");
  write("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  seteuid(getuid());
  file = "/open/inn_descs/"+(string)this_player()->query_name();
  if(file_exists(file)) rm(file);
  printf("] ");
  input_to("add_line", 0, 0, file);
  return 1;
}

void add_line(string str, int num, string file) {
  if(num >= 10 || str == ".") {
    write("Finished!");
    set("long", read_file(file));
    return;
  }
  write_file(file, str + "\n");
  printf("] ");
  input_to("add_line", 0, num+1, file);
  return;
}













