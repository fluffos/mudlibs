#include <std.h>
#include <config.h>
#include <sindarii.h>

inherit ROOM;

void create() {
    object ob;

    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "The Hall of the Immortals");
    set("long",
      "This is the meeting green room of the Immortals of Carnage. "
      "In this room, matters of mud policy and events are discussed "
      "by all Carnage immortals so that everyone might know what "
      "is going on.  There is a room for discussing LPC south and "
      "a planning room east where immortals post their plans for areas "
      "domains, guilds, and quests.");
    set_exits( 
      (["up" : ROOMS"mudlib",
        "north" : ROOMS"lpc_inner",
        "east" : ROOMS"planning_room",
        "west" : "/wizards/levi/crimroom" ]) );
    add_exit("/d/nopk/tirun/square", "down");

    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "reality board" }) );
    ob->set_board_id("immortal");
    ob->set_max_posts(500);
    ob->set_edit_ok(({ "stormbringer", "daboura", "nightshade", "whit", "nesoo", "daos", "levi" }));
    ob->set_location(ROOMS"adv_inner");
    ob->set("short", "Immortal's Reality Board");
    ob->set("long", "Posts any notes concerning the mud which do "
      "not belong out in a public forum among players "
      "here for immortal discussion.\n");
    set_property("no steal", 1);
}
void reset() {
    ::reset();
    if (!present("box"))
        new("/wizards/seeker/box")->move(this_object());
}

int receive_objects() {
    if(!previous_object()->is_player())
        return 1;
    if(!wizardp(previous_object())) {
        message("my_action", "You cannot penetrate the force of "
          "the blue force shield.", this_player());
        return 0;
    }
    return 1;
}
