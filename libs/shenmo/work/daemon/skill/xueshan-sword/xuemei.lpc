//雪梅笑
#include <ansi.h>

#include <combat.h>
inherit F_SSERVER;

int perform(object me)
{
        string msg;
        object weapon, target;
        int skill, ap, dp, neili_wound, qi_wound;
        int i, attack_time,damage,extra,p;

        if( !target ) target = offensive_target(me);

        skill = me->query_skill("xueshan-sword",1);
        extra = me->query_skill("xueshan-sword",1);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail(HIC"只能对战斗中的对手使用。\n"); 

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("你使用的武器不对。\n");
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("你的内力不够。\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("你的内力不够。\n");

       if( !wizardp(me) &&(int)me->query_skill("jinwu-blade", 1) < 500 )
		return notify_fail("你的本门外功不够!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("xueshan-sword", 1) < 500 )
		return notify_fail("你的本门外功不够高!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("bingxue-xinfa", 1) < 500 )
		return notify_fail("你的本门内功不够高!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("你的江湖经验还不够，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("你还没有通过华山论剑! 无法对本门武功贯通使用！\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "bingxue-xinfa")
                return notify_fail("不使用本门内功，如何使用本门绝学!\n");


        msg = HBWHT "$N贯通凌霄城武学，使出了凌霄城的绝学之精髓！\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);          
if (random(3)==0) target->start_busy(3);
         attack_time = random((int)me->query_skill("xueshan-sword", 1) / 30);
if (attack_time > 9 )attack_time=9;
        for(i = 0; i < attack_time; i++){
	me->add_temp("apply/attack",extra/3);
	me->add_temp("apply/damage",extra*2);
         msg = HIW "$N在漫漫雪花中，一技梅花刺了出来！\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack",-extra/3);
	me->add_temp("apply/damage",-extra*2);
                        }


        msg = HIW 
    "$N长啸一声,使出「万梅飘零」,手中兵器疾卷,掀起万朵雪花向前铺天盖地的撒去。\n"
    "在白茫茫的一片中,忽然出现万朵梅花形剑花,穿透雪幕,朝四面八方狂射而出。\n" NOR;
        message_combatd(msg, me, target);

        ap = me->query("combat_exp") + skill;
        dp = target->query("combat_exp") / 3;
        if( dp < 1 )
            dp = 1;
        if( random(ap) > dp )
        {
        msg = HIC 
    "无数梅花光华,幻出道道剑气,将$n全身上下罩得严严实实。$n身在其中,\n"
    "只觉剑光束束,在自己身上丝丝划过,一时全身剧痛,鲜血飞溅得到处都是。如同凌迟之刑,\n"
    "惨不堪言。\n" NOR; 
        //COMBAT_D->report_status(target);
            qi_wound = (int)me->query_skill("xueshan-sword",1)+(int)me->query_skill("sword",1);
            qi_wound = qi_wound/2 + random(qi_wound);
            if(qi_wound > target->query("qi"))
                 qi_wound = target->query("qi");
           if (qi_wound <50) qi_wound = 50;
            target->receive_damage("qi", qi_wound*3);
            target->receive_wound("qi", qi_wound);
            target->receive_damage("jing", qi_wound/3);
            target->receive_wound("jing", qi_wound/5);
        }
        else
        {
            msg = "可是$n轻捷地往旁边一闪，避过了这一剑。\n"NOR;
        }

        msg = HIC "$N回剑旋舞，剑势不断加快，剑气呼啸四散，如片片雪花遇风，飘然而出。\n形成一个雪花形旋涡，将$n裹在内里。\n";
        if(random(me->query("combat_exp")) > (int)target->query("combat_exp")/3) {
                msg +=HIG "$n只觉得四周压力越来越大，道道暗流缠绕周身，几乎动弹不得。\n" NOR;
target->apply_condition("cold_poison", 50 +
			target->query_condition("cold_poison"));
            target->receive_damage("qi", qi_wound*5);
            target->receive_wound("qi", qi_wound);
        } else {
                msg +=HIR "可是$n运足内力，雪花顿时全部溶解，一片不剩，脱出重围。\n" NOR;

        }

        me->start_busy(4);
        message_combatd(msg, me, target);

        return 1;
}

