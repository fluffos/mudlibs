// taoism.c 道学心法(武当)

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	int lvl;
	
	lvl = (int)me->query_skill("taoism", 1);
	
	if( (int)me->query("shen") < 0 )
		return notify_fail("你的邪气太重，无法修炼天师正道。\n");
		
	if(me->query("gender") == "无性" && lvl > 39)
		return notify_fail("你刚听一会儿，便觉心智迷糊，原来你没有阳刚之气，无法领会里面的阴阳变化之道。\n");
		
             if(me->query_skill("huagong-dafa",1) >= 1)
                  return notify_fail("你的内功不适合学天师正道，还是放弃吧.\n");
	if(me->query("class") == "bonze")
		return notify_fail("哈哈！"+RANK_D->query_respect(me)
			+"即入佛门，怎么却来学道家心法？\n");
		
	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("天师正道只能靠学习来提高。\n");
}
