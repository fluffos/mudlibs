#include <sindarii.h>
#include <std.h>
#include <objects.h>

inherit ROOM;

string go_away();

void create() {
    object ob;

    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "The Planning Room");
    set("long", (:go_away:));
      set_long( "This is the planning room...");
    set_exits( 
([
     "up" : ROOMS"arch",
     "east" : ROOMS"maintenance_room",
     "west" : ROOMS"adv_inner"]) );     
    set_pre_exit_functions( ({ "up" }), ({"do_check"}) );
    ob = new("/std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "planning board" }) );
    ob->set_board_id("planning");
    ob->set_max_posts(30);
    ob->set_location(ROOMS"planning_room");
    ob->set("short", "the Planning Our Reality Board");
    ob->set("long", "A board for posting ideas so that others "
	    "will not use them.\n");
}

int do_check(string str) { return archp(this_player()); }

string go_away() {
    string str;

    if(archp(this_player())) str = "The arch meeting room is upstairs. ";
    else str = "";
    str += "All ideas are unclaimed until they appear here.  "
      "If your idea is taken, and you did not post it, you have only yourself to blame.";
    return str;
}

