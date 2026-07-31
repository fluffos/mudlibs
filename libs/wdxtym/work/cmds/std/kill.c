// kill.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj;
	string *killer, callname;

	if (me->is_chatter())
		return 0;

	if (! arg)
		return notify_fail("你想杀谁？\n");

	if (! objectp(obj = present(arg, environment(me))))
		return notify_fail("这里没有这个人。\n");

	if (! obj->is_character() || obj->is_corpse())
		return notify_fail("看清楚一点，那并不是活物。\n");
	 if (obj->query("owner") == me->query("id"))
		 return notify_fail("你竟然要杀自己的宠物，太不人道了吧！！！\n");
	//if (obj == me)
	//	return notify_fail("用 suicide 指令会比较快:)。\n");

	if (arrayp(me->query_team()) &&
	    member_array(obj, me->query_team()) != -1)
		return notify_fail("连你自己队伍中的人也要杀吗？太不人道了吧！\n");

	if (me->is_fighting(obj) && me->is_killing(obj->query("id")))
		return notify_fail("你正在和人家生死相扑呢。\n");

    if ((me->query("age")<10 || me->query("combat_exp",1)<80000000) && userp(obj) && !me->query_temp("in_pkd"))
		return notify_fail("小小年纪就想杀人放火？还是练功去吧。\n");

	if ((obj->query("age")<1 || obj->query("combat_exp",1)<0) && userp(obj) && !obj->query_temp("in_pkd"))
		return notify_fail("连小朋友都要杀？你还真是心狠呀。\n");
	
	if (environment(me)->query("no_fight")&&!obj->query_condition("killer"))
		return notify_fail("这里不准战斗。\n");
	
	if (! wizardp(me) && wizardp(obj))
		return notify_fail("玩家不能试图杀害管理员。\n");

	//if (! me->is_fighting(obj) &&
	//    me->query("qi") < me->query("max_qi") * 3 / 10)
	//	return notify_fail("你已经没有多余力气战斗了。\n");

	callname = RANK_D->query_rude(obj);

	if (obj->query("can_speak"))
	{
	    if (random(3) > 1)
	    message_vision("\n$N对著$n喝道：「" 
		    + callname + "！今日不是你死就是我活！」\n\n", me, obj);
	    else
	    message_vision("\n$N对著$n喝道：「" 
		    + callname + "！明年今日就是你的忌日！」\n\n", me, obj);
	}

	switch(obj->accept_kill(me))
	{
	case 0:
		return (! objectp(obj));
	case -1:
		return 1;
	default:
	}

	if (userp(me) && userp(obj) && ! obj->is_want_kill(me->query("id")) )
		// Recoder the player want to kill another player
		me->want_kill(obj);

	me->kill_ob(obj);
	if (living(obj) && ! userp(obj))
		obj->kill_ob(me);
	else
		obj->fight_ob(me);

	return 1;
}

int help(object me)
{
	write(@HELP
指令格式 : kill <人物>
 
这个指令让你主动开始攻击一个人物，并且试图杀死对方，kill 和 fight 最大的
不同在於双方将会真刀实枪地打斗，也就是说，会真的受伤。由於 kill 只需单方
面一厢情愿就可以成立，因此你对任何人使用 kill 指令都会开始战斗，通常如果
对方是 NPC 的话，他们也会同样对你使用 kill。

当有人对你使用 kill 指令时会出现红色的字样警告你，对於一个玩家而言，如果
你没有对一名敌人使用过 kill 指令，就不会将对方真的打伤或杀死( 使用法术除
外)。

其他相关指令: hit, fight

有关 fight 跟 kill 的区分请看 'help combat'.
HELP );
	return 1;
}
