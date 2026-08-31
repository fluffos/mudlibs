#include <std.h>
#include <tirun.h>
inherit HALL;
void create() {
    object ob;
    ::create();
    set_type("vampire");
    set("short", "The inner sanctum of the mages");
    set("long",
        "Mages come here to advance their knowledge of the magical arts.  "
        "The available commands are <cost>, <advance>, <list (number)>, "
        "<improve stat>, <train skill amount>, and <roll stats>.  Up "
        "through a stairway "
        "guarded by a shimmering blue light is the "
        "entrance."
        "<help skills> will list all skills with their full, proper names."
        "  You cannot choose your subclass here.");
    set_exits( 
              (["down" : ROOMS "mage/mage_join",
                "east" : ROOMS "mage/mage_vote"]) );
    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "crystal board", "bulletin board"}) );
    ob->set_board_id("mage_board");
    ob->set_max_posts(75);
//   ob->set_edit_ok(MAGE_COUNCIL);
    ob->set_location(ROOMS "mage_hall");
    ob->set("short", "the Crystal Board of Mages");
    ob->set("long",
        "It is a huge slab of crystal into which mages have the power "
        "to cast their thoughts about the class of mages.\n");
}

