#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	object ob;
int skill,tg_skill,time;
string msg;
if( !target ) target = offensive_target(me);
if( !target || !target->is_character() || !me->is_fighting(target) )
return notify_fail("「金蛇游身」只能对战斗中的对手使用。\n");
if( (int)me->query_skill("wudu-yanluobu", 1) < 50 )
return notify_fail("你的五毒烟萝步火候不够，不能使出「金蛇游身」。\n");
if( (int)me->query("neili", 1) < 500 )
return notify_fail("你现在内力太弱，不能使用「金蛇游身」。\n");
if( target->is_busy() )
return notify_fail(target->name() + "目前正手忙脚乱，你还乱转什么，赶快进攻吧！\n");
msg = HIC "$N身行忽的一变，使出「金蛇游身」的绝技，身法越来越快。只见$N飞快的绕场游走，瞻之在前，望之在后，一时间到处都是$N的身影。"NOR"\n";
message_vision(msg, me, target);
time = (int)me->query_skill("wudu-yanluobu",1)/25;
skill = (int)me->query_skill("wudu-yanluobu",1)
 + (int)me->query_skill("dodge",1);
 tg_skill = (int)target->query_skill("dodge",1);
me->add("neili", -100);
 if (random(skill) > random(tg_skill))
{
target->start_busy(random(time)+3);
msg = HIR"$n不由得一阵手足无措，被$N连攻数招！"NOR"\n";
message_vision(msg, me, target);
return 1;
}
else
{
me->start_busy(4);
msg = HIR"可是$n以静制动，紧守门户，丝毫不受$N的影响,$N自己倒累的满头大汗！"NOR"\n";
message_vision(msg, me, target);
}
return 1;
}
int help(object me)
{
        write(HIY"\n五毒步法之「金蛇游身」:"NOR"\n\n");
        write(@HELP
        五毒教长老级人物才可修习的秘技，当年金蛇郎君夏雪宜
        自何红药处习得，后成为其独步武林的绝技之一，传说对
        身法要求很高。

HELP
);
return 1;
}
