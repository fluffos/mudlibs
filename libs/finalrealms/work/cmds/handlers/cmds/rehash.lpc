// /global/cmd/cmds/cmd.c (confusing hey? :)
// causes command handler to rehash.

#include <standard.h>
#include <cmd.h>

inherit CMD_BASE;

nosave mapping cmd_dirs, cmd_hash;
nosave string last_dir, file;

void setup()
{
#ifdef CMD_AURORA
  position = CREATOR;
#endif
#ifdef CMD_ROD
  position = CREATOR_CMD;
#endif
}

string query_usage()
{
  return "rehash [-v]";
}

string query_short_help()
{
	return "Causes command handler to rehash.\n"+
		"	-v	Verbose mode.";
}

protected int cmd(string tail, object thisob)
{
	int count, verbose;

	if(!stringp(tail) || !tail)
		tail = "";

	verbose = 0;

	if(member_array("-v", explode(tail, " ")) != -1)
		verbose = 1;

	write("Rehashing command handler...\n");

	count = (int)CMD_HANDLER->cmd_make_hash(verbose);

	write("Command handler hashed "+count+" commands.\n");
	return 1;
}
