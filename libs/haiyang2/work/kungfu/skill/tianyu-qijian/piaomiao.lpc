// 缥缈剑
 
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
                 return notify_fail("缥缈剑只能在战斗中对对手使用。\n");
         if(!weapon || weapon->query("skill_type") != "sword")
                 return notify_fail("你必须使用武器才能使用「缥缈剑」！\n");   

	if(me->is_busy())
		return notify_fail("你现在没空！！\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("你的内力不够。\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("你的内力不够。\n");

       if( !wizardp(me) &&(int)me->query_skill("tianyu-qijian", 1) < 500 )
		return notify_fail("你的本门外功不够!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("zhemei-shou", 1) < 500 )
		return notify_fail("你的本门外功不够高!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("bahuang-gong", 1) < 500 )
		return notify_fail("你的本门内功不够高!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("你的江湖经验还不够，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("你还没有通过华山论剑! 无法对本门武功贯通使用！\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "bahuang-gong")
                return notify_fail("不使用本门内功，如何使用本门绝学!\n");


        msg = HBWHT "$N贯通灵鹫宫武学，使出了灵鹫宫的绝学之精髓！\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);          
 
         me->set_temp("xtj_haichao", 1);
         message_vision(MAG"\n$N"+weapon->name()+MAG"微微晃动，当气势蓄至巅峰时，双眉耸竖，大步前跨，一股彻骨的剑气，立即潮涌而去。\n"NOR,me,target);
         i = me->query_skill("tianyu-qijian", 1)/2;
         j = me->query_skill("sword", 1)/2;
         me->add_temp("apply/strength", i);
         me->add_temp("apply/attack", j);
         me->add_temp("apply/damage", j); 
           if (random(3)==0) target->start_busy(3);
           msg = HIC "$w"HIC"在$N用劲的指引下，忽似轻巧起来，破空之声反收至净尽，变成沉雄的呼啸，更增使人心寒胆落的威势！" NOR;  
           COMBAT_D->do_attack(me,target, me->query_temp("weapon"),1,msg); 
           msg = HIC "$N挥剑起舞，一时剑气纵横，生出亦静亦动，静时有若波平如镜的大海，动时则似怒海激涛，变化莫测！" NOR;             
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),1,msg);      
           msg = HIC "$N每一姿态都妙至毫巅，每一个动作都表现出人类体能的极限，既文静又激烈，形成惊天地泣鬼神的气势！" NOR; 
           COMBAT_D->do_attack(me,target, me->query_temp("weapon"),1,msg);	

         me->add_temp("apply/strength", -i);
         me->add_temp("apply/attack", -j);
	me->add_temp("apply/damage", -j);
	if (random(me->query("combat_exp")) > target->query("combat_exp")/3 ){
         message_vision(HIW"\n突然间天空中一声巨响，一道闪电划破夜空劈在"+weapon->name()+HIW"上，$N挟雷电之威，向$n扑了过去。\n"NOR,me,target);
	if (random(me->query("combat_exp")) > target->query("combat_exp")/3 ){
		message_vision(HIR"结果$n躲闪不及被$N攻了正着，" + weapon->name() + HIR"上的"HIC"电劲"HIR"乘机钻入$n体内。\n"NOR,me,target);
              p = 2+random(4);
              	target->receive_damage("qi", i*5);
		target->receive_wound("qi", i*4);
		target->apply_condition("ss_poison", 5+(me->query_str()/10)); }
	else {
         dodge_skill = target->query_skill_mapped("dodge");
	 if( !dodge_skill ) dodge_skill = "dodge";
         message_vision(SKILL_D(dodge_skill)->query_dodge_msg(target, 1), me, target);	
		}
		}
weapon->unequip();
if (random(2)==0) target->start_busy(3);
msg = YEL "$N微微一笑，左手向$n轻轻弹出，好像是要弹去梅花上面的露珠！" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"), 1,msg);                                             message_vision(HIW"                                          【弹 梅】"NOR, me, target); 
target->receive_wound("qi",random((int)me->query_skill("bahuang-gong",1)));
msg = YEL "$N双手急挥，左右摇摆，幻出漫天梅花，飞雪似的向$n落来！" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"), 2,msg);                                           message_vision(HIW"                                          【落 雪】"NOR, me, target); 
target->receive_wound("qi",random((int)me->query_skill("bahuang-gong",1)));
msg = YEL "$n突然闻到一股若有若无的香味，心猿意马之中$N的双手已向$p胸口拍来！" NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"), 3,msg);                                             message_vision(HIW"                                          【散花香】\n"NOR, me, target); 
target->receive_wound("qi",random((int)me->query_skill("bahuang-gong",1)));
msg = HIR "$N双手幻出漫天手影，宛若朵朵梅花，将$n笼罩在一片梅海之中！"NOR;
COMBAT_D->do_attack(me,target, me->query_temp("weapon"), 4,msg);
target->receive_wound("qi",random((int)me->query_skill("bahuang-gong",1)));
me->start_busy(4);
       return 1;
 }

 