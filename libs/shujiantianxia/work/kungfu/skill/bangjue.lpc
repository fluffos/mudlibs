// bangjue.c 打狗棒心法
// by shang 97/6

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	if( (int)me->query_skill("stick", 1) < 30 )
		return notify_fail("你的基本棒法太差, 还领会不了棒诀。\n");
	if (me->query_skill("bangjue", 1) > 200)
		return notify_fail("你已经无法提高你的棒诀了。\n");
	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("打狗棒心法只能靠学(learn)来提高。\n");
}
