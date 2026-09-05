#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;

int perform(object me, object target)
{       
    if( !target ) target = offensive_target(me);
    if((int)me->query_skill("dushen-futi", 1) < 350 )
        return notify_fail("你的毒神附体不够娴熟，不能使用「毒神附体」。\n");

    if( (int)me->query_skill("poison", 1) < 350 )
        return notify_fail("你的基本毒技不够高，不能使用「毒神附体」。\n");

    if( (int)me->query("neili", 1) < 2000 )
        return notify_fail("你现在内力太弱，不能使用「毒神附体」。\n");
    if (me->query_temp("dushen-futi"))
        return notify_fail("你现在正在使用「毒神附体」。\n");
    if (me->query("family/family_name")!="星宿派")
        return notify_fail("只有星宿弟子才可以使用「毒神附体」。\n");
    
    message_vision(WHT"$N眉间黑气乱窜，已然发动了"+HIB+"「毒神附体」"+NOR+"。\n",me);
    
    me->add_busy(1);
    me->add("neili", -1000);
    me->set_temp("dushen-futi",(int)me->query_skill("poison",1)*9+random(3));
    return 1;
}

