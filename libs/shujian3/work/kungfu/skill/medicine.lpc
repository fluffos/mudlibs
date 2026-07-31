// medicine.c 本草术理

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
	int i = me->query_skill("medicine", 1);
	int j = me->query_skill("literate", 1);

	if(i <= 100 && i > j+10)
		return notify_fail("你的读书写字等级不够，无法研究更高深的本草术理。\n"); 
	if(i > 100 && i <= 150 && i > j+15)
		return notify_fail("你的读书写字等级不够，无法研究更高深的本草术理。\n");
	if(i > 150 && i > j+20)
		return notify_fail("你的读书写字等级不够，无法研究更高深的本草术理。\n");
	if (me->query_temp("mark/medicine")) {
		me->delete_temp("mark/medicine");
		return 1;
	}	   
	return notify_fail("本草术理只能通过研习医学书籍来提高。\n"); 
}

int practice_skill(object me)
{	
	return notify_fail("本草术理不能通过简单练习得以提高。\n");
}
