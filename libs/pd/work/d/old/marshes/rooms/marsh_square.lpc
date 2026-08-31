#include <std.h>
#include <amun.h>
inherit ROOM;
object bb;
void create() {
    ::create();
    set_properties(([ "night light" : 0, "no attack" : 1, "no magic" : 1, "no steal" : 1, "no bump" : 1]));
    set_short("Marsh Square");
    set_long("%^BOLD%^%^BLACK%^This is the square of the Marshes.  There is noone in sight and you have a feeling that it has been dead for a long time.  You get an eerie feeling being in this area.");
    set_exits( ([ "south" : MARSHROOM+"entrance2", "southwest" : MARSHROOM+"marsh_armour", "northeast" : MARSHROOM+"marsh_weapon", "southeast" : MARSHROOM+"pub", "northwest": MARSHROOM+"marsh_1"]) );
    new(MARSHARM+"statue")->move(this_object());
    bb = new("std/bboard");
    bb->set_name("Marshes Board");
    bb->set_id( ({ "board" }) );
    bb->set_max_posts(200);
    bb->set_edit_ok( ({ "stormbringer", "nightshade", "daos", "whit", "daboura", "nesoo", "amun", "biden" }) );
    bb->set_location(MARSHROOM+"marsh_square");
    bb->set_short("Marshes Board");
    bb->set_long("This board is for the travlers of the marshes. If you wish to leave fellow traveler bits of advice or messages, feel free to do so.");
    bb->set_board_id("board");
    bb->move(environment(this_object()));
}
