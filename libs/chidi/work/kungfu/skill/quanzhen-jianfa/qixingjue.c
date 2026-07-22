#include <ansi.h>
inherit F_SSERVER;
int perform(object me)
{
    string msg;
    object weapon;
    int skill, jing_cost;
//    mapping my_fam  = me->query("family");
    skill = me->query_skill("quanzhen-jianfa",1);
    if (me->query_int()<50)
        jing_cost = (int)me->query_int() - 50;
    else    jing_cost=1;
    if( me->is_fighting() )
        return notify_fail("「七星诀」不能在战斗中演练。\n");
 
    if (!objectp(weapon = me->query_temp("weapon"))
    || (string)weapon->query("skill_type") != "sword")
        return notify_fail("你必须先去找一把剑。\n");
    if( !skill || (skill < 60))
        return notify_fail("你的全真剑法等级不够, 不能演练「七星诀」！\n");
    if( me->query("neili") < 50 )
        return notify_fail("你的内力不够，没有力气演练「七星诀」！\n");
    if (me->query_skill("sword",1)<= skill)
        return notify_fail("你的基本剑法不够，无法通过演练「七星诀」提高全真剑法的技巧！\n");
    if( me->query("jing") < -jing_cost )
        return notify_fail("你现在太累了，无法集中精神演练「七星诀」！\n");
 write(HIC "你使出全真剑法之「七星诀」，将手中" + weapon->name() + HIC "随意挥舞击刺。\n" + NOR);
    me->add("neili", -50);
    me->add("jing", jing_cost);
    if ( skill < 60)
        me->improve_skill("quanzhen-jianfa", 10);
    else if (skill < 90)
        me->improve_skill("quanzhen-jianfa", 10 + random((int)me->query_int() - 9));
    else if (skill < 140)
        me->improve_skill("quanzhen-jianfa", 10 + random((int)me->query_int() * 2 - 9));
    else if (skill < 200)
        me->improve_skill("quanzhen-jianfa", 10 + random((int)me->query_int() * 4 - 9));
    else
        me->improve_skill("quanzhen-jianfa", 10 + random((int)me->query_int() * 8 - 9));
write(MAG "你的「全真剑法」进步了！\n" + NOR);
        if (random(10)>8)    me->start_busy(1);
    return 1;
}

