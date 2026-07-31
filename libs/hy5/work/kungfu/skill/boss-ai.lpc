// necromancy.c

inherit SKILL;

int valid_enable(string usage) 
{ 
        return usage=="spells" ;

}

int valid_learn(object me)
{
	   if( userp(me))
     return notify_fail("BOSS武功，不开放。\n");
	if( (int)me->query_skill("spells",1) < (int)me->query_skill("boss-ai",1))
		return notify_fail("你的基本魔法修为不够，无法领悟更高深的魔法。\n");
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"boss-ai/" + action;
}
