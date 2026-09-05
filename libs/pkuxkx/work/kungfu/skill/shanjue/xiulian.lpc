//exercise.c 修炼
#include <ansi.h>
int exert(object me)
{       
        if ( me->is_fighting() )
                return notify_fail("打架的时候怎么能静下心来修炼呢？\n");
        if ( (int)me->query("neili")<(int)me->query("max_neili") )
                return notify_fail("你的真气尚未充盈，乃修炼的大忌。\n");        
        if ( (int)me->query("jing")<(int)me->query("max_jing")
                && (int)me->query("qi")<(int)me->query("max_qi") )
                return notify_fail("你的精气不适宜修炼，还是歇歇吧。\n");
        if ( (int)me->query_skill("shanjue", 1) < 150 )
                return notify_fail("你的善诀等级不够，不能修炼。\n");

        write(HIW"你盘腿端坐，收敛心神，只觉脑海中坦坦荡荡。。。\n"NOR);

        if ( me->query("shaqi") <= 0 ){
                me->set("attitude","peaceful");
                tell_object( me, HIW"你心中一片平和，已经没有丝毫杀气。\n"NOR);
                me->delete("attitude");
                me->set("shaqi" ,0 );
        }
        else {
                me->add("shaqi", -(int)me->query_skill("shanjue", 1)/10);
                tell_object( me, HIW"你感觉心中的杀气渐渐消失......\n"NOR);
        }
        me->start_busy(1+random(2));

        return 1;
}

