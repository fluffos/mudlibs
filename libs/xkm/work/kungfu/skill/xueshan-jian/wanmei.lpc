#include <ansi.h>

inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, neili_wound, qi_wound;

        me->clean_up_enemy();
        target = me->select_opponent();

        skill = me->query_skill("xueshan-jianfa",1);

        if( !(me->is_fighting() ))
            return notify_fail("「"+HIW"万梅飘零"NOR+"」只能对战斗中的对手使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("你使用的武器不对。\n");

        if( (int)me->query_skill("xueshan-jian",1) < 80 )
            return notify_fail("你的雪山剑法修为不够, 不能使用「"+HIW"万梅飘零"NOR+"」！\n");  
        if( (int)me->query_skill("bingxue-xinfa",1) < 80 )
                return notify_fail("你的冰雪心法不够，不能使用「"+HIW"万梅飘零"NOR+"」！\n");

        if( me->query("neili") < 200 )
            return notify_fail("你的内力不够，无法运用「"+HIW"万梅飘零"NOR+"」！\n");

        message_vision(HIW "$N长啸一声,使出「万梅飘零」,手中兵器疾卷,掀起万朵雪花向前铺天盖地的撒去。
在白茫茫的一片中,忽然出现万朵梅花形剑花,穿透雪幕,朝四面八方狂射而出。\n"NOR,me,target);
        
        ap = me->query_skill("sword",1) + skill;
        dp = target->query_skill("dodge",1) / 2;
        if( dp < 1 )
            dp = 1;
        if( random(ap) > dp )
        {
            if(userp(me))
                 me->add("neili",-150); 
       message_vision( HIC"无数梅花光华,幻出道道剑气,将$n全身上下罩得严严实实。$n身在其中只觉剑光束束,
在自己身上丝丝划过,一时全身剧痛,鲜血飞溅得到处都是。如同凌迟之刑,惨不堪言。\n" NOR,me,target); 
        COMBAT_D->report_status(target);
            qi_wound = (int)me->query_skill("xueshan-jian",1)+(int)me->query_skill("sword",1);
            qi_wound = qi_wound + random(qi_wound);
            target->receive_damage("qi", qi_wound/2);
            target->receive_wound("qi", qi_wound/3);
            target->receive_damage("jing", qi_wound/6);
            target->receive_wound("jing", qi_wound/6);
            target->add("jingli",-qi_wound/5); 
            target->start_busy(2+random(1));
            me->start_busy(1+random(1));me->start_perform(6,"「"HIW"万梅飘零"NOR"」");
        }
        else
        {
            if(userp(me))
                 me->add("neili",-100);
            message_vision(HIR"可是$n轻捷地往旁边一闪，避过了这一剑。\n"NOR,me,target);
            me->start_busy(2);me->start_perform(4,"「"HIW"万梅飘零"NOR"」");
        }
        

        return 1;
}

