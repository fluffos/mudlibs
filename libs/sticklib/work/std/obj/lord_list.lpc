#include <mud_name.h>

inherit "/lib/treasure";

void create()
{
    set_name("top list");
    set_id( ({ "list", "lord list" }) );
    set_short("A list of the top players (lords)");
    set_long("This is a list of the top lord players of "+
      MUD_NAME+".  You can \"read lord\" to see if you are on it!");
    set_value(5);
    set_read("Type \"read lord\" to read this list.\n");
}

void init()
{
    add_action("read", "read");
}

int read(string str)
{
    if (!str || str != "lord")
	return 0;

    say(capitalize(this_player()->query_name())+" reads the "
      "top players list.\n");
    return this_player()->more("/log/LORD_LIST"), 1;
}
