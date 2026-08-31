#include <std.h>
#include <amun.h>
inherit ROOM;
object bb;
void create() {
    ::create();
    set_properties(([ "light" : 2, "night light" : 0, "no attack" : 1, "no magic" : 1, "no steal" : 1, "no bump" : 1]));
    set_short("Heaven Square");
    set_long("%^BOLD%^%^WHITE%^The square is bright with a heavenly glow. Towards the north there is a giant black cloud hovering over the rest of the area. This is odd, as Heaven is usually bright and sunny. Looking more carefully, blood can be seen tainting the soft pillowed cloads.%^RESET%^");
    set_smell("default", "There is a light smell of death mixed in with a sweet perfume.");
    set_items( ([ "cloud": "%^BOLD%^%^BLACK%^The Black clouds looks as if it could spit rain at any moment.%^RESET%^", "blood": "%^RED%^This blood looks as if it is old. There are spoltches everywhere tainting the clouds.%^RESET%^" ]) );
    set_exits( ([ "northwest" : HEVROOM "b_1", "south" :
	HEVROOM "portal_room", "northeast" : HEVROOM "b_17", "west" :
	HEVROOM "weapon_shop", "east" : HEVROOM "armour_shop"]) );
    bb = new("std/bboard");
    bb->set_name("Board of Heaven");
    bb->set_id( ({ "board" }) );
    bb->set_max_posts(200);
    bb->set_edit_ok( ({ "stormbringer", "nightshade", "daos", "whit",
	"daboura", "nesoo", "amun" }) );
    bb->set_location(HEVROOM "heaven_square");
    bb->set_short("%^BOLD%^%^WHITE%^B%^YELLOW%^o%^WHITE%^a%^YELLOW%^r%^WHITE%^d %^YELLOW%^o%^WHITE%^f %^YELLOW%^H%^WHITE%^e%^YELLOW%^a%^WHITE%^v%^YELLOW%^e%^WHITE%^n%^RESET%^");
    bb->set_long("%^BOLD%^%^WHITE%^This board is for the good and bad souls to share their adventures and concerns.%^RESET%^");
    bb->set_board_id("heaven_board");
    bb->move(environment(this_object()));
}
