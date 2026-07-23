// zhixin.c

#include <ansi.h>

int exert(object me)
{
	int skill;
	skill = (int)me->query_skill("linji-zhuang",1);

	if (me->query_temp("linji/int"))
		return notify_fail("你已经在运之心庄了！\n");


	if( me->is_fighting() )
		return notify_fail("战斗中无法运之心庄！\n");

	if( (int)me->query("neili") < 200)
		return notify_fail("你的真气不够。\n");

	if( (int)me->query_skill("linji-zhuang",1) < 60)
		return notify_fail("你的临济庄级别不够。\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail( "已经受伤过重，无法运功！\n");

	message_vision(
HIY "$N坐了下来运起之心庄，将手掌在脑门上磕了两下，顿觉灵台清明，....\n"
"站了起来，发现脑袋瓜灵光了不少。\n" NOR, me );
//	me->apply_condition("linji_zhixin", (int)skill/20);
	me->add("neili", -200);
	me->add("eff_jing", -10);
	me->add("jing", -20);
        me->add_temp("apply/intelligence",skill/20);
	me->set_temp("linji/int", (int)skill/30);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), (int)skill/10 );
	return 1;
}

void remove_effect(object me)
{
 	int skill;
	skill = (int)me->query_skill("linji-zhuang",1);
		tell_object(me, 
HIB "忽然你头脑里感到一阵空白，原来你的之心庄收功了，你顿时
觉得自己还是个大笨木瓜！\n" NOR );
        me->add_temp("apply/intelligence",-skill/20);
		me->delete_temp("linji/int");
}
