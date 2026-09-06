#include <cmd.h>
#include <coder_levels.h>

nomask int
echoto_cmd(string str)
{
    string who, msg;
    object ob;
    int i;

    if (!CHECK) return 0;

    if (!str
      || (sscanf(str, "%s %s", who, msg) != 2))
    {
	notify_fail("Usage: echoto <who> <msg>\n");
	return 0;
    }

    ob = find_player(who);
    if (!ob) ob = find_living(who);

    if (!ob)
    {
	notify_fail("Can't find living \"" + who + "\".\n");
	return 0;
    }

    if (IS_ADMIN_OB(ob) && ob != TP)
	ob->tell_me(capitalize((string)TP->query_real_name()) + "! " + msg);
    else
	ob->tell_me(msg + "\n");

    write("You echoto " + capitalize((string)ob->query_real_name()) +
      ":\n" + msg + "\n");
    return 1;
}
