// kuangfeng.c  狂风绝技

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
        string msg;
        int power,i=0;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「狂风绝技」只能在战斗中使用。\n");
 
        if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
                return notify_fail("「狂风绝技」开始时不能拿着兵器！\n");

        if( (int)me->query("neili") < 500 )
                return notify_fail("你的真气不够！\n");

        if( (int)me->query_skill("bihai-shengong",1) < 150 )

                return notify_fail("你的碧海神功不够！\n");

        if(me->query_skill("xuanfeng-tui",1) < 100)
                return notify_fail("你的腿上功夫还不到家，无法使用狂风绝技！\n");
        if (sizeof(me->query_skill_prepare())!=2)
                return notify_fail("只用同时使用落英神剑掌才能使用狂风绝技！\n");
        power = (me->query_skill("xuanfeng-tui",1)/3);
        power +=(me->query_skill("luoying-zhang",1)/10);

        me->add_temp("apply/strength", power);
        me->add_temp("apply/attack", power * 3 / 2);
        
        msg = YEL "$N使出桃花岛绝技「狂风绝技」，身法陡然加快！" NOR;
        message_vision(msg, me, target);                
        msg =  YEL  "$N聚力于左掌，右腿一脚跟着踢出！" NOR;
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = CYN  "人影中，$N翻身而起，左掌大力得挥向$n！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "$N见$n门户大开，暗运内力，双腿连环踢向$n！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = CYN  "$N越战越勇，周围骤起一阵旋风，使得$n看不清方向！" NOR;
                COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL "$N如星光乍现，右掌略带悠然之色轻拍$n！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = CYN "$N长啸一声，面如赤发，忽然转到$n身后，反手又是一掌！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/strength",-power);
        me->add_temp("apply/attack", -power * 3 / 2);
        if (me->query("exp/taohuanewbie")>=100000)
            i=1;
        me->add("neili", -(500-i*100));
        me->start_busy(3-i);
        return 1;
}
