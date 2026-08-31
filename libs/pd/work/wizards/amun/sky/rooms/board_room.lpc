#include <std.h>
#include <amun.h>
inherit ROOM;
object bb;
void create() {
    ::create();
    set_properties(([ "light" : 2, "night light" : 0, "no attack" : 1, "no magic" : 1, "no steal" : 1, "no bump" : 1]));
    set_short("Board Room");
    set_long("%^BOLD%^%^WHITE%^This is the room where adventurers come to share their stories about their conquests. There is a board lying in the middle of the room with clips of stories and words for all to read. A beam of %^YELLOW%^sunlight %^WHITE%^shines through the clouds providing enough %^YELLOW%^light %^WHITE%^to see. The clouds, in their beauty, offer a soft cushion for travelers.%^RESET%^");
    set_items( ([ "sunlight" : "%^BOLD%^%^YELLOW%^The sunrays shine sparatically through breaks in the clouds, offering light.%^RESET%^", "clouds" : "%^BOLD%^%^WHITE%^The clouds stretch as far as the naked eye can see and look like a fresh new powder of snow, untouched and beautiful.%^RESET%^" ]) );
    set_exits( ([ "southeast" : SKYROOM "square"]) );
    bb = new("std/bboard");
    bb->set_name("Board of the Temple");
    bb->set_id( ({ "board", "board of the", "board of", "board of the temple" }) );
    bb->set_max_posts(200);
    bb->set_edit_ok( ({ "stormbringer", "nightshade", "daos", "whit", "daboura", "nesoo", "amun" }) );
    bb->set_location(SKYROOM "board_room");
    bb->set_short("%^BOLD%^%^WHITE%^B%^YELLOW%^o%^WHITE%^a%^YELLOW%^r%^WHITE%^d %^YELLOW%^o%^WHITE%^f %^YELLOW%^t%^WHITE%^h%^YELLOW%^e %^WHITE%^T%^YELLOW%^e%^WHITE%^m%^YELLOW%^p%^WHITE%^l%^YELLOW%^e%^RESET%^");
    bb->set_long("%^BOLD%^%^WHITE%^This board is for all those who wish to share their adventures and concerns.%^RESET%^");
    bb->set_board_id("temple_board");
    bb->move(environment(this_object()));
}
