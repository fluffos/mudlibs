// yijin-jing.c 少林 易筋经神功
// Feb.21 1998 by Java

inherit FORCE;

int valid_enable(string usage)
{
	return usage == "force";
}

int valid_learn(object me)
{
	int i,nf;
	nf = (int)me->query_skill("force", 1);

	if (me->query("combat_exp") < 1000000)
		return notify_fail("你的经验不够，无法理解易筋经内功深邃的涵义。\n");
	if ( nf < 200)
		return notify_fail("你的基本内功火候还不够，无法领会易筋经神功。\n");

	return 1;
}


int practice_skill(object me)
{
	return notify_fail("易筋经神功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"yijin-jing/" + func;
}

string query_yinyang()
{
	return "纯阳";
}