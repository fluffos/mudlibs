//modify by jzw 2006/1/27
#include <ansi.h>
//#include skill.h
//#include weapon.h
//#include combat.h
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
                return notify_fail("「倚天剑诀」只能对战斗中的对手使用。\n");
        if (!objectp(weapon = me->query_temp("weapon"))
                || (string)weapon->query("skill_type") != "sword")
                return notify_fail("你使用的武器不对。\n");
         if( (int)me->query_skill("huifeng-jian", 1) < 800 )
          return notify_fail(WHT"你的回风拂柳剑法不够娴熟，还使不出「绝剑」。\n"NOR);
          msg = HIR "$N口念回风剑的「倚天剑诀」，招式陡然变快,越战越勇！\n"NOR;
          

            if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/20 )
        {
               attack_time =3 + random((int)me->query_skill("huifeng-jian", 1) / 3);
                if(attack_time < 1)
                        attack_time = 1;
                if(attack_time > 10)
                        attack_time = 10;
                msg += CYN"结果$p被$P的剑招镇住，受伤不轻！\n"NOR;
                for(i = 0; i < attack_time; i++)
                 COMBAT_D->do_attack(me, target,me->query_temp("weapon"), 0);
               if ( me->query_skill("huifeng-jian",1))
                {
                me->start_busy(3 + random(2));
                 } 
                else
                {
                me->start_busy(2 + random(2));
                 }
                me->add("neili", -attack_time*20);

        }
        else
        {
          msg += HIC"可是$p看破了$P的招数，并没有上当，轻松躲开。\n"NOR;
          me->start_busy(3);
        }
        message_vision(msg, me, target);
        return 1;
}


