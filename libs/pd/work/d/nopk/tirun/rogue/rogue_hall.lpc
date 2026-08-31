#include <std.h>
#include <tirun.h>
inherit HALL;

void create() {
    object ob;
    ::create();
    set_type("rogue");
    set("short", "The heart of the rogue hideout");
    set("long",
         "Welcome into the rogue hideout! "
         "Rogues come here to sharpen their fiendish skills. "
        "The available commands are <cost>, <advance>, <list (number)>, "
        "<train skill amount>, <improve stat> and <roll stats>.  Up "
        "through a stairway guarded by a shimmering %^BLUE%^blue%^RESET%^ "
        "light is the entrance to the fortress. <help skills> will list "
        "all of the full names of skills. You can choose your subclass "
        "here.");
    set_exits( 
              (["up" : ROOMS "rogue/rogue_join",
                "east" : ROOMS "rogue/rogue_vote"]) );
    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "rogue board" }) );
    ob->set_board_id("rogue_board");
    ob->set_max_posts(100);
/*    ob->set_edit_ok(ROGUE_COUNCIL); */
    ob->set_location(ROOMS"rogue/rogue_hall");
    ob->set("short", "Rogue Board of Fiendish Plots");
    ob->set("long", "On this rotting wood board, rogues come to post "
            "of bounties dastardly deeds, and other fiendish foils "
            "for other rogues to see.\n");
}
