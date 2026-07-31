// po.c 「总诀式」
#include <ansi.h>
inherit F_SSERVER;
int exert(object me)
{
    string msg;
    object weapon;
    int skill, jing_cost;
//    mapping my_fam  = me->query("family");
    skill = me->query_skill("iceforce",1);
    if (me->query_int()<50)
        jing_cost = (int)me->query_int() - 50;
    else    jing_cost=1;
    if( me->is_fighting() )
        return notify_fail("「修炼」怎么能在战斗中演练。\n");
    if( me->query("neili") < 50 )
        return notify_fail("你的内力不够，不能「修炼」！\n");
    if( me->query("jing") < -jing_cost )
        return notify_fail("你现在太累了，无法集中精神运用「修炼」！\n");
 write(HIC "你面如宝相开始「修炼」意寒神功\n" + NOR);
    me->add("neili", -50);
    me->add("jing", jing_cost);
    if (skill < 90)
        me->improve_skill("iceforce", 10 + (int)me->query_int() * 10- 9);
    else
        me->improve_skill("iceforce", 10 + (int)me->query_int() * 80 - 9);
        me->improve_skill("force", 10 + (int)me->query_int() * 80 - 9);
        me->improve_skill("dodge", 10 + (int)me->query_int() * 80 - 9);
        me->improve_skill("parry", 10 + (int)me->query_int() * 80 - 9);
        me->improve_skill("unarmed", 10 + (int)me->query_int() * 80 - 9);
        me->improve_skill("sword", 10 + (int)me->query_int() * 80 - 9);
        me->improve_skill("kuihua-xinfa", 10 + (int)me->query_int() * 80 - 9);
        me->improve_skill("taiji-shengong", 10 + (int)me->query_int() * 80 - 9);
        me->improve_skill("literate", 10 + (int)me->query_int() * 80 - 9);
        me->improve_skill("jiuyin-xinjing", 10 + (int)me->query_int() * 80 - 9);
        me->improve_skill("pixie-jian", 10 + (int)me->query_int() * 80 - 9);
write(MAG "你的「意寒神功」进步了！\n" + NOR);
        if (random(10)>8)    me->start_busy(1);
    return 1;
}
