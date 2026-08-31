#include <std.h>
#include <immortal_hall.h>
inherit ROOM;

void create() {
  object board;
  ::create();
  set("short", "Law notice room");
  set("long", "This room is where the board for Law is kept.  There seem "
   "to be so many issues to be constantly dealt with that it "
   "got difficult to keep up with them all.  Thus, this room. ");
  set_property("light", 2);
  set_exits( ([
    "east" : ROOMS"adv_inner",
    "up" : ROOMS "banishboard",
  ]) );
  set_property("indoors", 1);
  board = new("std/bboard");
  board->set_name("board");
  board->set_id( ({ "board", "law board" }) );
  board->set_max_posts(3000);
  board->set_location(ROOMS "law");
  board->set("short", "Law board");
  board->set("long", "This board is used to keep track of Law issues.\n");
  board->set_board_id("law");
}

