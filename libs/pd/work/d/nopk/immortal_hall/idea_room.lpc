#include <immortal_hall.h>
#include <std.h>

inherit ROOM;

void create() {
    object ob;

    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("The MUD Idea Report Room");
    set_long(
      "This room is where ideas are posted."
    );
    set_exits( ([
     "north" : ROOMS"praise_room",
     "south" : ROOMS"bug_room",
    ]) );     
    ob = new("/std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "idea board" }) );
    ob->set_board_id("idea_log");
    ob->set_max_posts(500);
    ob->set_location(ROOMS"idea_room");
    ob->set_short("the Idea board");
    ob->set_long("A board where ideas are logged.");
}

