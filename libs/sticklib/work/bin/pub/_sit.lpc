/* Moved to /bin/pub 22-sep-94. */

#include <cmd.h>

nomask varargs status
sit_cmd(string arg, object me)
{
    if (!me && !(me = this_player())) return 0;
    if (arg && arg != "down") return notify_fail("Sit what?\n"), 0;
    if (me -> query_ghost()) {
	me -> tell_me("You can't sit being just a ghost!");
	return 1;
    }
    if (!me -> query_can_move()) return 0;
    if (me -> is_fighting()) {
	me -> tell_me("You're too busy fighting now!");
	return 1;
    }
    if (me -> query_rest()) {
	me -> tell_me(TOO_RELAXED);
	return 1;
    }
    if (me -> query_sit()) {
	me -> tell_me("You are already sitting.");
	return 1;
    }
    me -> set_sit(1);
    return 1;
}
