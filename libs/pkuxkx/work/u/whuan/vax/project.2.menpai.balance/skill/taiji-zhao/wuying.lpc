// taijizhao.c 太极爪----无影爪
// by male

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
    string msg;
    int damage;
    int coefficient;

    if( !target ) target = offensive_target(me);
    if( !target ||      !target->is_character() ||      !me->is_fighting(target) )
        return notify_fail("「无影爪」只能对战斗中的对手使用。\n");
    if( (int)me->query_skill("taiji-zhao", 1) <600 )
        return notify_fail("你的太极爪不够火候, 使不出无影爪\n");
	 
	 // dewolf 大弟子判定
    if( me->query("family/family_name")!="武当派" || !me->query("family/topone") )
        return notify_fail("只有本派大弟子才有权使用无影爪对敌！\n");
	 
    msg="";
    if(me->query("qi")>me->query("max_qi")/5.0)
    {
        if((int)me->query("neili")<5000)
            return notify_fail("你的内力不够,难以驾驭无影爪!\n");
        if((int)target->query("max_qi")<3000||(int)target->query("combat_exp")<(int)me->query("combat_exp")*3.0/5.0)
            return notify_fail(HIY"无影爪乃高手过招时才能使用，非迫不得已不得滥用！\n"NOR);
    }
    else
    {
        msg=HIR"$N在生命垂危之际，迫不得已，使出救命绝招无影爪\n 情急之中,$N觉得自己真气迸发,内力有所增加!\n";
        me->add("neili",1000);
    }
    msg += HIW "$N一声长啸，双手幻化为千万爪影, 霎那间,爪影遍布$n周身,$n那里见过这种阵势？马上就被惊呆了\n";
    me->start_busy(1);
    if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/6)
    {
        msg += HIY"结果$p竟然忘了防御,被抓了个正着。\n" NOR;

        damage = (int)me->query_skill("taiji-zhao", 1)+(int)me->query_skill("taiji-shengong", 1)+(int)me->query_skill("force",1);
        coefficient=(int)me->query("combat_exp")/10000000;
        if (coefficient>5)
            coefficient=5;

        damage=damage*coefficient;
        target->receive_damage("qi", damage, me);
        target->receive_wound("qi", damage/2, me);
        me->add("neili",-4000);
        target->start_busy(2);

    } else {
        me->start_busy(1);
        msg += MAG"可是$p一凝神,会过神来看破了$P的企图，并没有上当。\n" NOR;
        me->add("neili",-1000);
    }
    message_vision(msg, me, target);
    if(me->query("neili")<0) {
        msg=HIR"终于，$N无影爪的滥用导致你的真气消耗过度，眼前一黑，虚脱过去......";
        message_vision(msg,me,target);
        me->unconcious();
    }
    return 1;
}


