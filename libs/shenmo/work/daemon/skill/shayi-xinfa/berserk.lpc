 // 忍术的狂杀术,在短时间内大幅度地提高力量,但是不能perform.
#include <ansi.h> 
inherit F_SSERVER;
int exert(object me, object target)
{
        int lvl,i,extra;
        
        lvl = (int) me->query_skill("ninjitsu",1);
        
        
        if ( (int) me->query_skill("ninjitsu",1) <= 150)
                return notify_fail("你忍术不够高！\n");
        
        if( target != me ) 
                return notify_fail("你只能将［狂杀］用在自己的身上。\n");       
                
        if(me->query_temp("ninjitsu_berserk")) 
                return notify_fail("你的力量已经提升到最大限度，无法继续提升了。\n");
        
        if( me->query("neili") < 300 )
                return notify_fail("你的内力不够！\n");
        if( me->query("qi") <= 150 )
                return notify_fail("你的精不够！\n");
    
        me->add("neili", -300);
        me->receive_damage("qi", 150);
        extra=lvl/5;
        if (extra > 300) extra=300;
        me->add_temp("apply/strength",extra);
        me->set_temp("ninjitsu_berserk",1);

        message_vision(HIR "$N狂吼一声，眼中似要滴出血来.\n"NOR,me);
        tell_object(me,WHT"    你只觉真气在周身游走,无处发泄．．．\n" NOR, me);
        me->start_call_out( (: call_other, __FILE__, "remove_effect", me ,extra:), extra*4);
        if( me->is_fighting() ) me->start_busy(2);
        return 1; 
}
void remove_effect(object me,int extra)
{
        me->add_temp("apply/strength", -extra);

        me->delete_temp("ninjitsu_berserk");
        tell_object(me, HIG"你终于慢慢地平静下来\n"NOR);
}  
