#include <immortal_hall.h>
#include <std.h>

inherit ROOM;

void create() {
    object ob;

    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("The MUD Bug Report Room");
    set_long(
      "This room is where bugs are posted to be fixed."
    );
    set_exits( ([
     "north" : ROOMS"idea_room",
     "south" : ROOMS"typo_room",
    ]) );     
    ob = new("/std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "bug board" }) );
    ob->set_board_id("bug_log");
    ob->set_max_posts(500);
    ob->set_location(ROOMS"bug_room");
    ob->set_short("the Bug board");
    ob->set_long("A board where bugs are logged for fixing.");
}

