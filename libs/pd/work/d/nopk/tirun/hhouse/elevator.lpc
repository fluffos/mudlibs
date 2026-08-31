#include <std.h>
#include <tirun.h>

inherit ROOM;

int down;
int lever;

void create() {
    ::create();
    set_smell("default", "The air is thick and damp.");
    set_listen("default", "Silence.");
    set_properties((["light":1, "no teleport":1, "indoors":1]));
    set_short("Haunted House");
    set_long(
        "There is not much to this room at all.  It is too small to be used for anything.  "
        "The walls are made of a smooth stone, which was very carefully carved.  There "
        "is very little light in this tiny room.  There is only one opening leading out.");
    set_items(
        (["walls" : "A very plain smooth stone.  No decorations here.  There seems to be a hole, though."]) );
    set_exits( ([ "out" : ROOMS"hhouse/hall" ]) );
    down = 0;
    lever = 0;
}

void init() {
  ::init();
  add_action("pull", "pull");
  add_action("look", "look");
  add_action("insert", "insert");
}

int insert(string str) {
  string what, where;
  if(!str) return notify_fail("Insert what into where?\n");
  if(sscanf(str, "%s into %s", what, where) != 2) return notify_fail("Insert what into where?\n");
  if(what != "lever" || where != "hole") return notify_fail("It does not fit there.\n");
  if(!present("lever_qo", this_player())) return notify_fail("You dont have a lever to insert!\n");
  write("You stick the lever in the hole, and it fits!");
  say(this_player()->query_cap_name()+" puts the lever in the hole.");
  lever = 1;
  present("lever_qo", this_player())->remove();
  return 1;
}

int look(string str) {
  if(str == "hole") {
    if(lever)
      write("The hole is filled with the lever.");
    else
      write("It seems like something should be inserted into the hole.");
    return 1;
  }
  if(str == "lever") {
    if(down || lever == 1)
      write("It's a lever.  Probably does something when pulled.");
    else
      write("You do not notice that here.");
    return 1;
  }
  return 0;
}

void reset() {
  ::reset();
  down = 0;
  lever = 0;
  set_exits( ([ "out" : ROOMS"hhouse/hall" ]) );
}

int query_down() { return down; }

int pull(string str) {

  if(!str)
    return notify_fail("Pull what?\n");  
  if(str != "lever" || !lever) 
    return notify_fail("You cannot pull that.\n");
  if(down == 0) {
    write("You pull on the lever and the room you're in starts to move down.");
    say(this_player()->query_cap_name()+" pulls the lever, and the room starts to move down.");
    down = 1;
    set_exits( ([ "out" : ROOMS"hhouse/bottom" ]) );
  }
  else {
    write("You pull on the lever and the room you're in starts to move up.");
    say(this_player()->query_cap_name()+" pulls the lever, and the room starts to move up.");
    down = 0;
    set_exits( ([ "out" : ROOMS"hhouse/hall" ]) );
  }
  return 1;
}
