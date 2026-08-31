#include <std.h>
#include <daemons.h>
#include <guild.h>
inherit HALL;
object bb;
void create() {
    ::create();
    set_type("rogue");
    set_properties(([ "light" : 2, "night light" : 0, "no attack" : 1, "no magic" : 1, "no steal" : 1, "no bump" : 1]));
    set_short("Board Room");
    set("long","%^BOLD%^%^BLACK%^This is a place for rogues, men and women, to come and train, improve and level to be the best at what they do. There are many shelves filled with books for those who wish to study. This is also a room for rogues to share their wisdom with others like themselves. They place their ideas, concerns and general comments on the board.%^RESET%^");
    set_items( ([ "shelves" : "%^BOLD%^%^WHITE%^The shelves are piled high with books to read.%^RESET%^", "books" : "%^BOLD%^%^WHITE%^The books line the shelves for those who wish to read through them.%^RESET%^" ]) );
    set_exits( ([ "northeast" : GROOM "l_main4" ]) );
    bb = new("std/bboard");
    bb->set_name("Guild Rogue Board");
    bb->set_id( ({ "board", "guild", "rogue", "rogue board" }) );
    bb->set_max_posts(200);
    bb->set_edit_ok( ({ "stormbringer", "luna", "daos", "whit", "daboura", "nulvect", "amun" }) );
    bb->set_location(GROOM "roghall");
    bb->set_short("%^BOLD%^%^BLACK%^Rogue Board%^RESET%^");
    bb->set_long("%^BOLD%^%^BLACK%^This board is for all those who wish to share their adventures and concerns.%^RESET%^");
    bb->set_board_id("guild_rogue_board");
    bb->move(environment(this_object()));
}
