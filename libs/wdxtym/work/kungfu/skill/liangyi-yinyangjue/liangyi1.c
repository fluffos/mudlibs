// powerup.c 阴阳道经加力

#include <ansi.h>

inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

string query_name() { return "阴阳"ZJBR"战意"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
   	int skill;

   	if (target != me)
   		return notify_fail("你只能用阴阳道经来提升自己的战斗力。\n");

   	if ((int)me->query("neili") < 1000)
   		return notify_fail("你的内力不够。\n");

   	if ((int)me->query_temp("powerup"))
   		return notify_fail("你已经在运功中了。\n");

   	skill = me->query_skill("liangyi-yinyangjue")+500;
	me->add("neili", -1000);
   	me->receive_damage("qi", 50);
   	message_combatd(HIY "$N" HIY "微一凝神，运起阴阳道经，全身灌满真气，衣裳无风自舞，气势迫人。"NOR"\n", me);
	me->add_temp("apply/attack", skill *5 / 2);
	me->add_temp("apply/parry", skill *5 / 2);
	me->add_temp("apply/dodge", skill *5 / 2);
	me->add_temp("apply/unarmed", skill *5 / 2);
	me->add_temp("apply/strike", skill *5 / 2);
	me->add_temp("apply/sword", skill *5 / 2);
	me->add_temp("apply/blade", skill *5 / 2);
	me->add_temp("apply/cuff", skill *5 / 2);

	me->set_temp("powerup", 1);

	me->start_call_out( (: call_other, __FILE__, "remove_effect", me, skill :), skill);

	if (me->is_fighting()) me->start_busy(3);

	return 1;
}

void remove_effect(object me, int amount)
{
	if ((int)me->query_temp("powerup"))
	{
		me->add_temp("apply/attack", - (amount *5 / 2));
		me->add_temp("apply/parry", - (amount *5 / 2));
		me->add_temp("apply/dodge", - (amount *5 / 2));
		me->add_temp("apply/unarmed", - (amount *5 / 2));
		me->add_temp("apply/strike", - (amount *5 / 2));
		me->add_temp("apply/sword", - (amount *5 / 2));
		me->add_temp("apply/blade", - (amount *5 / 2));
		me->add_temp("apply/cuff", - (amount *5 / 2));

		me->delete_temp("powerup");
		tell_object(me, "你的阴阳道经运行完毕，将内力收回丹田。\n");
	}
}
