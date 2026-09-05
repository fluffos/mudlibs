#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int delay, myhand;
        if (!me->query("yanqing"))
        {
            return notify_fail("没有得到燕青真传，你暂时不能使用燕青拳绝技！\n");
        }
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("不在战斗中，露什么破绽？\n");

        myhand=(int)me->query_skill("yanqing-quan",1);
        if(myhand > 160) myhand=160; 
        if(myhand < 50)
                return notify_fail("你的[燕青拳]级别太低，无法使用[燕青]绝技。\n");

        if(objectp(me->query_temp("weapon")) )
        	return notify_fail("你手持武器，无法使用[燕青]绝技！\n");
        	
        delay=myhand/16;

        if( target->is_busy() )
                return notify_fail(target->name() + "已经正忙着呢，放胆进攻吧\n");

        msg = CYN "$N"+CYN+"吐气开声，招式潇洒，绵绵不绝，仿佛燕青附身。\n"NOR;
        //change totoal random to half random half ur own value to make the sucessrate more stable
//D        
        if( F_KUNGFU->hit_rate( me->query("combat_exp")/10*3, (int)target->query("combat_exp")/5*2-me->query("combat_exp")/10, 11, me, target) )
        {
                msg += RED"$n看着$N招式华丽，不由目瞪口呆！\n"NOR;
                msg += HIB"结果$p被$P打了个措手不及！\n" NOR;
                F_KUNGFU->hit_busy( "confuse", delay, target );
                me->start_busy(random(2));
        } else {
                msg += "可是$p看破了$P的企图，回身攻出数招。\n" NOR;
                me->start_busy(2+random(1));
        }
        message_vision(msg, me, target);

        return 1;
}

