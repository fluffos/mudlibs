// whistle.c

#include <ansi.h>
inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object ob;
	string file;

	if (! arg)
		return notify_fail("你要召唤什么？\n");
			
	if (me->is_busy() || me->query("doing"))  
		return notify_fail("你现在正忙呢，等你有空了再说吧。\n");
 
	if (me->is_in_prison())   
		return notify_fail("你正在做牢呢，你想干什么？！\n"); 

	if (me->is_ghost())
		return notify_fail("等你还了阳再召唤吧。\n");

	if (! stringp(file = me->query("can_whistle/" + arg)))
		return notify_fail("你不知道如何召唤这个魔幻兽。\n");

	if (file_size(file + ".c") < 0)
		return notify_fail("你不知道如何召唤这个魔幻兽。\n");
	
	
//	if (me->query("beastdied"))
	//	return notify_fail("你的魔幻兽已经死亡，请用<recall reborn>让它先复活。\n");
	
	if (environment(me)->query("no_magic") || environment(me)->query("no_fly")) 
		return notify_fail("你发现这里有点古怪，你的魔幻兽好象不能进来！\n");    
	 
	call_other(file, "???");
	ob = find_object(file);

	if (! ob || ! ob->receive_whistle(me))
	{
	message_vision(HIM "$N" HIM "吹了一声口哨。\n"
			       "然而什么也没有发生 :)\n", me);
 }
	if (! ob) return 1;
	ob->reset_action();
	ob->set_leader(me);
	
	if (me->is_fighting())								     
		me->start_busy(1 + random(3));

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : whistle <魔幻兽ID>

此指令可让你把你的魔幻兽呼唤过来，当然你得有一定的精力施展才行。
HELP );
	return 1;
}



