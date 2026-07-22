// kuangfeng.c 狂风
// bye Dream
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon, ob;
    string msg;
        if( !me->is_fighting() )
            return notify_fail("「"+HIY"狂风"NOR+"」只能在战斗中使用。\n");
        if((int)me->query_str() < 40)
                return notify_fail("你的臂力不够, 还不能使用这项绝技! \n");
        if((int)me->query_skill("unarmed",1) < 250)
                return notify_fail("你的基本拳脚的火候还不到家, 不能使用这一绝技 !\n");
       if((int)me->query_skill("bibo-shengong",1) < 200)
                return notify_fail("你的碧波神功的修为不够, 不能使用狂风绝技 !\n");
    if (me->query_skill_mapped("unarmed") != "luoying-zhang")  
                return notify_fail("你没有激发落英神剑掌，无法施展「"+HIY"狂风"NOR+"」。\n"); 
        if((int)me->query_skill("luoying-zhang",1) < 300)
                return notify_fail("你的落英神剑掌的火候还不到家, 不能使用狂风绝技 !\n");
       if( me->query_temp("weapon"))
                return notify_fail("你先放下手中的武器再说吧？！\n");    
        if( (int)me->query("neili") < 5000 )
                return notify_fail("你的真气不够！\n");
        if( (int)me->query("max_neili") < 5000 )
                return notify_fail("你的内力修为不够！\n");

      msg = HIW "$N身形快速在原地旋转起来，顿时狂风大作，\n"NOR;
      msg += HIW"接着$N如电般射向$n，瞬间向$n攻出了八招。！\n"NOR;

        message_vision(msg, me);
        me->clean_up_enemy();
        ob = me->select_opponent();
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        COMBAT_D->do_attack(me, ob, me->query_temp("weapon"), 0);
        me->add("neili",-random(3000)-150);
                  me->start_busy(2+random(1));
    return 1;
}

