//jiuyang-shenggong.c
//changed by fast

inherit FORCE;

int valid_enable(string usage) 
{ 
   return usage == "force"; 
}


int valid_learn(object me)
{
	if ( ((int)me->query_skill("shenghuo-xinfa", 1)) < 100 )
		return notify_fail("你的圣火心法火候还不够，无法领会九阳神功。\n");
	return 1;
}


int practice_skill(object me)
{
return notify_fail("九阳神功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
       return SKILL_D("jiuyang-shengong/") + func;
}

string query_yinyang()
{
	return "纯阳";
}
