// kurong-shengong.c 枯荣神功
// by jackyboy@cctx

inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me)
{
	int lvl = (int)me->query_skill("kurong-shengong", 1);

	if ( me->query("gender") == "无性" && lvl > 49)
		return notify_fail("你无根无性，阴阳不调，难以领会高深的枯荣神功。\n");
	if ( me->query_skill("force",1)<100)
		return notify_fail("你的基本内功火候不到，无法练习枯荣神功。\n");
	if ( me->query_skill("tianlong-shengong",1)<40)
		return notify_fail("枯荣神功是以天龙神功为基础的，你必须先练好天龙神功。\n");
	return 1;
}

int practice_skill(object me)
{
    return notify_fail("枯荣神功只能用学的，或是从运用(exert)中增加熟练度。\n");
}

