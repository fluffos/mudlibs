// yunv-xinfa.c 玉女心法

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int query_neili_improve(object me)
{
	int lvl;

	lvl = (int)me->query_skill("yunv-xinfa", 1);
	return lvl * lvl * 15 * 6 / 100 / 200;
}

int valid_learn(object me)
{
	if ( me->query("gender") == "无性")
		return notify_fail("你无根无性，阴阳难调，不能修习玉女心法。\n");

	if ((int)me->query_skill("force", 1) < 30)
		return notify_fail("你的基本内功火候还不够。\n");

	return ::valid_learn(me);
}

int practice_skill(object me)
{
	return notify_fail("玉女心法只能用学(learn)来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"yunv-xinfa/" + func;
}
