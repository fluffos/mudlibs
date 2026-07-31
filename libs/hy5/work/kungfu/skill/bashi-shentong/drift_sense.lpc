// drift_sense.c 游识神通
// Modified by Venus Oct.1997

#include <ansi.h>
//inherit SSERVER;

int conjure(object me, object target)
{
    if( me->is_fighting() )
   return notify_fail("战斗中无法使用游识神通！\n");
    if( me->query("jingli") < 75 )
   return notify_fail("你的精力不够！\n");
    if( target )
   return notify_fail("游识神通只能对自己使用！\n");
    write("你要“游”到哪一个人身边？");
    input_to( (: call_other, __FILE__, "select_target", me :));
    return 1;
}

void select_target(object me, string name)
{
    object ob;


    if( !name || name=="" ) {
   write("中止施法。\n");
   return;
    }

    ob = find_player(name);
    if( !ob || !me->visible(ob) || wizardp(ob) )
   ob = find_living(name);
    if( !ob || !me->visible(ob) || wizardp(ob) ) {
   write("你无法感受到这个人的精力 ....\n");
   write("你要“游”到哪一个人身边？");
   input_to( (: call_other, __FILE__, "select_target", me :));
   return;
    }
    if( me->is_fighting() ) {
   write("战斗中无法使用游识神通！\n");
   return;
    } else if( me->query("jingli") < 75 ) {
   write("你的精力不够！\n");
   return;
    }

    me->add("jingli", -75);
    me->receive_damage("jing", 30);

    message_vision( HIY "$N微闭双目，盘膝坐下，开始施展游识神通……\n" NOR, me);
    if ( random( ob->query("max_jingli") + (int)me->query("jingli")) < 300 ) {
   write("对方的精力不够强烈，你感受不出其具体位置。\n");
   return;
    }
    if( random(me->query_skill("magic")) < (int)ob->query("jingli") / 50 ) {
   write("你因为不够熟练而失败了。\n");
   return;
    }
    message( "vision", HIY "\n一朵祥云忽然自天空中飘下，只见" + me->name()
   + "慢慢升上祥云，然後人和祥云一起飞走，消失得无影无踪！\n\n",
    environment(me), ({ me }) );
    me->move(environment(ob));
    message( "vision", HIY "\n你的眼前突然飘过一朵祥云，再仔细一看，竟有个人
影自祥云上一跃而下！\n\n" NOR,
   environment(ob), ({ me }) );
}

