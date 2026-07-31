// wudu-shengong
// By netkill

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	int lvl = (int)me->query_skill("wudu-shengong", 1);
	int t = 1, j;
	if (lvl<=100)
		for (j = 1; j < lvl / 10; j++)
			t*=2;

	
	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候还不够。\n");
	
	if(lvl<=100)
	{
		if (lvl > 10 && (int)me->query("shen") > -t * 100) 
			return notify_fail("心怀仁慈是练不好五毒神功的。\n");
	}
	else
	{
		if ((int)me->query("shen") > -(51200 + (lvl - 100) * 1000)) 
			return notify_fail("不心狠手辣，如何能修炼五毒神功。\n");
	}

	
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("五毒神功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"wudu-shengong/" + func;
}

