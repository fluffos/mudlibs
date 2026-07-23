 //mimicat@fy4
#include <ansi.h> 
inherit F_SSERVER;
int perform(object me, object target)
{
        int bonus;
        

        if( !target)
                return notify_fail("你要用真言为谁疗伤？\n");
        
        if( !living(target) )
                return notify_fail(target->name() + "已经无法接受你的好意了。\n");
                
        if( (int)me->query("neili") < 500 )
                return notify_fail("你的法力不够。\n"); 
        if (target==me) {
                message_vision(
                YEL "$N双手如捧宝盆，拢于身前．聚气凝神喝道“嘛”！\n"
                MAG "如云的紫气从$N双掌间涌出，笼罩在$N头顶，然后慢慢消失。 \n\n" 
                WHT "紫气散去，$N满头是汗水，伤势渐渐愈合。 \n"NOR,
                        me); 
        } else
                message_vision(
                YEL "$N双手如捧宝盆，拢于身前．聚气凝神喝道“嘛”！\n"
                MAG "如云的紫气从$N双掌间涌出，笼罩在$n头顶，然后慢慢消失。 \n\n" 
                WHT "紫气散去，$N满头是汗水，$n的伤势渐渐愈合。 \n"NOR,
                        me, target );  
        target->receive_curing("qi", 10 + (int)me->query_skill("magic")*8);
        target->receive_curing("jing", 10 + (int)me->query_skill("magic")*5);
        target->receive_curing("jingli", 10 + (int)me->query_skill("magic")*5);
        
        bonus = (me->query("combat_exp")-4000000)/15000;
        if (bonus<0) bonus=0;
        if (bonus>200) bonus = 200;
        
        me->add("neili", bonus-500);
        
        me->start_busy(2);
        return 1;
}    
