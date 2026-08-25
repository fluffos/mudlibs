// prompt.c

#include <standard.h>
#include <cmd.h>

inherit CMD_BASE;

void setup()
{
	position = 0;
}

string query_short_help()
{
  return " $m mud-name\n $t time\n $g guild points left\n " +
	  "$h hit points left\n $B bold\n $b reset bold\n\n For immortals:\n"+
	  "\n $~ current path\n $/ short path\n\n";
}

/*
string query_short_help()
{
  return "Sets your prompt.";
}
*/

string query_usage()
  {
  return "prompt string\n";
}


protected int cmd (string str, object me)
{
  me->set_trivial_action();
  return me->set_prompt(str);
}
