#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{
        string *style_siqi = ({
HIG "小苑莺歌歇－－$N舒臂轻弹手中$w，直刺$n的$l！\n" NOR,
HIG "长门蝶舞多－－$N手中$w化做流云，飘向$n的$l！\n" NOR,
HIG "眼看春又去－－$N纤腰摆动，手中$w似流水般袭向$n的$l！\n" NOR,
HIG "翠辇不曾过－－$N手中$w似重逾千斤，磕向$n的$l！\n" NOR
});
/*
       string *style_qiusheng= ({
HIR "江山如画－－$N纵身跃起，直上青天，手中$w大力劈出，自上而下攻向$n的$l！\n" NOR,
HIR "余音袅袅－－$N心神合一，刀力自手中$w呼啸而出，狂奔$n的$l！\n" NOR,
HIR "声景交融－－$N暴喝一声，手中$w圈转，啸音反强，刀光啸音浑然一体，滚向$n的$l！\n" NOR
});
*/
        string *style_mix= ({
HIG "小苑莺歌歇－－$N舒臂轻弹手中$w，直刺$n的$l！\n" NOR,
HIR "江山如画－－$N纵身跃起，直上青天，手中$w大力劈出，自上而下攻向$n的$l！\n" NOR,
HIG "长门蝶舞多－－$N手中$w化做流云，飘向$n的$l！\n" NOR,
HIR "余音袅袅－－$N心神合一，刀力自手中$w呼啸而出，狂奔$n的$l！\n" NOR,
HIG "眼看春又去－－$N纤腰摆动，手中$w似流水般袭向$n的$l！\n" NOR
HIR "声景交融－－$N暴喝一声，手中$w圈转，啸音反强，刀光啸音浑然一体，滚向$n的$l！\n" NOR,
HIG "翠辇不曾过－－$N手中$w似重逾千斤，磕向$n的$l！\n" NOR,
});

        string msg;
	int skl_me, skl_you, extra_me, extra_you,i;
	int FLAG=0;
	object you,ob,*obs;
	object weapon;
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail(HIM "［彩蝶念花］只能对战斗中的对手使用。\n"NOR);

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade")
		return notify_fail("你使用的武器不是刀。\n");

	if( (int)me->query_skill("zhaosheshu", 1) < 150 )
		return notify_fail("你的招蛇术不够娴熟。\n");

	if( (int)me->query_skill("shenlong-bashi", 1) < 250 )
		return notify_fail("你的神龙八式不够娴熟。\n");

	if( (int)me->query_skill("shenlong-xinfa", 1) < 150 )
		return notify_fail("你的本门内功不够娴熟。\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("你内力不够了。\n");


	if(pointerp(obs=me->query_team()) )
	{
	FLAG=1;
	for(i=0;i<sizeof(obs);i++)
	{
	if(obs[i] == me) continue;
	if(!obs[i]) {FLAG=0; continue;}
	if(environment(obs[i]) != environment(me)) {FLAG=0; continue;}
	if(!obs[i]->query_skill("shenlong-bashi")) {FLAG=0; continue;}
	if(!objectp(ob=obs[i]->query_temp("weapon"))) {FLAG=0; continue;}
	if(ob->query("skill_type") != "parry"){FLAG=0; continue;}
	if(obs[i]->query_skill_mapped("parry") != "shenlong-bashi") {FLAG=0; continue;}
	}	
	if(sizeof(obs) !=2) FLAG=0;
	}
	skl_me=(int)me->query_skill("parry");
	extra_me=(int)me->query_temp("apply/damage")+(int)me->query_str()*(int)me->query_str()/30;
	if(FLAG)
	{
		if(obs[0]==me) you=obs[1]; else you=obs[0];
	skl_you=(int)you->query_skill("parry");
	extra_you=(int)you->query_temp("apply/damage")+(int)you->query_str()*(int)you->query_str()/30;
        me->add_temp("apply/attack",(skl_you+skl_me)/4);
        me->add_temp("apply/damage",(extra_you+extra_me)/2);
        you->add_temp("apply/attack",(skl_you+skl_me)/4);
        you->add_temp("apply/damage",(extra_you+extra_me)/2);
        you->kill_ob(target);
	for(i=0;i<sizeof(style_mix);i++)
	if(i%2) COMBAT_D->do_attack(you,target,you->query_temp("weapon"),TYPE_REGULAR,style_mix[i]);
	else    COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,style_mix[i]);
        me->add_temp("apply/attack",-(skl_you+skl_me)/4);
        me->add_temp("apply/damage",-(extra_you+extra_me)/2);
        you->add_temp("apply/attack",-(skl_you+skl_me)/4);
        you->add_temp("apply/damage",-(extra_you+extra_me)/2);
	}
	else
	{
        me->add_temp("apply/attack",skl_me/10);
        me->add_temp("apply/damage",extra_me/3);
        for(i=0;i<sizeof(style_siqi);i++)
        COMBAT_D->do_attack(me,target,me->query_temp("weapon"),TYPE_REGULAR,style_siqi[i]);
        me->add_temp("apply/attack",-skl_me/10);
        me->add_temp("apply/damage",-extra_me/3);
	}	
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
        me->add("neili",-300);
	me->start_busy(2);
	return 1;
}
