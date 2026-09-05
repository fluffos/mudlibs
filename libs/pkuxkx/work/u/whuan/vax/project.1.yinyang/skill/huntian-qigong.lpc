// huntian-qigong.c
// written by Xiang

inherit FORCE;

int valid_enable(string usage) 
{ 
   return usage == "force"; 
}


int valid_learn(object me)
{
	if ( ((int)me->query_skill("jiaohua-xinfa", 1)) < 100 )
		return notify_fail("你的叫化心法火候还不够，无法领会混天气功。\n");
	return 1;
}


int practice_skill(object me)
{
	return notify_fail("混天气功只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return SKILL_D("huntian-qigong/") + func;
}

string query_yinyang()
{
	return "少阳";
}
