// 蝶舞飞满花 wudie.c

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon;
        string msg;
        int i, attack_time;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「蝶舞飞满花」只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if( (int)me->query_skill("dieyi-jianfa", 1) < 80 )
                return notify_fail("你的蝶翼剑法不够娴熟，不会使用蝶舞飞满花。\n");

        msg = HIC "$N使出蝶翼剑法之蝶舞飞满花，招式变得异常犀利。\n";

if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/50 )
        {
attack_time = random((int)me->query_skill("dieyi-jianfa", 1) / 45);
                if(attack_time > 7){
                        attack_time = 12;
                msg += RED " 结果$p被$P乱剑齐发攻了个不只所错！\n" NOR;
                }else{ 
                msg += RED " 结果$p被$P连攻"+attack_time+"剑！\n" NOR;
                } 
                if(attack_time < 1) attack_time = 1;
                for(i = 0; i < attack_time; i++){
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                }
                message_vision(msg, me, target);
                if(attack_time < 4)
                  me->start_busy(2);
                if(attack_time < 5)
                me->start_busy(3);
                if(attack_time < 7)
                    me->start_busy(3);
                if(attack_time > 7)
                  me->start_busy(3);
                me->add("neili", -200);
        }
        else
        {
                msg += MAG"可是$n看破了$N的企图，并没有上当。\n" NOR;
                me->start_busy(4);
                message_vision(msg, me, target);
        }
        return 1;
}
