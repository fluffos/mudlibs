#include <ansi.h>

#include <combat.h>
inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, neili_wound, qi_wound;
        int i, attack_time;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("xueshan-sword",1);

        if( !(me->is_fighting() ))
            return notify_fail("「"+HIW"万梅飘零"NOR+"」只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("你使用的武器不对。\n");

        if( skill < 80)
            return notify_fail("你的雪山剑法修为不够, 不能使用「"+HIW"万梅飘零"NOR+"」！\n");  
        if( (int)me->query_skill("bingxue-xinfa",1) < 80 )
                return notify_fail("你的冰雪心法不够，不能使用「"+HIW"万梅飘零"NOR+"」！\n");

        if( me->query("neili") < 200 )
            return notify_fail("你的内力不够，无法运用「"+HIW"万梅飘零"NOR+"」！\n");

        msg = HIW 
    "$N长啸一声,使出「万梅飘零」,手中兵器疾卷,掀起万朵雪花向前铺天盖地的撒去。\n"
    "在白茫茫的一片中,忽然出现万朵梅花形剑花,穿透雪幕,朝四面八方狂射而出。\n" NOR;
        message_combatd(msg, me, target);

        ap = random(me->query("combat_exp") + skill*5);
        dp = target->query("combat_exp")/2;
        if( dp < 1 )
            dp = 1;
        if( random(ap) > dp )
        {
            if(userp(me))
                 me->add("neili",-150); 
        msg = HIC 
    "无数梅花光华,幻出道道剑气,将$n全身上下罩得严严实实。$n身在其中,\n"
    "只觉剑光束束,在自己身上丝丝划过,一时全身剧痛,鲜血飞溅得到处都是。如同凌迟之刑,\n"
    "惨不堪言。\n" NOR; 
        COMBAT_D->report_status(target);
            qi_wound = (int)me->query_skill("xueshan-sword",1)+(int)me->query_skill("sword",1);
            qi_wound = qi_wound/2 + random(qi_wound);
            if(qi_wound > target->query("qi"))
                 qi_wound = target->query("qi");
if (qi_wound <50) qi_wound = 50;
            target->receive_damage("qi", qi_wound);
            target->receive_wound("qi", qi_wound/2);
            target->receive_damage("jing", qi_wound/3);
            target->receive_wound("jing", qi_wound/5);
target->apply_condition("cold_poison",50);
target->apply_condition("ill_shanghan",50);
target->apply_condition("ice_poison",50);
target->apply_condition("iceshock",50);
target->apply_condition("xuantian_han",50);
target->apply_condition("xuanming_poison",50);
            me->start_busy(2);
        }
        else
        {
            if(userp(me))
                 me->add("neili",-100);
            msg = "可是$n轻捷地往旁边一闪，避过了这一剑。\n"NOR;
            me->start_busy(2);
        }
        if( random(me->query("combat_exp")) > (int)target->query("combat_exp")/4 ) {
         attack_time = random((int)me->query_skill("xueshan-sword", 1) / 30);
        if (attack_time > 9 ) attack_time=9;
        for(i = 0; i < attack_time; i++){
         msg = HIW "$N在漫漫雪花中，一技梅花刺了出来！\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
                        }
        me->start_busy(2);
}
        message_combatd(msg, me, target);

        return 1;
}

