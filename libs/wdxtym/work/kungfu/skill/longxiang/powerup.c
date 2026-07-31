// powerup.c 龙相功加力

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

string query_name() { return "龙象"ZJBR"之力"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
	int skill;

	if( target != me )
		return notify_fail("你只能提升自己的战斗力。\n");

	if( (int)me->query("neili") < 200)
		return notify_fail("你的真气不够。\n");

	if( (int)me->query_temp("powerup"))
		return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("force");

	message_vision(HIR "$N" HIR "大喝一声，全身骨骼节节暴响，一股迅猛的罡气向四周扩散开来！"NOR"\n", me);

	if(me->query_skill("longxiang",1)>=300)
	{
		me->add_temp("apply/damage", skill / 5);
		me->add_temp("apply/unarmed_damage", skill / 5);
		me->set_temp("lx_damage", 1);
	}
	me->add_temp("apply/attack", (skill / 3) + 50);
	me->add_temp("apply/parry", skill / 3);
	me->add_temp("apply/dodge", skill / 3);
	me->set_temp("powerup", 1);
	me->add("neili", -100);

	me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill :), skill);

	if (me->is_fighting()) me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
        if (!me) return;

	if ((int)me->query_temp("powerup"))
	{
		if(me->query_temp("lx_damage"))
		{
			me->add_temp("apply/damage", -amount / 5);
			me->add_temp("apply/unarmed_damage", -amount / 5);
			me->delete_temp("lx_damage", 1);
		}
		me->add_temp("apply/attack", -amount/3 - 50);
		me->add_temp("apply/parry", -amount/3);
		me->add_temp("apply/dodge", -amount/3);
		me->delete_temp("powerup");
		tell_object(me, "你的龙象般若功运行完毕，将内力收回丹田。\n");
	}
}
