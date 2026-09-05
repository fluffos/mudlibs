#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
inherit F_CLEAN_UP;
int perform(object me, object target)
{
        string msg;
        int extra;
        object weapon;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("夕阳残照只能对战斗中的对手使用。\n");
        weapon = me->query_temp("weapon");
        extra = me->query_skill("hero-jianfa",1) / 10;
        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", extra);
         msg = HIR  "$N使出英雄剑法中的必杀着［夕阳残照］，手中的"+ weapon->name() +"舞出一片红光,$n顿时什么也看不见！\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
msg=HIR "$N剑光一闪，只剩下一片惨淡的血红弥漫在黄昏的天地间.....\n";
        message_vision(msg, me, target);
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
        me->start_busy(1);
        return 1;
}
