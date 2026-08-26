//
// the "unset" command
// Part of the TMI distribution mudlib
//
// Zak, 930610: cleaned up a lot
//

#include <uid.h>
#include <mudlib.h>

inherit DAEMON;

#define SET_CMD "/cmds/std/_set"


int cmd_unset(string arg)
{
    object act_ob;

    act_ob = previous_object();
    if (!arg)
    {
	notify_fail ("usage: unset <variable_name>\n");
	return 0;
    }
    if (!act_ob->env_exists(arg))
    {
	notify_fail("No such variable defined.\n");
	return 0;
    }
    if ( (   this_player(1) != previous_object()
	  && geteuid(previous_object()) != ROOT_UID )
	|| ! SET_CMD->valid_set(act_ob, arg) )
    {
	printf("You aren't allowed to unset '%s'.\n", arg);
	return 1;
    }
    act_ob->remove_env(arg);
    printf("Variable removed: %s\n", arg);
    return 1;
}

void help()
{
    write( @HELP
Usage: unset <variable name>

This command will remove an environment variable if it exists.
HELP
    );
}
