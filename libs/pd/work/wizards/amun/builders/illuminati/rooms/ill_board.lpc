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
    set_name("Illuminati");
    set_short("Illuminati");
    set_long("%^BOLD%^%^WHITE%^This is the discussion hall of the illuminati. There is a board in the middle of the room where all members can post their thoughts and requests.Everyone should feel free to speak their mind.%^RESET%^");
    set_exits( ([ "northwest" : ILLROOM "ill_20" ]) );
    bb = new("std/bboard");
    bb->set_name("%^BOLD%^%^YELLOW%^Board %^WHITE%^of the %^YELLOW%^Illuminati%^RESET%^");
    bb->set_id( ({ "board" }) );
    bb->set_max_posts(200);
    bb->set_edit_ok( ({ "goldenberry", "furiae", "amun" }) );
    bb->set_location(ILLROOM "ill_board");
    bb->set_short("%^BOLD%^%^YELLOW%^Board %^WHITE%^of the %^YELLOW%^Illuminati%^RESET%^");
    bb->set_long("%^BOLD%^%^YELLOW%^This board is for the members of the %^WHITE%^Illuminati.%^RESET%^");
    bb->set_board_id("illuminati_board");
    bb->move(environment(this_object()));
}
