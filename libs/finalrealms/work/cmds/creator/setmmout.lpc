// setmmout cmd from player.c. Made external by Morgoth 3/Mar/95

#include <standard.h>
#include <cmd.h>

inherit CMD_BASE;

void setup()
{
	position = 0;			// consider makoutg it creator only
	dodest = 1;			// not often used command
}

string query_usage()
{
	return "setmmout <teleport out message>";
}

string query_short_help()
{
	return "Sets text for magic exit. Include $N.";
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
		notify_fail("Must have a $N out your teleport message out.\n");
		return 0;
	}
	me->setmmout("@"+str);
	write("Ok.\n");
  me->set_trivial_action();
	return 1;
}

