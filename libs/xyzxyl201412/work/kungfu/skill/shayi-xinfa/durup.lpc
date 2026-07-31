 // void_sense.c
#include <ansi.h> 
inherit F_SSERVER;
int exert(object me, object target)
{
        int lvl,i,extra;
        object env, *inv;
        
        
        if(me->query_temp("ninjitsu_durup")) return notify_fail("你现在已经处在精神的极度亢奋状态了。\n");
        
        lvl = (int) me->query_skill("ninjitsu",1);
                
        if ( (int) me->query_skill("ninjitsu",1) <= 150)
                return notify_fail("你忍术不够高！\n");
        if( target != me ) 
                return notify_fail("你只能用在自己的身上。\n");        
            
        if( me->query("neili") < 300 )
                return notify_fail("你的内力不够！\n");
        if( me->query("jing") <= 250 )
                return notify_fail("你的精不够！\n");
        me->add("neili", -300);
        me->receive_damage("jing", 250);
        
        extra=lvl/5;
        if (extra > 300) extra=300;
        me->add_temp("apply/dexerity",extra);
        me->set_temp("ninjitsu_durup",1);
        message_vision(HIM "$N的眼光变得迷离，似乎已经被一种强大的精神力量所控制．．．\n" NOR, me);
            
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me ,extra:), lvl/10);
        if( me->is_fighting() ) me->start_busy(2);
        return 1; 
}
void remove_effect(object me,int extra)
{
        me->add_temp("apply/dexerity", - extra);
        me->delete_temp("ninjitsu_durup");
        message_vision(HIW"$N的眼神恢复正常，看来已经回到了清醒状态。\n"NOR,me);
        
}     
