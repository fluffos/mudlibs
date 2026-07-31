// mi.c 痴心鞭法迷梦击

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
                return notify_fail("迷梦击只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "whip")
                return notify_fail("你使用的武器不对。\n");
        if ((int)me->query("shen") < 0) 
                return notify_fail("你的侠义正气太低了，无法集中心志！\n");

        if( (int)me->query_skill("chixin-bianfa", 1) < 40 )
                return notify_fail("你的痴心鞭法不够娴熟，不会使用迷梦击。\n");
        if ((int)me->query_skill("wangran-xinfa", 1) < 50)
                return notify_fail("你的本门心法火候不够，无法使用。\n");
         if ((int)me->query_skill("shuiyue", 1) < 50)
                return notify_fail("你的本门轻功火候不够，无法使用。\n");

        msg = HIW "$N使出迷梦击，脸上突然露出诡异的媚笑，$n"HIW"只觉得有无数的呼唤缠绕着自己。\n";

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/30 )
        {
                attack_time = random((int)me->query_skill("chixin-bianfa", 1) / 50);
                if (me->query("family/family_name") == "痴心妄想门")
                {
                if(attack_time < 2)
                        attack_time = 2;
                if(attack_time > 6)
                       attack_time = 6;
                }
                else
                {
                if(attack_time < 2)
                        attack_time = 2;
                if(attack_time > 4)
                        attack_time = 4;
                }
                msg += MAG "结果$n"MAG"被$N引入了迷梦，顿时精神恍惚！\n" NOR; 
                message_vision(msg, me, target);
                for(i = 0; i < attack_time; i++)
                        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), 0);
                if (me->query("family/family_name") == "痴心妄想门")
                {
                me->start_busy(2+random(1));
                me->start_busy(1+random(2));
                target->start_busy(1+random(4));}
                else {me->start_busy(4+random(2));
                  target->start_busy(1+random(2));}
                me->add("neili", -100);
        }
        else
        {
                msg += RED"可是$n"RED"看破了$N的企图，稳住了心智。\n" NOR;
                message_vision(msg, me, target);
                me->start_busy(2+random(2));
        }

        return 1;
}
