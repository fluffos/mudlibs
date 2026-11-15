// powerup.c



inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

string query_name() { return "葵花真气"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
	int skill;

	if (target != me)
		return notify_fail("你只能用葵花真气提升自己的战斗力。\n");
	
	if (userp(me) && !me->query("special_skill/ghost"))
		return notify_fail("你没有鬼脉属性，无法运用葵花真气。\n");
	
	if ((int)me->query("neili") < 100)
		return notify_fail("你的真气不够！\n");

	if (userp(me) && me->query_skill("kuihua-shengong", 1) < 120)
		return notify_fail("你的葵花神功修行不够，难以运功。\n");

	if ((int)me->query_temp("powerup"))
		return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("force");

	me->add("neili", -100);
	me->receive_damage("qi", 0);

	message_combatd(HIR "$N" HIR "身形忽然变得诡秘异常，进退"
			"之间飘忽不定，令人无从捉摸。"NOR"\n", me);

	me->add_temp("apply/attack", (skill / 3) *150 /100);
	me->add_temp("apply/dodge", (skill * 2 / 5) *150 /100);
	me->set_temp("powerup", 1);

	me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill :), skill);

	if (me->is_fighting()) me->start_busy(3);

	return 1;
}

void remove_effect(object me, int level)
{
	if ((int)me->query_temp("powerup"))
	{
		me->add_temp("apply/attack", -(level / 3) *150 /100);
		me->add_temp("apply/dodge", -(level * 2 / 5) *150 /100);
		me->delete_temp("powerup");
		tell_object(me, "你的葵花真气运行完毕，将内力收回丹田。\n");
	}
}

