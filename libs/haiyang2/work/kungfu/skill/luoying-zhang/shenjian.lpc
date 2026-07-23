// shenjian.c 桃花影里飞神剑

#include <ansi.h>

inherit F_SSERVER;

#include "/kungfu/skill/eff_msg.h"
 
int perform(object me, object target)
{
        string msg;
        object weapon;
        int damage, rand, p;

        if( !target ) target = offensive_target(me);

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("桃花影里飞神剑只能对战斗中的对手使用。\n");

//        if (!(me->query("thd/perform") & 2))
//                return notify_fail("你虽然听说过“桃花影里飞神剑”这一招，可是却未获传授。\n");
        if( objectp(me->query_temp("weapon")) )
               return notify_fail("你必须空手使用桃花影里飞神剑！\n");
        if( (int)me->query_skill("luoying-zhang", 1) < 80 )
                return notify_fail("你的落英神剑掌不够娴熟，无法使用桃花影里飞神剑。\n");
        if ((int)me->query_skill("bibo-shengong", 1) < 80)
                return notify_fail("你的碧波神功火候不够，无法施展桃花影里飞神剑。\n");
        if ( (int)me->query("neili") < 120)
                return notify_fail("你的内力不够，无法使用桃花影里飞神剑。\n");
        if ( me->query_skill_mapped("strike") != "luoying-zhang")
                return notify_fail("你现在无法使用桃花影里飞神剑进行攻击！\n");

        msg = CYN "\n$N双掌竖起，默运碧波神功，掌缘便似剑锋一样发出丝丝的"GRN"剑气"CYN"，分别从左右两边斩向$n！\n"NOR;
        rand = random(me->query("combat_exp"));
        if( rand > (int)target->query("combat_exp")/3 ) {
                me->add("neili", -100);
                me->start_busy(2);
                damage = (int)me->query_skill("luoying-zhang", 1)*2+random(damage/2);
                damage += random(damage);
                target->receive_damage("qi", damage*2);
                target->receive_wound("qi", damage);
                p = (int)target->query("qi") * 100 / (int)target->query("max_qi");
                msg += damage_msg(damage, "劈伤");
                msg += "( $n" + eff_status_msg(p) + " )\n";
                } 
        else {
                me->add("neili", -50);
                me->start_busy(1);
                msg += HIY"$n大吃一惊，退步抽身，万分惊险中堪堪躲过了这招，早已吓出了一身冷汗！\n" NOR;
        }
        message_vision(msg, me, target);
        return 1;
}
