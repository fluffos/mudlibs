// hup.c 天人化生



inherit F_CLEAN_UP;

string query_name() { return "天人化生"; }
string *pfm_type() { return ({ "force", }); }

int exert(object me, object target)
{
	int skill;
	string msg;
	mapping my;
	int rp;
	int neili_cost;
/*
	if (userp(me) && ! me->query("can_perform/kuihua-shengong/tian"))
		return notify_fail("你还没有通晓天人化生的奥秘。\n");
*/
	if (target != me)
		return notify_fail("你只能用天人化生来为自己疗伤。\n");
	if (userp(me)) {
		if (!me->query("special_skill/ghost"))
			return notify_fail("你没有鬼脉属性，无法运用天人化生。\n");
		if ((int)me->query_skill("kuihua-shengong", 1) < 200)
			return notify_fail("你的葵花神功不够深厚，无法使用天人化生。\n");
		if ((int)me->query_skill("force", 1) < 200)
			return notify_fail("你的葵花神功不够深厚，无法使用天人化生。\n");
	}
	if ((int)me->query("neili") < 200) 
		return notify_fail("你现在的真气不够。\n");

	my = me->query_entire_dbase();
	if ((rp = (my["max_qi"] - my["eff_qi"])) < 1)
		return (SKILL_D("force") + "/recover")->exert(me, target);

	if (rp >= my["max_qi"] / 10)
		rp = my["max_qi"] / 10;

	skill = me->query_skill("force");
	msg = HIY "$N" HIY "脸色不断变化，慢慢的恢复了些血色。"NOR"\n";
	message_combatd(msg, me);

	neili_cost = rp + 100;
	if (neili_cost > my["neili"])
	{
		neili_cost = my["neili"];
		rp = neili_cost - 100;
	}
	rp = rp *60 /100; //为周天功hup.c的效果60% by luoyun 2018.5.21
	me->receive_curing("qi", rp);
	me->receive_heal("qi", rp * 3 / 2);
	me->add("neili", -neili_cost);

	me->start_busy(3);
	return 1;
}
