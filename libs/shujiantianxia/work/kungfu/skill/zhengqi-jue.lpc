// zhengqi-jue.c 正气诀
// cck 3/7/97

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me)
{
	if( (int)me->query("shen") < 0 )
	return notify_fail("华山门下怎么容得带有恶意之人学习正气诀？\n");
        if( (int)me->query_skill("zhengqi-jue", 1) >= 200 )
        return notify_fail("你不能再学习正气诀了。\n");
	return 1;
}

int practice_skill(object me)
{
	return notify_fail("正气诀只能靠学(learn)来提高。\n");
}

