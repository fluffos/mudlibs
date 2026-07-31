#include <ansi.h>
inherit F_SSERVER;
int exert(object me)
{
    string msg;
    object weapon;
    int skill, jing_cost;
//    mapping my_fam  = me->query("family");
    skill = me->query_skill("kuihua-xinfa",1);
    if (me->query_int()<50)
        jing_cost = (int)me->query_int() * 10;
    else    jing_cost=1;
    if( me->is_fighting() )
        return notify_fail("「隐身术」不能在战斗中演练。\n");
 
    if( !skill || (skill < 200))
        return notify_fail("你的葵花心法等级不够, 不能练习「隐身术」！\n");
    if( me->query("neili") < 500 )
        return notify_fail("你的内力不够，没有力气练习「隐身术」！\n");
    if( me->query("jing") < -jing_cost )
        return notify_fail("你现在太累了，无法集中精神练习「隐身术」！\n");
msg = HIR "$N微一凝神，运起葵花心法之"NOR WHT"隐身术"HIR"，整个人如同被烟雾笼罩一般，漂忽不定!!\n" + NOR;
    message_vision(msg, me);
    me->add("neili", -1000);
    me->add("jing", jing_cost);
        me->improve_skill("kuihua-xinfa", 10 + random((me->query_int() * 4)/3));
    msg = HIM"$P的「葵花心法」进步了！\n"NOR;
        if (random(10)>5)    me->start_busy(1);
    message_vision(msg, me);
    return 1;
}

