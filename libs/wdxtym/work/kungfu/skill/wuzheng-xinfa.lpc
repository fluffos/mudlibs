// wuzheng-xinfa.c
inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	 if (me->query_skill("force", 1) > 49)
		return 1;

	 return notify_fail("你的基本内功还需要进一步提高。\n");
}

int practice_skill(object me)
{
	return notify_fail("无争心法只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return SKILL_D("wuzheng-xinfa/") + func;
}
