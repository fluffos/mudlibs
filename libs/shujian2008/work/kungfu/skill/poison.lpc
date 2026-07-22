// poison.c 毒技
// by pishou

inherit SKILL;

void create() { seteuid(getuid()); }

string type() { return "knowledge"; }

int valid_learn(object me) 
{
        int i = (int)me->query_skill("poison", 1);
        int t = 1, j;
      if (i>150) return notify_fail("学就只能学的这里了，剩下的要靠你自己练毒了。 \n");
        for (j = 1; j < i / 10; j++) t*= 2;
       	if( (int)me->query("shen") > 0 )
		return notify_fail("你是侠义正士, 怎么能修炼如此阴狠的毒技? \n");
        if (i > 10 && (int)me->query("shen") > t * 100)
        return notify_fail("只有大奸大恶之人才能继续修练毒技！\n");
        if( (int)me->query_skill("poison", 1) >= 200 )
        return notify_fail("你不能再修炼毒技了。\n");

	return 1;
}

int practice_skill(object me)
{	
	return notify_fail("毒技不能通过简单练习得以提高。\n");
}
