#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;

        if( !target ) target = offensive_target(me);      

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("幻术只能对战斗中的对手使用。\n");

 if ( (string)me->query("family/family_name") != "星宿派") 
return notify_fail("不是星宿门人也想用这武功？\n");


        if( target->is_busy() )
                return notify_fail(target->name() + "已经不能动了！\n");
                
        if( (int)me->query_skill("xingxiu-duzhang", 1) < 100 )
                return notify_fail("你的星宿毒掌不够娴熟，不会使用「幻术」。\n");

       msg = HIB "$N口念邪咒，手捏青红涅磐印，施展出星宿独门幻术，企图迷惑对手。\n"NOR;

    if( random( me->query_skill("xingxiu-duzhang",1)+me->query_skill("unarmed",1) ) > (me->query_skill("unarmed",1)*2)/4 ) {
   msg += HIW "$p被$N幻术所迷，竟然发起呆来。\n" NOR;
             target->start_busy( (int)me->query_skill("xingxiu-duzhang") / 40 );
   me->add("neili", -500);
        } else {
        me->start_busy(2);
           me->add("neili",-300);        
                msg += HIC "$p静下心神，很快从幻术中恢复了。\n" NOR;
        }
        message_vision(msg, me, target);

        return 1;
}

