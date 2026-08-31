#include <std.h>
#include <amun.h>
inherit ROOM;
object bb;
void create() {
    ::create();
    set_properties(([ "light" : 2, "indoors" : 1, "no attack" : 1, "no magic" : 1, "no steal" : 1, "no bump" : 1]));
    set_short("Tomb Square");
    set_long("%^BOLD%^%^YELLOW%^The square is full of travelers that have come to see the ancient eqyptian pyramids.  There is something mysterious about this place.");
    set_smell("default", "There is a strong smell of dust in the air.");
    set_exits( ([ "south" : ROOMS+"entrance2", "southwest" : ROOMS+"hamen_armour", "southeast" : ROOMS+"hamen_weapon", "west" : ROOMS+"hamen_tomb_1", "east" : ROOMS+"hamen_tomb_2"]) );
    bb = new("std/bboard");
    bb->set_name("Hamen's Board");
    bb->set_id( ({ "board" }) );
    bb->set_max_posts(200);
    bb->set_edit_ok( ({ "stormbringer", "nightshade", "daos", "whit", "daboura", "nesoo", "amun" }) );
    bb->set_location(ROOMS+"hamen_square");
    bb->set_short("Hamen's Board");
    bb->set_long("This board is for the travlers of Hamen's Tomb to leave fellow travelers bits of advice or messages.");
    bb->set_board_id("board");
    bb->move(environment(this_object()));
}
