// by bugbug & alading @ 缥缈水云间, 2003-4-5
// yudian 2000-11-14
// zouxiao.c  碧箫传情
// modified by advent@pkuxkx and iszt@pkuxkx, 2007-02-14

#include <ansi.h>
#include <char.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
	string msg;
	int damage, ap, dp, qixue, eff_qi, max_qi, qi_pcg;
	object weapon = me->query_temp("weapon");

	if( !target ) target = offensive_target(me);

	if( !target || !target->is_character() || target->is_corpse() )
		return notify_fail("你要对谁奏箫？\n");

    if( !me->is_fighting(target) )
        return notify_fail("大家都很忙，没人有时间听你吹吹打打。\n");

    if( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FAMILY) && 
        me->query("family/family_name") != "桃花岛")
		return notify_fail("「碧海潮生曲」是桃花岛不传之密！\n");

	if (!objectp(me->query_temp("weapon"))
		|| (string)me->query_temp("weapon")->query("id") != "yu xiao")
		return notify_fail("你必须使用玉箫才能吹奏「碧海潮生曲」。\n");

/*	if (me->query_skill_mapped("sword")!="yuxiao-jian")
		return notify_fail("只有用玉箫剑法才能吹奏「碧海潮生曲」。\n"); */

	if ( !(me->query_temp("ignore_pfm_limit") & IGNORE_PFM_LIMIT_FORCE) &&
         me->query_skill_mapped("force")!="bihai-shengong")
		return notify_fail("只有用碧海神功才能吹奏「碧海潮生曲」。\n");

	if (me->query_skill("yuxiao-jian",1)<50)
		return notify_fail("你的玉箫剑法还得再练练。\n");

	if (me->query_sub_skill("music::shaw",1)<200)
		return notify_fail("你奏箫的功夫还不够，再好好练练吧。\n");

	if (target->query_skill("literate",1)<100)
		return notify_fail("对他吹箫？还不如对牛弹琴呢。\n");

	if((int)me->query("neili") < 200 )
		return notify_fail("你的内力还不到火候。\n");

	if((int)me->query("qi") < 200 )
		return notify_fail("你的体力已经不够了！\n");

	if((int)me->query("jing") < 200 )
		return notify_fail("你无法集中精力！\n");

	if(me->query_temp("no_zouxiao") > time())
		return notify_fail("你一口气没接上，吹不出声音来！\n");

	me->set_temp("no_zouxiao",time()+5);    

	msg = HIC "\n$N举起"+weapon->query("name")+HIW"，对着$n奏起了一曲，箫声凄凉，"
		  +"似是叹息，又似哭泣，跟着箫声颤抖，发出瑟瑟断续之音，如一滴滴小雨落上树叶。\n" NOR,
	me->add("jing", -50);
	me->add("neili", -150);

	damage = (int)me->query_skill("yuxiao-jian",1) + (int)me->query_skill("literate", 1)/2+(int)me->query_sub_skill("music::shaw", 1)/2;
	damage = damage + random(damage);
	damage = damage*8/10;

	ap = (int)me->query_skill("sword", "yuxiao-jian")+(int)me->query_skill("force", "bihai-shengong");
	ap = ap/10;
	ap = ap* ap * ap;
	ap = ap + (int)me->query("combat_exp")/100;
	dp =  (int)target->query_skill("parry")/3
	     +(int)target->query_skill("dodge")/3
	     +(int)target->query_skill("literate",1)/5
	     +(int)target->query_skill("force");
	dp = dp/10;
	dp = dp * dp * dp;   
	dp = dp + (int)target->query("combat_exp")/100;
	
        ap = ap/10;
        dp = dp/10;
	if( wizardp(me) )
	{
		tell_object(me,sprintf("ap = %d\t",ap));
		tell_object(me,sprintf("dp = %d\n",dp));
	}
//旧的几率函数是rand(100*ap/dp)<14 和 rand(100*ap/dp)<25
//在ap=dp的时候几率下降2.5%和5%，但是ap=dp/2的时候几率上升了17%和5%，应当说大多数情况下略有损失，但是某些情况下获得几率提升。 
//by seagate@pkuxkx
	if( F_KUNGFU->hit_rate( dp, ap, 16+random(2), me, target) ) //小于号右端设为a
	{
		msg += HIW "$n冲着$N不屑的冷笑道：就这点本事，也来贻笑大方？"
			+"$N顿时羞愧难当。\n"NOR;
		message_vision(msg, me, target);
		me->start_busy(1+random(3));
	} 
	else if( F_KUNGFU->hit_rate( dp, ap, 14+random(3), me, target) ) //小于号右端设为b
	{
		msg += HIW "可$n充耳不闻，不为所动。\n"NOR;
		message_vision(msg, me, target);
		me->start_busy(random(3));
	} 
	else 
	{
		F_KUNGFU->hit_wound("jing", damage, damage/2, me, target);
		//对精的伤害icer似乎建议过慎行，有的npc可能精很短
		msg += HIR "$n听了箫声，心中莫名其妙的感到一阵酸楚，悲从中来，泪水正涔涔落下。\n"NOR;
		message_vision(msg, me, target);
        COMBAT_D->report_status(target);
     
    if ( !target->is_busy() )
		target->start_busy(3+random(3));
		me->start_busy(random(2));
	}
	//假设ap=dp
	//那么，第一种情况P(1)的概率为a/100；
	//	第二种情况P(2)的概率为(1-a/100)*b/100；
	//	第二种情况P(3)的概率为(1-a/100)*(1-b/100)。
	//设a=14，b=25，则P(1)=0.14，P(2)=0.215，P(3)=0.645
	//假设ap=dp/2
	//那么，第一种情况P(1)的概率为a/50；
	//	第二种情况P(2)的概率为(1-a/50)*b/50；
	//	第二种情况P(3)的概率为(1-a/50)*(1-b/50)。
	//设a=14，b=25，则P(1)=0.28，P(2)=0.36，P(3)=0.36
	//就是这样。

	return 1;
}
