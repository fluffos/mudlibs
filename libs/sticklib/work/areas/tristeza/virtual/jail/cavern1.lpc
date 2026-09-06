#include "defs.h"

#include <room.h>

void
create_room()
{
    set_short("Big cavern");
    set_long(
      "Wow, what a big room! You become dizzy when you think about the amount "+
      "of work and spoons which they have used when digging this chamber. In "+
      "fact, you become so confused that you don't know where you came from.");

    set_light_level(LT_DIM);
    set_wd(WD_INDOORS);

    add_exit("north", DIRR + "/tunnel2");
    add_exit("east", DIRR + "/tunnel5");
    add_exit("south", DIRR + "/tunnel6");
    add_exit("west", DIRR + "/tunnel3");
}

init()
{
    ::init();
    add_action("north", "gosomewhere");
    add_action("south", "gosomewhere");
    add_action("east", "gosomewhere");
    add_action("west", "gosomewhere");
}

status
gosomewhere()
{
    /* Aaaaaaaaaaaaaaaaaaarrrrrrrrrrrrrrrrrrrrrrrrrghhhhhhhhhh! */
    if (this_player()->query_sit()) {
	if (this_player()->short())
	    say((string)this_player()->query_name()+" stands up.\n");
	this_player()->set_ssit(0);
    }

    if (this_player()->query_rest()) {
	write("Nah, you feel too relaxed to move.\n");
	return 1;
    }

    this_player()->move_player(query_verb() + "#" +
      ({
	DIRR + "/tunnel2",
	DIRR + "/tunnel5",
	DIRR + "/tunnel6",
	DIRR + "/tunnel3"
      })[random(4)]);

    return 1;
}
