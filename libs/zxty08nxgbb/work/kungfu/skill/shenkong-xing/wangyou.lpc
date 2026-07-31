#include <ansi.h>
#include <combat.h>
// inherit F_CLEAN_UP;
inherit F_SSERVER;
void remove_effect(object me, int amount);

int perform(object me, object target)
{
       object ob;
        int skill,tg_skill,time;
        string msg;

        if( !target ) target = offensive_target(me);

if ( (string)me->query("family/family_name") != "雪山寺") 
       return notify_fail("「"HIR"忘忧"NOR"」只有雪山弟子才能使用。\n");

        if( !target || !target->is_character() || !me->is_fighting(target) )
                return notify_fail("「"HIR"忘忧"NOR"」只能对战斗中的对手使用。\n");

        if( (int)me->query_skill("shenkong-xing", 1) < 50 )
                return notify_fail("你的身空行火候不够，不能使出「"HIR"忘忧"NOR"」。\n");

        if( (int)me->query("neili", 1) < 500 )
                return notify_fail("你现在内力太弱，不能使用「"HIR"忘忧"NOR"」。\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正手忙脚乱，你还忘个屁忧，赶快进攻吧！\n");
                        
        msg = HIB "$N口吐六字真言，一时眼中精光大盛，只见$N用脚踩出奇怪胡节拍，而$n眼中匆忙悔恨之色。\n"NOR;
        message_vision(msg, me, target);
    time = (int)me->query_skill("shenkong-xing",1)/80;

if (time<8)  time=8;
       skill = (int)me->query_skill("shenkong-xing",1)
             + (int)me->query_skill("dodge",1);
       tg_skill = (int)target->query_skill("dodge",1);
        me->add("neili", -100);
       if (random(skill) > random(tg_skill))
       {
       target->start_busy(random(time)+3);
        msg = HIR"$n完全陷入悔恨之中，$N奸计得逞，连使绝招向$n攻去。\n"NOR;
        message_vision(msg, me, target);
       return 1;
        }
       else
        {
       me->start_busy(2);
        msg = HIY"$n眼睛一花，突然见到$N嘴角的一丝得色，连忙守住灵台一点清明。\n"NOR;
        message_vision(msg, me, target);
       }
        return 1;
}

