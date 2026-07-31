// xiaoyao-qixue.c

inherit SKILL;

string type() { return "knowledge"; }

int valid_enable(string usage) { return usage == "medical"; }

int valid_learn(object me)
{
	if (me->query("family/family_name") != "逍遥派")
		return notify_fail("逍遥派的弟子才能学习该技能。\n");
	
	if ((int)me->query_skill("medical", 1) < 100)
		return notify_fail("你的基本医术造诣太浅，无"
				   "法领会深奥的逍遥奇学。\n");

	if ((int)me->query_skill("medical", 1) < (int)me->query_skill("xiaoyao-qixue", 1))
		return notify_fail("你的基本医术水平有限，无"
				   "法掌握更深奥的逍遥奇学。\n");

	return 1;
}

