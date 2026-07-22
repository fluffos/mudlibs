// by mop
#include <ansi.h>
inherit F_SSERVER;
#include <combat.h>
#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{
        int damage, p;
        string msg;
        int extra;
        object weapon = me->query_temp("weapon");
        if( !target ) target = offensive_target(me);
        
        if( !target || !target->is_character()
           || !me->is_fighting(target) || !living(target) )
                return notify_fail("天翔龍閃只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("feitian-yujianliu", 1) < 200 )
                return notify_fail("你的飞天御剑流还不够熟练，不能使用天翔龍閃对敌！\n");
       
        if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("你使用的武器不对。\n");

        if (me->query_skill_mapped("force") != "shayi-xinfa")
                return notify_fail("你的内功中无此功夫。\n");

             if (me->query_skill_mapped("sword") != "feitian-yujianliu")
                return notify_fail("你的剑法中无此功夫。\n");
       
             if( (int)me->query_skill("shayi", 1) < 200 )
		return notify_fail("你的杀意太低，领悟不到天翔龍闪奥义。\n");

              if(me->query("family/family_name") != "飞天御剑流")
              return notify_fail("你并非飞天御剑流传人，无法体会到绝招。\n");

             if (!(me->query("feitian/tian") & 1))
              return notify_fail("你虽然听说过“天降龙闪”这一招，可是却未获传授。\n");

        if( (int)me->query("max_neili", 1) < 1500 )
                return notify_fail("你现在内力不足，使不出最高绝学天降龙闪！\n");     

        if( (int)me->query("neili", 1) < 300 )
                return notify_fail("你现在真气不足，使不出天降龙闪！\n");     

        if( (int)me->query_skill("sword", 1) < 180 )
                return notify_fail("你的剑法不够娴熟，使不出天降龙闪的绝招！\n");

        if (me->query_dex() < 42 )
                return notify_fail("你的速度太差，使不出天降龙闪！\n");

        msg = WHT "\n$N将兵器收了回去，凝神闭气。突然左脚踏前闪电般抽刀向$n劈去。正是最高剑决[天翔龍閃]！\n"NOR;        
        if (random(me->query_skill("dodge")) > target->query_skill("dodge") /3 )
        {                     
                me->start_busy(1);
                target->start_busy(1); 
                me->add("neili", -200);
                me->add("qi", -20);
                damage = (int)me->query_skill("feitian-yujianliu", 1);                
                damage = damage*8 + random(damage);
                msg += ""HIR"$p只觉得眼前一道闪亮的弧月划过，剑带着一阵破空声已经劈到了咽喉。"NOR"\n" NOR;

                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);
                
                p = (int)target->query("qi")*100/(int)target->query("max_qi");
                msg += damage_msg(damage, "刺伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";
                call_out("perform2", 2, me, target, p);    
        } else 
        {
                me->start_busy(3);
                target->start_busy(1);
                me->add("neili", -100);
    msg += HIY"\n$p只觉空气都要被抽空了一样，在$p面前形成了一个真空，真空吸着$p向$N移去，$p连忙跃开数尺。\n" NOR;
        }
        message_vision(msg, me, target);
        return 1;
}

int perform2(object me, object target, int p)
{
        int damage;
        string msg;
  
        if(!living(target))
              return notify_fail("对手已经不能再战斗了。\n");

        if( (int)me->query("neili", 1) < 700 )
                return notify_fail("你正要打出第二招，却发现自己的内力不够了！\n");     

        msg = HIW "\n$N一剑未完中途变招，身形疾转利用离心力劈出了第二招[天翔龍閃*响雷]。
空气中劈啪噼啪犹如炸雷般的一阵的乱响，剑带着一阵尖啸劈向$n。\n"NOR;        
        if (random(me->query_skill("dodge")) > target->query_skill("dodge") / 2 &&
            me->query_skill("feitian-yujianliu", 1) > 149 )
        {
                me->start_busy(4);
                target->start_busy(random(2));
                me->add("neili", -600);
                me->add("qi", -40);                
                damage = (int)me->query_skill("feitian-yujianliu", 1);                
                damage = damage*12 + random(damage);
                msg += ""HIC"$p一个飞跃避开了这致命的一击，正在得意之时切发现自己被$N剑气所造成的真空吸了过去。"NOR"\n" NOR;

                target->receive_damage("qi", damage);
                target->receive_wound("qi", damage/2);

                p = (int)target->query("qi")/(int)target->query("max_qi")*3;
                msg += damage_msg(damage, "割伤");
                msg += "( $n"+eff_status_msg(p)+" )\n";     
                
        } else 
        {
                me->start_busy(5);
                target->start_busy(1);
                me->add("neili", -300);
                target->add("qi", -100);
    msg += HIY"\n$p面色苍白带着恐惧之色，使出浑身解数终于逼开了这致命一击！\n" NOR;
        }
        message_vision(msg, me, target);

        return 1;
}
