// pojian.c 独孤九剑「总诀式」
// qfy July 5, 1996.

#include <ansi.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        object weapon;
        mapping my_fam  = me->query("family");
        if( !target ) target = offensive_target(me);
        if(my_fam["master_id"] != "feng qingyang")

           return notify_fail("你不是风清扬的弟子，不能使用「总诀式」。\n");

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("总诀式只能对战斗中的对手使用。\n");

        if( target->is_busy() )
                return notify_fail(target->name() + "目前正自顾不暇，放胆攻击吧。\n");
                
        if( (int)me->query_skill("lonely-sword", 1) < 100 || (int)me->query("max_neili") < 500 )
                return notify_fail("你的独孤九剑或内力修为不够，还未学成「总诀式」。\n");

        if( me->query("neili") <= 100 )
                return notify_fail("你的内力不够！\n");

        msg = CYN "$N窥破$n招式的破绽，使出独孤九剑「总诀式」，随手一剑妙到颠毫。\n";

        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/2 ) {
            if( !weapon = target->query_temp("weapon") ) {
             switch (random(2)) {
             case 0:
                msg += HIR"$p意外之余，闪避无从，惊骇中连中数剑受伤。\n" NOR; 
                target->receive_wound("qi",random((int)me->query_skill("lonely-sword"))*2,me);
                break;
             case 1:
                msg += HIY"$p惊骇莫明，欲避不能，被$P刺中丹田，功力受损。\n" NOR;
                target->add("neili",-(random((int)me->query_skill("lonely-sword"))*2));
                break;
             }
            }
            else {
             switch (random(2)) {
             case 0:
                msg += HIW"$p莫明其妙，百思不解为何$P随意一剑竟能如此神妙，只好放弃"+weapon->query("name")+"。\n" NOR;
                weapon->move(environment(me));
                break;
             case 1:
                msg += HIM"$p惊骇莫明，欲避不能，被$P刺中丹田，功力受损。\n" NOR;
                target->add("neili",-(random((int)me->query_skill("lonely-sword"))*2));
                break;
             }
            }
            target->start_busy( (int)me->query_skill("sword") / 28 );
        } 
        else {
                msg += HIC"$p虽然看破了$P的剑路，几经艰难方能还招挡开。\n" NOR;
                me->start_busy(1 + random(3));
        }
        message_vision(msg, me, target);
        me->add("neili", -25);
        me->add("jing", -10);
        me->start_busy(1);
        return 1;
}
