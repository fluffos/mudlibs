#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int calc_damage(int,int); 
int perform(object me, object target)
{
	int extra;
	object weapon,ob;
	string msg,result;
	int i,j,k,total; 
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
	extra = me->query_skill("shenlong-bashi",1);
        if( !target ) target = offensive_target(me);
if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("「美人三招」只能在战斗中使用。\n");
 
	if (me->query("gender") != "女性")
		return notify_fail("你不是纯阴之体，不能用美人三招！\n");

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("「美人三招」只能空手使用。\n");		
	if( (int)me->query_skill("huagu-mianzhang", 1) < 50 )
		return notify_fail("你的化骨绵掌还不够熟练，不能使用「美人三招」！\n");

	if( (int)me->query_skill("shenlong-tuifa", 1) < 50 )
		return notify_fail("你的神龙腿法还不够熟练，不能使用「美人三招」！\n");

       
        if ((int)me->query_skill("shenlong-xinfa", 1) < 60 )
        return notify_fail(RED"你神龙心法火候不够。\n"NOR);

	 if( (int)me->query("neili") < 200 )
                return notify_fail("你的真气不够！\n");

        if( (int)me->query_skill("shenlong-bashi",1) < 70 )
                return notify_fail("你的神龙八式火候不够，无法使用「美人三招」！\n");

        if( (int)me->query_skill("force",1) < 60 )
                return notify_fail("你的内功修为不够，无法使用「美人三招」！\n");
if ((int)me->query_skill("shenlong-xinfa",1) >250
&& me->query("neili") >1000)
{

         if (random(me->query_skill("dodge")) > target->query_skill("dodge") / 2)
        {                
        msg = HIW "第一道毒气"+HIR+"击中$n右身，！\n"NOR;   
        message_vision(msg, me, target);
        target->apply_condition("snake_poison",60);
        }
        if (me->query("combat_exp")> target->query("combat_exp")/2 )
        {                
        msg = HIC "第二道毒气"+HIM+"扫中$n的左身！\n"NOR;   
                message_vision(msg, me, target);
        target->apply_condition("wugong_poison",60);
        }
        if (random(me->query_skill("force")) > target->query_skill("force") / 2)
        {                
        msg = MAG "最后一道毒气"+HIB+"扫中$n的上身!\n"NOR;   
        message_vision(msg, me, target);
        target->apply_condition("chanchu_poison",60);
        }
	target->apply_condition("ill_fashao",60);
	target->apply_condition("ill_kesou",60);
	target->apply_condition("ill_shanghan",60);
	target->apply_condition("ill_zhongshu",60);
	target->apply_condition("ill_dongshang",60);

	target->start_busy(1);
	me->add("jing",-10);
	me->add("neili",-200);

	i = (me->query_skill("shedao-qigong") + me->query_skill("hand") + me->query_skill("strike")) /3 ;
	j = (target->query_skill("force") + target->query_skill("dodge") + target->query_skill("parry"))/3;

	k = (-me->query("shen"))*100 / 3000000;
	if(k>1000) k=1000;
	if(k<-1000) k=-1000;
	i = i*(1000+k/3)/1000;
	k = 1000 + k/2;

	if(wizardp(me)) tell_object(me,sprintf("\nattack: %d , parry: %d  , shen: %d \n",i,j,k));

	msg = HIR"$N乘$n稍稍走神之机，拼尽全力使出苏夫人不传之绝技－－「美人三招」"NOR;

	if( (random(me->query("combat_exp"))+300000) > (int)target->query("combat_exp")/2 ) {
		me->start_busy(1);
		me->add("neili",-random(800));
		me->add("jing",-random(10));

		total = 0;

		msg += 
MAG "\n\n$N使出一招「贵妃回眸」，身子微曲，纤腰轻扭，左足反踢，向$n小腹踢去，
而后顺势反身，左手搂住$n头颈，右手兵刃对准$n后心击去。\n"NOR;
		i = calc_damage(me->query_skill("huagu-mianzhang",1),k);
		total += i;
		if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",i));
		target->receive_damage("qi", i, me );
		target->receive_wound("qi", i/2 , me);
		result = COMBAT_D->damage_msg(i,"瘀伤");
		result = replace_string( result, "$l", "头颈" );
		msg += result;
		message_vision(msg,me,target);
		COMBAT_D->report_status(target, 0);	

		msg =
MAG "\n$N使出一招「小怜横陈」，脑袋蓦地向自己胸口钻落，顺势在地上一个斛斗，
从$n胯下钻过，握着兵器的右手成拳击向$n后心。\n"NOR;
		i = calc_damage(me->query_skill("shenlong-bashi",1),k);
		total += i;
		if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",i));
		target->receive_damage("qi", i, me );
		target->receive_wound("qi", i/2 , me);
		result = COMBAT_D->damage_msg(i,"刺伤");
		result = replace_string( result, "$l", "后心" );
//		result = replace_string( result, "$w", weapon->query("name") );
		msg += result;
		message_vision(msg,me,target);
		COMBAT_D->report_status(target, 0);	

		msg = 
MAG "\n$N使出一招「飞燕回翔」，右足顺势一勾，在兵器上一点，兵器陡地向$N咽喉
射过去，$N身子向下一缩，那兵器急射$n胸口。\n"NOR;
		i = calc_damage(me->query_skill("shenlong-tuifa",1),k);
		total += i;
		if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",i));
		target->receive_damage("qi", i, me );
		target->receive_wound("qi", i/2 , me);
		result = COMBAT_D->damage_msg(i,"内伤");
		result = replace_string( result, "$l", "胸口" );
		msg += result;
		message_vision(msg,me,target);
		COMBAT_D->report_status(target, 0);	

		if(wizardp(me)) tell_object(me,sprintf("Total damage: %d \n",total));

//		me->start_perform(3,"「美人三招」");
	}
	else {
		msg += 
MAG "\n\n$N使出一招「贵妃回眸」，身子微曲，纤腰轻扭，左足反踢，向$n小腹踢去，
而后顺势反身，左手搂住$n头颈，右手兵刃对准$n后心击去。\n"NOR;
		msg += "但是$n看破了$N的企图，没有上当，急急忙忙向旁边一闪，躲了过去。\n";
		msg += 
MAG "\n$N使出一招「小怜横陈」，脑袋蓦地向自己胸口钻落，顺势在地上一个斛斗，
从$n胯下钻过，握着兵器的右手成拳击向$n后心。\n"NOR;
		msg += "$n吃了一惊，但随即冷静下来，在空中猛一蹬腿踢向$N面门，$N只得松开了手。\n";
		msg += 
MAG "\n$N使出一招「飞燕回翔」，右足顺势一勾，在兵器上一点，兵器陡地向$N咽喉
射过去，$N身子向下一缩，那兵器急射$n胸口。\n"NOR;
		msg += "$n被$N制住，但临危不乱，以内力护住要害，同时高高跃起，翻身以头撞地，把$N撞了出去！\n";

		message_vision(msg,me,target);
		me->start_busy(2);
//		me->start_perform(2,"「美人三招」");
	}
}
else {
	me->add_temp("apply/attack",2*extra);
	me->add_temp("apply/damage",2*extra);
	me->add_temp("apply/dexerity",extra);
	me->add_temp("apply/dodge",extra);
	weapon = me->query_temp("weapon");

        msg = CYN "$N动作抚媚，朝$n微微一笑"HIY"[美人三招]"CYN"！" NOR;
       	         message_vision(msg, me, target);                
	 msg =  RED  "-------------贵妃回眸！" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
         if (random(me->query_skill("dodge")) > target->query_skill("dodge") / 2)
        {                
        msg = HIW "第一道毒气"+HIR+"击中$n右身，！\n"NOR;   
        message_vision(msg, me, target);
        target->apply_condition("snake_poison",60);
        }
        msg = GRN   "-------------------飞燕回翔！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (me->query("combat_exp")> target->query("combat_exp")/2 )
        {                
        msg = HIC "第二道毒气"+HIM+"扫中$n的左身！\n"NOR;   
                message_vision(msg, me, target);
        target->apply_condition("wugong_poison",60);
        }
        msg =  MAG  "-------------------------小怜横陈！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (random(me->query_skill("force")) > target->query_skill("force") / 2)
        {                
        msg = MAG "最后一道毒气"+HIB+"扫中$n的上身!\n"NOR;   
        message_vision(msg, me, target);
        target->apply_condition("chanchu_poison",60);
        }
	target->apply_condition("ill_fashao",60);
	target->apply_condition("ill_kesou",60);
	target->apply_condition("ill_shanghan",60);
	target->apply_condition("ill_zhongshu",60);
	target->apply_condition("ill_dongshang",60);

	me->add_temp("apply/attack",-2*extra);
	 me->add_temp("apply/damage",-2*extra);
	me->add_temp("apply/dexerity",-extra);
	me->add_temp("apply/dodge",-extra);
        me->add("neili", -150);
        me->start_busy(3);
}
        return 1;
}

int calc_damage(int skill,int k)
{
	int i;

	if(skill>200)
		i = (200*5 + (skill-200)*40/10) * k/1000;
	else
		i = (skill * k/1000) * 5;
	i = i/2 + random(i/2);
	if(i>1500) i=1500;

	return i;
}

