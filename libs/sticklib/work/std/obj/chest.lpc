#include <container_defs.h>

inherit CONTAINER_FILE;

int chest_is_open;

void
create_container()
{

    set_name("chest");
    set_short("a chest");
    set_long("A chest that seems to be of a high value.");
    set_value(200);
    set_weight(6);
    chest_is_open = 0;
    this_object() -> create_chest();
}

void
reset_container() { this_object()->reset_chest(); }

varargs string
query_long(string s, object who)
{
    return ::query_long() + "\n"
    +  (chest_is_open ? "It is open." : "It is closed.");
}

status can_put_and_get(string s) { return chest_is_open; }

status
close_cmd(string str)
{
    if (!chest_is_open) this_player() -> tell_me("It's already closed.");
    else {
	chest_is_open = 0;
	this_player() -> tell_me("Ok.");
    }
    return 1;
}

status
open_cmd(string str)
{
    if (chest_is_open) this_player() -> tell_me("It's already open.");
    else {
	chest_is_open = 1;
	this_player() -> tell_me("Ok.");
    }
    return 1;
}
