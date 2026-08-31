#include <std.h>
inherit OBJECT;

void create() {
    ::create();
    set_id(({"fountain", "well", "water"}));
    set_name("fountain");
    set_short("a stone fountain");
    set_long("The beautifully crafted fountain remains ageless, despite "
      "the harsh climate. Its waters have been said to have "
      "a certain rejuvenating capability." );

    set_prevent_get( "You cant budge the solid foundation of the well." );
}
int init()
{
    ::init();
    add_action("goDrink", "drink");
}

int goDrink(string str) {
    if (str != "well" && str != "from well" && str != "fountain" && str != "from fountain") {
	notify_fail("Drink from what?\n");
	return 0;
    }
    if (this_player()->query_disable())
    {
	write("You cannot drink that fast.");
	return 1;
    }
    this_player()->set_disable();

    this_player()->heal(10);

    write("%^GREEN%^The fountain's water refreshes you.");
    return 1;
}
