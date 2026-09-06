#include <daemons.h>

nomask int finger2_cmd(string str)
{
    if (!str)
    {
	this_player()->more(explode(FINGER_D2->finger_list(this_player()), "\n"));
	return 1;
    }

    if (!FINGER_D2->show_data(str))
    {
	notify_fail("No such player.\n");
	return 0;
    } 

    return 1;
}
