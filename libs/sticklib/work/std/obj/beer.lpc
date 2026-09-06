// This file needs some work on the query_name and query_short functions
// once this has been consumed
#include <drink_defs.h>

inherit	DRINK_FILE;

void
create_drink()
{
    set_name("bottle of beer");
    set_id(({ "bottle", "beer" }));
    set_liquid("beer");
    set_short("bottle of beer");
    set_long("It's a normal bottle of beer.");
    set_weight(1);
    set_full(1);
}

string
query_short(int mode, object me) {
    return query_full() ? ::query_short(mode, me) : "Empty bottle";
}

varargs status
id(string str, object who)
{
    if (query_full()) return ::id(str, who);
    return str == "bottle" || str == "empty bottle";
}

// The shop only buys empty bottles!

int
query_value()
{
    if (!query_full()) return 10;
    return 0;
}

// No need for add_action!
status
drink_cmd(string str)
{
    if (!query_full()) {
	this_player() -> tell_me("But it's empty!");
	return 1;
    }
    if (!call_other(this_player(), "drink_alcohol", 2)) return 1;
    set_full(0);
    this_player() -> tell_me("It is really good beer!");
    environment(this_player()) -> tell_here(
      (string) this_player() -> query_name(0, this_player()) +
      " drinks a bottle of beer.", this_player());
    return 1;
}
