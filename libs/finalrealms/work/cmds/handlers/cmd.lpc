// /global/cmd/cmd.c -- Inherit for object-based commands
/* Added verb, Baldrick dec '97 
 */

#include <standard.h>
#include <cmd.h>

nosave int position = 0, dodest = 0, doclone = 0;
nosave object command_giver;
nosave string fail_msg;

void create()
{
	seteuid(getuid());

	TO->setup();
}

void dest_me()
{
	destruct(TO);
}

void clean_up()
{
	dest_me();
}

void setup() { return; }

/* Added by Baldrick.
 * using this_player ain't good.
 */
void notify_fail(string fa)
  {
  this_player()->set_notified(1);
  fail_msg = fa;
  return;
}

protected int cmd(string tail, object thisob, string verb) { return 0; }

string query_usage() { return 0; }
string query_short_help() { return 0; }

int _cmd(string tail, object thisob, string verb)
{
  string euid;
  int ret;

  if(previous_object() != find_object(CMD_HANDLER))
    return 0;

  command_giver = thisob;

  // Set the euid to that of either the creator, or to PLAYER.
  seteuid(euid = geteuid(command_giver));

  // Will check who is using command and if allowed here sort of :)
  switch(position)
	{
	case GOD_CMD:
		if(!thisob->query_god() && !thisob->query_highlord(euid))
			return 0;
		break;

	case DEMI_CMD:
		if(!MASTER->query_lord(euid))
			return 0;
		break;

	case THANE_CMD:
		if(!thisob->query_thane())
			return 0;
		break;

	case PATRON_CMD:
		if(!thisob->query_patron())
			return 0;
		break;

	case BUILDER_CMD:
		if(!thisob->query_creator())
			return 0;
		break;
	}
	ret = cmd(tail, thisob, verb);

	seteuid(getuid());

        if (ret == 0)
          write(fail_msg);
	return ret;
}

int _query_position() { return position; }
int _query_dodest() { return dodest; }
int _query_doclone() { return doclone; }
