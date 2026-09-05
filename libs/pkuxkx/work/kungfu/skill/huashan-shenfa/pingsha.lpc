// 屁股向后平沙落雁， zine 2014 huashan new skills
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

string* valid_weapon() 
{
    return ({ "all" });
}

int valid_target_arg(string target)
{
    if (target == "version") return 2;
    return target == "null" || target == "other";
}

int r_move(object pl,object me)
{
	int i;
	mapping exits;
	string *dirs;
	if(!environment(pl)) return 0;
	if(sizeof(environment(pl)->query("exits")) == 0) return 0;
	if( !mapp(exits = environment(pl)->query("exits")) ) return 0;
	dirs = keys(exits);
	i = random(sizeof(dirs));
	if( !environment(pl)->valid_leave(this_object(), dirs[i]) ) return 0;
	if(pl->move(load_object(environment(pl)->query("exits/"+dirs[i])))) 
	{
		tell_room(environment(me),pl->name()+"被"+me->name()+"一脚踢得向"+environment(pl)->query("short")+"飞去。\n");
		message("vision", pl->name()+"被人一脚踢了过来。\n",
                        environment(pl), ({pl}) );
		return 1;
	}
	return 0;
}
int perform(object me, object target)
{
    int rate=10;
	string msg;

	if (me->query("huashan_newskills/jianzong")&&!me->query("huashan_newskills/dodge2"))
		return 0;

	if (!me->query("huashan_newskills/jianzong")&&!me->query("huashan_newskills/dodge1"))
		return 0;

    if( !target ) target = offensive_target(me);
//	if (me->is_busy())	return notify_fail("你正忙着呢。\n");
    if( !target || !target->is_character() )
        return notify_fail("你要逼迫谁使出『屁股向后平沙落雁式』？\n");

    if( (int)me->query_skill("huashan-shenfa", 1) < 80 )
        return notify_fail("你的华山身法还不够，无法逼迫对手使出「屁股向后平沙落雁式」！\n");

	if (!userp(target)&&!wizardp(me))
		return notify_fail("踢NPC也那么好玩吗？\n");

    if( (int)me->query("combat_exp") < target->query("combat_exp")/2 &&!me->query("is_LINGHU")&&!wizardp(me))
        return notify_fail("你只是动念想了想，并不敢对前辈不敬！\n");

	if (environment(me)->query("lingwu_family"))
		return notify_fail("这里是人家主场，你还是收起狂悖之心吧。\n");

	if (target->is_busy())
		return notify_fail(target->name()+"已经在忙着了，这时候踢人太胜之不武了。\n");

	if (environment(me)->query("no_fight"))
		return notify_fail("这里不许战斗。\n");

    if( (int)me->query("neili", 1) < 200 )
        return notify_fail("你现在内力太弱，无法逼迫对手使出「屁股向后平沙落雁式」！\n");

	if( (int)me->query("jingli", 1) < 200 )
        return notify_fail("你现在精力不足，无法逼迫对手使出「屁股向后平沙落雁式」！\n");

    msg = HIM+"$N"+HIM+"左掌一带，将$n"+HIM+"带得身子转了半个圈子。\n"NOR;

    me->add("neili", -100);
	me->add("jingli", -100);

    //命中率c,d+,d-三种情况    
	if (!target->is_fighting())//不在战斗
        rate=10;
	else if (target->is_fighting(me))//在和我战斗
        rate=12;
	else//在和别人战斗
        rate=8;

    if( F_KUNGFU->hit_rate(me->query("combat_exp"), target->query("combat_exp"), rate, me, target ) 
	||wizardp(me)||me->query("is_LINGHU")) 
    {
        msg += HIW+"跟着$N"+HIW+"飞出一腿，踢中了$n"+HIW+"的后臀。这一腿又快又准，巧妙之极。\n$n"+HIW+"站立不定，被踢了出去。\n"NOR;
        message_vision(msg, me, target);
        r_move(target,me);
		if (environment(target)==environment(me))//减低random_move到不许进入房间不动的概率。
            r_move(target,me);
    } 
    else 
    {
        msg += WHT"$n哼了一声，躲开了$N这一招。\n" NOR;
        message_vision(msg, me, target);
        me->start_busy(2+random(2));
        if (!random(10))//小概率攻击
            target->hit_ob(me);
    }
    me->start_busy(1);

    return 1;
}
