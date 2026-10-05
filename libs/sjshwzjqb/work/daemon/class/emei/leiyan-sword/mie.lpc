// mie.c 峨嵋灭剑  海上飘（piao）

#include <ansi.h>
inherit SSERVER;
int perform(object me, object target)
{
        object weapon;
        int i;
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      target->is_corpse()
        ||      target==me)
                return notify_fail("你要对谁施展这一招「灭剑」？\n");
        if (me->query_skill_mapped("force")!="emeiforce")
                return notify_fail("「灭剑」必须配合峨嵋心法才能使用。\n");
        if(!me->is_fighting())
                return notify_fail("「灭剑」只能在战斗中使用！\n");
        if((int)me->query("max_force") < 1000 )
                return notify_fail("你的内力不够！\n");
        if((int)me->query("force") < 1000 )
                return notify_fail("你的内力不足！\n");
        if((int)me->query("sen") < 500 )
                return notify_fail("你的精神不足，没法子施用外功！\n");
         i=(int)me->query_skill("leiyan-sword",1)+(int)me->query_kar();
        if( i < 120)
                return notify_fail("你的雷炎剑级别还不够，使用这一招会有困难！\n");
	 message_vision(HIG"\n$N运起内力，脸上一阵怒气，一声巨吼之下发出绝招「"HIW"灭剑"HIG"」！\n"NOR,me);
	 me->delete("env/brief_message");
	 target->delete("env/brief_message");
        me->set_temp("QJB_perform", 7);
        COMBAT_D->do_attack(me, target, me->query_temp("weapon"));
        me->delete_temp("QJB_perform");
        me->receive_damage("sen", 100+random(100));
        me->add("force", -200);
        if( !target->is_fighting(me) ) {
                if( living(target) ) {
                        if( userp(target) ) target->fight_ob(me);
                        else target->kill_ob(me);
                }
        }
        me->start_busy(1+random(1));
        return 1;
}

