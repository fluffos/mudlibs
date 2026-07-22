// beauty.c

inherit SKILL;

int valid_learn(object me)
{
	if (me->query("gender") == "男性" && me->query("age") < 50)
		return notify_fail("你一个大老爷们学这玩意干嘛？\n");
	return 1;
}

string type() { return "knowledge"; }
