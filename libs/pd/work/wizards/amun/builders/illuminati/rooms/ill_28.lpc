#include <std.h>
#include <guild.h>
#include <amun.h>
inherit HALL;
object bb;
void create() {
    ::create();
    set_type("fighter");
    set_properties(([  "no attack"   : 1,
	"no magic"    : 1,
	"no bump"     : 1,
	"light"       : 2,
	"no scry"     : 1,
	"indoors"     : 1,
	"no steal"    : 1
      ]));
    set_name("Illuminati");
    set_short("The inner sanctum of the Hall of Rogues");
    set_long("%^BOLD%^%^WHITE%^This is the place where people of all races come to train, improve and level to become the best rogue God could ask for. There are many books and weapons lying about for rogues to learn and study. This is also a room for rogues to share their wisdom with others like themselves.%^RESET%^");
    set_exits( ([ "southeast" : ILLROOM "ill_24" ]) );
    bb = new("std/bboard");
    bb->set_name("board");
    bb->set_id( ({ "board" }) );
    bb->set_max_posts(200);
    bb->set_edit_ok( ({ "goldenberry", "furiae", "amun", "daos" }) );
    bb->set_location(ILLROOM "ill_28");
    bb->set_short("%^BOLD%^%^RED%^Rogues Unite%^RESET%^");
    bb->set_long("%^BOLD%^%^RED%^The Rogues of our reality post tales of their glorious adventures here, as well as info on the dangers out there.%^RESET%^");
    bb->set_board_id("illum_rogue_board");
    bb->move(environment(this_object()));
}
