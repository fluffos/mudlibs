#include <daemons.h>
#include <guild.h>

inherit ROOM;

void init() {
    ::init();
#ifndef NO_START
    add_action("fstart", "start");
#endif
}


void create() {
    object board;
    ::create();
    set_name("Main Guild hall of The Chosen");
    set_short("Main Guild hall of the Chosen");
    set_long("This is the hall of The Chosen.\nIn the middle "
      "of the room there is a huge fire that lights up "
      "the room, a circle of small fires "
      "surround the edges of the room. The roof has some "
      "small holes to release the smoke from the fire. There "
      "are some comfortable chairs in the corner of the room "
      "for members to relax. Strange colours are coming from "
      "the east.");
    set_exits(([
	"hall":"/d/guilds/meeting",
	"east":CHOSEN"treasury",
	"up":CHOSEN"entrance",
      ]));
    set_properties( ([ "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"night light" : 2,
	"no teleport" : 1,
	"no scry" : 1,
	"indoors" : 1,
	"no steal"    : 1 ]) );   
    board = new("/std/bboard");
    board->set_board_id("chosen_guild");
    board->set_id(({"board", "chosen board"}));
    board->set_name("board of the Chosen");
    board->set_short("The board of the Chosen");
    board->set_long("This is the main guild board of the Chosen.");
    board->set_location(CHOSEN"hall");
    board->set_edit_ok(GUILD_D->post_able("chosen"));
    board->set_max_posts(100);
    board->set_board_name("chosen");
}

int fstart(string str) {
    if (!str || str=="") {
	notify_fail("Start where?\n");
	return 0;
    }
    if (str!="here") {
	notify_fail("You cannot start there.\n");
	return 0;
    }
    if(this_player()->query_original_guild() == "illuminati")
	this_player()->set_primary_start("/d/guilds/illuminati/new/hall");
    else
    if(this_player()->query_original_guild() == "aod")
	this_player()->set_primary_start("/d/guilds/AoD/hall");
    else

	this_player()->set_primary_start("/d/guilds/"
	  ""+this_player()->query_original_guild()+"/hall");
    write("You are now set to start in "
      "the "+capitalize(this_player()->query_guild())+" hall.\n");
    return 1;
}

