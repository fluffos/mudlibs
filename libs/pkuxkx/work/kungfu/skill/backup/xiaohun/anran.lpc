//anran.c -黯然销魂-

#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
	int damage;
        if( !target ) target = offensive_target(me);

        if( !me->query("anran"))
                return notify_fail("你的外功中没有这种功能。\n");

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「黯然销魂」只能对战斗中的对手使用。\n");

        if( objectp(me->query_temp("weapon")) )
                return notify_fail("你必须空手才能施展「黯然销魂」！\n");

          if (me->query_skill_mapped("force") != "jiuyin-shengong" || me->query_skill("force",1)/2 + me->query_skill("jiuyin-shengong",1) < 120 )
                return notify_fail("你的内功等级不够，无法施展「黯然销魂」。");

        if (me->query_skill("strike",1)/2 + me->query_skill("xiaohun-zhang", 1) < 150 )
                return notify_fail("你的黯然销魂掌等级不够，施展不出「黯然销魂」一式。\n");

      if (me->query("neili")<200||me->query("max_neili")<200)
                return notify_fail("你的内力不够，无法施展「黯然销魂」。");
        msg = RED "$N心念俱灰，满脸凄苦之色，心中叫道:别了，我的爱人，随手几掌，拍向$n。";

me->start_busy(1);
        if(( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2)&&
	(random(me->query("eff_qi"))>(int)me->query("qi")))	
 {
                msg += "结果$p被$P攻了个措手不及！\n" NOR;
                message_vision(msg, me, target);
		damage=2*(int)me->query_skill("xiaohun-zhang",1)+(int)me->query("eff_qi")-(int)me->query("qi");
		target->receive_damage("qi", damage, me);
                target->receive_wound("qi", damage/3, me);
           //     target->unconcious();
        } else {
                msg += "可是$p还是躲过了$P的黯然一击！！\n" NOR;
                message_vision(msg, me, target);
      me->set("neili",(me->query("neili")-200));
        }
        return 1;
}
