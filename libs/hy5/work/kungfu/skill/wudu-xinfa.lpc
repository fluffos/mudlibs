// wudu-xinfa

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	if( (int)me->query("shen") > -10000)
		return notify_fail("修习五毒心法必需心狠手辣才行。\n");
	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("五毒心法只能靠学(learn)来提高。\n");
}
