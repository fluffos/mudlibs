#include <daemons.h>
inherit DAEMON;
int cmd_notify(string str)
{
    if (!str || str=="") return notify_fail("Notify what?\n");
    if (str=="skills")
    {
	if (this_player()->getenv("SKILL_SHOW"))
	{
	    write("You will no longer be shown skill increase.");
	    this_player()->remove_env("SKILL_SHOW");
	    return 1;
	}
	write("You will now be shown skill increases.");
	this_player()->set_env("SKILL_SHOW", "1");
	return 1;
    }
    return notify_fail("Notify what?\n");
}

int help()
{
    write( @EndText
Syntax: <notify skills>
Effect: shows you when skills advance even if in battle.
EndText
    );
    return 1;
}
