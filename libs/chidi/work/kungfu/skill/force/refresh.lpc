// recover.c
//inherit SSERVER;
int exert(object me, object target)
{
    int n, q;
    if (me != target)
        return notify_fail("你只能用内功恢复自己的精力。\n");
    if ((int)me->query("neili") < 20)
        return notify_fail("你的内力不够。\n");
    q = (int)me->query("max_jingli") - (int)me->query("jingli");
    if (q < 10)
        return notify_fail("你现在精力充沛。\n");
        n = q/2 ;
    if (n < 20)
        n = 20;
    if ((int)me->query("neili") < n) {
        q = 2 * (int)me->query("neili");
        n = (int)me->query("neili");
    }
    me->add("neili",-n);
    me->add("jingli", q);
    if(me->query("jingli")>me->query("max_jingli"))
    me->set("jingli",me->query("max_jingli"));
    
//         message_vision("$N深深吸了几口气，感觉到又充满了活力。\n", me);
 write("你深深吸了几口气，感觉到又充满了活力。\n");
        if( me->is_fighting() ) me->start_busy(2);
        me->improve_skill("force", random(me->query_skill("force", 1)),0);
    return 1;
}
