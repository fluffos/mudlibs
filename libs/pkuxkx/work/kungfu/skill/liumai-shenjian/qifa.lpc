// qifa.c
//减弱北冥的加成，去除枯荣要求和门派要求buy huacuoh 2015/2/14
#include <ansi.h>
inherit F_SSERVER;

int valid_target_arg(string target)
{
    if ( target == "version" ) return 2;
    return target=="null" || target=="other" ;
}

int perform(object me, object target)
{
    string msg;
    int damage;
    int damage1;
    int damage2;
    object weapon;

    if( !target ) target = offensive_target(me);

    if( !objectp(target) || !target->is_character() || !me->is_fighting(target) )
        return notify_fail("「六剑齐发」只能对战斗中的对手使用。\n");

   if ( userp(me) && 
         (int)me->query_skill("beiming-shengong", 1) < 100 )
        return notify_fail("你的北冥神功不够火候, 使不出「六剑齐发」。\n");


 /*   if ( userp(me) && 
         (int)me->query_skill("kurong-shengong", 1) < 100 )
        return notify_fail("你的枯荣神功不够火候, 使不出「六剑齐发」。\n");  2015/2/14 注释掉by huacuoh
*/
    if( (int)me->query_skill("liumai-shenjian", 1) <100 )
        return notify_fail("你的六脉神剑不够火候, 使不出六剑齐发\n");

    if((int)me->query("neili")<50) return notify_fail("你的内力不够呀!\n");

    msg = CYN "$N使出六脉神剑的六剑齐发, 一时间数条剑气纵横捭阖，冲向$n。\n";
    me->start_busy(3);
    if( F_KUNGFU->hit_rate( me->query("combat_exp"), (int)target->query("combat_exp"), 8, me, target) )
    {
        msg += "结果$p被$P刺个正着。\n" NOR;
        //damage = (int)me->query_skill("liumai-shenjian", 1)+me->query_skill("beiming-shengong",1);
        damage = (int)me->query_skill("liumai-shenjian", 1)*3/4+me->query_skill("beiming-shengong",1)/4;// 减弱北冥的影响by huaucoh  2015/2/14
        //if (  me->query("family/family_name")=="天龙寺" &&
        //      !me->query("chushi/done") )
       // {
          if ( me->query("max_neili")>10000 && me->query("max_neili")<=20000)
            damage+=200;
          else if ( me->query("max_neili")>20000 && me->query("max_neili")<=30000)
            damage+=500;
          else if ( me->query("max_neili")>30000 && me->query("max_neili")<=40000)
            damage+=1000;
          else if ( me->query("max_neili")>40000 )
            damage+=1500;
        //}
        
        damage = damage/2 + random( damage );
        F_KUNGFU->hit_wound("qi", damage, damage/2, me, target);
        me->add("neili",-100);
    } 
    else 
    {
        me->start_busy(3);
        msg += "可是$p看破了$P的企图，并没有上当。\n" NOR;
        me->add("neili",-100);
    }
    message_vision(msg, me, target);
    COMBAT_D->report_status(target);
    return 1;
}


