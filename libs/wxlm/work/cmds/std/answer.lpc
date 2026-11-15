// reply.c


#include <net/dns.h>

inherit F_CLEAN_UP;

int help(object me);

int main(object me, string arg)
{
	string target;
	string st;
	object obj;
	object env;
	mixed info;

	if (! arg || arg == "")
		return notify_fail("你要回答什么？\n");

	obj = 0;
	if (sscanf(arg, "%s %s", st, arg) == 2 &&
	    ! objectp(obj = present(st, environment(me))))
	{
		arg = st + " " + arg;
	}

	env = environment(me);
	if (info = env->query("no_say"))
	{
		if (stringp(info))
		{
			write(info);
			return 1;
		}

		write("这个地方不能讲话。\n");
		return 1;
	}

	if (! stringp(target = me->query_temp("ask_you")))
		return notify_fail("刚才没有人向你询问。\n");

	if (me->ban_say(1))
		return 0;

	if (objectp(obj) && ! playerp(obj) && ! obj->is_chatter())
		obj = 0;
	if (! obj) obj = find_player(target); 
	if (! obj) obj = MESSAGE_D->find_user(target); 

	if (! obj)
		return notify_fail("刚才向你询问的人现在无法听见你，或者已经离开游戏了。\n");

	if (environment(obj) != environment(me))
		return notify_fail("刚才向你询问的人现已不在这里了。\n");

	message_vision(CYN "$N" CYN "回答$n" CYN "：『" HIG + arg + NOR CYN "』"NOR"\n", me, obj);

	if (userp(obj) || obj->is_chatter())
	{
		obj->set_temp("ask_you", me->query("id"));
		return 1;
	}

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式：answer [ <player> ] <讯息>

你可以用这个指令和刚才用 ask 和你说话的使用者说话，如果
指明了玩家则回答指定的玩家。

see also : tell
HELP
	);
	return 1;
}
