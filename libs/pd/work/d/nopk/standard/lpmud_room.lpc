#include <config.h>
#include <std.h>
#include <sindarii.h>
inherit ROOM;

void create() {
    object ob;

    ::create();
    set_property("light", 2);
    set_property("indoors", 1);
    set("short", "The LPMud Room");
    set("long",
	"Advertisements for new LPMuds are posted here. "
	"Ads on other boards will be quickly removed.");
    set_exits( 
	      (["west" : ROOMS "adv_main"]) );

    ob = new("std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board", "lpmud board" }) );
    ob->set_board_id("lpmud");
    ob->set_max_posts(20);
    ob->set_location(ROOMS "lpmud_room");
    ob->set("short", "LPMud Advertising Board");
    ob->set("long", "This board exists to promote LPMuds everywhere. "
	"Please feel free to post about a mud you know of here.\n");
}

