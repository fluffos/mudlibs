#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        int i,sl;
        object weapon;
        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("化蝶对战斗中的对手使用。\n");
        weapon = me->query_temp("weapon");
        if (!weapon) return notify_fail("化蝶只能和剑法配和！\n");
        if( (string)weapon->query("skill_type") != "sword" )
        return notify_fail("化蝶只能和剑法配和！\n");

        if ((int)me->query_skill("kurong-changong",1) < 80)
            return notify_fail("你的枯荣禅功太低。\n");
        if ((int)me->query_skill("duanjia-sword", 1) < 80)
		return notify_fail("你的段家剑火候太浅。\n");    
        if ((int)me->query_skill("jinyu-quan", 1) < 80)
		return notify_fail("你的金玉拳火候太浅。\n");
        if ((int)me->query_skill("wuluo-zhang", 1) < 80)
		return notify_fail("你的五罗轻烟掌火候太浅。\n");
        if ((int)me->query_skill("feifeng-whip", 1) < 80)
		return notify_fail("你的飞凤鞭火候太浅。\n");


		        if ((int)me->query("neili") < 500)
                return notify_fail("你现在的真气不够，难以施展。\n");
        extra = me->query_skill("tiannan-step",1) / 40;
        extra += me->query_skill("tiannan-step",1) /40;
        if (extra> 200) extra=200;
        sl=extra/3;
        if (sl > 9) sl=9;
        me->add_temp("apply/attack", extra);    
        me->add_temp("apply/damage", extra);
        msg = HIG  "$N脚踏［段氏步法］，同时使出［段氏剑法］中的精髓－［" + HIR"化蝶"HIG + "］，手中的"+ weapon->name() +"划出" + HIC"彩" + HIY"蝶" + HIG"般的曲线击向$n！" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
        for(i=0;i<sl;i++)
        {
        msg = HIC "$N身形如彩蝶飞舞，又出第"+chinese_number(i+1)+"剑！\n" NOR;
        COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
 me->add("neili",-20);
        }
        me->add_temp("apply/attack", -extra);
        me->add_temp("apply/damage", -extra);
        me->start_busy(2);
        return 1;

}