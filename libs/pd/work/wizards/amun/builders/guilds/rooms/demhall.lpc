#include <std.h>
#include <daemons.h>
#include <guild.h>
inherit HALL;
object bb;
void create() {
    ::create();
    set_type("demon");
    set_properties(([ "light" : 2, "night light" : 0, "no attack" : 1, "no magic" : 1, "no steal" : 1, "no bump" : 1]));
    set_short("Board Room");
    set("long","%^BOLD%^%^BLACK%^This is a place for D%^RED%^e%^BLACK%^mons to come and train, improve and level to be the best at what they do. There are many shelves filled with books for those who wish to study. This is also a room for D%^RED%^e%^BLACK%^mons to share their wisdom with others like themselves. They place their ideas, concerns and general comments on the board.%^RESET%^");
    set_items( ([ "shelves" : "%^BOLD%^%^WHITE%^The shelves are piled high with books to read.%^RESET%^", "books" : "%^BOLD%^%^WHITE%^The books line the shelves for those who wish to read through them.%^RESET%^" ]) );
    set_exits( ([ "southwest" : GROOM "l_main4" ]) );
    bb = new("std/bboard");
    bb->set_name("Guild Demon Board");
    bb->set_id( ({ "board", "guild", "demon", "demon board" }) );
    bb->set_max_posts(200);
    bb->set_edit_ok( ({ "stormbringer", "nulvect", "daos", "whit", "daboura", "luna", "amun" }) );
    bb->set_location(GROOM "demhall");
    bb->set_short("%^BOLD%^%^BLACK%^Demon Board%^RESET%^");
    bb->set_long("%^BOLD%^%^BLACK%^This board is for all those who wish to share their adventures and concerns.%^RESET%^");
    bb->set_board_id("guild_demon_board");
    bb->move(environment(this_object()));
}
