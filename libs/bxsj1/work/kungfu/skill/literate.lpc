// literate.c

inherit SKILL;

string type() { return "knowledge"; }

void skill_improved(object me)
{}

int valid_learn(object me)
{
	if (me->query_temp("mark/literate")) {
		me->delete_temp("mark/literate");
		return 1;
	}

	if( (me->query("family/family_name") =="少林派"
	|| me->query("family/family_name") =="峨嵋派"
	|| me->query("family/family_name") =="天龙寺")
	&& me->query("class") == "bonze"
	&& me->query_skill("literate", 1) < 100)
		return 1;

	return notify_fail("你必须去学堂学习读书写字。\n");
}
