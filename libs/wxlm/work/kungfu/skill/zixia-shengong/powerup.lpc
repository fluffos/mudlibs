// powerup.c



inherit F_CLEAN_UP;

void remove_effect(object me, int amount);

string query_name() { return "紫霞"ZJBR"真气"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
	int skill;
	int num;

	if (target != me)
		return notify_fail("你只能用紫霞神功提升自己的战斗力。\n");

	if ((int)me->query("neili") < 100)
		return notify_fail("你的内力不够。\n");
	
	if ((int)me->query_skill("zixia-shengong") < 10)
		return notify_fail("你的紫霞神功等级不够10级。\n");

	if ((int)me->query_temp("powerup"))
		return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("force");

	me->add("neili", -100);

	message_combatd(MAG "$N" MAG "微一凝神，运起紫霞神功，背转"
			"身去，脸上突然紫气大盛！只是那紫气一现即隐，\n"
			"转过身来，脸上又回复如常。"NOR"\n", me);
	
	//在原来的基础上提升了20%左右威力
	//by luoyun 2018.5.14
	num = skill /3;
	num += num *2 /10;
	
	me->add_temp("apply/attack", num);
	//me->add_temp("apply/armor", skill / 3);
	me->add_temp("apply/defense", num);
	me->set_temp("powerup", 1);
	me->start_call_out((: call_other, __FILE__, "remove_effect", me, num :), skill);
	if (me->is_fighting()) me->start_busy(3);
	return 1;
}

void remove_effect(object me, int amount)
{

        if (!me) return;

	if (me->query_temp("powerup"))
	{
		me->add_temp("apply/attack", -amount);
	        //me->add_temp("apply/armor", -amount);
		me->add_temp("apply/defense", -amount);
		me->delete_temp("powerup");
		tell_object(me, "你的紫霞神功运行完毕，将内力收回丹田。\n");
	}
}
