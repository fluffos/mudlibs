// kuangfeng.c 狂风卷地

#include <ansi.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
        string msg;
        object weapon, weapon2;
        int ap, dp, damage, bt, sk;

        bt = me->query("betrayer");

        if( !target ) target = offensive_target(me);

        if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「狂风卷地」只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
          || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if (!objectp(weapon2 = target->query_temp("weapon")))
                return notify_fail("对方没有使用兵器，你无法使用「狂风卷地」。\n");

        if( (sk=me->query_skill("dugu-jiujian",1)) < 300)
                return notify_fail("你的独孤九剑等级不够, 不能使用「狂风卷地」！\n");

        if( me->query("max_neili") < 4000 )
                return notify_fail("你的内力不够，无法运用「狂风卷地」！\n");

        if( me->query("neili") < 1000 )
                return notify_fail("你的内力不够，无法运用「狂风卷地」！\n");

        msg = HIC "$N一声断喝，使出独孤九剑「狂风卷地」逼近$n，手中"+weapon->name()+HIC "幻出重重剑影，如柔丝般向$n裹去。\n";
        message_vision(msg, me, target);

        me->start_perform(4,"狂风卷地");

        me->add("neili",-400);

        damage = sk/2+random(sk/2) + 1;
        ap = (int)(me->query("combat_exp")/100 * me->query("int"));
        dp = (int)(target->query("combat_exp")/100 * target->query("int"));
        if( ap < 1 )  ap = 1;
        if( dp < 1 )  dp = 1;
//命中率B-，判师一次下调2个大级别
        if( F_KUNGFU->hit_rate( ap, dp, 6+bt*6, me, target) ) {
                msg = "$n顿时觉得压力骤增，手腕一麻，手中";
                msg += weapon2->name();
                msg += "脱手而出！\n" NOR;
                F_KUNGFU->hit_wound("qi", damage, 0, me, target);
                me->start_busy(1);
                if( !target->is_busy() )  target->start_busy(3);
                weapon2->unequip();
                weapon2->move(environment(me));
                if ( objectp(weapon2) &&
                	   weapon2->query("unique") )
                  destruct(weapon2);
        }
        else{
                msg = "可是$n看破了$N的剑路，立刻采取守势，使$N的「狂风卷地」没有起到任何作用。\n"NOR;
                me->start_busy(1+random(2));
        }
        message_vision(msg, me, target);
        COMBAT_D->report_status(target);
        return 1;
}

