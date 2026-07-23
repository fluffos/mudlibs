// longhe.c

#include <ansi.h>

int exert(object me)
{
	int skill;
	skill = (int)me->query_skill("linji-zhuang",1);

	if (me->query_temp("linji/con"))
		return notify_fail("你已经在运龙鹤庄了！\n");


	if( me->is_fighting() )
		return notify_fail("战斗中无法运龙鹤庄！\n");

	if( (int)me->query("neili") < 300)
		return notify_fail("你的真气不够。\n");

	if( (int)me->query_skill("linji-zhuang",1) < 90)
		return notify_fail("你的临济庄级别不够。\n");

	if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
		return notify_fail( "已经受伤过重，无法运功！\n");

	message_vision(
HIR "$N坐了下来运起龙鹤庄，把全身上下拍打了一遍，觉得全身充满力量，....\n"
"就想发泄出去，和谁过过招一样。\n" NOR, me );
//	me->apply_condition("linji_longhe", (int)skill/20);
	me->add("neili", -300);
	me->add("eff_jing", -15);
	me->add("jing", -20);
        me->add_temp("apply/constitution",skill/20);
//	me->add("con", (int)skill/25);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me :), (int)skill/10 );
	me->set_temp("linji/con", (int)skill/30);
	return 1;
}

void remove_effect(object me)
{
 	int skill;
	skill = (int)me->query_skill("linji-zhuang",1);
		tell_object(me, 
HIB "忽然你觉得全身懒洋洋的，连个小指头也不想动了，原来你的
龙鹤庄收功了！\n" NOR );
        me->add_temp("apply/constitution",-skill/20);
		me->delete_temp("linji/con");
}