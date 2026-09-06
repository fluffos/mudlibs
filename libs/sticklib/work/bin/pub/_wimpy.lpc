#include <cmd.h>
#include <player_defs.h>

varargs nomask status
wimpy_cmd(string str, object me)
{
    int d;

    if (!me && !(me = this_player())) return 0;

    if(str && sscanf(str, "%d", d)) {
	if (d < 0) {
	    me -> tell_me("No negative wimpy allowed.");
	    return 1;
	}
	if(d > 40) {
	    me -> tell_me("You can't set wimpy higher than 40%.");
	    d = 40;
	}
	me -> set_wimpy(d);
	me->set(PLR_USED_WIMPY, d);
    } else d = (int) me -> query_wimpy();
    if (d) me -> tell_me("Your wimpy is set to " + d + "%.");
    else me -> tell_me("Brave mode.");
    return 1;
}
