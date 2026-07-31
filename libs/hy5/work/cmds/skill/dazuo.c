// exercise.c
// snowman 15,12,98

#include <skill.h>

int exercising(object me);
int halt_exercise(object me);

int main(object me, string arg)
{
	string force;
	mapping msg;
	int exercise_cost, max;
	object where;

	max = (int)me->query("max_neili");
	seteuid(getuid());
	where = environment(me);
	
	if (where->query("pigging"))
		return notify_fail("你还是专心拱猪吧！\n");

	if (me->is_busy())
		return notify_fail("你现在正忙着呢。\n");
    if (me->is_exert()) return notify_fail("你正在使用"+me->query_exert()+"。\n");

	if( me->is_fighting() )
		return notify_fail("战斗中不能练内功，会走火入魔。\n");
	if( (int)me->query("qi") < 30 )
		return notify_fail("你现在气不够!\n");

	if( (int)me->query("jing") < 30 )
		return notify_fail("你现在精不够!\n");

    if (me->is_exert()) return notify_fail("你正在使用"+me->query_exert()+"。\n");
	if (where->query("sleep_room"))
		return notify_fail("卧室不能打坐，会影响别人休息。\n");

        if (where->query("no_fight"))
                return notify_fail("这里不准战斗，也不准打坐。\n");

        if( !(force = me->query_skill_mapped("force")) )
		return notify_fail("你必须先用 enable 选择你要用的特殊内功。\n");

	if( !arg || !sscanf(arg, "%d", exercise_cost))
		return notify_fail("你要花多少气练功？\n");
	if (exercise_cost < 10)
		return notify_fail("你无法控制内息运行到如此精细的程度！\n");

	if( (int)me->query("qi") < exercise_cost )
		return notify_fail("你没有那么多的气来产生内息运行全身经脉。\n");

	if( (int)me->query("jing") * 100 / (int)me->query("max_jing") < 70 )
		return notify_fail("你现在精不够，无法控制内息的流动！\n");

	me->receive_damage("qi", exercise_cost);
	msg = SKILL_D(force)->exercise_msg(me);
	if (!msg || undefinedp(msg["start_my_msg"]))
		write("你坐下来运气用功，一股内息开始在体内流动。\n");
	else
		write(msg["start_my_msg"]);

	me->set_temp("pending/exercise", 1);
	me->set_temp("exercise_cost", exercise_cost);
	if (!msg || undefinedp(msg["start_other_msg"]))
		tell_room(environment(me),
			me->name() + "盘膝坐下，开始运功打坐。\n", ({ me }));
	else
		tell_room(environment(me),
			msg["start_other_msg"], ({ me }));
	me->start_busy((: exercising :), (:halt_exercise:));
	return 1;
}

int exercising(object me)
{
	string force;
	mapping msg;
	int exercise_cost = (int)me->query_temp("exercise_cost");
	int neili_gain = 1 + (int)me->query_skill("force") / 15
		* (1 + (int)me->query_skill("force") / 100);    // changed by pishou

//	int exercise_cost = (int)me->query_temp("exercise_cost");
//        int neili_gain = 1 + (int)me->query_skill("force") / 10;
//        int max = (me->query_skill("force") * me->query("con")*2/3) + (me->query_skill("beiming-shengong", 1)*20);
//if players wanna get max_neili after force*10, the only way is drugs, quests and age :)
// yes, add some max_neili each year they grow up :)
// yuj please fix it if i made any mistake :)

        int max = me->query_skill("force")*10 + me->query("combat_exp")/1000;

        if (exercise_cost<0) neili_gain = neili_gain + exercise_cost;
//	if (neili_gain > exercise_cost) neili_gain = exercise_cost;
        if (exercise_cost < 1)
                return 0;

//	me->receive_damage("qi", neili_gain);
	me->add("neili", neili_gain);
	me->set_temp("exercise_cost", exercise_cost -= neili_gain);

	force = me->query_skill_mapped("force");
	if (force) msg = SKILL_D(force)->exercise_msg(me);
	if (exercise_cost > 0) {
		if (msg && !undefinedp(msg["exec_my_msg"]))
			tell_object(me, msg["exec_my_msg"]);
		if (!random(3) && msg && !undefinedp(msg["exec_other_msg"]))
			//tell_room(environment(me), msg["exec_other_msg"], ({me}));
		tell_object(me, msg["exec_other_msg"]);
		return 1;
	}

	me->delete_temp("pending/exercise");
	if (!msg || undefinedp(msg["end_my_msg"]))
			tell_object(me, "你只觉内息运转顺畅，将真气还合丹田，站了起来。\n");
	else
		tell_object(me, msg["end_my_msg"]);
	if (!msg || undefinedp(msg["end_other_msg"]))
		tell_object(me, me->name()+"运功完毕，深深吸了口气，站了起来。\n");
		//tell_room(environment(me),me->name()+"运功完毕，站了起来。\n", ({me}));
	else
		//tell_room(environment(me),msg["end_other_msg"], ({me}));
tell_object(me, msg["end_other_msg"]);
	if (me->query("max_neili") >= max){
		tell_object(me, "你的内力修为似乎已经达到了瓶颈。\n");
		me->set("neili", me->query("max_neili") * 2);
		return 0;
	        }


if (!me->query("zhuanshen") && me->query("combat_exp",1) < 12000000)
{
	me->set("neili", me->add("max_neili", 1));
	tell_object(me, "你的内力修为增加了！\n");
	return 0;
}
	if (me->query("neili") < me->query("max_neili") * 2)
		return 0;

	me->set("neili", me->add("max_neili", 1));
	tell_object(me, "你的内力修为增加了！\n");
	return 0;
}

int halt_exercise(object me)
{
	string force;
	mapping msg;

	if (me->query("neili") > me->query("max_neili") * 2)
		me->set("neili", me->query("max_neili") * 2);
	me->delete_temp("pending/exercise");
	force = me->query_skill_mapped("force");
	if (force) msg = SKILL_D(force)->exercise_msg(me);
	if (!msg || undefinedp(msg["halt_msg"]))
		message_vision(
			"$N把正在运行的真气强行压回丹田，站了起来。\n", me);
	else
		message_vision(msg["halt_msg"], me);
	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : exercise|dazuo [<耗费「气」的量> 必须不少于 10]

运气练功，控制体内的气在各经脉间流动，藉以训练人体肌肉骨骼的耐
力、爆发力，并且用内力的形式将能量储备下来。
HELP
        );
        return 1;
}
