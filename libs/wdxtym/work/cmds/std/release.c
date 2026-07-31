// fang.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;

	if (! arg)
		return notify_fail("你要和谁脱离关系？\n");

	if (! objectp(ob = present(arg, environment(me))))
		return notify_fail("你要和谁脱离关系？\n");

	if (ob->query_temp("owner") != me)
		return notify_fail("你并不是" + ob->name() + "的主人啊，发什么话？\n");

	if (ob->query("can_speak"))
		message_vision("$N道：走吧，" + ob->name() +
			       "，你走吧。\n", me, ob);
	else
		message_vision("$N很慈悲地把$n放离，任其回归自然了。\n", me, ob);

	if (me->query_temp("comedby") == ob)
		me->delete_temp("comedby");

	ob->delete_temp("owner");
	ob->delete_temp("owner_id");
	ob->delete_temp("owner_name");
	ob->set_leader(0);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : release <对象>

此指令可用于让你的跟随者或是驯养的动物结束主奴状态。

HELP );
	return 1;
}
