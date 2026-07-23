// posha 破杀灭
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#include "/kungfu/skill/eff_msg.h";
void remove_effect(object me, int f, int j);

int perform(object me)
{
        object weapon,victim_w,armor,ring;
        int damage,p,i;
        string msg,dodge_skill;
object target;        
        int attack_time,extra;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
 return notify_fail(RED"你要对谁使用「破杀灭」。\n"NOR);


	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("你的内力不够。\n");

	if ((int)me->query_skill("force", 1) < 300)
		return notify_fail("你的内功修为还不够。\n");

	if( (int)me->query("max_neili") < 2000 )
		return notify_fail("你的内力修为不够。\n");

	if (me->query_skill("never-defeated", 1) < 100)
		return notify_fail("你的不败神功还不够娴熟，不能使用破杀灭！\n");

        if (! objectp(weapon = me->query_temp("weapon")))
                return notify_fail("你必须手持兵刃才能施展破杀灭！\n");

//       if( !me->query("zhuanbest",1))
//        return notify_fail("你没有资格使用这项技能！\n");

       if( !me->query("4zhuan") && !me->query("5zhuan"))
        return notify_fail("你没有资格使用这项技能！\n");

        if (me->query("neili") < 200)
                return notify_fail("你的内力不够！\n");
 
       if (! living(target))
              return notify_fail("对方都已经这样了，用不着这么费力吧？\n");     

        if (target->is_busy()) 
		return notify_fail("对方正忙着呢，赶快攻击吧！\n");		        
        msg = HBWHT "$N斗气暴发，贯通武学之精髓，使出了破气之绝学！\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);

        msg = HIR "$N使出「破杀灭」，五道真气，刺向$n的全身！\n";

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/4 ) {
        msg += HIR "\n 破穴灭 ！$p被真气点中全身穴位！\n" NOR;
                target->start_busy( (int)me->query_skill("force",1) / 60 + 3 );
        i=(int)me->query_skill("force",1) / 60 + 3;
       if (wizardp(me)) msg += HIR "\n 点穴时间"+i+"秒。\n" NOR;
if (userp(target))
{
        msg += HIY " 破防灭 ！$p全身的防御完全被破坏！\n" NOR;
       if (target->query_temp("apply/armor") > 1)
        target->set_temp("apply/armor", target->query_temp("apply/armor")/2);
        if (target->query_temp("apply/dodge") > 1)
        target->set_temp("apply/dodge", target->query_temp("apply/dodge")/2);
        if (target->query_temp("apply/defense") > 1)
        target->set_temp("apply/defense", target->query_temp("apply/defense")/2);

        msg += HIW " 破攻灭 ！$p使用的招式完全被封死！\n" NOR;
       if (target->query_temp("apply/attack") > 1)
        target->set_temp("apply/attack", target->query_temp("apply/attack")/2);
        if (target->query_temp("apply/damage") > 1)
        target->set_temp("apply/damage", target->query_temp("apply/damage")/2);

        msg += HIB " 破体灭 ！$p的力量和速度完全被打乱！\n" NOR;
        if (target->query_temp("apply/strength") > 1)
        target->set_temp("apply/strength",target->query_temp("apply/strength")/2);
        if (target->query_temp("apply/dexerity") > 1)
        target->set_temp("apply/dexerity",target->query_temp("apply/dexerity")/2);
        if (target->query_temp("apply/intelligence") > 1)
        target->set_temp("apply/intelligence",0);
}
        msg += HIC " 破器灭 ！$p的武器和防具失去了作用！\n\n" NOR;
        if( target->query_temp("armor/cloth")){
        armor = target->query_temp("armor/cloth");
	armor->unequip();
	armor->reset_action();
        }

        if( target->query_temp("armor/shield")){
        ring = target->query_temp("armor/shield");
	ring->unequip();
	ring->reset_action();
        }

        if( target->query_temp("armor/ring")){
        ring = target->query_temp("armor/ring");
	ring->unequip();
	ring->reset_action();
        }

        if( target->query_temp("armor/gem")){
        ring = target->query_temp("armor/gem");
	ring->unequip();
	ring->reset_action();
        }

        if( target->query_temp("armor/armor")){
        ring = target->query_temp("armor/armor");
	ring->unequip();
	ring->reset_action();
        }
        
	if (target->query_temp("weapon")){
	victim_w = target->query_temp("weapon");
        victim_w->unequip();
	victim_w->reset_action();
        }
        
        } else {
                msg += HIG"可是$p认识$P的历害，逃出了攻击范围。\n" NOR;
                me->start_busy(2);
        }
if (me->query("zhuanfinal/4") ==1 && random(2)==0)
{
                if (me->query("qi") < me->query("max_qi") )
                me->add("qi", me->query("max_qi") / 8);
                if (me->query("eff_qi",1) < me->query("max_qi",1) )
                me->add("eff_qi",me->query("max_qi")/8);
                if (me->query("qi") < me->query("max_qi") )

	msg += HIY"$N使用了妙仙决!!$N全身的伤好了很多!\n"NOR;
}
else
if (me->query("zhuanfinal/5") ==1 && random(2)==0)
{
if (me->is_busy() )
me->start_busy(1);
if (!target->is_busy() )
target->start_busy(2);
	msg += HIY"$N使用了动仙决!!$N突然动作又快了!\n"NOR;
}
else
if (me->query("zhuanfinal/6") ==1 && random(2)==0)
{
                if (me->query("neili") < me->query("max_neili") )
                me->add("neili", me->query("max_neili") / 8);
	msg += HIY"$N使用了银仙决!!$N突然内力恢复了!\n"NOR;
}
        message_combatd(msg, me, target);
       if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
         attack_time = random((int)me->query_skill("never-defeated", 1) / 40);
        if (attack_time > 8 ) attack_time=8;
        for(i = 0; i < attack_time; i++){
         msg = HIY "$N招式奇异，转身回跃飞身一击！\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
                        }
        me->start_busy(3);
}

        return 1;
}

