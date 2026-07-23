int exercising(object me);
int halt_exercise(object me);

int do_dazuo(string arg)
{
	int exercise_cost;
	int i,num;
	object me = this_player();
	object ob = this_object();
	object *obs,obj;

	seteuid(getuid());
	
	num=0;
	obs = all_inventory(ob);
	for(i=0; i<sizeof(obs); i++)
		if (obs[i]->is_character())
			num++;

	if (num > 1)
		return 0;
				
	if (me->is_busy() || me->query_temp("pending/exercising"))
		return notify_fail("你现在正忙着呢。\n");

	if( me->is_fighting() )
		return notify_fail("战斗中不能练内功，会走火入魔。\n");

	if( !stringp(me->query_skill_mapped("force")) )
                return notify_fail("你必须先用 enable 选择你要用的内功心法。\n");

	if( !arg || !sscanf(arg, "%d", exercise_cost))
		return notify_fail("你要花多少气练功？\n");
	if (exercise_cost < 10)
		return notify_fail("你的内功还没有达到那个境界！\n");

	if( (int)me->query("qi") < exercise_cost )
		return notify_fail("你现在的气太少了，无法产生内息运行全身经脉。\n");

	if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 )
		return notify_fail("你现在精不够，无法控制内息的流动！\n");

	write("你坐下来闭目行功，静寂的气氛下内息比往常更畅快的流动。\n");

	me->set_temp("pending/exercise", 1);
	me->set_temp("exercise_cost", exercise_cost);
	me->set_temp("force_gain", exercise_cost/30);
	message_vision("$N盘膝坐下，开始修炼内力。\n", me);
	me->start_busy((: exercising :), (:halt_exercise:));
	return 1;
}

int exercising(object me)
{
	int exercise_cost = (int)me->query_temp("exercise_cost");
	int neili_gain = 2 + (int)me->query_skill("force") / 5;
	int i, clan, extra;
	string force;

        if (exercise_cost < 1)
                return 0;
	force = (string)me->query_skill_mapped("force");

	extra = 1.5;

	neili_gain = neili_gain*extra;
	me->add("neili", neili_gain);
	me->set_temp("exercise_cost", exercise_cost -= neili_gain);

	//me->add("qi", -neili_gain);
	me->receive_damage("qi", neili_gain, "打坐走火入魔死了");

	if (exercise_cost > 0)
		return 1;

	me->set_temp("pending/exercise", 0);
	message_vision("$N运功完毕，深深吸了口气，站了起来。\n", me);
	if ((int)me->query("neili") < (int)me->query("max_neili") * 2)
		return 0;
	else {
		if ((int)me->query("max_neili") > (int)me->query_skill("force") * me->query("con") * 2 / 3) {
			write("你的内力修为似乎已经达到了瓶颈。\n");
			me->set("neili", (int)me->query("max_neili"));
			return 0;
		}
		else {
			me->add("max_neili", 1);
			me->set("neili", (int)me->query("max_neili"));
			write("你的内力增加了！！\n");
			return 0;
		}
	}
}

int halt_exercise(object me)
{
	if ((int)me->query("neili") > (int)me->query("max_neili") * 2)
		me->set("neili", (int)me->query("max_neili") * 2);
	me->set_temp("pending/exercise", 0);
	return 1;
}





