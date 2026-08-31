#include <daemons.h>
#include <std.h>
#include <guild.h>
inherit ROOM;

void init() {
    ::init();
#ifndef NO_START
    add_action("fstart", "start");
#endif
    add_action("cmd_drop", "drop");
    add_action("cmd_put", "put");
}

void create() {
    object board;
    ::create();
    set_name("Hall of the Forsaken");
    set_long("This is the main room of the Forsaken Guild. The room is lit "
      "from within by coldfire that flickers around the room consumming any "
      "material it can find. All heat is sucked out of the air by the demonic blue "
      "flames. An enourmous blade that glows of power is burried into the ground "
      "here.");
    set_properties( ([ "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"night light" : 2,
	"no teleport" : 1,
	"no scry" : 1,
	"indoors" : 1,
	"no steal"    : 1 ]) );
    set_items(([
	"sword" : "An inscription reads 'The Forsaken. He who does battle with "
	"monsters must see to it that he does not himself become a monster. When you "
	"gaze long into the abyss, the abyss also gazes into you.'",
      ]));
    set_exits(([
	"south" : ROOMS"forsaken/entrance",
	"hall" : ROOMS"meeting",
	"east" : ROOMS"forsaken/treasury",
	"west" : ROOMS"forsaken/room1",
	"north" : ROOMS"forsaken/itemshop",
	"up" : ROOMS"forsaken/lockerf",
	"down" : ROOMS"forsaken/stoneshop",
      ]));
    board = new("/std/bboard");
    board->set_name("Forsaken's board");
    board->set("long", "This is the board for the Forsaken's guild.  Members "
      "post on anything from ideas to assassinate missions.");
    board->set_edit_ok(GUILD_D->post_able("forsaken"));
    board->set("short", "Forsaken's board");
    board->set_max_posts(99);
    board->set_board_id("forsaken");
    board->set_location("/d/guilds/forsaken/hall");
    board->set_id(({"board", "forsakens board", "forsaken board", "guild board"}));
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

int cmd_drop(string str)
{
    this_player()->force_me("put "+str+" in chest");
    return 1;
}

int cmd_put(string str)
{
    this_player()->force_me("put "+str+" in chest");
    return 1;
}

void reset() {
    ::reset();

    if(!present("chest"))
	new("/d/guilds/forsaken/obj/chest")->move(this_object());
}

