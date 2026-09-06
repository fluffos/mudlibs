#include <cmd.h>

varargs nomask int
unkeep_cmd(string str, object me)
{
    object ob;
    string s;
    if (!me && !(me = this_player())) return 0;

    if (!str) return notify_fail("Unkeep what?\n"), 0;
    if (str == "all") {
	me -> add_keep_item(0, 0);
	me -> tell_me("Ok.");
	return 1;
    }

    if (s && sscanf(str, "the %s", s))
	str = s;

    if (!(ob = present(str, me))) return notify_fail(
	  "But you don't have any \""+str+"\"!\n"), 0;

    if (!me -> add_keep_item(ob, 0))
	me->tell_me("You aren't even keeping it!");
    else
	me->tell_me("Ok.");

    return 1;
}
