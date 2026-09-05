
// say.c
// Modified by iszt@pkuxkx, 2007-03-11, filter NOR & \n in msg, add 「」

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string tmp;

	if( me->query("silent") )
		return notify_fail("你不会说话呀！\n");
	if( me->query("chblk_on") )
		return notify_fail("STOP！你的聊天频道被关闭了！\n");

	if (!arg) {
		write("你自言自语不知道在说些什么。\n");
		message("sound", me->name() + "自言自语不知道在说些什么。\n",
			environment(me), me);
		return 1;
	}
	if( (int)me->query("qi") < (int)me->query("max_qi") / 5 ) {
		arg = replace_string(arg, " ", " ... ");
	}

	while(sscanf(arg, "%s"+NOR+"%s", arg, tmp))
		arg += ESC + "[0m" + CYN + tmp;
	while(arg != "" && arg[<1]=='\n')
		arg = arg[0..<2];

	message("sound",CYN "你说道：「" + arg + "」\n" NOR,me);

    message("sound", CYN + me->name() + CYN"说道：「" +  arg + CYN"」\n" NOR,
		environment(me), me);
	 //enable message logger to get bug information from users
	if (objectp(CHANNEL_D->query("logger")) && !me->query("no_logger"))
	{
		if ((userp(me) && userp(CHANNEL_D->query("logger"))) && (arg[0..3] != me->query_temp("logger/last_say_msg")) && (arg[0..3] != me->query_temp("logger/last_say_msg2")) || (strsrch(arg,"私人谈话")!=-1) )
			if (time()-me->query_temp("task/last_locate") > 10)
				tell_object(CHANNEL_D->query("logger"),sprintf(  "%s的%s说道："+HIM+"%s\n" NOR,
					environment(me)->query("short"),me->name(1)+"("+me->query("id")+")",arg));
		me->set_temp("logger/last_say_msg2",me->query_temp("logger/last_say_msg"));
		me->set_temp("logger/last_say_msg",arg[0..3]);
	}

	me->set_temp("last_say_message",arg);
	// The mudlib interface of say
	all_inventory(environment(me))->relay_say(me, arg);

	return 1;
}

int help (object me)
{
	write(@HELP
指令格式: say <讯息>
 
说话，所有跟你在同一个房间的人都会听到你说的话。
 
注: 本指令可用 ' 取代.
 
HELP
	);
	return 1;
}
