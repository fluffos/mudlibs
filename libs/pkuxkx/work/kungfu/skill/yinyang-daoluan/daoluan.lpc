// daoluan.c  倒乱刃
//create by westerd@pkuxkx
//Modified by yhzzyahoo@pkuxkx, 2015-11-17

#include <ansi.h>
#include <char.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

void end(object me, object target,int damage);

int perform(object me, object target)
{
    int damage,cd_time,dur_time,eff1,eff2,eff;
	int xt_int,xt_dex;
    string msg;
    object weapon;

    if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FAMILY) && 
        me->query("daoluan_perform") != 1)
	{
		if (me->query("tqt/free_trial")!="yinyang-daoluan")
		{
	        return notify_fail("你还没有学会阴阳倒乱刃法的特殊攻击。\n");
		}
	}

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("倒乱刃法只能对战斗中的对手使用。\n");
	
	xt_int = me->query("int");
	eff1 = 50 - xt_int;
	eff2 = (int)(40-me->query_skill("yinyang-daoluan",1)/50);
	if (eff2<0)
	{
		eff2=0;
	}
	if (eff1 > eff2)
	{
		cd_time = eff1;
	}
	else
	{
		cd_time = eff2;
	}
	if (cd_time < 1)
	{
		cd_time =1;
	}
     if( (time() - (int)me->query_temp("daoluan_start_time")) < cd_time )
                return notify_fail("你的「倒乱刃法」刚刚使用完毕，精力尚未平复。\n");	
    if( me->query_temp("yinyang-daoluan/daoluan")) 
        return notify_fail("你已经在使用阴阳倒乱刃！\n");
	if (me->query("zyhb") || me->query("hubo") || me->query("suxin"))
			return notify_fail("你会左右互博，再使用阴阳倒乱刃法的特殊攻击会造成神经错乱的。\n");

	if (me->query_skill("shenghuo-lingfa",1))
			return notify_fail("你会圣火令法，再使用阴阳倒乱刃法的特殊攻击会造成神经错乱的。\n");
    if (!objectp(weapon = me->query_temp("weapon")) || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你右手无剑，如何使得倒乱刃法绝招？\n");
	if (!objectp(weapon = me->query_temp("secondary_weapon")) || (string)weapon->query("skill_type") != "blade") 
        return notify_fail("你左手无刀，如何使得倒乱刃法绝招？\n");
    if( (int)me->query_skill("yinyang-daoluan", 1) < 300 )
        return notify_fail("你的阴阳倒乱刃法不够娴熟，不会使用「倒乱刃法」。\n");

//先天判定放到获取sk那里去

    if( (int)me->query("neili", 1) < 500 )
        return notify_fail("你现在内力太弱，不能使出「倒乱刃法」。\n");


    msg = HIW "\n$N取出阴阳双刃，当的一声互击，喝道：“好，好！今日让你见识下倒乱刃的厉害！”\n刀剑齐出，向$n攻来。\n" NOR;



	//对方debuff不要了
	xt_dex = me->query("dex");
	eff1 = (int)((me->query_skill("yinyang-daoluan",1)-300)/6);
	eff2 = (xt_dex - 20)*10;
	if (eff1>eff2)
	{
		eff = eff2;
	}
	else
	{
		eff = eff1;
	}
	if (eff > 250)
		eff = 250;//最高加成到2
	if (xt_dex > 49)
		eff = 280;//身法50的特殊加成
	if (eff<0)
		eff=0;
	eff1 = (xt_int - 20)*10+100;
	eff2 = (int)(me->query_skill("yinyang-daoluan",1)/50);
	if (eff1 > eff2)
	{
		dur_time = eff2;
	}
	else
	{
		dur_time = eff1;
	}
	if (xt_int > 49)
	{
		dur_time = 1000;
	}
	if (dur_time < 10)
	{
		dur_time = 10;
	}
//	dur_time = 30;
    me->add("neili", -175-random(50));
	me->set_temp("daoluan_start_time",time());
    me->set_temp("active_buffer/yinyang-daoluan.daoluan/name", "倒乱刃法");                  //buff名称
    me->set_temp("active_buffer/yinyang-daoluan.daoluan/last_time", time() + dur_time );               //持续时间
	me->set_temp("active_buffer/yinyang-daoluan.daoluan/effect1", "攻击速度+"+eff+"%");   //效果描述1
	me->set_temp("yinyang-daoluan/daoluan",1);
	me->add_temp("apply/attack_speed", eff);
	call_out("check_daoluan",4,me,eff);
	call_out("remove_dl_eff", dur_time, me, eff); 
    message_vision(msg, me, target);
    me->start_busy(2);
    return 1;
}

void check_daoluan(object me,int count)
{	mapping sk_map=([]);
    /*object weapon;
	if (!objectp(weapon = me->query_temp("secondary_weapon")) || (string)weapon->query("skill_type") != "blade")
	{
		call_out("remove_dl_eff", 1, me, count); 
		return;
	}*/
	sk_map = me->query_skill_map();
	if (sk_map["sword"]!="yinyang-daoluan"||sk_map["blade"]!="yinyang-daoluan")
	{
		call_out("remove_dl_eff", 1, me, count);
		return;
	}
	if (me->query_temp("yinyang-daoluan/daoluan"))
	{
		call_out("check_daoluan",4,me,count);
	}
}



void remove_dl_eff(object me, int amount)
{	
    if( me->query_temp("yinyang-daoluan/daoluan")) 
	{
		me->delete_temp("yinyang-daoluan/daoluan");
		me->delete_temp("apply/attack_speed", amount);
        me->delete_temp("active_buffer/yinyang-daoluan.daoluan");
        message_vision(CYN "$N的「倒乱刃法」已使用完毕，攻势缓了下来。\n"NOR,me);
	}
//	remove_call_out();
}


