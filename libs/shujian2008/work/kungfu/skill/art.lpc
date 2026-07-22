// art.c 琴棋书画
// cck 3/7/97
//cool 10/10/98

inherit SKILL;
void init();

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me)
{
	if(me->query_int() < 32)
		return notify_fail("琴棋书画乃是极其风雅之事，你似乎太过于俗气了些。\n");
/*
	if((int)me->query("shen") < -10000 )
		return notify_fail("你杀人如麻，倘若不能先平息了心头魔念，哪里又会有心思弹琴下棋？\n");
*/
	if((int)me->query_skill("art", 1) >= 200 )
		return notify_fail("你不能再学习琴棋书画了。\n");

	if(me->query("family/master_name") != "何足道" )
		return notify_fail("你一个练武的粗人，学这些酸腐文人的东西干什么？\n");

	return 1;
}

int practice_skill(object me)
{
	return notify_fail("琴棋书画只能靠学(learn)来提高。\n");
}
