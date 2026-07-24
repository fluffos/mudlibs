// bashi.c 金顶绵掌 八式合一

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

void remove_effect(object target, int aamount, int damount);

int perform(object me, object target)
{
        object weapon;
        int damage;
        string msg;
        int count,d_count,qi, maxqi, skill;

        if( !target ) target = offensive_target(me);

        if( !me->is_fighting() )
                return notify_fail("「八式合一」只能在战斗中使用。\n");
        if( (int)target->query_temp("bashi") )
                return notify_fail("你已经在运功中了。\n");
        if( (int)me->query("neili") < 300 )
                return notify_fail("你的内力还不够高！\n");
        if( (int)me->query_skill("linji-zhuang", 1) < 40)
                return notify_fail("你的临济使二庄的修为不够，不能使用八式合一!\n");
        if( (int)me->query_skill("jinding-zhang",1) <100)
                return notify_fail("你的金顶绵掌的八式修习不全，无法使用八式合一！\n");
        if( me->query_skill_mapped("strike") != "jinding-zhang")
                return notify_fail("你没有激发金顶绵掌，无法使用八式合一！\n");
        if( me->query_temp("weapon"))
                return notify_fail("你先放下手中的武器再说吧？！\n");     

//        if( !target->is_killing(me) ) target->kill_ob(me);

        msg = HIY "$N深深吸了一口气，提起全身的功力于双掌，只听的$N骨骼一阵爆响！\n" NOR;
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/3)
        {
                damage = (int)me->query_skill("linji-zhuang", 1)/2;
                damage = damage +  (int)me->query_skill("jinding-zhang", 1);
                target->set_temp("bashi", 1);
                
                target->add_temp("apply/attack", -damage/2);
                target->add_temp("apply/defence", -damage/2);
                target->add_temp("apply/dodge", -damage/2);
                msg += HIR "$N腾空而起，使出了「八式合一」，漫天的掌影，飘忽不定的罩向$n全身各个部位，\n" NOR;
                me->start_call_out( (: call_other, __FILE__, "remove_effect",target,damage/2, damage/2:), damage/30);
                me->add("neili",-200);
                target->start_busy(3);
         }
         else {
                msg += NOR"可是$p猛地向前一跃,跳出了$P的攻击范围。\n"NOR;
         }
                me->start_busy(2);
         message_combatd(msg, me, target);
         return 1;
}

void remove_effect(object target,int aamount, int damount)
{
if (target)
{
               target->add_temp("apply/attack", aamount);
               target->add_temp("apply/defence", aamount);
               target->add_temp("apply/dodge", damount);
               target->delete_temp("bashi");
               message_combatd(YEL"$N从猛烈的攻击中摆脱了出来，连退数步,稳住了脚步\n"NOR, target);
}
}

