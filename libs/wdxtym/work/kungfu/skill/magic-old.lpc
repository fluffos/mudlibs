// necromancy.c

inherit SKILL;

int valid_enable(string usage) 
{ 
        return usage=="spells" ;

}

int valid_learn(object me)
{
	if( (int)me->query_skill("spells",1) < (int)me->query_skill("magic-old",1))
		return notify_fail("你的基本魔法修为不够，无法领悟更高深的火系魔法。\n");
	return 1;
}

string perform_action_file(string action)
{
        return __DIR__"magic-old/" + action;
}
