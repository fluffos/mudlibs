//来去若无形 wuying.c
// by godzilla 99.03.06

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";
//inherit F_CLEAN_UP;

void remove_effect(object me, int a_amount, int d_amount);

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon,ob;
        int skill;
	int extra;
        string msg;
int damage,p;        
        string dodge_skill;
        int ap, dp;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「分身无影」只能在战斗中使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "sword")
                return notify_fail("「分身无影」必须用剑才能施展。\n");

        if( (int)me->query_skill("wuying-jian", 1) < 150 )
                return notify_fail("你的「少林无影剑」不够娴熟，不会使用「分身无影」。\n");

//        if (me->query_skill_mapped("force") != "yijinjing")
//                return notify_fail("你的内功中无易筋经。\n");

	if( (int)me->query_skill("yijinjing", 1) < 100 )
		return notify_fail("你的易筋经不够娴熟。\n");

        if( (int)me->query("neili") < 400  ) 
                return notify_fail("你的内力不够。\n");

        skill = me->query_skill("wuying-jian");
	extra = me->query_skill("wuying-jian",1) / 10;
	extra += me->query_skill("wuying-jian",1) /10;
	me->add_temp("apply/attack", 80);	
	me->add_temp("apply/damage", (extra*5));

        msg = HIG "$N身行突变，瞬间犹如分出无数身影闪电般的向$n攻去！\n"NOR;
        message_vision(msg, me, target);

        me->add("neili", -200);
if (random(2)==0 && !target->is_busy()) target->start_busy(2);
        msg = HIR"来字决！-+-----\n"NOR;
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
        msg = HIY"去字决！-+-----\n"NOR;
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
        msg = HIG"若字决！-+-----\n"NOR;
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
        msg = HIB"无字决！-+-----\n"NOR;
        
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);
        msg = HIW"形字决！-+-----\n"NOR;
       
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_REGULAR,msg);

if (me->query_skill("wuying-jian",1)>200 )
{
	msg = HIG "$N使出绝技「达摩三绝剑」，身法陡然加快！\n" NOR;     
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg =  HIC  "$N身形加快，反手又是一剑！ \n" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  HIC  "$N身形逆转，朝着$n又是一剑！ \n" NOR;
	 COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
}	 
        me->start_busy(2);
	me->add_temp("apply/attack", -80);
	me->add_temp("apply/damage", -(extra*5));
if (me->query_skill("wuying-jian",1)>300 && me->query("neili")>500)
{
  msg = HIG "$N" HIG "将手中" + weapon->name() +
              HIG "轻轻一振，剑脊叮叮作响，无形剑气直指$n"
              HIG "气海要穴。\n" NOR;

        ap = me->query_skill("sword") + me->query_skill("force");
        dp = target->query_skill("force") * 2;

	if (ap / 3 + random(ap) > dp || random(3)==0)
        {
                damage = ap / 3 + random(ap / 3)+200;

target->add("qi",-damage);
target->add("eff_qi",-damage/2);
target->add("jing",-damage/2);
msg += HIR "结果$n" HIR "只觉气海穴上一痛，眼前一团"
               "黑，阵阵晕眩，难以继续战斗。\n" NOR;
                me->start_busy(2);
               
	} else
        {
		msg += CYN "可是$n" CYN "内力深厚，使得$P"
                       CYN "这一招没有起到任何作用。\n" NOR;
		me->start_busy(2);
                
	}
	message_combatd(msg, me, target);	
}	

if (me->query_skill("wuying-jian",1)>400 && me->query("neili")>500)
{
        msg = HIR "\n$N" HIR "蓦地将" + weapon->name() +
              HIR "往前一送，顿时一道光华自剑上亮起，直逼$n"
              HIR "丹田而去。\n" NOR;

        ap = me->query_skill("sword") + me->query_skill("force");
        dp = target->query_skill("force") * 2;

	if (ap / 3 + random(ap) > dp || random(3)==0)
        {
                damage = ap / 3 + random(ap / 3)+300;
msg += HIR "突然$n" HIR "只觉丹田忽然一热，随即变得冷"
               "冰冰，不禁大惊失色。\n" NOR;

target->add("qi",-damage);
target->add("neili",-damage);
                me->start_busy(2);
               
	} else
        {
		msg += CYN "可是$n" CYN "内力深厚，使得$P"
                       CYN "这一招没有起到任何作用。\n" NOR;
		me->start_busy(2);
                
	}
	message_combatd(msg, me, target);	
}

if (me->query_skill("wuying-jian",1)>500 && me->query("neili")>500)
{
	msg = HIM "\n$N" HIM "回转剑锋，手中" + weapon->name() +
              HIM "紫光荡漾，如作龙吟，无形剑气笼罩$n"
              HIM "全身。\n" NOR;

        ap = me->query_skill("sword") + me->query_skill("force");
        dp = target->query_skill("force") * 2;

	if (ap / 3 + random(ap) > dp || random(3)==0)
        {
                damage = ap / 3 + random(ap / 3)+500;
msg += HIR "霎时$n" HIR "心头一阵迷惑，体内的真气登时"
                "不听使唤，四处游走。\n" NOR;

target->add("qi",-damage);
target->add("eff_qi",-damage);
                me->start_busy(2);
                
	} else
        {
		msg += CYN "可是$n" CYN "内力深厚，使得$P"
                       CYN "这一招没有起到任何作用。\n" NOR;
		me->start_busy(2);
                
	}
	message_combatd(msg, me, target);
	
}	


        return 1;
}
