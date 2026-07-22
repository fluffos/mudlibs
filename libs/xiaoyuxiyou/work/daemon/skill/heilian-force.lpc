// heilian-force.c  【黑莲魔功】
inherit FORCE;

int valid_enable(string usage) { return usage=="force"; }

int valid_learn(object me) 
{
	if( (int)me->query_skill("force", 1) < 10 )
//		|| (int)me->query_skill("force", 1) <= (int)me->query_skill("heilian-force", 1) )
		return notify_fail("你的内功修为还不够高深，无法学习黑莲魔功。\n");
	return 1;
}

int practice_skill(object me)
{
        return notify_fail("黑莲魔功只能向师父学，或是从运用(exert)中增加熟练度。\n");
}
string exert_function_file(string func)
{
        return CLASS_D("mojie") + "/heilian-force/" + func;
}

