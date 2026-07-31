// po.c 「总诀式」
#include <ansi.h>
inherit F_SSERVER;
int perform(object me)
{
    string msg;
    object weapon;
    int skill, jing_cost;
//    mapping my_fam  = me->query("family");
    skill = me->query_skill("dugu-jiujian",1);
    if (me->query_int()<50)
        jing_cost = (int)me->query_int() - 50;
    else    jing_cost=1;
    if( me->is_fighting() )
        return notify_fail("「总诀式」不能在战斗中演练。\n");
 
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你必须先去找一把剑。\n");
    if( !skill || (skill < 60))
        return notify_fail("你的独孤九剑等级不够, 不能演练「总诀式」！\n");
    if( me->query("neili") < 50 )
        return notify_fail("你的内力不够，没有力气演练「总诀式」！\n");
    if (me->query_skill("sword",1)<= skill)
        return notify_fail("你的基本剑法不够，无法通过演练「总诀式」提高独孤九剑的技巧！\n");
    if( me->query("jing") < -jing_cost )
        return notify_fail("你现在太累了，无法集中精神演练「总诀式」！\n");
 write(HIC "你使出独孤九剑之「总诀式」，将手中" + weapon->name() + HIC "随意挥舞击刺。\n" + NOR);
    me->add("neili", -50);
    me->add("jing", jing_cost);
    if ( skill < 60)
        me->improve_skill("dugu-jiujian", 10);
    else if (skill < 90)
        me->improve_skill("dugu-jiujian", 10 + random((int)me->query_int() - 9));
    else if (skill < 140)
        me->improve_skill("dugu-jiujian", 10 + random((int)me->query_int() * 2 - 9));
    else if (skill < 200)
        me->improve_skill("dugu-jiujian", 10 + random((int)me->query_int() * 4 - 9));
    else
        me->improve_skill("dugu-jiujian", 10 + random((int)me->query_int() * 8 - 9));
write(MAG "你的「独孤九剑」进步了！\n" + NOR);
        if (random(10)>8)    me->start_busy(1);
    return 1;
}
