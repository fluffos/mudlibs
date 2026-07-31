// bibo-shengong.c 碧波神功
// By Jungu

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int query_neili_improve(object me)
{
    int lvl;

    lvl = (int)me->query_skill("bibo-shengong", 1);
    return lvl * lvl * 15 * 10 / 100 / 200;
}

int valid_force(string force)
{
    return (force == "luoying-xinfa");
}

int valid_learn(object me)
{
	int lvl = (int)me->query_skill("bibo-shengong", 1);

	if (me->query("gender") == "无性" && lvl > 49)
		return notify_fail("你无根无性，阴阳不调，难"
				   "以领会高深的碧波神功。\n");

	if (me->query_skill("chuixiao-jifa", 1) < 100)
		return notify_fail("你没有精通吹箫技法，无法"
				   "领会碧波神功的奥秘。\n");
       if (me->query_skill("force",1) <= me->query_skill("bibo-shengong",1) )
	return notify_fail("你的基本内功不够，无法领会更高深的碧波神功。\n");

	return ::valid_learn(me);
}

int practice_skill(object me)
{
    return notify_fail("碧波神功只能用学的，或是从运用(exert)中增加熟练度。\n");
}

string exert_function_file(string func)
{
    return __DIR__"bibo-shengong/" + func;
}
