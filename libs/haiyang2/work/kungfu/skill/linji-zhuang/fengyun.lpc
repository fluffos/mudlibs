// fengyun.c

#include <ansi.h>

int exert(object me)
{
	int skill;
	skill = (int)me->query_skill("linji-zhuang",1);

	if (me->query_temp("linji/dex"))
		return notify_fail("你已经在运风云庄了！\n");


	if( me->is_fighting() )
		return notify_fail("战斗中无法运风云庄！\n");

	if( (int)me->query("neili") < 400)
		return notify_fail("你的真气不够。\n");

	if( (int)me->query_skill("linji-zhuang",1) < 120)
		return notify_fail("你的临济庄级别不够。\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail( "已经受伤过重，无法运功！\n");

	message_vision(
HIC "$N坐了下来运起风云庄，缓缓将内力运到脚心涌泉穴，....\n"
"稍许，觉得一股暖流自足底涌汹涌而上，顿时觉得身轻如燕，跃跃欲飞。\n" NOR, me );
//	me->apply_condition("linji_fengyun", (int)skill/20);
	me->add("neili", -400);
	me->add("jing", -20);
        me->add_temp("apply/dexerity",skill/20);
//        me->add("dex", (int)skill/20);
	me->set_temp("linji/dex", (int)skill/30);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), (int)skill/10 );
	return 1;
}

void remove_effect(object me)
{
 	int skill;
	skill = (int)me->query_skill("linji-zhuang",1);
		tell_object(me, 
HIB "忽然你觉得一股浊气自腰间猛向下沉去，顿时双足如灌铅般沉
重，原来你的风云庄收功了！\n" NOR );
        me->add_temp("apply/dexerity",-skill/20);
		me->delete_temp("linji/dex");
}