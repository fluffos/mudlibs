// gui.c 鬼魅身法



inherit F_CLEAN_UP;
void remove_effect(object me, int amount);

string query_name() { return "鬼魅"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
	string msg;
	int skill;

	if (target != me)
		return notify_fail("你只能用鬼魅来提升自己的身法。\n");
	
	if (userp(me) && !me->query("special_skill/ghost"))
		return notify_fail("你没有鬼脉属性，无法运用「鬼魅」。\n");
	
	if (userp(me) && me->query_skill_mapped("force") != "kuihua-shengong")
		return notify_fail("你没有激发葵花神功为内功，难以施展「鬼魅」。\n");
			
	if (userp(me) && (int)me->query_skill("kuihua-shengong", 1) < 150)
		return notify_fail("你的葵花神功火候不够，不会使用鬼魅。\n");

	msg = HIR "$N" HIR "身子忽进忽退，身形诡秘异常，行踪飘忽不定。"NOR"\n";

	if ((int)me->query_temp("guimei"))
		return notify_fail("你已经在运功中了。\n");

	skill = me->query_skill("kuihua-shengong", 1);
	me->add("neili", -100);
	me->receive_damage("qi", 0);

	message_combatd(msg, me);

	me->add_temp("apply/dodge", skill/20);
	me->set_temp("guimei", 1);

	me->start_call_out((: call_other, __FILE__, "remove_effect", me, skill :), skill);

	if (me->is_fighting()) me->start_busy(2);

	return 1;
}

void remove_effect(object me, int amount)
{
        if (!me) return;

	me->add_temp("apply/dodge", -(amount/20));
	me->delete_temp("guimei");
	tell_object(me, "你的鬼魅运行完毕，将内力收回丹田。\n");
}

