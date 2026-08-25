// setmmin cmd from player.c. Made external by Morgoth 3/Mar/95

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
	return "setmmin <teleport in message>";
}

string query_short_help()
{
	return "Sets text for magic entry. Include $N.";
}

protected int cmd (string str, object me)
{
	

	if(!me->query_creator() && !me->query_property("setmm"))
	{
		notify_fail("You are not allowed that power yet.\n");
		return 0;
	}
	str = str + " ";
	if (sizeof(explode("^"+str, "$N")) < 2)
	{
		notify_fail("Must have a $N in your teleport message in.\n");
		return 0;
	}
	me->setmmin("@"+str);
	write("Ok.\n");
  me->set_trivial_action();
	return 1;
}

