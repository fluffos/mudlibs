// Drack's Workroom
// Adapted from NM3 Mudlib
#include <std.h>

inherit ROOM;
object ob;

void create() {
    ::create();
    set_properties( ([ "light" : 2, "indoors" : 1 ]) );
    set_short("a new workroom");
    set_long(
	"Thousands of brightly colors lights strobe "
	"brilliantly through what seems like black "
	"empty space.  Swirling clouds of dust form "
	"into objects at various points throughout the "
	"room.  A large platform, floating in the center "
	"of the void provides the only standing space. "
	"A desk a chair sit in the middle of this, with "
	"a magical portal behind the desk."
    );
    set_items( ([ "workroom" : "Code is being created here." ]) );
    set_listen("default", "The sounds of code creation vibrate the room.");
    set_exits( ([ 
        "square" :  "/d/standard/square",
        "hall"  :  "/d/standard/adv_inner"
    ]) );
    ob = new(BBOARD);
    ob->set_name("drackmire board");
    ob->set_location("/wizards/drackmire/workroom");
    ob->set_id( ({ "board", "drackmire's board", "drack board", "drack's board" }) );
    ob->set_board_id("drack_board");
    ob->set_max_posts(200);
    ob->set_short("Drackmire's Wonderful Board of Ideas and Exchange");
    ob->set_long("Awesome.");
}
