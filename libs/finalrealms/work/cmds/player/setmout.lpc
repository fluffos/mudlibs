// setmout cmd from player.c. Made external by Morgoth 3/Mar/95

#include <standard.h>
#include <cmd.h>

inherit CMD_BASE;

void setup()
{
	position = 0;			// consider making it creator only
	dodest = 1;			// not often used command
}

string query_usage()
{
	return "setmout <exit message>";
}

string query_short_help()
{
	return "Sets text for normal exit. Include $N (name) and $F (from).";
}

protected int cmd (string str, object me)
{
	

	if(!me->query_creator() && !me->query_property("setm"))
	{
		notify_fail("You are not allowed that power yet.\n");
		return 0;
	}
	str = str + " ";
	if (sizeof(explode("^"+str, "$N")) < 2
		|| sizeof(explode("^"+str, "$T")) < 2)
	{
		notify_fail("Must have a $N and a $T in your message out.\n");
		return 0;
	}
	me->setmout("@"+str);
	write("Ok.\n");
	return 1;
}

