//taiyi-shengong.c	太乙神功
//desighed for newbie training
//by zoom
//2003.4.6

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
        if ((int)me->query_skill("force", 1) < 5)
                return notify_fail("你的基本内功火候不足，不能学太乙神功。\n");
	if ((int)me->query_skill("taiyi-shengong", 1)>20)
                return notify_fail("你的太乙神功已经无法再提高了。\n");		
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("太乙神功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"taiyi-shengong/" + func;
}
