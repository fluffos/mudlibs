// heal.c
// 2009.8.15 edited by zgbl

#include <ansi.h>
int exert(object me, object target)
{
        if( me->is_fighting() )
                return notify_fail("战斗中运功疗伤？找死吗？\n");
        if ((int)me->query_skill("taiyi-shengong", 1) < 40)
                return notify_fail("你的太乙神功修为还不够。\n");
        if( (int)me->query("neili") < 50 )
                return notify_fail("你的真气不够。\n");
        if( (int)me->query("eff_qi") < (int)me->query("max_qi") / 2 )
                return notify_fail("你已经受伤过重，只怕一运真气便有生命危险！\n");
        write( HIW "你盘膝而坐，五心向天，暗运太乙神功，脸上青气流转，不久，吐出一口瘀血站了起来。\n" NOR);
        message("vision",
                HIW + me->name() + HIC "盘膝而坐，五心向天，脸上青气流转，不久，吐出一口瘀血站了起来。\n" NOR,
                environment(me), me);
        me->receive_curing("qi", (int)me->query_skill("force")/3 );
        me->receive_curing("jing", (int)me->query_skill("force")/6 );
        me->add("neili", -50);
        me->set("jiali", 0);
        return 1;
//无busy的heal，系数采用原有，治疗系数为1/3，治疗精神1/6
}