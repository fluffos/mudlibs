//jiuyin-shenggong.c
//changed by lianxing

inherit FORCE;

int valid_enable(string usage) 
{ 
   return usage == "force"; 
}

int valid_learn(object me)
{
	if ( ((int)me->query_skill("riyue-shengong", 1)) < 100 )
		return notify_fail("你的日月神功火候还不够，无法领会葵花神功。\n");
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("葵花神功只能用学(learn)或读来增加熟练度。\n");
}

string exert_function_file(string func)
{
       return SKILL_D("kuihua-shengong/") + func;
}

string query_yinyang()
{
	return "纯阴";
}

