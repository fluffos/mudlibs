#include <sindarii.h>
#include <std.h>
#include <objects.h>

inherit ROOM;

void create() {
    object ob;

    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set_short("The MUD Maintenance Room");
    set_long(
      "This room is used for discussing MUD maintenance, "
      "such as fixing typos and bugs."
    );
    set_exits( ([
     "west" : ROOMS"planning_room",
    ]) );     
    ob = new("/std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "typo board" }) );
    ob->set_board_id("typo_log");
    ob->set_max_posts(500);
    ob->set_location(ROOMS"maintenance_room");
    ob->set_short("the Typo board");
    ob->set_long("A board where typos are logged for fixing.");
}

