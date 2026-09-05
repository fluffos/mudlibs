// yulong 玉龙倒悬
#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int cd_time,dur_time,cal_temp1,cal_temp2;
        object weapon;
//safari_skill/riyue_pomo
	if (me->query("safari_skill/riyue_pomo"))
	{
		return 1;
	}
	if ( !me->is_fighting() )
        return notify_fail("「乱泼墨」只能在战斗中使用。\n");

    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
	        return notify_fail("你没拿剑，拿什么「乱泼墨」?\n");

	if( (int)me->query_skill("pomo-jianfa", 1) <300 )
		return notify_fail("你的泼墨披麻剑法剑法不够火候, 使不出「乱泼墨」。\n");
    if( (int)me->query_skill("riyue-shengong", 1) < 300 )
        return notify_fail("你的日月神功等级不够，无法使用「乱泼墨」。\n");
    if( (int)me->query_skill("daguangming-xinfa", 1) < 300 )
        return notify_fail("你的大光明心法等级不够，不能使用「乱泼墨」。\n");
	if (me->query_skill("kuihua-shengong"))
		{
			return notify_fail("葵花神功与泼墨剑法并不能很好的相互支持。");
		}
		
    if( (int)me->query("max_neili") < 2000 || (int)me->query("neili") < 1000 )
        return notify_fail("你的内力不足，无法使用「乱泼墨」。\n"); 

    if ((int)me->query_temp("riyue_luanpomo"))
        return notify_fail("你刚使完「乱泼墨」，目前真气翻涌，无法再次运用！\n");

    msg = HIB"$N"HIB"左手轻挥，右手握起" + weapon->name() + HIB"，左右扫出，姿势犹如泼墨写生，\n";
    msg += "正是泼墨披麻剑法中的「乱泼墨」。\n"NOR;
    message_vision(msg, me, target);

    cal_temp1 = (int)me->query_skill("pomo-jianfa", 1);
	cal_temp1 += (int)me->query_skill("riyue-shengong", 1);
	cal_temp1 /=50;
	cal_temp2 = cal_temp1*2;
	cal_temp2 += me->query("con")*2;
	dur_time = cal_temp2;
	cd_time = cal_temp2 + me->query("con")*3;

	if (cal_temp1>60)
	{
		cal_temp1 = 60;
	}
	cal_temp1 += (int)me->query("dex")/2;
	if (cal_temp1>85)
	{
		cal_temp1 = 85;
	}
//write("加成"+cal_temp1+",持续"+dur_time+",cd"+cd_time+"\n");
	if (me->query("chushi/done"))
	{
		cal_temp1/=2;
		dur_time-=20;
		cd_time+=20;
	}
	if (me->query("betrayer"))
	{
		cal_temp1/=2;
		dur_time-=20;
		cd_time+=20;
	}

    me->set_temp("riyue_luanpomo", 1);
    me->set_temp("pomo-jianfa.luanpomo/buff_cnt", cal_temp1);
    me->set_temp("active_buffer/family", "日月神教");
    me->set_temp("active_buffer/pomo-jianfa.luanpomo/name", "乱泼墨");                  //buff名称
    me->set_temp("active_buffer/pomo-jianfa.luanpomo/last_time", time() + dur_time);       //持续时间
    me->set_temp("active_buffer/pomo-jianfa.luanpomo/effect1", "极大增强招架属性+" + cal_temp1 + "级");    //效果描述1
    call_out("remove_effect1", dur_time, me);
    call_out("remove_effect2", cd_time, me);

    me->add("neili", -300);
    me->start_busy(2);

    return 1;
}

void remove_effect1(object me)
{
    if (!me) return;
    me->delete_temp("pomo-jianfa.luanpomo/buff_cnt");
    me->delete_temp("active_buffer/pomo-jianfa.luanpomo");
   if ( sizeof(me->query_temp("active_buffer"))==1 )
      me->delete_temp("active_buffer");
	message_vision(YEL"\n$N的身形迟滞了起来，挥洒自如的剑势也随之消失。\n" NOR,me);
	return;
}

void remove_effect2(object me)
{
    if (!me) return;
    me->delete_temp("riyue_luanpomo");
    tell_object(me, HIG"\n你真气已经平复，又可以使用「乱泼墨」了。\n"NOR);
}

