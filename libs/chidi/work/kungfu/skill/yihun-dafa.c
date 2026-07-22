// yihun-dafa.c 移魂大法
// By Kayin@CuteRabbit Studio 99-4-15 18:58 new
inherit SKILL;

void create() { seteuid(getuid()); }
int valid_learn(object me) 
{
	int lvl;
	
	lvl = (int)me->query_skill("yihun-dafa", 1);
	
	if( (int)me->query("shen") < 0 )
		return notify_fail("你的邪气太重，无法修炼移魂大法。\n");
		
	if ( (int)me->query("per") < 20)
		return notify_fail("就凭你这惨不忍睹的形象？。\n");
		
	if(me->query("gender") == "女性")
	{
		if(lvl>me->query("per")*15)
			return notify_fail("你就只能学到这里了。\n");
	}
	else
	{
		if(lvl>me->query("per")*5)
			return notify_fail("你就只能学到这里了。\n");
	}
	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("移魂大法只能靠学习来提高。\n");
}
