#include <std.h>
#include <daemons.h>
#include <guild.h>
inherit HALL;
object bb;
void create() {
    ::create();
    set_type("angel");
    set_properties(([ "light" : 2, "night light" : 0, "no attack" : 1, "no magic" : 1, "no steal" : 1, "no bump" : 1]));
    set_short("Board Room");
    set("long","%^BOLD%^%^WHITE%^This is a place for %^YELLOW%^A%^WHITE%^n%^YELLOW%^gels %^WHITE%^to come and train, improve and level to be the best at what they do. There are many shelves filled with books for those who wish to study. This is also a room for %^YELLOW%^A%^WHITE%^n%^YELLOW%^gels %^WHITE%^to share their wisdom with others like themselves. They place their ideas, concerns and general comments on the board.%^RESET%^");
    set_items( ([ "shelves" : "%^BOLD%^%^WHITE%^The shelves are piled high with books to read.%^RESET%^", "books" : "%^BOLD%^%^WHITE%^The books line the shelves for those who wish to read through them.%^RESET%^" ]) );
    set_exits( ([ "southwest" : GROOM "r_main4" ]) );
    bb = new("std/bboard");
    bb->set_name("Guild Angel Board");
    bb->set_id( ({ "board", "guild", "angel", "angel board" }) );
    bb->set_max_posts(200);
    bb->set_edit_ok( ({ "stormbringer", "nulvect", "daos", "whit", "daboura", "luna", "amun" }) );
    bb->set_location(GROOM "anghall");
    bb->set_short("%^BOLD%^%^YELLOW%^A%^WHITE%^n%^YELLOW%^gel B%^WHITE%^o%^YELLOW%^ard%^RESET%^");
    bb->set_long("%^BOLD%^%^BLACK%^This board is for all those who wish to share their adventures and concerns.%^RESET%^");
    bb->set_board_id("guild_angel_board");
    bb->move(environment(this_object()));
}
