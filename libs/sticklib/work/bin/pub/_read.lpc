/*
 * "New" 'read'-command.
 * 08-jun-94 Doomdark,
 */


#include <cmd.h>

varargs nomask status
read_cmd(string s, object me)
{
    object ob;
    string t;

    if (!me && !(me = this_player()))
	return 0;

    if (!me->query_can_see())
	return 0;

    if (!s) return notify_fail("Read what?\n"), 0;

    if (sscanf(s, "the %s", t)) s  = t;
    if ((ob = present(s, me)) ||
      (ob = present(s, environment(me)))) {
	notify_fail("You don't see any writing on the "+s+".\n");
	return (status) ob -> read_cmd(s);
    }
    notify_fail("You can't see any "+s+" here.\n");
    return (status) environment(me) -> read_cmd(s);
}
