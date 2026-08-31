#include <std.h>
#include <venenum.h>
inherit ROOM;

void create() {
    ::create();
    set_short("Room");
    set_long("There's a big button here.");
    set_smell("default", "Smells like buttons.");
    set_listen("default", "Sounds like buttons.");
    set_properties(([
	"light" : 0,
	"night light" : -1,
      ]));
}

void init() 
{
    ::init();
    add_action("pushfunc", "push");
}

int pushfunc(str)

{
    if(str == "button")
    {
	write("You push the button.");
	message("room message", this_player()->query_cap_name()+" pushes the button.", this_object(), this_player());
	return 1;
    }
}
