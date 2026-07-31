// qimen-wuxing

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int practice_skill(object me)
{	
	return notify_fail("奇门五行只能靠学(learn)来提高。\n");
}
int valid_learn(object me)
{
	if (me->query("family/family_name") != "桃花岛")
		return notify_fail("桃花岛的弟子才能学习该技能。\n");
	return 1;
}