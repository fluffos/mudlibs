// zhanbu.c

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me)
{
	if( (int)me->query_skill("literate", 1) < 100 )
	return notify_fail("你的读书写字水平还不够高，无法进行占卜。\n");

	if( (int)me->query("jingli", 1) < 200 )
	return notify_fail("你太累了，还是先休息一下吧。\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("琴棋书画只能靠学(learn)来提高。\n");
}

