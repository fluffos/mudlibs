#include <std.h>
#include <council.h>
#include <radyne.h>
inherit HALL;

void create() {
    object ob;
    ::create();
    set_type("clergy");
    set("short", "Inside the Hall of Monks");
    set("long",
          "Welcome to the Monastary of Eternal Holiness. "
        "All monks come here to advance in life and study.  The "
        "available commands are <cost>, <advance>, <list (number)>, "
        "<improve stat>, <train skill amount>, and <roll stats>.  West "
        "through a passage guarded by a shimmering %^BLUE%^blue%^RESET%^ "
        "light is the entrance to the monastery. Type <help skills> to "
        "get a list of the full names of skills. You may <choose> your "
        "subclass here.");
    set_exits( 
              (["west" : ROOMS "clergy/monk/monk_join",
                "east" : ROOMS "clergy/monk/monk_vote"]) );
    ob = new(BBOARD);
    ob->set_name("subclass");
    ob->set_id( ({ "holy tableau", "tableau", "monk tableau", "board" }) );
    ob->set_board_id("monk_board");
    ob->set_max_posts(99);
    ob->set_edit_ok(MONK_COUNCIL);
    ob->set_location(ROOMS "clergy/monk/monk_hall");
    ob->set("short", "Holy Tableau of Monks");
    ob->set("long", "A holy tableau into which monks mark their thoughts.\n");
}
