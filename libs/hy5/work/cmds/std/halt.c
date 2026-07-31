#include <ansi.h>
// halt.c
// By Xiang@XKX (12/17/95)

int main(object me, string arg)
{
        object ob;
	if( arg && wizardp(me) ) {
		ob = present(arg, environment(me));
		if( !ob ) return notify_fail("没有这个生物。\n");
		if( !ob->is_fighting() ) return notify_fail(ob->name()+"现在不忙。\n");
		ob->remove_all_enemy();
                message_vision("\n$N用巫师的神力停止了$n的战斗。\n", me, ob);
		return 1;
	}

        if (me->query_condition("killer") && userp(me)) {
            message_vision("$N你正在被通辑，哪里跑?\n", me);
			return notify_fail("你逃跑失败。\n");
		}

    if(environment(me)->query("short")==BLU"山洞"NOR
       ||environment(me)->query("short")==WHT"钟乳石洞"NOR
       ||environment(me)->query("short")==YEL"岩洞"NOR
       ||environment(me)->query("short")==RED"熔岩洞"NOR
       ||environment(me)->query("short")==CYN"石洞"NOR
       ||environment(me)->query("magicset")==1
       ||environment(me)->query("maze")
       )
			return notify_fail("这个地方到处是路，你向哪里逃呢!\n");
if( environment(me)->query("magicroom"))
			return notify_fail("这个地方到处是路，你向哪里逃呢!\n");
        if (me->query_condition("huaxunshan") || me->query_condition("shaolin_song")|| me->query_condition("lingjiu_song")) {
            message_vision("$N你正在做任务不能乱跑,身上负有重责！\n", me);
			return notify_fail("你逃跑失败。\n");
		}
        if (present("letter", me)||present("biao",me)||present("prize",me)){
            message_vision("$N你身上有重要的任务物品,不能乱逃！\n", me);
			return notify_fail("你逃跑失败。\n");
		}
//        if ((int)me->query_temp("pending/exercise") != 0 && me->is_fighting()) {
//	        message_vision("$N把正在运行的真气强行压回丹田，站了起来。\n", me);
//                me->start_busy(3);
//		me->interrupt_me();
//	}

	if (!me->is_busy() && me->is_fighting()) {
		me->remove_all_enemy();
                message_vision("\n$N身行向后一跃，跳出战圈不打了。\n", me); 
if (me->query("combat_exp") >1000000 && !me->is_busy())
{
                me->start_busy(random(2));
}
		return 1;
	}
	else if ((int)me->query_temp("biguan") != 0) {
	        message_vision("$N在闭关中途突然复出，站了起来。\n", me);
                me->start_busy(1);
                me->set_temp("biguan", 0);
		            //me->interrupt_me();
                //me->force_me("quit");
	return 1;
	}
//	else if ((int)me->query_temp("pending/exercise") != 0) {
//	        message_vision("$N把正在运行的真气强行压回丹田，站了起来。\n", me);
//		me->interrupt_me();
//	}
	else if (!me->is_busy()) 
		return notify_fail("你现在不忙。\n");
	else if ((int)me->query_temp("pending/respirate") != 0)
		me->interrupt_me();
	me->interrupt_me();
        if (me->is_busy()) write("你现在很忙，停不下来。\n");
	return 1;
}

