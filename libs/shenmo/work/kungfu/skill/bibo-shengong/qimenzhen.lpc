// maze.c 奇门八卦迷阵

#include <ansi.h>

inherit F_SSERVER;

void remove_effect(object me, object target, int count, int skill);

int exert(object me)
{
        string msg;
object target;
	int skill;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("奇门五转只能对战斗中的对手使用。\n");

	if( (int)me->query("neili") < 80  ) 
		return notify_fail("你的内力不够。\n");
	if( (int)me->query_skill("qimen-wuxing",1) < 250  ) 
		return notify_fail("你的奇门五行不够。\n");

	if( (int)me->query_temp("thd/maze") > 2 ) 
		return notify_fail("你的能力只能布三个迷阵。\n");

if (!userp(target))
		return notify_fail("只能对玩家使用!\n");
	skill = me->query_skill("qimen-wuxing", 1);
	me->add("neili", -580);
        msg = HIG "$N脸上青气大盛，脚下缓缓踩着九宫八卦方位，头顶冒出腾腾白气，";
        msg += "四面隐隐传来潮涌之声，碧涛玄功已发挥到极致！\n"NOR;

	message_vision(
	HIC "$N一边作战，一边利用周围的石块、树枝等布了一个简单的阵。\n" NOR, me);
if (random(me->query("combat_exp")) > target->query("combat_exp")/4)
{
	message_vision(
	HIC "$N心中一迷，只觉腾云一般，不知走到哪里去了!\n" NOR, target);
	if (random(12)==0)
	target->move("/d/sdxl/linhai5");
	else if (random(12)==1)
	target->move("/d/jqg/hc4");
	else if (random(12)==2)
	target->move("/d/taohua/tao0");
	else if (random(12)==3)
	target->move("/d/feitian/senlin1");
	else if (random(12)==4)
	target->move("/d/feitian/shulin2");
	else if (random(12)==5)
	target->move("/d/shaolin/bamboo3");
	else if (random(12)==6)
	target->move("/d/shaolin/bagua3");
	else if (random(12)==7)
	target->move("/d/xingxiu/silk2");
	else if (random(12)==8)
	target->move("/d/xingxiu/shamo4");
	else if (random(12)==9)
	target->move("/d/gaochang/shulin12");
	else if (random(12)==10)
	target->move("/d/gumu/shulin4");
	else if (random(12)==11)
	target->move("/d/meizhuang/senlin7");
	else
	target->move("/d/taohua/tao0");
	me->add_temp("thd/maze", 1);
        message_vision(msg, me);
}
else 
	message_vision(
	HIC "$N大吃一惊，知道其中历害，远远跳出了迷阵。\n" NOR, me);
	target->start_busy(6);
	if( me->is_fighting() ) me->start_busy(2);

	return 1;
}

