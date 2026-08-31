#include <std.h>
#include <amun.h>
inherit ROOM;
object bb;
void create() {
    ::create();
    set_properties(([ "light" : 2, "night light" : 0, "no attack" : 1, "no magic" : 1, "no steal" : 1, "no bump" : 1]));
    set_short("Board Room");
    set_long("%^BOLD%^%^WHITE%^This is the room where elite adventurers come to share their stories about their conquests. There is a board lying in the middle of the room with clips of stories and words for all to read. A beam of %^YELLOW%^sunlight %^WHITE%^shines through the clouds providing enough %^YELLOW%^light %^WHITE%^to see. The clouds, in their beauty, offer a soft cushion for travelers.%^RESET%^");
    set_items( ([ "sunlight" : "%^BOLD%^%^YELLOW%^The sunrays shine sparatically through breaks in the clouds, offering light.%^RESET%^", "clouds" : "%^BOLD%^%^WHITE%^The clouds stretch as far as the naked eye can see and look like a fresh new powder of snow, untouched and beautiful.%^RESET%^" ]) );
    set_exits( ([ "up" : SKYROOM "lsup_8"]) );
    bb = new("std/bboard");
    bb->set_name("Elite Board");
    bb->set_id( ({ "board", "elite", "elite board" }) );
    bb->set_max_posts(200);
    bb->set_edit_ok( ({ "stormbringer", "nulvect", "daos", "whit", "hepualahaole", "luna", "amun" }) );
    bb->set_location(SKYROOM "elite_nook");
    bb->set_short("%^BOLD%^%^WHITE%^E%^RESET%^l%^BOLD%^%^WHITE%^i%^RESET%^t%^BOLD%^%^WHITE%^e %^RESET%^B%^BOLD%^%^WHITE%^o%^RESET%^a%^BOLD%^%^WHITE%^r%^RESET%^d%^RESET%^");
    bb->set_long("%^BOLD%^%^WHITE%^This board is for all those elite's who wish to share their adventures and concerns.%^RESET%^");
    bb->set_board_id("elite_nook_board");
    bb->move(environment(this_object()));
}
