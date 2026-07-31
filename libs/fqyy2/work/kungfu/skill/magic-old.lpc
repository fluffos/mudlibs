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
int practice_skill(object me)
{	
	object bug;

	if( bug = me->query_temp("mind_bug") )
		return notify_fail("你的魂魄还没有全部收回，赶快杀死你的"
			+ bug->name() + "吧！\n");

	if( (int)me->query("neili") < 10 )
		return notify_fail("你的内力(法力)不够。\n");

	if( (int)me->query("jing") < 30 )
		return notify_fail("你的精神无法集中。\n");

	me->add("neili", -10);
	me->receive_damage("jing", 5);

	write("你闭目凝神，神游物外，开始修习魔法中的火系法术....\n");
	if( random((int)me->query("jing")) < 5 ) {
		int rnd;

		rnd = random(me->query_skill("spells", 1));
		if( rnd < 10 )	bug = new("/obj/npc/mind_bug");
		else			bug = new("/obj/npc/mind_beast");

		write("可是你心思一乱，变出了一只面目狰狞的" + bug->name() + "！\n");
		bug->move(environment(me));
		bug->kill_ob(me);
		me->fight(bug);
		me->set_temp("mind_bug", bug);
		bug->set("owner", me->query("id"));
		return notify_fail("你的魂魄正被" + bug->name() + "缠住，快把它除掉吧！\n");
	}	
	else return 1;
}
int effective_level() { return 15;}

int learn_bonus()
{
	return 30;
}
int practice_bonus()
{
	return 10;
}
int black_white_ness()
{
	return -50;
}

