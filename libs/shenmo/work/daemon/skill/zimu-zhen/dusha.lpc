#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra,i,lmt,l;
	int skill, ap, dp, neili_wound, qi_wound;
	object weapon;
       if( !target ) target = offensive_target(me);
       if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("只能对战斗中的对手使用。\n");
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "throwing")
		return notify_fail("你使用的武器不对。\n");
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("你的内力不够。\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("你的内力不够。\n");

       if( !wizardp(me) &&(int)me->query_skill("biye-wu", 1) < 500 )
		return notify_fail("你的本门外功不够!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("zimu-zhen", 1) < 500 )
		return notify_fail("你的本门外功不够高!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("biyun-xinfa", 1) < 500 )
		return notify_fail("你的本门内功不够高!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("你的江湖经验还不够，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("你还没有通过华山论剑! 无法对本门武功贯通使用！\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "biyun-xinfa")
                return notify_fail("不使用本门内功，如何使用本门绝学!\n");


        msg = HBWHT "$N贯通唐门武学，使出了唐门的绝学之精髓！\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);    		
	weapon = me->query_temp("weapon");
	extra = me->query_skill("zimu-zhen",1);
if (random(3)==0) target->start_busy(3);
	msg = GRN  "$N使出唐门暗器中的七子钢镖，击向$n" NOR;
	message_vision(msg,me,target);
	me->add_temp("apply/attack",extra/3);
	me->add_temp("apply/damage",extra);
        l=extra/30;
	lmt = random(l)+5;
	if (lmt>12) lmt=12;
	for(i=1;i<=lmt;i++)
	{
	msg =  BLU "第"+chinese_number(i)+"镖" NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	}
        me->add_temp("apply/attack",-extra/3);
        me->add_temp("apply/damage",-extra);
	me->start_busy(4);
	msg = HIW "$N突然收掌，然后迅速发掌! 掌中尽然有毒砂，这掌风尽然是五颜六色的！！\n";
	msg += HIG "$N双目突然泛过怪异绿光,中指在不易察觉间微微一动,一点银星悄无声息打向$n眉心。\n"NOR;
        target->apply_condition("chanchu_poison", 60);
        target->apply_condition("xiezi_poison", 60);
        target->apply_condition("wugong_poison", 60);
        target->apply_condition("snake_poison", 60);
        target->apply_condition("zhizhu_poison", 60);
        target->apply_condition("tmzhuihun_poison", 60);
        target->apply_condition("tmpili_poison", 60);
        target->apply_condition("zm_poison", 60);
	if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
        target->apply_condition("tmqidu_poison", 60);
	} 
        msg += HIR"$n硬起头皮，以掌硬接！！结果身中巨毒！\n" NOR;
        message_vision(msg,me,target);

	msg = HIY "$N并指入刀，指缝间夹着三枚暗器,潜运内力，一式「破气针」，直奔$n的上、中、下丹田打去。\n";
	message_vision(msg, me, target);
 
	ap = me->query_skill("throwing") + skill;
	dp = target->query_skill("force") / 2;
	if( dp < 1 )
		dp = 1;

	if( random( (int)me->query("combat_exp",1))
          > target->query("combat_exp")/3  ) {
		msg = "$N「破气针」正中目标, $n顿时觉得丹田上一阵刺痛，\n";
		msg += "全身真气狂泄而出！\n" NOR;

		neili_wound = 600 + random(skill);
		if(neili_wound > target->query("neili"))
			neili_wound = target->query("neili");

		qi_wound = neili_wound / 5;
		if(qi_wound > target->query("qi"))
			qi_wound = target->query("qi");
            target->receive_damage( "qi",extra*3);
            target->receive_wound( "qi",extra*6);
       	    target->add("neili", -neili_wound);
	}
	else
	{
			me->add("neili",-80);
		msg = "可是$n瞬间反应过来，腾挪跳跃，躲过了这次重创。\n"NOR;
	}
	message_vision(msg, me, target);
	return 1;
}

