#include <std.h>
#include <tirun.h>
inherit HALL;

void create() {
    object ob;
    ::create();
    set_type("wanderer");
    set("short", "The wanderer's cave");
    set("long",
      "Welcome into the gathering hall of the wanderers! "
      "New wanderers come here to dedicate their lives to the wanderlust "
      "in their soul. Every once in a while, wanderers will gather "
      "for meetings. The room is not very well kept, although not at all "
      "in bad condition. ");
    set_exits( 
      (["down" : ROOMS "wand/wanderer_join",
//	"east" : ROOMS "wand/wanderer_vote",
    ]) );
    ob = new(BBOARD);
    ob->set_max_posts(95);
    ob->set_board_id("wanderer");
    ob->set_location(ROOMS "wanderer_hall");
    ob->set_id(({ "board" }));
    ob->set_short("The Wanderer board of adventure.");
    ob->set_long("Wanderer post songs among other things here.\n");
    ob->set_name("class");
    ob->set_edit_ok( ({"nulvect"}) );
}
