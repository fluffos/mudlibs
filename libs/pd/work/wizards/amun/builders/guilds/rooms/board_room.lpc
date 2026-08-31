#include <std.h>
#include <daemons.h>
#include <guild.h>
#include <boat.h>
inherit ROOM;
int sigma;
int cmd_start(string str);
void init()
{
    ::init();
    add_action("cmd_start", "start");
    add_action("cmd_drop", "drop");
}
object bb;
void create() {
    ::create();
    set_properties( ([ "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"night light" : 2,
	"no steal"    : 1 ]) );
    set_property("town",1);
    set_short("Guild Town Board Room");
    set_long("%^BOLD%^%^WHITE%^Placed in the center of the Guild Town, the square has many different charms about it. Towards the south the %^GREEN%^t%^RESET%^%^ORANGE%^r%^BOLD%^%^GREEN%^ees %^WHITE%^and %^GREEN%^w%^RESET%^%^ORANGE%^i%^BOLD%^%^GREEN%^ldlife %^WHITE%^grow like a %^RED%^w%^RESET%^%^ORANGE%^i%^BOLD%^%^RED%^l%^RESET%^ORANGE%^d%^BOLD%^%^RED%^f%^RESET%^%^ORANGE%^i%^BOLD%^%^RED%^r%^RESET%^%^ORANGE%^e%^BOLD%^%^WHITE%^. The paths that lead to the northeast and northwest stretch out of sight. This is the main gathering area for members of all guilds to communicate with one another. %^RESET%^");
    set_items( ([ "trees" : "%^BOLD%^%^GREEN%^The trees stretch high making light work hard to been seen.%^RESET%^", "wildlife" : "%^BOLD%^%^GREEN%^The wildlife is abundant to the south.%^RESET%^", "paths" : "The paths lead towards the northeast and northwest." ]) );
    set_exits( ([ "north" : GROOM "g55", "enter cave" : GROOM "pray_room", "enter bank" : GROOM"bank", "down" : GROOM"docks_entrance", "enter hall" : ROOMS"meeting", "northwest" : GROOM"l_main", "northeast" : GROOM"r_main", "enter shop" : GROOM "miscshop" ]) );
    add_exit_alias("enter shop", "shop");
    add_exit_alias("enter cave", "cave");
    add_exit_alias("enter bank", "bank");
    add_exit_alias("enter hall", "hall");
    bb = new("std/bboard");
    bb->set_name("Guild Town Board");
    bb->set_id( ({ "board", "guild", "town", "guild town", "guild town board" }) );
    bb->set_max_posts(200);
    bb->set_edit_ok( ({ "stormbringer", "nulvect", "daos", "whit", "daboura", "amun", "luna", "hepualahaole", "ironman", "pyro" }) );
    bb->set_location(GROOM "board_room");
    bb->set_short("%^BOLD%^%^WHITE%^Guild Town Board%^RESET%^");
    bb->set_long("%^BOLD%^%^WHITE%^This board is for all those who wish to share their adventures and concerns about guilds and anything else.%^RESET%^");
    bb->set_board_id("gtown_board");
    bb->move(environment(this_object()));
}
void reset() {
    ::reset();
    if(!present("crater"))
	new(GOBJ "crater")->move(this_object());
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

    this_player()->set_primary_start(GROOM"board_room");
    write("You are now set to start here.");
    return 1;
}

int cmd_drop(string str)
{
    this_player()->force_me("put "+str+" in crater");
    return 1;
}
