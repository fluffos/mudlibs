//sanjue.c 
#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg,msg1;
        int i;
        object weapon;
        if( !target ) target = offensive_target(me);
        if( !target || !me->is_fighting(target) )
                return notify_fail("「修罗三绝刀」只能在战斗中对对手使用。\n");
        weapon = me->query_temp("weapon");
        if (!weapon || weapon->query("skill_type") != "blade"
           || me->query_skill_mapped("blade") != "xiuluo-dao")
                return notify_fail("你必须使用在刀时才能使出「修罗三绝刀」！\n");

        if( (int)me->query_skill("xiuluo-dao", 1) < 80 )
                return notify_fail("你的修罗刀不够娴熟，不会使用「修罗三绝刀」。\n");

        if( (int)me->query_skill("yijinjing", 1) < 60 )
                return notify_fail("你的易筋经内功修为不够，不能使用「修罗三绝刀」。\n");

        if( (int)me->query_dex() < 30 )
                return notify_fail("你的身法太低，不能使用「修罗三绝刀」。\n");

//        if (me->query_skill_mapped("force") != "yijinjing")
//                return notify_fail("你的内功等级不够，不能使用「修罗三绝刀」。\n");

        if( (int)me->query("neili", 1) < 400 )
                return notify_fail("你现在内力太弱，不能使用「修罗三绝刀」。\n");
        if((int)me->query("jing",1)<200)
               return notify_fail("你现在精力太少，不能使用「修罗三绝刀」。\n");
        i = (me->query_skill("xiuluo-dao", 1)/6);
        msg = RED "$N高喧佛号，身形如叶般飞舞，迅捷如飞般发出三刀。\n"NOR;
        msg1=HIY"$N一声长啸，身法渐渐缓慢下来。\n"NOR;
        me->add_temp("apply/strength", i);
        me->add_temp("apply/attack", i); 
        message_vision(msg, me, target);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"), TYPE_QUICK);
        me->add("neili", -200);
        me->start_busy(2);
        me->add_temp("apply/strength",-i);
        me->add_temp("apply/attack", -i); 
        message_vision(msg1, me,target);
      return 1;
}
