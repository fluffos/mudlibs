/* The base object for the pools that are in /domains/Standard/center
 * Beek - 090194
 */

#include <std.h>

inherit OBJECT;
string adjective;
string destination;

get() { return 0; }

create() {
    ::create();
    set_name("pool");
    set_short("an empty pool");
    set_id( ({ "pool", "empty pool" }) );
    set_long( "Somehow, this pool is completely empty." );
}

init() {
    add_action("wade", "wade");
}

wade(string str) {
    string which;
    if (!str || !sscanf(str, "in %s", which))
	return notify_fail("Wade in what?\n");
    if (which == "pool")
	return notify_fail("Wade in which pool?\n");
    if (!id(which))
	return notify_fail("You can't wade in " + which + ".\n");
    if (!destination) {
	write("Tough to do with an empty pool.\n");
	tell_room(this_object(), this_player()->query_cap_name()+" tries to wade in an empty pool.\n", this_player());
	return 1;
    }
    write("You slowly wade deeper and deeper into the pool.  Suddenly, the bottom disappears and you find yourself falling ....\n\n\n\n");
    destination->pool_enter();
    this_player()->move_player(destination, "#$N wades into the " + adjective + " pool, and disappears below the surface.");
    return 1;
}

set_adjective(string adj) {
    adjective = adj;
    set_name(adj+" pool");
    set_id( ({ "pool", adj + " pool" }) );
    set_short( "a " + adj + " pool" );
}

set_destination(string dest) {
    destination = dest;
}

query_long() {
    write("As you look at the " + adjective + " pool, an image forms on the surface ...\n");
    this_player()->move(destination);
    this_player()->describe_current_room(1);
    this_player()->move(environment());
    return "\nbut then the image fades.\n";
}
