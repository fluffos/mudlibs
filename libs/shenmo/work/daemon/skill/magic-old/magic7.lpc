// mie.c  火炎球

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        int damage;
        string msg;
        object weapon;

        if (!target ) target = offensive_target(me);
        if (!target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「圣雷」只能对战斗中的对手使用。\n");
        if ((int)me->query_skill("magic-old", 1) < 50)
                return notify_fail(WHT"你的古代魔法不够娴熟，还使不出「圣雷」。\n"NOR);
        if ((int)me->query("neili")<50)
        {
               return notify_fail(HIC"你现在内力(法力)不够，没能将「圣雷」使完！\n"NOR);
        }
        msg = YEL "$N"YEL"口中吟唱起了咒文.天空中开始聚集巨大无比的能量.\n"NOR;
       msg += HIC"$N"HIM"念到 站在祭坛上，我以圣灵的名义命令！  打雷吧...\n"NOR;
        msg += HIC"$N"HIC"大叫一声  「轰雷」!!  ,天上出现一道巨大的雷电径直向$n打去，威力无伦.！\n"NOR;
        if (random(me->query_skill("force"))>target->query_skill("force")/3|| 
           random(me->query("combat_exp"))>(int)target->query("combat_exp")/3)
        {
//                target->start_busy(2);
                damage = (int)me->query_skill("magic-old", 1);
                damage = damage + random(damage);
                target->receive_damage("qi", target->query("eff_qi")/3);
                target->receive_wound("qi", target->query("eff_qi")/3);
        msg += HIC"$n"HIC"根本没法躲避，冲天的闪电,端端正\n"NOR;
        msg += HIC"正打在$n"HIC"的身上！$n"HIC"的周围全部炸开了!!\n"NOR;
                me->add("neili", -10);
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
        } else
        {
                me->start_busy(1);
        msg += HIY"可是$p"HIY"轻轻一笑，一个起身飞跃.\n"NOR;
        msg += HIY"闪电在$p"HIY"身后炸落，毫发无伤。\n"NOR;
                me->add("neili", -50);
		message_combatd(msg, me, target);
        }
	if(!target->is_fighting(me)) target->fight_ob(me);
        return 1;
}
