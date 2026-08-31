#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_name("the box");
    set_id( ({ "box", "the box"}) );
    set_short("The Box");
    set_long("This is a large box. It can be opened to reveal what's inside...");
    set_mass(15);
    set_value(0);
}
void init() 
{
    ::init();
    add_action("open", "open");
}

int open(string str)
{
    if (str != "the box")
    {
	return 0;
    }
    if (query_short() != "The Box" || str == "letter" || str == "the letter" || str == "hint" || str == "envelope")
    {
	write("You tug and tug but it doesn't work. It must be something else...");
	return 0;
    }
    write("You open the box! A present appears in your hand: %^YELLOW%^a hint to the vampire quest!%^RESET%^");
    message("info", this_player()->query_cap_name()+" opens the box! A present appears in their hand: %^YELLOW%^a hint to the vampire quest!%^RESET%^", environment(this_player()), this_player());
    set_name("a hint");
    set_id( ({ "hint" }) );
    set_short("A hint to the vampire quest");
    set_long("This plain looking envelope is a HINT to the VAMPIRE QUEST! ... now, if only you could figure out the syntax to get it open...");
    return 1;
}
