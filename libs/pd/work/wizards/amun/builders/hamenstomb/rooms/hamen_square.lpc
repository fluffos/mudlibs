#include <std.h>
#include <amun.h>
inherit ROOM;
object bb;
void create() {
    ::create();
    set_properties(([ "light" : 2, "indoors" : 1, "no attack" : 1, "no magic" :
	1, "no steal" : 1, "no bump" : 1]));
    set_short("Tomb Square");
    set_long("%^BOLD%^%^YELLOW%^The square is full of travelers that have come to see the ancient eqyptian pyramids. Along the walls there are writings written in the ancient eqyptian language. The torches around the room flicker, giving an uneasy feeling to all passerbys. There is something mysterious about this place.%^RESET%^");
    set_smell("default", "There is a strong smell of dust in the air.");
    set_items( ([ "writings": "%^BOLD%^%^BLACK%^Although you cannot read Ancient Eqyptian, words seem to form into English, they read: '%^BOLD%^%^YELLOW%^To all of those that feel they are safe, they should turn back around now.  Noone passes this room, but it is said that those who have...were never to return.%^BLACK%^'%^RESET%^" ]) );
    set_exits( ([ "south" : ROOMS+"entrance2", "southwest" : ROOMS+"hamen_armour", "southeast" : ROOMS+"hamen_weapon", "west" : ROOMS+"hamen_tomb_1", "east" : ROOMS+"hamen_tomb_2"]) );
    bb = new("std/bboard");
    bb->set_name("Hamen's Board");
    bb->set_id( ({ "board" }) );
    bb->set_max_posts(200);
    bb->set_edit_ok( ({ "stormbringer", "nightshade", "daos", "whit", "daboura", "nesoo", "amun" }) );
    bb->set_location(ROOMS+"hamen_square");
    bb->set_short("Hamen's Board");
    bb->set_long("This board is for the travlers of Hamen's Tomb to leave fellow travelers bits of advice or messages.");
    bb->set_board_id("hamen_board");
    bb->move(environment(this_object()));
}
