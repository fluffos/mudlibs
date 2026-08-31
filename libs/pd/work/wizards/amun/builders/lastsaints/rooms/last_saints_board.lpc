#include <std.h>
#include <amun.h>
inherit ROOM;
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
    set_name("Last Saints");
    set_short("Last Saints");
    set_long("%^BOLD%^%^WHITE%^This rooms is the unity of the Last Saints.  The board laid in the center of the room is where the Saints come and discuss many thoughts and ideas.");
    set_items((["writings" : "%^BOLD%^%^WHITE%^When I raise my flashing sword, and my hand takes hold on judgment. I will take vengeance up on mine enemies, and I will repay those who haze me. O Lord, raise me to Thy right hand and count me among Thy saints.%^RESET%^" ]));
    set_exits( ([ "southwest" : GUILDROOM+"level2_1", "southeast" : GUILDROOM+"level2_4", "east" : GUILDROOM+"level2_3", "west" : GUILDROOM+"level2_2", "down" : GUILDROOM+"level1_main", "up" : GUILDROOM+"level3_main"]) );
    bb = new("std/bboard");
    bb->set_name("Last Saints Board");
    bb->set_id( ({ "board" }) );
    bb->set_max_posts(200);
    bb->set_edit_ok( ({ "carina", "cyan", "furiae" }) );
    bb->set_location(GUILDROOM+"last_saints_board");
    bb->set_short("Last Saints Board");
    bb->set_long("This board is for the members of Last Saints.");
    bb->set_board_id("board");
    bb->move(environment(this_object()));
}
