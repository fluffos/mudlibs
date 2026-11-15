// message.c


#include <dbase.h>
#include <name.h>

#define MAX_STRING_SIZE		 8000
#define MAX_MSG_BUFFER		  500

nosave string *msg_buffer = ({});
nosave int written = 0;

#define NONE		    0
#define PROMPT_WRITTEN	  1
#define COMMAND_RCVD	    2

nosave string log_in = 0;

// Should I be log ?
int is_loging_now()
{
	return log_in != 0;
}

int start_log()
{
	string file;
	if (! is_root(previous_object())) return 0;

	if (log_in) return 0;

	if (! (file = EXAMINE_D->create_log_file(this_object())))
		return 0;

	log_file(file, sprintf("The system log the action of %s(%s) from %s on %s.\n\n",
			       name(1), query("id"),
			       query_ip_name(this_object()), ctime(time())));
	log_in = file;
	return 1;
}

void end_log()
{
	if (! log_in) return;
	if (! is_root(previous_object())) return;

	log_file(log_in, sprintf("The system stop log at %s.\n\n",
		 ctime(time())));
	log_in = 0;
}

void log_command(string msg)
{
	if (! log_in) return;

	log_file(log_in, HIC + ctime(time())[11..18] +
			 HIY "> " + msg + NOR "\n");
}

void log_message(string msg)
{
	if (! log_in) return;

	msg = replace_string(msg, ESC "[256D" ESC "[K", "\n");
	msg = replace_string(msg, ESC "[1A", "");
	log_file(log_in, msg);
}

string prompt()
{
	return "";
}


void receive_message(string msgclass, string msg)
{
	string subclass, *ch;

	if (! interactive(this_object()))
	{
		this_object()->relay_message(msgclass, msg);
		return;
	}

	if (msgclass == "telnet")
	{
		receive(msg);
		return;
	}

	if (sscanf(msgclass, "%s:%s", subclass, msgclass) == 2)
	{
		switch(subclass)
		{
			case "channel":
				if(!pointerp(ch = query("channels"))||member_array(msgclass, ch) == -1)
					return;
				msg = ZJCHANNEL + msg;
			break;
			case "outdoor":
				if (! environment() || ! environment()->query("outdoors"))
				{
					if (query("env/look_window"))
						msg = HIG "【窗外景象】" + NOR + msg;
					else
						return;
				}
				break;
			case "system":
				break;

			default:
				error("Message: Invalid Subclass " + subclass + ".\n");
		}
	}

	if (query_temp("block_msg/all") || query_temp("block_msg/" + msgclass))
		return;

	if (in_input(this_object()) || in_edit(this_object()) || this_object()->is_attach_system() && msgclass != "system")
	{
		if (sizeof(msg_buffer) < MAX_MSG_BUFFER)
			msg_buffer += ({ msg });
	} else
	{
		log_message(msg);
		if (written && ! this_object()->is_attach_system())
		{
			if (written == COMMAND_RCVD)
			{
				written = NONE;
			msg = msg;
			} else
			msg = msg + prompt();
		}

		while (strlen(msg) > MAX_STRING_SIZE)
		{
			receive(msg[0..MAX_STRING_SIZE - 1]);
			msg = msg[MAX_STRING_SIZE..<1];
		}
		receive(msg);
	}
}

void clear_written()
{
	written = COMMAND_RCVD;
}

int is_waiting_command()
{
	return (written == PROMPT_WRITTEN);
}

void write_prompt()
{
	if (sizeof(msg_buffer))
	{
		receive(BOLD "[输入时暂存讯息]"NOR"\n");
		for(int i = 0; i < sizeof(msg_buffer); i++)
			receive(msg_buffer[i]);
		msg_buffer = ({});
	}

	if (! living(this_object()))
		return;

	if (this_object()->is_attach_system())
		receive(HIR "执行中" HIY "> " NOR);
	written = PROMPT_WRITTEN;
}

void receive_snoop(string msg)
{
	receive(msg);
}
