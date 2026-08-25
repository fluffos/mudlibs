
/* history command externalized by Baldrick.
 */

#include <standard.h>
#include <cmd.h>

inherit CMD_BASE;

void setup()
{
	position = 0;
}

string query_usage()
{
	return "commands";
}

string query_short_help()
{
	return "Shows your history.";
}

protected int cmd (string name, object me)
{
  /* This is a hack.. altho bloody effective. */
  me->print_history();
  me->set_trivial_action();
  return 1;
}
