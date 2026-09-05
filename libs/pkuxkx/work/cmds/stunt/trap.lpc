// trap.c
// zine@pkuxkx 2014/7/11
#include <ansi.h>
#include <skill.h>
#define interval 60
inherit F_CLEAN_UP;
int reset_trap(object me)
{
	if (me)
	{
		if (stringp(me->query_temp("stunt/trap/target")))
		tell_object(me,"等了很久，"+me->query_temp("stunt/trap/target")+"都没有过来。你略略放松了警惕。\n");
		else
		tell_object(me,"等了很久，都没有人过来。你略略放松了警惕。\n");
		me->delete_temp("stunt/trap/place");
		me->delete_temp("stunt/trap/target");
	}
	return 1;
}
int main(object me, string arg)
{
	int busy=0;
	if ((!me->query("StuntList")||!arrayp(me->query("StuntList"))||member_array("trap",me->query("StuntList"))==-1)
	&&!me->query("myVeins/足阳明胃经/completed"))
	return notify_fail("你还没有掌握trap绝技。\n");
	if (!environment(me))
	return notify_fail("都在这里了，还是老老实实待着吧。\n");
	if (me->is_busy())
	return notify_fail("你正忙着呢。还是先顾好自己吧。\n");
	if (time()<me->query_temp("stunt/trap/time"))
	return notify_fail("你刚刚使用过trap绝技，等等再用吧。\n");
	if (!arg||!stringp(arg))
	return notify_fail("你准备对谁使用trap绝技？\n");
	message_vision("$N准备好等在这里，要伏击"+arg+"。\n",me);
	if (!me->query_temp("stunt/trap/time")&&me->query("myVeins/足阳明胃经/completed"))
	{
		me->add_temp("apply/dodge",5);
		write(HIC"你运转内息在足阳明胃经之间，提升自己的躲闪效率。\n"NOR);
	}
	if ((me->query("StuntList")&&arrayp(me->query("StuntList"))&&member_array("trap",me->query("StuntList"))!=-1)
	||me->query("myVeins/足阳明胃经/completed")==2)
	busy=2;
	if (me->query("myVeins/足阳明胃经/completed")==3)
	busy=3+random(2);
	if (F_VEIN->query("/足阳明胃经/fastest/player")==me->query("id"))
	busy=5+random(4);
	me->set_temp("stunt/trap/time",time()+interval);
	me->set_temp("stunt/trap/target",arg);
	me->set_temp("stunt/trap/busy_time",busy);
	me->set_temp("stunt/trap/place",environment(me));
	call_out("reset_trap",interval,me);
	return 1;
}

int help(object me)
{
	tell_object(me,@HELP
指令格式 : trap <目标id>

拥有绝技trap或足阳明胃经通脉后可使用。
效果：让通过自己房间且小于自己经验150%的玩家
或NPC小幅度busy。
足阳明胃经通脉后，可小幅提升自身闪躲。
HELP
        );
	return 1;
}
