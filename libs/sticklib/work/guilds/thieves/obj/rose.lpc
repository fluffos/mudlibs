#include <treasure.h>

void create_treasure()
{
    set_name("black rose");
    set_id( ({ "rose", "flower", "black rose" }) );
    set_short("A perfect black rose");
    set_long("This flower is certainly created by powerful magic.");
    set_value(30);
    set_weight(1);
}

void init_treasure()
{
    add_action("smell","smell");
    add_action("smell","sniff");
}

status smell(string str) {
    if(!str || !id(str))
	return notify_fail("Did you want to smell the rose?\n"), 0;

    this_player()->tell_me("It smells very good.");
    return 1;
}
