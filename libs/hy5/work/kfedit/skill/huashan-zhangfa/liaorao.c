// pfm 烟雾缭绕 liaorao 
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        if( !target ) target = offensive_target(me);
        if( !target
         || !target->is_character()
         || !me->is_fighting(target))
           return notify_fail("牵制攻击只能对战斗中的对手使用。\n");
        if((int)me->query_dex() < 25)
           return notify_fail("你的身法不够,不能使用烟雾缭绕绝技!\n");
         if( (int)me->query_skill("huashan-zhangfa", 1) < 80 )
                return notify_fail("你的华山掌不够娴熟，不会使用混元无极！\n");
                                
        if( (int)me->query_skill("zixia-shengong", 1) < 80 )
                return notify_fail("你的紫霞神功不够高，不能用出混元无极伤敌。\n");
        if((int)me->query("max_neili") < 400)
           return notify_fail("你的内力修为尚欠火候。\n");  
        if((int)me->query("neili") < 300)
           return notify_fail("你内力现在不够, 不能使用烟雾缭绕绝技! \n");
        if( target->is_busy() )
           return notify_fail( target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");
        msg = HIM"\n$N面带微笑，目不斜视，出掌如行云流水般向后斜劈，跟着右掌向后斜劈，如此连出五掌，\n"+
                 "一股阴柔的掌力罩住了$n的全身要穴。\n"NOR;
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp") / 2 ){
           msg +=  HIY"结果$p只觉眼前一阵烟雾缭绕，被$P趁势点中要穴! \n"NOR;
           target->start_busy((int)me->query_skill("huashan-zhangfa",1) / 50 + 3);
           me->add("neili",-100);
           me->add("jing",-10);
           }
           else{
           msg += HIC"$p脸色一变，大喝一声往后一纵，$P五掌落空，身形为之一滞。\n"NOR; 
           me->add("neili",-100);
           me->add("jing",-10);
           me->start_busy(2);
           }
           message_vision(msg, me, target);
           return 1;
}

