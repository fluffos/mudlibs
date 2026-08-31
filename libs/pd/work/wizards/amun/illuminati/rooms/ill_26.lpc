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
    set_short("The inner sanctum of the Hall of Mages");
    set_long("%^BOLD%^%^WHITE%^This is the place where people of all races come to train, improve and level to become the best mage God could ask for. There are many spell books lying around for mages to study. This is also a room for mages to share their wisdom with others like themselves.%^RESET%^");
    set_exits( ([ "west" : ILLROOM "ill_24" ]) );
    bb = new("std/bboard");
    bb->set_name("board");
    bb->set_id( ({ "board" }) );
    bb->set_max_posts(200);
    bb->set_edit_ok( ({ "goldenberry", "furiae", "amun", "daos" }) );
    bb->set_location(ILLROOM "ill_26");
    bb->set_short("%^BOLD%^%^RED%^Mages Unite%^RESET%^");
    bb->set_long("%^BOLD%^%^RED%^The Mages of our reality post tales of their glorious adventures here, as well as info on the dangers out there.%^RESET%^");
    bb->set_board_id("illum_mage_board");
    bb->move(environment(this_object()));
}
