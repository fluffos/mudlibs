// tiandi.c

#include <ansi.h>

int exert(object me)
{
	int skill;
	skill = (int)me->query_skill("linji-zhuang",1);

	if (me->query_temp("linji/per"))
		return notify_fail("你已经在运天地庄了！\n");


	if( me->is_fighting() )
		return notify_fail("战斗中无法运天地庄！\n");

	if( (int)me->query("neili") < 100)
		return notify_fail("你的真气不够。\n");

	if( (int)me->query_skill("linji-zhuang",1) < 30)
		return notify_fail("你的临济庄级别不够。\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail( "已经受伤过重，无法运功！\n");

	message_vision(
HIM "$N坐了下来运起天地庄，将手掌贴在脸上，缓缓地将真气轻轻扑在脸上....\n"
"过了不久，$N的脸上亮出晶莹的颜色，缓缓睁开的眼里透出青春的气息。\n" NOR,
	me );
//	me->apply_condition("linji_tiandi", (int)skill/20);
	me->add("neili", -100);
	me->add("jing", -20);
	me->add("eff_jing", -10);
        me->add_temp("apply/percao",skill/20);
//	me->add("per", (int)skill/20);
	me->set_temp("linji/per", (int)skill/20);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), (int)skill/5 );
	return 1;
}

void remove_effect(object me)
{
 	int skill;
	skill = (int)me->query_skill("linji-zhuang",1);
		tell_object(me, 
HIB "忽然你心里头感到一阵失落，原来你的天地庄收功了，你顿时
倍感红颜老去之叹！\n" NOR );
        me->add_temp("apply/percao",-skill/20);
		me->delete_temp("linji/per");
}