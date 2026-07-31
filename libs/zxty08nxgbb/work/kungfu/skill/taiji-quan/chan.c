#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    int time;
    object weapon;
    string msg;
    if( !target ) target = offensive_target(me);
    if( !target
    ||  !target->is_character()
    ||  !me->is_fighting(target) )
        return notify_fail("牵制攻击只能对战斗中的对手使用。\n");
      
 if ( (string)me->query("family/family_name") != "武当派") 
     return notify_fail("只有武当弟子才能使用该PFM。\n");
    if( target->is_busy() )
        return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧ⅵ\n");
        
    if( (int)me->query_skill("taiji-quan", 1) < 80 )
        return notify_fail("你的太级拳法不够娴熟，不会使用「缠」字诀。\n");
        if( me->is_busy()) return notify_fail("你现在正忙着。\n");     
    if (!me->visible(target))    return notify_fail("你看不到"+target->name()+"。\n");
    msg = HIW "$N使出太极拳法「缠」字诀，连递数个虚招企图扰乱$n的攻势。\n";
    time = (int)me->query_skill("taiji-quan",1) / 70;
    if (time<3) time = 3;
   if( random(me->query_skill("taiji-quan",1)+me->query_skill("unarmed",1)) > ((int)target->query_skill("unarmed",1)*2)/3 ){
       msg += HIG " 结果$p被$P攻了个措手不及！\n" NOR;
        target->start_busy(time);
    } else {
        me->start_busy(2);
         msg += HIG"可是$p看破了$P的企图，并没有上当。\n" NOR;
    }
    message_vision(msg, me, target);
    return 1;
}

