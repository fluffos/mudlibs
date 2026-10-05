
// fengyun.c

#include <ansi.h>

int exert(object me)
{
	int skill;
        skill = (int)me->query_skill("emeiforce",1);

	if (me->query_condition("linji_fengyun"))
		return notify_fail("你已经在运风云庄了！\n");


	if( me->is_fighting() )
		return notify_fail("战斗中无法运风云庄！\n");

        if( (int)me->query("force") < 400)
		return notify_fail("你的真气不够。\n");

        if( (int)me->query_skill("emeiforce",1) < 120)
                return notify_fail("你的峨嵋心法级别不够。\n");

        if( (int)me->query("sen") < (int)me->query("max_sen") / 2 )
                return notify_fail( "你已经受伤过重，无法运功！\n");

	message_vision(
HIC "$N坐了下来运起风云庄，缓缓将内力运到脚心涌泉穴，....\n"
"稍许，觉得一股暖流自足底涌汹涌而上，顿时觉得身轻如燕，跃跃欲飞。\n" NOR, me );
	me->apply_condition("linji_fengyun", (int)skill/20);
        me->add("force", -400);
        me->add("sen", -20);
	me->add("dex", (int)skill/20);
	me->set("linji/dex", (int)skill/30);
	return 1;
}

