// ziyin-yin.c 紫氤吟
// cck 3/7/97

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me)
{

	if( (int)me->query("shen") < 0 )
	return notify_fail("华山门下怎么容得带有恶意之人学习紫氤吟？\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("紫氤吟只能靠学(learn)来提高。\n");
}

