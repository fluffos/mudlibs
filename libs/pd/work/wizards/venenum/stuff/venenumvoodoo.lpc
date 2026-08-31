#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("doll");
    set_id( ({ "doll", "voodoo doll" "venenum doll"}) );
    set_short("Venenum Voodoo Doll");
    set_long("This tiny stuffed toy resembles Venenum in every way. If you wanted to, you could use it to <stick> him good!");
    set_mass(1);
    set_value(0);
}

void init()
{
    add_action("stick","stick");
}

int stick(string str)
{
    if (str != "venenum") 
    {
	notify_fail("Stick who?");
    }
    write("You stick Venenum in the eye!");
    if (find_player("venenum"))
    {
	message("global","%^BOLD%^%^BLUE%^Venenum shouts:%^RESET%^ OW! MY EYE!",users());
	this_object()->remove();
	return 1;
    }
    else
    {
	notify_fail("You can't see Venenum about.");
    }
    return 1;
}
