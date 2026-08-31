#include <std.h>
#include <amun.h>
inherit ROOM;
object bb;
void create() {
    ::create();
    set_properties(([ "light" : 2, "night light" : 0, "no attack" : 1, "no magic" : 1, "no steal" : 1, "no bump" : 1]));
    set_short("Board Room");
    set_long("%^BOLD%^%^WHITE%^This is the room where high mortal adventurers come to share their stories about their conquests. There is a board lying in the middle of the room with clips of stories and words for all to read. A beam of %^YELLOW%^sunlight %^WHITE%^shines through the clouds providing enough %^YELLOW%^light %^WHITE%^to see. The clouds, in their beauty, offer a soft cushion for travelers.%^RESET%^");
    set_items( ([ "sunlight" : "%^BOLD%^%^YELLOW%^The sunrays shine sparatically through breaks in the clouds, offering light.%^RESET%^", "clouds" : "%^BOLD%^%^WHITE%^The clouds stretch as far as the naked eye can see and look like a fresh new powder of snow, untouched and beautiful.%^RESET%^" ]) );
    set_exits( ([ "up" : SKYROOM "rsup_8"]) );
    bb = new("std/bboard");
    bb->set_name("High Mortal Board");
    bb->set_id( ({ "board", "high", "mortal" "high mortal board", "high mortal", "mortal board", "high board" }) );
    bb->set_max_posts(200);
    bb->set_edit_ok( ({ "stormbringer", "nulvect", "daos", "whit", "hepualahaole", "luna", "amun" }) );
    bb->set_location(SKYROOM "hm_nook");
    bb->set_short("%^BOLD%^%^WHITE%^H%^RESET%^i%^BOLD%^%^WHITE%^g%^RESET%^h %^BOLD%^%^WHITE%^M%^RESET%^o%^BOLD%^%^WHITE%^r%^RESET%^t%^BOLD%^%^WHITE%^a%^RESET%^l %^BOLD%^%^WHITE%^B%^RESET%^o%^BOLD%^%^WHITE%^a%^RESET%^r%^BOLD%^%^WHITE%^d%^RESET%^");
    bb->set_long("%^BOLD%^%^WHITE%^This board is for all those high mortal's who wish to share their adventures and concerns.%^RESET%^");
    bb->set_board_id("hm_nook_board");
    bb->move(environment(this_object()));
}
