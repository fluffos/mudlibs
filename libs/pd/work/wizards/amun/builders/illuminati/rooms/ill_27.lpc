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
    set_short("The inner sanctum of the Hall of Wanderer");
    set_long("%^BOLD%^%^WHITE%^This is the place where people of all races come to train, improve and level to become the best wanderer God could ask for. There are many aimless things lying around for wanderers to study. This is also a room for wanderers to share their wisdom with other like themselves.%^RESET%^");
    set_exits( ([ "southwest" : ILLROOM "ill_24" ]) );
    bb = new("std/bboard");
    bb->set_name("board");
    bb->set_id( ({ "board" }) );
    bb->set_max_posts(200);
    bb->set_edit_ok( ({ "goldenberry", "furiae", "amun", "daos" }) );
    bb->set_location(ILLROOM "ill_27");
    bb->set_short("%^BOLD%^%^RED%^Wanderers Unite%^RESET%^");
    bb->set_long("%^BOLD%^%^RED%^The Wanderers of our reality post tales of their glorious adventures here, as well as info on the dangers out there.%^RESET%^");
    bb->set_board_id("illum_wanderer_board");
    bb->move(environment(this_object()));
}
