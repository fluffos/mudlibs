#include <immortal_hall.h>
#include <std.h>

inherit ROOM;

void create() {
  object ob;

  ::create();
  set_property("light", 2);
  set_property("indoors", 1);
  set_short("The MUD Typo Report Room");
  set_long(
   "This room is where typos are posted to be fixed."
  );
  set_exits( ([
    "west" : ROOMS"planning_room",
    "north" : ROOMS"bug_room",
   ]) );     
  ob = new("/std/bboard");
  ob->set_name("board");
  ob->set_id( ({ "board", "typo board" }) );
  ob->set_board_id("typo_log");
  ob->set_max_posts(500);
  ob->set_location(ROOMS"typo_room");
  ob->set_short("the Typo board");
  ob->set_long("A board where typos are logged for fixing.");
}

