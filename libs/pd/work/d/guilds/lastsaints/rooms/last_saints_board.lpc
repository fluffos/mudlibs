#include <std.h>
#include <amun.h>
inherit ROOM;

int cmd_start(string str);
object bb;
void create() {
    ::create();
    set_properties(([  "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"no scry"     : 1,
	"indoors"     : 1,
	"no steal"    : 1
      ]));
    set_no_clean(1);
    set_name("Last Saints");
    set_short("Last Saints");
    set_long("This rooms is the unity of the Last Saints.  "
      "The board laid in the center of the room is where the Saints come "
      "and discuss many thoughts and ideas.");
    set_items((["writings" : "%^BOLD%^%^WHITE%^When I raise my flashing sword, and my "
	"hand takes hold on judgment. I will take vengeance up on mine enemies, and I "
	"will repay those who haze me. O Lord, raise me to Thy right hand and count "
	"me among Thy saints.%^RESET%^" ]));
    set_exits( ([ "southwest" : GUILDROOM+"level2_1", 
	"southeast" : GUILDROOM+"level2_4", 
	"hall" : "/d/guilds/meeting",
	"east" : GUILDROOM+"level2_3", 
	"west" : GUILDROOM+"level2_2", 
	"down" : GUILDROOM+"level1_main", 
	"up" : GUILDROOM+"level3_main"]) );
    bb = new("std/bboard");
    bb->set_name("Last Saints Board");
    bb->set_id( ({ "board" }) );
    bb->set_max_posts(200);
    bb->set_edit_ok( ({ "piehl", "cyan", "furiae" }) );
    bb->set_location(GUILDROOM+"last_saints_board");
    bb->set_short("Last Saints Board");
    bb->set_long("This board is for the members of Last Saints.");
    bb->set_board_id("last_saints");
    bb->move(environment(this_object()));
}

string query_long() {
    return "%^BOLD%^%^WHITE%^"+::query_long();
}

void init() {
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
	notify_fail("You cannot start there.\n");
	return 0;
    }
    this_player()->set_primary_start("/d/guilds/lastsaints/rooms/last_saints_board");
    write("You are now set to start here.");
    return 1;
}
