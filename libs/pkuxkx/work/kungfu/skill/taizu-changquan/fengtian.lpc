#include <ansi.h>

inherit F_SSERVER;

int perform(object me, object target)
{
        string msg;
        int delay, myhand;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("不在战斗中，露什么破绽？\n");

        myhand=(int)me->query_skill("taizu-changquan",1);
        if(myhand > 160) myhand=160; // mon 12/7/98
        if(myhand < 50)
                return notify_fail("你的[太祖长拳]不够级别，无法使用『双抄封天』绝技。\n");

//        if(objectp(me->query_temp("weapon")) )
//        	return notify_fail("你手持武器，无法使用[萧风]！\n");
        	
        delay=myhand/16;

        if( target->is_busy() )
                return notify_fail(target->name() + "已经中了你的『双抄封天』绝技。\n");

        msg = HIB "$N的招式突然一变，双手化掌，向前双抄而上......接着左脚以勾腿法向前踢出。\n"NOR;
        //change totoal random to half random half ur own value to make the sucessrate more stable
        if( F_KUNGFU->hit_rate(me->query("combat_exp")/10, (int)target->query("combat_exp")/20*5-me->query("combat_exp")/10, 6, me, target) )
        {
                msg += RED"$n被这一招牢牢限制住自己的动作。\n"NOR;
                msg += HIB"结果$p被$P攻了个措手不及！\n" NOR;
                F_KUNGFU->hit_busy( "fenjin", delay, target );
                me->start_busy(random(2));
        } else {
                msg += "可是$p看破了$P的企图，并没有被这一招缠住。\n" NOR;
                me->start_busy(2+random(1));
        }
        message_vision(msg, me, target);

        return 1;
}

