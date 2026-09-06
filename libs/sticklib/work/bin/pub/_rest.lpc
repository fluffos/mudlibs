/* Moved to /bin/pub 22-sep-94. */

#include <cmd.h>

nomask varargs status
rest_cmd(string arg, object me)
{
    if (!me && !(me = this_player())) return 0;
    if (arg) return notify_fail("Rest what?\n"), 0;
    if (me -> query_ghost()) {
	me -> tell_me("You can't rest being just a ghost!");
	return 1;
    }
    if (!me -> query_can_move()) return 0;
    if (me -> is_fighting()) {
	me -> tell_me("You're too busy fighting now!");
	return 1;
    }
    if (me -> query_sit()) {
	me -> tell_me(TOO_RELAXED);
	return 1;
    }
    if (me -> query_rest()) {
	me -> tell_me("You are already resting.");
	return 1;
    }
    me -> set_rest(1);
    return 1;
}
