// kuangfeng.c 狂风卷地
 
#include <ansi.h>
 
inherit F_SSERVER;
 
int perform(object me)
{
        string msg;
        object weapon, weapon2, target;
        int skill, ap, dp, damage;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("dugu-jiujian",1);

        if( !(me->is_fighting() ))
                return notify_fail("「狂风卷地」只能对战斗中的对手使用。\n");
 
        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");

        if (!objectp(weapon2 = target->query_temp("weapon")))
                return notify_fail("对方没有使用兵器，你无法使用「狂风卷地」。\n");

        if( skill < 120)
                return notify_fail("你的独孤九剑等级不够, 不能使用「狂风卷地」！\n");

        if( me->query("neili") < 500 )
                return notify_fail("你的内力不够，无法运用「狂风卷地」！\n");
 
        msg = HIC "$N一声断喝，使出独孤九剑「狂风卷地」逼近$n，手中"+weapon->name()+HIC "幻出重重剑影，如柔丝般向$n裹去。\n";
        message_vision(msg, me, target);
        me->start_perform(4,"狂风卷地");
        damage = random(skill)+1;
        ap = me->query_skill("sword") + skill;
        ap = ap/10*ap*ap;
        dp = (int)target->query("combat_exp");
        if( dp < 1 )
                dp = 1;
        if( random(ap) > dp)
        {
                if(userp(me))
                        me->add("neili",-300);
                msg = "$n顿时觉得压力骤增，手腕一麻，手中";
                msg += weapon2->name();
                msg += "脱手而出！\n" NOR;

                target->receive_damage("qi", damage);
                target->add_busy(2);
                weapon2->move(environment(me));
		if (weapon2->query("unique")) destruct(weapon2);
        }
        else
        {
                if(userp(me))
                        me->add("neili",-300);
                msg = "可是$n看破了$N的剑路，立刻采取守势，使$N的「狂风卷地」没有起到任何作用。\n"NOR;
                me->start_busy(3);
        }
        message_vision(msg, me, target);

        return 1;
}
