#include <std.h>
#include <tirun.h>
inherit HALL;

void create() {
    object ob;
    ::create();
    set_type("clergy");
    set("short", "The Druid Hall");
    set("long",
         "Welcome to Druid Hall! "
        "Druids come here to reach a oneness with nature.  "
        "The available commands are <cost>, <advance>, <list (number)>, "
        "<improve stat>, <train skill amount>, and <roll stats>.  "
    );
    set_exits( 
             (["up" : ROOMS"clergy/druid/druid_vote",
             "down" : ROOMS"clergy/druid/druid_join"]) );
    ob = new(BBOARD);
    ob->set_name("board");
    ob->set_id( ({ "board" }) );
    ob->set_board_id("druid_board");
    ob->set_max_posts(90);
    ob->set_location(ROOMS"clergy/druid/druid_hall");
    ob->set("short", "The Nature of Druids Board");
    ob->set("long", "Druids post tales of their experiences of "
            "this reality here.\n");
}
