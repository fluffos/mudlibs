/* Moved to /bin/pub 22-sep-94. */

#include <cmd.h>

nomask varargs status
stand_cmd(string arg, object me)
{
    if (!me && !(me = this_player())) return 0;
    if (arg && arg != "up") return notify_fail("Stand what?\n"), 0;
    if (me -> query_ghost()) {
	me -> tell_me("You can't stand being just a ghost!");
	return 1;
    }
    if (!me->query_can_move()) return 0;

    if (me -> query_rest()) me -> set_rest(0);
    else if (me -> query_sit()) me -> set_sit(0);
    else me -> tell_me("You are already on your feet.");
    return 1;
}
