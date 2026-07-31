// void_sense.c 空识神通
// Modified by Venus Oct.1997

#include <ansi.h>

//inherit SSERVER;

int conjure(object me, object target)
{
    int     delta;
    if( target ) return notify_fail("空识神通只能对自己使用。\n");
    if( me->query("jingli") < 30 )
   return notify_fail("你的灵力不够！\n");
    me->add("jingli", -30);
    me->receive_damage("jing", 10);
    message_vision(HIY "$N盘膝而座，一动不动，开始静思入定……\n" NOR, me);
    if( random(me->query_skill("magic")) > (int)me->query_int() ) {
    if( random(me->query("max_jingli")) < (int)me->query("jingli")/2 )
 {
    me->add("learned_points", 1);
    write( HIR "你只觉得心绪一阵烦乱，你的潜能降低了！\n" NOR);
    return 1;
   }
    if( ((int)me->query("potential") - (int)me->query("learned_points")) < 500 )
    {
    delta = random((int)me->query_con() + (int)me->query_skill("bashi-shentong") )/10;
   if( delta > 0 )
   {
      me->add("potential", random((int)me->query_con() + (int)me->query_skill("bashi-shentong") )/10);
      write( HIG "你的潜能获得提高了！\n" NOR );
      return 1;
   }
    }
    }
    write("但你只觉得一无所获。\n");
    return 1;
}

