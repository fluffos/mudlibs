// taoism.c

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	int lvl;
	
	lvl = (int)me->query_skill("murong-xinfa", 1);
	
	if(me->query("gender") == "无性" && lvl > 39)
		return notify_fail("你刚听一会儿，便觉心智迷糊，原来你没有阳刚之气，无法领会慕容心法中高深莫侧的变化之道。\n");

	if(me->query("class") == "bonze" && lvl > 39)
		return notify_fail("哈哈！"+RANK_D->query_respect(me)
			+"即入佛门，怎么却来学习慕容心法？\n");

	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("慕容心法只能靠学习来提高。\n");
}
