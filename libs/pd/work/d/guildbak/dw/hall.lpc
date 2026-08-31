#include <std.h>
#include <guild.h>

inherit ROOM;

void init() {
    ::init();
#ifndef NO_START
    add_action("fstart", "start");
#endif
    add_action("fbuy", "buy");
    add_action("fread", "read");
}

void create() {
    object board;
    ::create();
    set_name("Dragon Warriors hall");
    set_short("Dragon Warriors hall");
    set_long("Inside a cave that looks suspiciously like a dragons lair. Large "
      "rats feed on the dead dragon scales that litter the ground. A board covered in "
      "cobwebs sits off to the side of a dark opening in the back of the lair. The "
      "ledge outside is the only way out of here. %^BOLD%^There is a "
      "sign posted here%^RESET%^.");

    set_exits(([
	"south": ROOMS"dw/treasury",
	"out": ROOMS"dw/entrance",
	"hall" : "/d/guilds/meeting",
	"vote" : "/d/guilds/dw/vote",
	"up" : "/d/guilds/dw/hallway",
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
    board->set_board_id("Dragon_warrior");
    board->set_id(({"board", "dw board"}));
    board->set_name("Dragon Warriors board");
    board->set_short("A dusty board");
    board->set_long("Small scribbles have been made in the dust on this board. They "
      "look to be made by claws..");
    board->set_location(ROOMS"dw/hall");
    board->set_edit_ok(({"daboura", "nightshade", "stormbringer", "whit"}));
    board->set_max_posts(100);
    board->set_board_name("Dragon Warrior");
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
	this_player()->set_primary_start("/d/guilds/"+this_player()->query_original_guild()+"/hall");
    write("You are now set to start in the "+capitalize(this_player()->query_guild())+
      " hall.\n");
    return 1;
}

int fbuy(string str) {

    if (!str || str != "egg") {
	return notify_fail("Buy what?\n");
    }
    if (this_player()->query_money("gold") < 400) {
	return notify_fail("You do not have enough gold.\n");
    }
    write("You buy a dragon egg.");
    say(this_player()->query_cap_name()+" buys a dragon egg.");
    this_player()->add_money("gold", -400);
    new("/d/guilds/dw/egg")->move(this_player());
    return 1;
}

int fread(string str) {
    if (!str || str != "sign") {
	return notify_fail("Read what?\n");
    }
    say(this_player()->query_cap_name()+" reads the sign.");
    write("The sign reads: \n"
      "-----------------------\n"
      "dragon egg - 400 gold ");
    return 1;
}


