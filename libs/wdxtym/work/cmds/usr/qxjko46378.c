// flyto.c

#include <ansi.h>
#include <command.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	string home;
	object obj;
	string msg;
	
	if (! arg) return notify_fail("你要飞到哪儿去？\n");

	obj = MESSAGE_D->find_user(arg);
	if (! obj) obj = find_living(arg);
	if (! obj || ! me->visible(obj))
		return notify_fail("没有这个玩家或生物。\n");
		
	if (environment(me)->query("fuben2"))
		return notify_fail("你在副本内不可使用该指令。\n");	
			
	if (me->is_busy())
		return notify_fail("你正忙著呢。\n");

	if (me->is_ghost()) 
		return notify_fail("等你还了阳再说吧。\n"); 
		
	if (me->is_in_prison())   
		return notify_fail("你正在做牢呢。\n");

	if (! me->query("born"))
		return notify_fail("你还没有出生呢！\n");

	if (me->query("doing"))
		return notify_fail("你还想干什么？！\n");
				
	while (obj && obj->is_character())
		obj = environment(obj);

	if (obj == environment(me))
		return notify_fail("不就在你面前么？乱飞个啥？\n");

	if (! obj) return notify_fail("这个物件没有环境可以 flyto。\n");
	if (! me->query("env/invisible"))
		message("vision", me->name() + "轻飘飘的飞了起来。\n",
			environment(me), ({ me }));
	tell_object(me, "到了？到了！降落喽！！！\n");
	if (! me->query("env/invisible"))
		message("vision", me->name() + "从天上慢慢的落了下来。\n", obj);
	me->move(obj);
	return 1;
}
