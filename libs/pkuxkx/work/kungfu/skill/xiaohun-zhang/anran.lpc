//anran.c -黯然销魂-

#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
        string msg;
        int damage;
        int poison;

        if( !target ) target = offensive_target(me);

        if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「黯然销魂」只能对战斗中的对手使用。\n");

        if ( me->query_skill_mapped("force") != "yunu-xinfa" && me->query_skill_mapped("force") != "jiuyin-shengong" )
                return notify_fail("你必须激发激发九阴神功或玉女心法才能使用。\n");

        if ( me->query_skill("force") < 120 )
                return notify_fail("你的内功等级不够，无法施展「黯然销魂」。");

        if ( me->query_skill("strike", "xiaohun-zhang") < 150 )
                return notify_fail("你的黯然销魂掌等级不够，施展不出「黯然销魂」一式。\n");

        if ( me->query("neili") < 300 || me->query("max_neili") < 1000 )
                return notify_fail("你的内力不够，无法施展「黯然销魂」。");

        if (random(me->query("max_qi"))<(int)me->query("eff_qi")/2 ||
            time()-me->query_temp("anran_cd")<=1 )
        {
               if ( time()-me->query_temp("anran_cd")>1 )
                 me->set_temp("anran_cd", time());
               return notify_fail("此刻并非危急关头，你无法施展「黯然销魂」一式。\n");
        }


        msg = RED "$N心念俱灰，满脸凄苦之色，心中叫道:别了，我的爱人，随手几掌，拍向$n。\n"NOR;

        me->start_busy(2);
        if (!userp(me))
        {
            me->add_busy(2);
        }
        if( F_KUNGFU->hit_rate(me->query_skill("force",1), (int)target->query_skill("force",1), 9, me, target) )
                poison=1;
        else
                poison=0;
//命中率级别B-
        if( F_KUNGFU->hit_rate(me->query("combat_exp"), (int)target->query("combat_exp"), 6, me, target) )
        {
                msg += HIY"结果$p被$P攻了个措手不及！\n" NOR;
                message_vision(msg, me, target);
                damage=3*((int)me->query_skill("xiaohun-zhang",1)+(int)me->query("max_qi")-(int)me->query("eff_qi"));
                if (damage > 3000) damage = 3000;
                F_KUNGFU->hit_wound("qi", damage, damage/3, me, target);
                COMBAT_D->report_status(target);
                if(poison)
                {
                    //target->set_temp("death_cond_origin/anran_poison", me);
					F_POISON->poison_attack(me,target,"anran_poison", ((int)me->query_skill("xiaohun-zhang",1)/30));
                    me->start_busy(1+random(2));
                }
                me->add("neili", -damage/10);
        } else {
                msg += HIG"可是$p还是躲过了$P的黯然一击！！\n" NOR;
                message_vision(msg, me, target);
                me->add("neili",-100);
        }
        return 1;
}

