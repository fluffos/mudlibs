// 舞剑术

inherit SKILL;

string type() { return "art"; }

int valid_learn(object me)
{
	if (me->query_skill("art-cognize", 1) < 30)
		return notify_fail("你艺术造诣太浅，难以掌握舞剑术。\n");

	if (me->query_skill("wujian-shu", 1) > me->query_skill("art-cognize", 1))
		return notify_fail("你艺术造诣有限，不足以掌握更高深的舞剑术。\n");

	return 1;
}
