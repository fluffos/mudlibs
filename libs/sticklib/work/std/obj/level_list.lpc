#include <mud_name.h>

inherit "/lib/treasure";

void create()
{
    set_name("top list");
    set_id( ({ "list", "non-lord list" }) );
    set_short("A list of the top players (non-lords)");
    set_long("This is a list of the top non-lord players of "+
      MUD_NAME+".  You can \"read player\" to see if you are on it!");
    set_value(5);
    set_read("Type \"read player\" to read this list.\n");
}

void init()
{
    add_action("read", "read");
}

int read(string str)
{
    if (!str || str != "player")
	return 0;

    say(capitalize(this_player()->query_name())+" reads the "
      "top players list.\n");
    return this_player()->more("/log/PLAYER_LIST"), 1;
}
