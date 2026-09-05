// tianshi-zhengqi.c 天师正气
// Made by ysg (1997.10.18)

inherit FORCE;

int valid_enable(string usage) { return usage == "force"; }

int valid_learn(object me)
{
	int lvl = (int)me->query_skill("tianshi-zhengqi", 1);
	if ( me->query("gender") == "无性")
		return notify_fail("你无根无性，阴阳不调，如何领会天师正气？\n");
	if ( me->query("class") == "bonze" )
		return notify_fail("天师正气追求的乃是自然之道，于佛家六根清净之意有碍，"
			+RANK_D->query_respect(me)+"欲修此功，如何堪破世间百情？\n");
	if ((int)me->query_skill("force", 1) < 10)
		return notify_fail("你的基本内功火候还不够。\n");
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("天师正气只能用学(learn)来增加熟练度。\n");
}

string exert_function_file(string func)
{
	return __DIR__"tianshi-zhengqi/" + func;
}

