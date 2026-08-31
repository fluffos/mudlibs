#include <immortal_hall.h>
#include <std.h>

inherit ROOM;

void create() {
    object ob;

    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("The MUD Praise Room");
    set_long(
      "This room is where player praise is posted."
    );
    set_exits( ([
     "south" : ROOMS"idea_room",
    ]) );     
    ob = new("/std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "praise board" }) );
    ob->set_board_id("praise_log");
    ob->set_max_posts(500);
    ob->set_location(ROOMS"praise_room");
    ob->set_short("the Praise board");
    ob->set_long("A board where praise is logged.");
}

