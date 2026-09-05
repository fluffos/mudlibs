// riyue-shengong 日月神功
// by bing

inherit FORCE;
int valid_enable(string usage) { return usage == "force"; }
int valid_learn(object me)
{
        if ((int)me->query_skill("force", 1) < 10)
                return notify_fail("你的基本内功火候还不够。\n");
        return 1;
}

int practice_skill(object me)
{
        return notify_fail("只能用学(learn)的来增加熟练度。\n");
}

string exert_function_file(string func)
{
        return __DIR__"riyue-shengong/" + func;
}

void disable_skill(object me)
{
	string gm = exert_function_file("guangming");
	if (me->query_temp("daguangming/apply"))
		gm->remove_effect(me);
}
