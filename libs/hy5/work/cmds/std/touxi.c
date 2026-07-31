// touxi.c 偷袭
// by King 97.05

#include <ansi.h>
inherit F_CLEAN_UP;
int main(object me, string arg)
{
	object obj;
	int skill, count;

        if (userp(me) && !query_heart_beat(me))
        {
         "/cmds/usr/quithy"->main(me);
         write("由于你没有心跳，请重新登陆!!\n");
        }

	if( environment(me)->query("no_fight") )
		return notify_fail("这里禁止战斗。\n");

	if( environment(me)->query("outdoors")=="12gong" )
		return notify_fail("在12宫内不允许使用这个命令。\n");

	if(!arg || !objectp(obj = present(arg, environment(me))))
		return notify_fail("你想偷袭谁？\n");

	if( !obj->is_character() )
		return notify_fail("看清楚一点，那并不是生物。\n");

        if (me->is_fighting()) 
        return notify_fail("你正打的热闹着呢!\n");

	if( obj->is_fighting(me) )
		return notify_fail("你已经在战斗中了，还想偷袭？\n");

	if( !living(obj) )
		return notify_fail(obj->name() + "都已经这样了，你还用得着偷袭吗？\n"); 

	if((int)obj->query("age") <= 19 && userp(obj))
		return notify_fail("为了世界更美好，放过小孩子吧.\n");

	if(obj->query("tasknpc"))
		return notify_fail("你想偷袭谁？\n");

	if(obj->query_temp("no_kill"))
		return notify_fail("你不能杀这个人。\n");
	if(obj->query("no_touxi"))
		return notify_fail("偷袭蜜蜂干什么?\n");
//	if(me->query("combat_exp") < obj->query("combat_exp")/3  && userp(obj))
//		return notify_fail("你和人家差那么多，打什么打?\n");

	if (me->is_fighting(obj) && me->is_killing(obj->query("id")))
		return notify_fail("你正在和人家生死相扑呢。\n");

	if(obj==me)
		return notify_fail("偷袭自己？别这么想不开。\n");

if(obj->query_temp("owner/id") && obj->query_temp("owner/id") != me->query("id"))
		return notify_fail("这个人和别人的任务有关，你不能杀这个人。\n");

	if( me->is_busy() )
		return notify_fail("你的动作还没有完成，不能偷袭。\n");
//pk
    if( userp(obj) && me->query_condition("killer"))
        return notify_fail("你已经被通辑了，不要再乱杀玩家了！\n");
    if( userp(obj) && obj->query("combat_exp") < me->query("combat_exp") && me->query_condition("killer"))
        return notify_fail("你已经被通辑了，不要再乱杀玩家了！\n");

       if( userp(me) && userp(obj) && obj->query("combat_exp")/3 > me->query("combat_exp") )
	return notify_fail("你想要杀此人，但他比你强太多，你不敢动手。\n");

	
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


	
        me->fight_ob(obj);
        obj->fight_ob(me);
        me->fight_ob(obj);

	me->start_busy(2);
	tell_object(me, "你飞身纵起，扑向" + obj->name() +"！\n");
	tell_object(obj, CYN"\n" + me->name() + "忽然向你扑来！\n\n"NOR);
	message("vision", CYN"\n" + me->name() + "忽然向" + obj->name() +"扑去！\n\n"NOR, environment(me), ({me, obj}) );

	count = me->query_str();

	if( random(me->query("combat_exp")) < (int)obj->query("combat_exp")/2 )
	{
		COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
	me->start_busy(1);
	}

	else
	{
		COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
		COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
		COMBAT_D->do_attack(me, obj, me->query_temp("weapon") );
	me->start_busy(1);
	}


	return 1;
}

int help(object me)
{
  write(@HELP
指令格式 : touxi <人物>
 
这个指令用来向敌人偷袭。偷袭不成时，则会招至反击。
特别适合于经验低的玩家向经验高的玩家拚命。:)

其他相关指令: fight, kill, hit
HELP
    );
    return 1;
}                                                                                                                                                                                                                                                                                                                    