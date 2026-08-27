// message.c
// #pragma save_binary
#include <ansi.h>
#include <dbase.h>

#define MAX_MSG_BUFFER 300

static string *msg_buffer = ({});

int receive(string str)
{
	if(this_object()->query_temp("gb_player"))
	{
		str=LANGUAGE_D->Big52GB(str);
	}
	return efun::receive(str);
}

void receive_message(string msgclass, string msg)
{
	string subclass, *ch;
	string env_dir, buffer1, buffer2;	// add by shengsan

	if( !interactive(this_object()) ) {
		this_object()->relay_message(msgclass, msg);
		return;
	}
/*	
	if(this_object()->query_temp("gb_player"))
	{
		msg=LANGUAGE_D->Big52GB(msg);
	}
*/
	// add by shengsan for world message
	if( sscanf(msgclass, "world:%s:%s", buffer1, msgclass) == 2 )
	{
			if(!environment()) return;
			env_dir = base_name(environment());
			if(!wizardp(this_object()))
			{
				if( sscanf(env_dir,"/open/%s/%s",env_dir,buffer2)!=2
				|| buffer1 != env_dir )
				return;
			} else
			{
				if(msgclass[0..6]=="outdoor" && ( sscanf(env_dir,"/open/%s/%s",env_dir,buffer2)!=2
				|| buffer1 != env_dir ))
				return;
			}
	} else
	if( sscanf(msgclass, "world_channel:%s:%s", buffer1, msgclass) == 2 )
	{
			if(!environment()) return;
			env_dir = base_name(environment());
			if(!wizardp(this_object()))
			{
				if( sscanf(env_dir,"/open/%s/%s",env_dir,buffer2)!=2 || buffer1 != env_dir ) return;
				if( !pointerp(ch = query("channels")) || member_array("chat", ch)==-1 )	return;
			}
			else if( !pointerp(ch = query("channels")) || member_array("chat", ch)==-1 )	return;
	}
	// end add
	if( sscanf(msgclass, "%s:%s", subclass, msgclass)==2 )
	{
		switch(subclass)
		{
			case "channel":
				if( !pointerp(ch = query("channels"))
				||	member_array(msgclass, ch)==-1 )
					return;
				break;
			case "outdoor":
				if( !environment() || !environment()->query("outdoors") )
					return;
				// add by shengsan for 地形氣候訊息
				if( msgclass && msgclass!="vision"
				&& msgclass!=environment()->query("outdoors") )
					return;
				// end add
				break;
			case "dayphase":
				if( !environment() || !environment()->query("outdoors") )
					return;
				if( environment()->query("outdoors")=="universe" )
					return;
				break;
			default:
				error("Message: Invalid Subclass " + subclass + ".\n");
		}
	}

	if( query_temp("block_msg/all") || query_temp("block_msg/" + msgclass) )
		return;

	if( !query("env/edit_msg") && (in_input(this_object()) || in_edit(this_object())) )
	{
		if( sizeof(msg_buffer) < MAX_MSG_BUFFER ) msg_buffer += ({ msg });
	} else receive( msg );
}

void write_prompt()
{
	string pwd;
	if( sizeof(msg_buffer) )
	{
		if(query_temp("halt_msg_in_edit")) this_object()->delete_temp("halt_msg_in_edit");
		receive(BOLD "[輸入時暫存訊息]\n" NOR);
		for(int i=0; i<sizeof(msg_buffer); i++)
			receive(msg_buffer[i]);
		msg_buffer = ({});
	}
	
	if (wiz_level(this_object())>1)
	{
		pwd=this_object()->query("cwd");
                if (!pwd || pwd=="/") write("/");
                else write(pwd[0..strlen(pwd)-2]);
        }
	write("> ");
}

void receive_snoop(string msg)
{
	if(this_object()->query_temp("gb_playey"))
	{
		if(this_object()->query_temp("snoop_type")=="big5") msg=LANGUAGE_D->Big52GB(msg);
	} else
	{
		if(this_object()->query_temp("snoop_type")=="gb") msg=LANGUAGE_D->GB2Big5(msg);
	}
	receive("%" + msg);
}
