// xiantian-gong.c 先天功
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_force(string force)
{
	return force == "duanshi-xinfa" ||
	       force == "quanzhen-xinfa";
}

int query_neili_improve(object me)
{
	int lvl;

	lvl = (int)me->query_skill("xiantian-gong", 1);
	return lvl * lvl * 15 * 17 / 100 / 200;
}

int valid_learn(object me)
{
	if (me->query("gender") == "无性" && (int)me->query_skill("xiantian-qigong", 1) > 49)
		return notify_fail("你无根无性，阴阳难调，无法学习更高深的先天功。\n");

	if ((int)me->query_skill("force", 1) < 110)
		return notify_fail("你的基本内功火候还不够。\n");

	if ((int)me->query_skill("taoism", 1) < 100)
		return notify_fail("你对道家心法领悟的太浅，无法理解先天功。\n");

	if ((int)me->query_skill("taoism", 1) < 500 &&
	    (int)me->query_skill("taoism", 1) < (int)me->query_skill("xiantian-gong", 1))
		return notify_fail("你对道家心法领悟的有限，无法理解更高深先天功。\n");

	return ::valid_learn(me);
}

int practice_skill(object me)
{
	return notify_fail("先天功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"xiantian-gong/" + func;
}
