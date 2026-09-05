//jiuyin-shenggong.c
//changed by lianxing

inherit FORCE;

int valid_enable(string usage) 
{ 
   return usage == "force"; 
}

int valid_learn(object me)
{
	if ( ((int)me->query_skill("force", 1)) < 150 )
		return notify_fail("你的基本内功火候还不够，无法领会九阴神功。\n");
	return 1;
}

int practice_skill(object me)
{
return notify_fail("九阴神功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"jiuyin-shengong/" + func;
}

string query_yinyang()
{
	return "纯阴";
}
