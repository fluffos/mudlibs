#include <ansi.h>

#define QQ_MSG "/qq/qq_msg.txt"
#define MUD_MSG "/qq/mud_msg.txt"
#define PREFIX_CLR HIW

inherit F_DBASE;

int enabled = 1;

void create()
{
	set("channel_id", "北侠QQ频道精灵");
	seteuid(ROOT_UID);
	remove_call_out("check_qq_msg");
	call_out("check_qq_msg",1);
}

void process_send_msg(string send_msg)
{
	string all_msg;
	string *msg, *del;
	int i, len;
	if (enabled == 0) return;
	send_msg = replace_string(send_msg, "【北侠QQ群】", "【闲聊】");
	if (file_size(MUD_MSG)>0)
	{
		all_msg = read_file(MUD_MSG);
		msg = explode(all_msg, "\n");
		msg -= ({ "", 0 });
		len = sizeof(msg);
		if (len>=10)
		{
			del = ({ });
			for (i=0; i<(len-9); i++)
			{
				del += ({ msg[i] });
			}
			msg -= del;
		}
		all_msg = "";
		for (i=0; i<sizeof(msg); i++)
			all_msg += msg[i] + "\n";
		send_msg = all_msg + send_msg;
	}
	write_file(MUD_MSG, send_msg, 1);
}

void check_qq_msg()
{
	string all_msg,s1,s2;
	if (enabled == 0) return;
	if (file_size(QQ_MSG)>0)
	{
		all_msg = read_file(QQ_MSG);
		rm(QQ_MSG);
//		write_file(QQ_MSG, "", 1);
		while (sscanf(all_msg, "%s\n%s", s1, s2)==2)
		{
			CHANNEL_D->do_channel(this_object(), "qq", s1, -1);
			all_msg = s2;
		}
		if (strwidth(all_msg)>0)
			CHANNEL_D->do_channel(this_object(), "qq", all_msg, -1);
	}
	
	call_out("check_qq_msg",1);
}

void enable()
{
	if (enabled == 0) 
	{
		enabled = 1;
		remove_call_out("check_qq_msg");
		call_out("check_qq_msg",1);
	}
}

void disenable()
{
	enabled = 0;
	remove_call_out("check_qq_msg");
}

