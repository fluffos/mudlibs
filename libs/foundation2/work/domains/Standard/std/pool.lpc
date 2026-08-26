/* The base object for the pools that are in /domains/Standard/center
 * Beek - 090194
 */

#include <lib.h>

inherit LIB_ITEM;

string adjective;
string destination;

void create() {
    ::create();
    SetKeyName("pool");
    SetShort("an empty pool");
    SetId( ({ "pool", "empty pool" }) );
    SetLong( "Somehow, this pool is completely empty." );
    SetPreventGet("Interesting concept.");
}

void init() {
    add_action("wade", "wade");
}

int wade(string str) {
    string which;
    if (!str || !sscanf(str, "in %s", which))
	return notify_fail("Wade in what?\n");
    if (which == "pool")
	return notify_fail("Wade in which pool?\n");
    if (!id(which))
	return notify_fail("You can't wade in " + which + ".\n");
    if (!destination) {
	write("Tough to do with an empty pool.\n");
	tell_room(this_object(), this_player()->GetName()+" tries to wade in an empty pool.\n", this_player());
	return 1;
    }
    write("You slowly wade deeper and deeper into the pool.  Suddenly, the bottom disappears and you find yourself falling ....\n\n\n\n");
    destination->pool_enter();
    this_player()->eventMoveLiving(destination, "#$N wades into the " + adjective + " pool, and disappears below the surface.");
    return 1;
}

void set_adjective(string adj) {
    adjective = adj;
    SetKeyName(adj+" pool");
    SetId( ({ "pool", adj + " pool" }) );
    SetShort( "a " + adj + " pool" );
}

void set_destination(string dest) {
    destination = dest;
}

string GetLong(string unused) {
    write("As you look at the " + adjective + " pool, an image forms on the surface ...\n");
    this_player()->move(destination);
    this_player()->eventDescribeEnvironment(0);
    this_player()->eventMove(environment());
    return "\nbut then the image fades.\n\nDespite the obvious hallucinogenic effects of the pool, it looks like it would be safe to 'wade' in it.\n";
}
