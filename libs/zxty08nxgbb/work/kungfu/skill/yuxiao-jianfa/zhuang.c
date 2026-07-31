//by pipip
#include <ansi.h>
inherit F_SSERVER;
int perform(object me, object target)
{
    int time;
    object weapon;
    string msg;
    int busy;
    busy=(int)me->query_skill("yuxiao-jianfa") / 40; 
    if (busy > 20 ) busy=20;
    if( !target ) target = offensive_target(me);
    if( !target
    ||  !target->is_character()
    ||  !me->is_fighting(target) )
        return notify_fail("「撞穴」只能对战斗中的对手使用。\n");
if ( (string)me->query("family/family_name") != "桃花岛") 
     return notify_fail("只有桃花岛弟子才能使用该PFM。\n");
    if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
    if (!objectp(weapon = me->query_temp("secondary_weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("你使用的武器不对。\n");
      
        if( target->is_busy() )
                return notify_fail(target->name() + "已经忙不得了了哦！\n");
                
        if( (int)me->query_skill("yuxiao-jianfa", 1) < 200 )
                return notify_fail("你还没得到玉箫剑法的精髓，使不出「撞穴」绝学。\n");

    msg = HIG "$N猛一回手，施展出玉箫剑法的精髓「撞穴」，数道剑光同时撞向$n身上一十三处穴道！\n";

 if( random(me->query_exp()*5) > target->query_exp() ) {
   msg += HIB "$p躲闪不及，被$N刺中几处大穴，顿时动弹不得。\n" NOR;
             target->start_busy( busy );
   me->add("neili", -500);
        } else {
        me->start_busy(2);
           me->add("neili",-300);        
                msg += HIY "$p看穿了$N手中剑尖落点，凝气聚神将那一十三剑尽数躲开。\n" NOR;
        }
        message_vision(msg, me, target);

        return 1;
}


