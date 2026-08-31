#include <std.h>
#include <daemons.h>
#include <guild.h>
inherit ROOM;
int sigma;
int cmd_start(string str);
void init()
{
    ::init();
    add_action("cmd_start", "start");
    add_action("cmd_drop", "drop");
}

void create() {
    object board;
    ::create();
set_name("Hall of the Forsaken");
    set_no_clean(1);
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
	"south" : "/d/nopk/tirun/ehonin1",
	"hall" : ROOMS"meeting",
	"east" : ROOMS"forsaken/treasury",
	"west" : ROOMS"forsaken/room1",
	"north" : ROOMS"forsaken/itemshop",
	"up" : ROOMS"forsaken/lockerf",
	"down" : ROOMS"forsaken/stoneshop"
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
void reset() {
    ::reset();

    if(!present("chest"))
	new("/d/guilds/forsaken/obj/chest")->move(this_object());
}

int cmd_start(string str)
{
    if (!str || str=="") 
    {
	notify_fail("Start where?\n");
	return 0;
    }

    if (str!="here")
    {
	notify_fail("You cannot start there.\n");
	return 0;
    }

    this_player()->set_primary_start("/d/guilds/forsaken/hall");
    write("You are now set to start here.");
    return 1;
}

int cmd_drop(string str)
{
    this_player()->force_me("put "+str+" in chest");
    return 1;
}
