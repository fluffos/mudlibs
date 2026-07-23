// 海潮汹涌
 
#include <ansi.h>
#include <combat.h> 
#include <skill.h>

inherit F_SSERVER;

int perform(object me, object target)
{
         string name,dodge_skill,msg;
         int i, j, p;
 
         object weapon = me->query_temp("weapon");
        
         if( !target ) target = offensive_target(me);
 
         if( !target || !me->is_fighting(target) )
                 return notify_fail("「闪电惊虹」只能在战斗中对对手使用。\n");
         if(!weapon || weapon->query("skill_type") != "sword")
                 return notify_fail("你必须使用武器才能使用「闪电惊虹」！\n");   
         if( (int)me->query_skill("tianyu-qijian", 1) < 150 )
                 return notify_fail("你的天羽奇剑还不够娴熟，使不出「闪电惊虹」绝技。\n");
         if( (int)me->query_skill("bahuang-gong", 1) < 150 )
                 return notify_fail("你的八荒六合功等级还不够，使不出「闪电惊虹」绝技。\n");
         if( (int)me->query_skill("force") < 150 )
                 return notify_fail("你的内功等级不够，不能使用「闪电惊虹」。\n");
         if( (int)me->query_str() < 30 )
                 return notify_fail("你的膂力还不够强劲，使不出「闪电惊虹」来。\n");
         //if ( me->query_skill_mapped("sword") != "tianyu7gong")
         //       return notify_fail("你现在无法使用「闪电惊虹」！\n");                                                                                 
         if( (int)me->query("max_neili") < 1000 )
                 return notify_fail("你现在内力太弱，使不出「闪电惊虹」。\n");      
         if( (int)me->query("neili") < 500)
                 return notify_fail("你现在真气太弱，使不出「闪电惊虹」。\n");
 
         me->set_temp("xtj_haichao", 1);
         message_vision(MAG"\n$N"+weapon->name()+MAG"微微晃动，当气势蓄至巅峰时，双眉耸竖，大步前跨，一股彻骨的剑气，立即潮涌而去。\n"NOR,me,target);
         i = me->query_skill("tianyu-qijian", 1)/2;
         j = me->query_skill("sword", 1)/2;
         me->add_temp("apply/strength", i);
         me->add_temp("apply/attack", j);
         me->add_temp("apply/damage", j); 
           msg = HIC "$w"HIC"在$N用劲的指引下，忽似轻巧起来，破空之声反收至净尽，变成沉雄的呼啸，更增使人心寒胆落的威势！" NOR;  
           COMBAT_D->do_attack(me,target, me->query_temp("weapon"),1,msg); 
           msg = HIC "$N挥剑起舞，一时剑气纵横，生出亦静亦动，静时有若波平如镜的大海，动时则似怒海激涛，变化莫测！" NOR;             
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),1,msg);      
           msg = HIC "$N每一姿态都妙至毫巅，每一个动作都表现出人类体能的极限，既文静又激烈，形成惊天地泣鬼神的气势！" NOR; 
           COMBAT_D->do_attack(me,target, me->query_temp("weapon"),1,msg);	
         me->add("neili", -300);

         me->add_temp("apply/strength", -i);
         me->add_temp("apply/attack", -j);
	me->add_temp("apply/damage", -j);
	if (random(me->query("combat_exp")) > target->query("combat_exp")/3 ){
         message_vision(HIW"\n突然间天空中一声巨响，一道闪电划破夜空劈在"+weapon->name()+HIW"上，$N挟雷电之威，向$n扑了过去。\n"NOR,me,target);
	if (random(10)>3||target->is_busy()){
		message_vision(HIR"结果$n躲闪不及被$N攻了正着，" + weapon->name() + HIR"上的"HIC"电劲"HIR"乘机钻入$n体内。\n"NOR,me,target);
              p = 3+random(4);
              target->start_busy(p);
}
	else {
         dodge_skill = target->query_skill_mapped("dodge");
	 if( !dodge_skill ) dodge_skill = "dodge";
         message_vision(SKILL_D(dodge_skill)->query_dodge_msg(target, 1), me, target);	
         me->add("neili",-50);
		}
		}
me->start_busy(2);
//	      me->start_perform(6,"「闪电惊虹」");
       return 1;
 }

 