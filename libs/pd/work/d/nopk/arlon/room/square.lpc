#include <std.h>
#include <arlon.h>

inherit ROOM;
object bo;

void create()
{
    ::create();
    set_properties( ([ "light":2,
	"night light":2,
	"no attack":1,
	"no magic":1,
	"no bump":1,
	"no steal":1 ]) );

    set_short("Arlon Square");
    set_long("Arlon Square is all paved with cobblestone. There is a "
      "small statue of a lion in the middle of the square. The "
      "cobblestone path leads off in all directions into the town "
      "through different buildings and houses.");

    set_listen("default", "The sound of townsmen chatting fill the room.");
    set_exits( ([ "north" : ROOMS "plains10",
	"south" : ROOMS "s_square",
	"east"  : ROOMS "esquare1",
	"west"  : ROOMS "wsquare1"  ]) );
    bo = new("/std/bboard");

    bo->set_name("board");
    bo->set_id( ({ "board", "arlon board" }) );
    bo->set_max_posts(80);
    bo->set_location("/d/nopk/arlon/room/square");
    bo->set("short", "Arlon board");
    bo->set("long", "This is a board for Arlonians to keep in "
      "touch and talk about new things");
    bo->set_board_id("arlon_board");

}

void reset()
{
    ::reset();
    if (!present("statue"))
	new(OBJ "statue")->move(this_object());
}
void init()
{
    ::init();
    add_action("cmd_start", "start");
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
	notify_fail("You cant start there.\n");
	return 0;
    }

    this_player()->set_primary_start("d/nopk/arlon/room/square");
    write("You are now set to start here.");
    return 1;
}

