// transfer.c 轉內力
// Modified by Venus Oct.1997
#include <ansi.h>


int exert(object me, object target)
{
    int force, trans;

    if( !target || target==me || !living(target) )
   return notify_fail("你要將真氣傳給誰？\n");

    if( (string)me->query_skill_mapped("force") !=
target->query_skill_mapped("force") )
   return notify_fail(target->name() +
"所使用的內功\和你不同，不能傳內力。\n");

    if( (int)me->query("neili") <= (int)me->query("max_neili")/3 )
   return notify_fail("你的真氣不足。\n");

    if ((int)target->query("neili")>=(int)target->query("max_neili")*4)
     return notify_fail("對方的真氣充沛，不需要你的真氣。\n");

    force = me->query("neili") - (me->query("max_neili")/3);

    if( force/2 < 1 ) return notify_fail("你的真氣不足。\n");
    me->add("neili", -force/3 );
    message_vision(HIW"$N一掌拍在$n背心，順勢運氣將體內真氣傳送過去。\n"NOR,
 me,target);
    target->add("neili", force/2);
    write("Ok。\n");
    tell_object(target, HIW "你覺得一股熱氣從" + me->name() +"的手掌中傳了過
來。\n" NOR);
    return 1;
}

