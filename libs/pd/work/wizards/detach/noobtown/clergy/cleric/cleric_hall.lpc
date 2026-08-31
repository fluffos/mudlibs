#include <std.h>
#include <radyne.h>

inherit HALL;
void create() {
    object ob;
    ::create();
    set_type("clergy");
    set("short", "The inner sanctum of the Clerics");
    set("long",
        "Welcome to the inner sanctum of the clerics! "
        "Clerics come here to reach a oneness with the gods that they worship.  "
        "The available commands are <cost>, <advance>, <list (number)>, "
        "<improve stat>, <train skill amount>, and <roll stats>.  "
        "Through the passage guarded by a shimmering %^BLUE%^blue%^RESET%^ "
        "light is the open area of the church.");
    set_exits( 
              (["down" : ROOMS"clergy/cleric/cleric_join"]) );
    ob = new(BBOARD);
    ob->set_name("board");
    ob->set_id( ({ "board", "reality board" }) );
    ob->set_board_id("cleric_board");
    ob->set_max_posts(25);
//    ob->set_edit_ok(CLERIC_COUNCIL);
    ob->set_location(ROOMS"clergy/cleric/cleric_hall");
    ob->set("short", "the Cleric's Reality Board");
    ob->set("long", "Clerics post tales of their experiences of "
            "this reality here.\n");
}

