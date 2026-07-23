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
                return notify_fail("「英雄三式」只能在战斗中使用。\n");
 
	if (me->query("gender") != "男性")
		return notify_fail("你不是纯阳之体，不能用英雄三式！\n");

	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("「英雄三式」只能空手使用。\n");		

	if( (int)me->query_skill("huagu-mianzhang", 1) < 50 )
		return notify_fail("你的化骨绵掌还不够熟练，不能使用「英雄三招」！\n");

	if( (int)me->query_skill("shenlong-tuifa", 1) < 50 )
		return notify_fail("你的神龙腿法还不够熟练，不能使用「英雄三招」！\n");
       
	 if( (int)me->query("neili") < 200 )
                return notify_fail("你的真气不够！\n");

        if( (int)me->query_skill("shenlong-bashi",1) < 70 )
                return notify_fail("你的神龙八式火候不够，无法使用「英雄三式」！\n");

        if ((int)me->query_skill("shenlong-xinfa", 1) < 60 )
        return notify_fail(RED"你神龙心法火候不够。\n"NOR);

        if( (int)me->query_skill("force",1) < 60 )
                return notify_fail("你的内功修为不够，无法使用「英雄三式」！\n");
if ((int)me->query_skill("shenlong-xinfa",1) >250
&& me->query("neili") >1000)
{
         if (random(me->query_skill("dodge")) > target->query_skill("dodge") / 2)
        {                
        msg = HIW "第一道毒气"+HIR+"击中$n右身，！\n"NOR;   
        message_vision(msg, me, target);
        target->apply_condition("snake_poison",50);
        }
        if (me->query("combat_exp")> target->query("combat_exp")/2 )
        {                
        msg = HIC "第二道毒气"+HIM+"扫中$n的左身！\n"NOR;   
                message_vision(msg, me, target);
        target->apply_condition("wugong_poison",50);
        }
        if (random(me->query_skill("force")) > target->query_skill("force") / 2)
        {                
        msg = MAG "最后一道毒气"+HIB+"扫中$n的上身!\n"NOR;   
        message_vision(msg, me, target);
        target->apply_condition("chanchu_poison",50);
        }
	target->apply_condition("ill_fashao",50);
	target->apply_condition("ill_kesou",50);
	target->apply_condition("ill_shanghan",50);
	target->apply_condition("ill_zhongshu",50);
	target->apply_condition("ill_dongshang",50);

	target->start_busy(1);
	me->add("jing",-10);
	me->add("neili",-200);

	i = (me->query_skill("shedao-qigong") + me->query_skill("hand") + me->query_skill("strike")) /3 ;
	j = (target->query_skill("force") + target->query_skill("dodge") + target->query_skill("parry"))/3;

	k = (-me->query("shen"))*100 / 300000;
	if(k>1000) k=1000;
	if(k<-1000) k=-1000;
	i = i*(1000+k/3)/1000;
	k = 1000 + k/2;

	if(wizardp(me)) tell_object(me,sprintf("\nattack: %d , parry: %d  , shen: %d \n",i,j,k));

	msg = HIR"$N乘$n稍稍走神之机，拼尽全力使出洪教主不传之绝技－－「英雄三招」\n"NOR;

	if( (random(me->query("combat_exp"))+300000) > (int)target->query("combat_exp")/2 ) {
		me->start_busy(1);
		me->add("neili",-random(800) );
		me->add("jing",-random(40));

		total = 0;

		msg += HIY "\n$N使出一招「子胥举鼎」，一手轻搔$n腋底极泉穴，乘其慌张之际，另一手同\n时拿向$n肘后小海穴，将其摔向地上。\n\n"NOR;
		i = calc_damage(me->query_skill("huagu-mianzhang",1),k);
		total += i;
		if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",i));
		target->receive_damage("qi", i, me );
		target->receive_wound("qi", i/2 , me);
		result = COMBAT_D->damage_msg(i,"瘀伤");
		result = replace_string( result, "$l", "小海穴" );
		msg += result;
		message_vision(msg,me,target);
		COMBAT_D->report_status(target, 0);	

		msg =
HIY "\n$N使出一招「鲁达拔柳」，缩腿假装向$n叩头，突然一个斛斗，似欲向$n胯下
钻过，但只一作势，左手抓向$n右脚足踝，右手兵器虚点向$n小腹，一用力，把$n头下
脚上，倒提起来。\n"NOR;
		i = calc_damage(me->query_skill("shenlong-bashi",1),k);
		total += i;
		if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",i));
		target->receive_damage("qi", i, me );
		target->receive_wound("qi", i/2 , me);
		result = COMBAT_D->damage_msg(i,"刺伤");
		result = replace_string( result, "$l", "小腹" );
//		result = replace_string( result, "$w", weapon->query("name") );
		msg += result;
		message_vision(msg,me,target);
		COMBAT_D->report_status(target, 0);	

		msg = 
HIY "\n$N使出一招「狄青降龙」，背脊后撞，十指向$n胸口虚抓，乘其避让之际，
突然一个倒翻斛斗，身子跃起，双腿一分，跨坐在$n肩头，同时双手拇指压住$n
太阳穴，食指按眉，中指按眼。\n"NOR;
		i = calc_damage(me->query_skill("shenlong-tuifa",1),k);
		total += i;
		if(wizardp(me)) tell_object(me,sprintf("damage: %d \n",i));
		target->receive_damage("qi", i, me );
		target->receive_wound("qi", i/2 , me);
		result = COMBAT_D->damage_msg(i,"内伤");
		result = replace_string( result, "$l", "头部" );
		msg += result;
		message_vision(msg,me,target);
		COMBAT_D->report_status(target, 0);	

		if(wizardp(me)) tell_object(me,sprintf("Total damage: %d \n",total));

//		me->start_perform(3,"「英雄三招」");
	}
	else {
		msg += HIY "\n$N使出一招「子胥举鼎」，一手轻搔$n腋底极泉穴，乘其慌张之际，另一手同\n时拿向$n肘后小海穴，将其摔向地上。\n"NOR;
		msg += "但是$n看破了$N的企图，没有上当，急急忙忙向旁边一闪，躲了过去。\n";
		msg += 
HIY "\n$N使出一招「鲁达拔柳」，缩腿假装向$n叩头，突然一个斛斗，似欲向$n胯下
钻过，但只一作势，左手抓向$n右脚足踝，右手兵器虚点向$n小腹，一用力，把$n头下
脚上，倒提起来。\n"NOR;
		msg += "$n吃了一惊，但随即冷静下来，在空中猛一蹬腿踢向$N面门，$N只得松开了手。\n";
		msg += 
HIY "\n$N使出一招「狄青降龙」，背脊后撞，十指向$n胸口虚抓，乘其避让之际，
突然一个倒翻斛斗，身子跃起，双腿一分，跨坐在$n肩头，同时双手拇指压住$n
太阳穴，食指按眉，中指按眼。\n"NOR;
		msg += "$n被$N制住，但临危不乱，以内力护住要害，同时高高跃起，翻身以头撞地，把$N撞了出去！\n";

		message_vision(msg,me,target);
		me->start_busy(2);
//		me->start_perform(2,"「英雄三招」");
	}
} else {
	me->add_temp("apply/attack",2*extra);
	me->add_temp("apply/damage",2*extra);
	me->add_temp("apply/dexerity",extra);
	me->add_temp("apply/dodge",extra);
	weapon = me->query_temp("weapon");

      msg = CYN "$N深吸一口气，朝$n大叫一声"HIY"[英雄三式]"CYN"！" NOR;
       	         message_vision(msg, me, target);                
	 msg =  RED  "-------------狄龙降龙！" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        if (random(me->query_skill("dodge")) > target->query_skill("dodge") / 2)
        {                
        msg = HIW "第一道毒气"+HIR+"击中$n右身，！\n"NOR;   
        message_vision(msg, me, target);
        target->apply_condition("snake_poison",50);
        }
        msg = GRN   "-------------------子胥举鼎！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        if (me->query("combat_exp")> target->query("combat_exp")/2 )
        {                
        msg = HIC "第二道毒气"+HIM+"扫中$n的左身！\n"NOR;   
                message_vision(msg, me, target);
        target->apply_condition("wugong_poison",50);
        }
        msg =  MAG  "-------------------------鲁达拔柳！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        if (random(me->query_skill("force")) > target->query_skill("force") / 2)
        {                
        msg = MAG "最后一道毒气"+HIB+"扫中$n的上身!\n"NOR;   
        message_vision(msg, me, target);
        target->apply_condition("chanchu_poison",50);
        }
	target->apply_condition("ill_fashao",50);
	target->apply_condition("ill_kesou",50);
	target->apply_condition("ill_shanghan",50);
	target->apply_condition("ill_zhongshu",50);
	target->apply_condition("ill_dongshang",50);

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


