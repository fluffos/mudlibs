// message.c
// modify by Yu Jue 1998-3-5

#include <ansi.h>
#include <dbase.h>

//#define MAX_STRING_SIZE                 8000
#define MAX_MSG_BUFFER 500

static string *msg_buffer = ({});

void receive_message(string msgclass, string msg)
{
        string subclass, *ch;
	object me = this_object();
	int len;
	if (!stringp(msg)) return;
	if(!msg || (len=strlen(msg))<1) return;
	//added by mon 11/13/97 trying to prevent crash.

	if(len>8000) 
	  msg=msg[0..8000]+"\n\n．．．\n";
	  //added by mon 11/13/97 trying to prevent crash.

	msg = CONVERT_D->output(msg,this_object());
//	if( !userp(me) ) {
//		me->relay_message(msgclass, msg);
//		return;
//	}
//        if( userp(me) && !environment(me))
//        return;
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


	if( query_temp("block_msg/all") || query_temp("block_msg/" + msgclass) )
		return;

//    if (query_temp("big5")) msg = "/adm/daemons/gb_b5d"->gb_b5(msg);

    if( in_input(me) || in_edit(me) ) {
		if( sizeof(msg_buffer) < MAX_MSG_BUFFER )
			msg_buffer += ({ msg });
	} else
//                while (strlen(msg) > MAX_STRING_SIZE)
//                {
//                        receive(msg[0..MAX_STRING_SIZE - 1]);
//                        msg = msg[MAX_STRING_SIZE..<1];
//                }
		receive( msg );
}

void write_prompt()
{
	int env;
	string prompt;
	object me;
        string msg = "[输入时暂存讯息]\n" ;
        string cwd = this_object()->query("cwd");
	me=this_player(1);

        msg = CONVERT_D->output(msg,this_object());


        if( sizeof(msg_buffer) ) {
                receive(BOLD + msg + NOR);
                for(int i=0; i<sizeof(msg_buffer); i++)
                        receive(msg_buffer[i]);
                msg_buffer = ({});
        }
        if (!me) return;
	if(intp(me->query("env/prompt")))
	{
		env=(int)me->query("env/prompt");
		switch(env)
		{
		case 1:
			env=(int)me->query("env/time_format");
			prompt=HIY"["+HIW+
				"/cmds/usr/rtime"->chinese_time(env,(string)localtime(time()))
				+HIY"]"NOR;
			break;
		case 2:
			if(!stringp(prompt=me->query_temp("reply")))
				prompt="c:\\> ";
			else
				prompt=HIY"["+HIW+prompt+HIY"]"NOR;
			break;
		case 3:
			prompt=HIY"["+HIW+"气:"+me->query("qi")+"|精:"+me->query("jing")+HIY"]"NOR;
			break;
		case 4:
			prompt=HIY"["+HIW+"气:"+me->query("qi")+"|精:"+me->query("jing")+
				"|经验:"+me->query("combat_exp")+"|潜能:"+
				((int)me->query("potential") - (int)me->query("learned_points"))+
				HIY"]"NOR;
			break;
		default:
			if(!stringp(prompt))
				prompt=HIB"⊙"NOR;
		}
	}
	else
		prompt=me->query("env/prompt");
	write(prompt);
}

void receive_snoop(string msg)
{
        msg = CONVERT_D->output(msg,this_object());
	receive("%" + msg);
}
