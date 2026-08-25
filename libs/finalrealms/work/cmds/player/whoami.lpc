#include <standard.h>
#include <cmd.h>

inherit CMD_BASE;
  
void setup()
{
	position = 0;
}
 
string query_usage()
{
	return "whoami";
}

string query_short_help()
{
	return "Shows current player name and title(s).";
}

protected int cmd (string str, object me)
{
	efun::tell_object(me, (string)me->query_short()+
		(me->query_gtitle()? " "+me->query_gtitle() : "")+
		(me->query_title()? " "+me->query_title() : "")+
		".\n");
	return 1;
}
