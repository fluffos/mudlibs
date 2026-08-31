#include <daemons.h>
#include <std.h>
#include <guild.h>
inherit ROOM;

void create() {
    object board;
    ::create();

    set_properties( ([ "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"night light" : 2,
	"no teleport" : 1,
	"no scry" : 1,
	"indoors" : 1,
	"no steal"    : 1 ]) );

    set_name("Hall of the Forsaken");
    set_long("Giving light to this grand room is a great pillar of blue fire. "
      "It dances in the middle of the room wildly being fueld by the air around you. "
      "Through a small window the town of Purgatory can be seen with is everlasting "
      "sounds of deranged childern playing and undead groans of the towns people.");
    set_exits(([
	"out" : "/d/freepk/purgatory/room/purgatory10",
	"south" : "/d/guilds/forsaken/purgportal",
      ]));
    board = new("/std/bboard");
    board->set_name("Forsaken's Purgatory board");
    board->set("long", "This is the board for the Forsaken's guild.  Members "
      "post on anything from ideas to assassinate missions.");
    board->set_edit_ok(GUILD_D->post_able("forsaken"));
    board->set("short", "Forsaken's board");
    board->set_max_posts(99);
    board->set_board_id("forsaken");
    board->set_location("/d/guilds/forsaken/purghall");
    board->set_id(({"board", "forsakens board", "forsaken board", "guild",
	"board"}));
}
