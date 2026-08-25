// editor.c

#include <standard.h>
#include <cmd.h>

inherit CMD_BASE;

void setup()
{
	position = 0;
}

string query_short_help()
{
	return "Shows various player statistics.";
}


protected int cmd (string str, object me)
{
  me->set_trivial_action();
  return me->set_editor(str);
}
