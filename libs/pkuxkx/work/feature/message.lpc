// message.c
//
// Modified by pretty 98/10/31

#include <ansi.h>
#include <dbase.h>

#define MAX_MSG_BUFFER 500

nosave string *msg_buffer = ({});
string filter_regexp(string pattern);


void receive_message(string msgclass, string msg)
{
    string subclass, *ch;
	string pattern;
    int received_len = 0;
    
    if( !interactive(this_object()) ) {
	this_object()->relay_message(msgclass, msg);
	return;
    }

    if( sscanf(msgclass, "%s:%s", subclass, msgclass)==2 ) {
	switch(subclass) {
	case "channel":
	    if( !pointerp(ch = query("channels"))
	      ||	member_array(msgclass, ch)==-1 )
		return;
	    break;
	case "outdoor":
	    if( !environment() || !environment()->query("outdoors") )
		return;
	    break;
	default:
	    error("Message: Invalid Subclass " + subclass + ".\n");
	}
    }

    if( query_temp("block_msg/all") || query_temp("block_msg/" + msgclass))
	return;

    if( query("block_msg"))
        return;

    if(environment() && environment()->query("no_remote_message") && msgclass != "sound" && !wizardp(this_object()))
    {
        //在某些房间，比如机器人检查室，屏蔽一切say以外的消息。
        return;
    }
        
    //在real_dark的房间里屏蔽部分消息（副本）        
        
    if(objectp(environment(this_object())) && environment(this_object())->query("real_dark") == 1)
    {        
        if(msgclass == "sound" || msgclass == "say" || msgclass == "tell_room" || msgclass == "exert")
        {
            return;
        }
    }     

	//别人拔刀穿甲的信息可以选择过滤掉
	if(msgclass == "wield" && query("env/nowieldmsg"))
	{
		return;
	}
	//filter messages before send to user
	//this can save network bandwidth but consume cpu
	//可以作为一个福利/奖励提供，呵呵。测试阶段，只提供一个filter
    
    //暂时删除，看看对性能影响如何
    /*
	if(!query_temp("force_receive_msg"))
	{
		pattern = query("env/msgfilter1");		

		if (sizeof(pattern) > 0 && sizeof(regexp(({msg}),filter_regexp(pattern))) > 0)
		{
			return;
		}
		
		pattern = query("env/msgfilter2");
		if (sizeof(pattern) > 0 && sizeof(regexp(({msg}),filter_regexp(pattern))) > 0)
		{
			return;
		}
		pattern = query("env/msgfilter3");
		if (sizeof(pattern) > 0 && sizeof(regexp(({msg}),filter_regexp(pattern))) > 0)
		{
			return;
		}
		pattern = query("env/msgfilter4");
		if (sizeof(pattern) > 0 && sizeof(regexp(({msg}),filter_regexp(pattern))) > 0)
		{
			return;
		}

		if(query("special_reward/msgfilter"))
		{
			pattern = query("env/msgfilter5");
			if (sizeof(pattern) > 0 && sizeof(regexp(({msg}),filter_regexp(pattern))) > 0)
			{
				return;
			}
		}
	}*/
	
    // 暂时删除，看看对性能影响如何
	//if ( stringp(msg) )
	//  msg = replace_string(msg,"法轮","氵去  车仑");

    if( in_input(this_object()) || in_edit(this_object()) || this_object()->query("disable_type") == "<睡梦中>" )
    {
        if( sizeof(msg_buffer) < MAX_MSG_BUFFER )
            msg_buffer += ({ msg });
    } else if(!this_object()->query("disable_type"))
    {
        if(strwidth(msg) < __LARGEST_PRINTABLE_STRING__) 
        {
            received_len = strwidth(msg);
            if(objectp(this_object()->query_temp("antirobot/snooper")))
            {
                this_object()->query_temp("antirobot/snooper")->receive_snoop(this_object(),msg);
            }
						if(query_temp("UTF8")) msg = gb_to_utf8(msg);
            receive(msg);
        }
        else {
            while(strwidth(msg) > 0) {
                received_len += __LARGEST_PRINTABLE_STRING__;
                if(objectp(this_object()->query_temp("antirobot/snooper")))
                {
                    this_object()->query_temp("antirobot/snooper")->receive_snoop(this_object(),msg);
                }
								if(query_temp("UTF8"))
								{
									receive(gb_to_utf8(msg[0..__LARGEST_PRINTABLE_STRING__ - 1]));
								}
								else
								{
									receive(msg[0..__LARGEST_PRINTABLE_STRING__ - 1]);
								}
                msg = msg[__LARGEST_PRINTABLE_STRING__..];
            }
        }
    }
    //统计玩家流量
    if(received_len)
    {
        "/adm/daemons/bandwidthd"->add_traffic(received_len);
        this_object()->add_temp("stat_traffic/send_bytes",received_len);    
        if(!this_object()->query_temp("stat_traffic/last_time"))
        {
            this_object()->set_temp("stat_traffic/last_time",time());
        }
        else 
        {
            if(time() - this_object()->query_temp("stat_traffic/last_time") > 60)
            {
                this_object()->set_temp("stat_traffic/last_bw",this_object()->query_temp("stat_traffic/send_bytes")/(time() - this_object()->query_temp("stat_traffic/last_time")));                
                this_object()->set_temp("stat_traffic/last_time",time());
                this_object()->set_temp("stat_traffic/send_bytes",0);                
            }
        }
    }
}

void write_prompt()
{
    if( !living(this_object()) ) return;
    if( msg_buffer != ({}) ) {
			if(query_temp("UTF8"))
				receive(gb_to_utf8(BOLD "[临时存储讯息]\n" NOR));
			else
				receive(BOLD "[临时存储讯息]\n" NOR);
	for(int i=0; i<sizeof(msg_buffer); i++)
			{
				if(query_temp("UTF8")) msg_buffer[i] = gb_to_utf8(msg_buffer[i]); 
				receive(msg_buffer[i]);
			}
	msg_buffer = ({});
    }
if ( wizardp(this_object()) && (query("env/prompt") == "path")  )
    {
	string prompt;
	if ( !stringp(query("cwd")) ) prompt = "";
	else prompt = (string)query("cwd")[0..<2];
	if(query_temp("UTF8"))
			{
				receive(gb_to_utf8(prompt + "> "));
			}
			else
			{
				receive(prompt + "> ");
			}
    }
    else
	{
			if(query_temp("UTF8"))
		  	receive(gb_to_utf8("> "));
			else
				receive(("> "));
	}
}

void receive_snoop(string msg)
{
	if(query_temp("UTF8"))
    receive(gb_to_utf8("%" + msg));
	else
		receive("%" + msg);
}

//只支持*一种，而且被替换为.+
string filter_regexp(string pattern)
{
	pattern = replace_string(pattern,".","");
	pattern = replace_string(pattern,"^","");
	pattern = replace_string(pattern,"$","");
	pattern = replace_string(pattern,"\"","");
	pattern = replace_string(pattern,"'","");
	pattern = replace_string(pattern,"[","");
	pattern = replace_string(pattern,"]","");
	pattern = replace_string(pattern,"(","");
	pattern = replace_string(pattern,")","");
	pattern = replace_string(pattern,"+","");
	pattern = replace_string(pattern,"?","");
	pattern = replace_string(pattern,"-","");
	pattern = replace_string(pattern,"*",".+");
	return pattern;
}