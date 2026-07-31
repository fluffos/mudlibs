// fight.c

#include <ansi.h>

inherit F_CLEAN_UP;

int main(object me, string arg)
{
	object obj, old_target;

        if (userp(me) && !query_heart_beat(me))
        {
         "/cmds/usr/quithy"->main(me);
return notify_fail("由于你没有心跳，请重新登陆!!\n");
        }

	if( environment(me)->query("no_fight") )
		return notify_fail("这里禁止战斗。\n");

	if( environment(me)->query("outdoors")=="12gong" )
		return notify_fail("在12宫内不允许使用这个命令。\n");

	if(!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("你想攻击谁？\n");

	if( !obj->is_character() )
		return notify_fail("看清楚一点，那并不是生物。\n");

        if (me->is_fighting()) 
        return notify_fail("你正打的热闹着呢!\n");

	if(obj->query_temp("no_kill"))
		return notify_fail("你不能杀这个人。\n");

     if( obj->query("env/no_fight") )
        return notify_fail("不能打，打不得啊！\n");

	if( obj->is_fighting(me) )
		return notify_fail("加油！加油！加油！\n");

        if (userp(obj) && !query_heart_beat(obj))
        {
         write("你想做什么！\n");
        return notify_fail("此人无心跳！\n");
        }

	if( me->query_temp("hitting") )
		return notify_fail("加油！加油！加油！\n");
	if(obj==me)	return notify_fail("打自己？别这么想不开。\n");

    if(me->is_busy())
        return notify_fail("你现在正忙，没法杀人。\n");

    if(obj->is_fighting())
        return notify_fail("那个人正在打着呢!\n");

if(obj->query_temp("owner/id") && obj->query_temp("owner/id") != me->query("id"))
		return notify_fail("这个人和别人的任务有关，你不能杀这个人。\n");

    if(me->is_fighting())
        return notify_fail("你现在正和别人打着呢 ，没法杀人。\n");

	if((int)me->query("age") <= 19 && userp(obj))
		return notify_fail("你现在还是小孩子，不能对玩家发起攻击!\n");

	if(me->query("combat_exp") < obj->query("combat_exp")/3  && userp(obj))
		return notify_fail("你和人家差那么多，打什么打?\n");

	if((int)obj->query("age") <= 19 && userp(obj))
		return notify_fail("为了世界更美好，放过小孩子吧.\n");
//	if( !userp(obj) || wizardp(obj) )
//		return notify_fail("只能对玩家使用。\n");

//pk
    if( userp(obj)  && me->query_condition("killer"))
        return notify_fail("你已经被通辑了，不要再乱杀玩家了！\n");
    if( userp(obj) && obj->query("combat_exp") < me->query("combat_exp") && me->query_condition("killer"))
        return notify_fail("你已经被通辑了，不要再乱杀玩家了！\n");

if( !living(obj) && userp(obj) && obj->query("combat_exp")/3 > me->query("combat_exp") )
	return notify_fail("你想要杀此人，但他比你强太多，你不敢动手。\n");

/*if( obj->query("combat_exp") > 5000000 && userp(obj) && (obj->query("combat_exp")-2000000) > 
me->query("combat_exp") )
	return notify_fail("你和人家差那么多，打什么打?\n");
*/
//免战系统
        if (userp(me) && userp(obj)
         && obj->query_temp("nokill") )
        return notify_fail("那人启用了免战牌！\n");

        if (userp(me) && userp(obj)
         && me->query_temp("nokill") )
        return notify_fail("你启用了免战牌！\n");

    if( userp(me) && userp(obj) && obj->query_condition("nokill")
    && !obj->query_condition("killer"))
        return notify_fail("那个人刚被杀过，放过他吧！\n");
if( !living(obj) && userp(obj) && obj->query("combat_exp")/3 > me->query("combat_exp") )
	return notify_fail("你想要杀此人，但他比你强太多，你不敢动手。\n");


	if (me->is_fighting(obj) || me->is_killing(obj))
		return notify_fail("你正在和人家生死相博呢。\n");

if( obj->query("combat_exp") > 5000000 && userp(obj) && (obj->query("combat_exp")-2000000) > 
me->query("combat_exp") )
	return notify_fail("你和人家差那么多，打什么打?\n");
	if( userp(obj) ) {
		message_vision("\n$N对著$n大喝一声：看招！\n\n", me, obj);
		me->set_temp("hitting");
		remove_call_out("do_hit");
		call_out("do_hit", 1, me, obj);
		return 1;
	}

	if( obj->query("can_speak") ) {
		message_vision("\n$N对著$n大喝一声：看招！\n\n", me, obj);
if( (int)obj->query("jing") * 100 / (int)obj->query("max_jing") >= 90
||(int)obj->query("qi") * 100 / (int)obj->query("max_qi") >= 90 ) 
{
		me->fight_ob(obj);
		obj->fight_ob(me);
if (!userp(obj))
{
              obj->set("neili",obj->query("max_neili"));
}
}
else {
        me->fight_ob(obj);
        obj->fight_ob(me);
		me->kill_ob(obj);
		obj->kill_ob(me);
if (!userp(obj))
{
              obj->set("neili",obj->query("max_neili"));
}
}
		me->fight_ob(obj);
		obj->fight_ob(me);
                //me->start_busy(2);
	} else {
		message_vision("\n$N大喝一声，开始对$n发动攻击！\n\n", me, obj);
        me->fight_ob(obj);
        obj->fight_ob(me);

		me->kill_ob(obj);
		obj->kill_ob(me);
                //me->start_busy(2);
	}

	return 1;
}

void do_hit(object me, object obj)
{
	if(objectp(present(obj, environment(me)))) {
		me->fight_ob(obj);
                obj->fight_ob(me);
		COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
		COMBAT_D->do_attack(obj, me, obj->query_temp("weapon") );
	}
    if(userp(me) && userp(obj))
    {
         me->start_busy(1);
    }
	me->delete_temp("hitting");
	return;
}

int help(object me)
{
  write(@HELP
指令格式 : hit <人物>
 
这个指令让你直接向一个人物「进招」。这种形式的战斗是即时的，只要玩家一
敲这个命令，战斗就会开始，直到某一方受伤50% 以上为止。这个指令对那些不
喜欢fight的NPC很有用，因为很多时候你的比武要求会被拒绝。
 
其他相关指令: fight, kill

HELP
    );
    return 1;
}
 
