#include <std.h>
#include <amun.h>
inherit HALL;
object bb;
void create() {
    ::create();
    set_type("wanderer");
    set_properties(([ "light" : 2, "night light" : 0, "no attack" : 1, "no magic" : 1, "no steal" : 1, "no bump" : 1]));
    set_short("Board Room");
    set("long","%^BOLD%^%^BLUE%^This is a place for wanderers, men and women, to come and train, improve and level to be the best at what they do. There are many shelves filled with books for those who wish to study. This is also a room for wanderers to share their wisdom with others like themselves. They place their ideas, concerns and gerneral comments on the board.%^RESET%^");
    set_items( ([ "shelves" : "%^BOLD%^%^WHITE%^The shelves are piled high with books to read.%^RESET%^", "books" : "%^BOLD%^%^WHITE%^The books line the shelves for those who wish to read through them.%^RESET%^" ]) );
    set_exits( ([ "south" : SKYROOM "wanderer_hall1" ]) );
    bb = new("std/bboard");
    bb->set_name("Temple Wanderer Board");
    bb->set_id( ({ "board", "temple", "wanderer", "wanderer board" }) );
    bb->set_max_posts(200);
    bb->set_edit_ok( ({ "stormbringer", "nightshade", "daos", "whit", "daboura", "amun" }) );
    bb->set_location(SKYROOM "wanderer_hall2");
    bb->set_short("%^BOLD%^%^BLUE%^Wanderer Board%^RESET%^");
    bb->set_long("%^BOLD%^%^BLUE%^This board is for all those who wish to share their adventures and concerns.%^RESET%^");
    bb->set_board_id("temple_wanderer_board");
    bb->move(environment(this_object()));
}
