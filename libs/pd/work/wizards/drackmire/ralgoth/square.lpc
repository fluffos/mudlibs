// Drackmire
// Ralgoth Square
// 100405

#include <std.h>
#include "ralgoth.h"

inherit ROOM;

int cmd_start(string str);

void create() {
	object ob;
        ::create();


    set_properties( ([
        "light"       : 1,
        "night light" : 1,
        "no steal"    : 1,
	"indoors"     : 1
		]) );
    set_property("town",1);
    set_listen("default", "An eerie silence pervades the square.");
    set_smell("default", "The rank smell of decaying flesh fills the air.");
    set_short("Ralgoth Square");
    set_long(
      	"Ralgoth Square\n"
      	"Ralgoth Square lies at the center of the of the Ralgoth fortress, "
	"at the intersection of the four districts of the city.  The two major "
	"dividing roads, Ralgoth Avenue runs east and west, while Drolmire street "
	"runs north to the mountains and south to the fields.  Ralgoth, known as "
	"the city of the dead, is home to the slaves and the army of the powerful "
	"necromancer for whom the city is named. A large fountain stands in the "
	"center of the square, but the most prominent feature is the giant statue "
	"of Ralgoth himself standing at the north end of the square." 
    );
    set_exits((["north" : RALROOMS "ndrolst_1",
        "south" : RALROOMS "sdrolst_1",
        "east" :  RALROOMS "eralg_1",
        "west" :  RALROOMS "wralg_1"]));

    ob = new("/std/bboard");
    ob->set_name("board");
    ob->set_id( ({ "board" }) );
    ob->set_board_id("ralgoth");
    ob->set_max_posts(50);
    ob->set_edit_ok(({ "drackmire" }));
    ob->set_location(RALROOMS"square");
    ob->set("short", "Ralgoth Fortress Board");
    ob->set("long", "Discussion in the realm of Ralgoth\n");

}

/*

void reset() {
    ::reset();

	if(!present("fountain")) new(RALMISC "fountain")->move(this_object());
	if(!present("statue")) new(RALMISC "statue")->move(this_object());

}

*/

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

    this_player()->set_primary_start(RALROOMS"square");
    write("You are now set to start here.");
    return 1;
}
