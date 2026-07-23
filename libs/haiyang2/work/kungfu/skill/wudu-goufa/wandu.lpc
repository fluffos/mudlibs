// 万毒散
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
string *du=({
"ice_poison",
"ill_dongshang",
"ill_fashao",
"ill_kesou",
"ill_shanghan",
"ill_zhongshu",
"xx_poison",
"cold_poison",
"flower_poison",
"rose_poison",
"sanpoison",
"scorpion_poison",
"qx_snake_poison",
"anqi_poison",
"yf_poison",
"nx_poison",
"chilian_poison",
"yufeng_poison",
"insect_poison",
});
int perform(object me, object target)
{
	string msg;
       int damage;
int rlevel,i,p;
int level;
object weapon = me->query_temp("weapon");
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("只能对战斗中的对手使用。\n");
 	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "sword")
		return notify_fail("开始时必须拿着一把剑！\n");
     

	if(me->is_busy())
		return notify_fail("你现在没空！！\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("你的内力不够。\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("你的内力不够。\n");

       if( !wizardp(me) &&(int)me->query_skill("wudu-goufa", 1) < 500 )
		return notify_fail("你的本门外功不够!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("qianzhu-wandushou", 1) < 500 )
		return notify_fail("你的本门外功不够高!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("wudu-shengong", 1) < 500 )
		return notify_fail("你的本门内功不够高!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("你的江湖经验还不够，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("你还没有通过华山论剑! 无法对本门武功贯通使用！\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "wudu-shengong")
                return notify_fail("不使用本门内功，如何使用本门绝学!\n");
if (random(3)==0) target->start_busy(3);

        msg = HBWHT "$N贯通五毒教武学，使出了五毒教的绝学之精髓！\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);          

rlevel=(int) me->query_skill("wudu-shengong", 1)/10;
if (!rlevel) rlevel=10;
p=rlevel/4;
if (p> 8) p=8;
	for(i=0;i<p;i++)
	{
	me->add_temp("apply/attack", (rlevel*2));	
	me->add_temp("apply/damage", (rlevel*4));
        msg = HIB "$N运起五毒神功,头顶黑气蒸腾，一剑刺了出来！\n" NOR;
       COMBAT_D->do_attack(me,target, weapon, TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -(rlevel*2));	
	me->add_temp("apply/damage", -(rlevel*4));
}
me->start_busy(4);
	msg = HIR "$N一声狞笑飞身纵起，凌空一指向$n的眉心点去。\n";
	message_vision(msg, me, target);
	       target->apply_condition("chilian_poison",
		        (int)target->query_condition("chilian_poison") + 50 );
	       target->apply_condition("snake_poison",
		        (int)target->query_condition("snake_poison") + 50 );
	       target->apply_condition("wugong_poison",
		        (int)target->query_condition("wugong_poison") + 50 );
	       target->apply_condition("zhizhu_poison",
		        (int)target->query_condition("zhizhu_poison") + 50 );
	       target->apply_condition("xiezi_poison",
		        (int)target->query_condition("xiezi_poison") + 50 );
	       target->apply_condition("chanchu_poison",
		        (int)target->query_condition("chanchu_poison") + 50 );


	if( random( (int)me->query("combat_exp",1))
          > target->query("combat_exp")/3  ) {
		msg = HIR"只见一缕黑气从$N的指尖透出，只一闪就没入$n的眉心！\n" NOR;
	       message_vision(msg, me, target);
             if(target->query_skill("hunyuan-yiqi",1)>me->query_skill("qianzhu-wandushou",1)*12/10&&random(2)==0){             
		msg = RED"$N忽然觉得指力被一团无形的劲力包裹着，紧接着只听\n
$n一声大喝，$N顿时如一根稻草般被抛向远处。\n" NOR;
	       message_vision(msg, me, target);
		msg = RED"$P只觉得一股如山的劲力顺指尖猛攻过来，只觉得全身毒气狂窜。\n忽然胸口一痛，不由“哇”的一声吐出一口黑血！\n" NOR;
	       message_vision(msg, me);
              damage=(int)me->query_skill("qianzhu-wandushou",1)
                     +(int)me->query_skill("wudu-shengong",1);
              if(damage < 50 ) damage = 50;
		target->receive_wound( "qi",damage);

              }    
              else{
		msg = HIR"$n不由一声惨嚎摔倒在地，身体已痛苦得蜷缩成一团！\n" NOR;
	       message_vision(msg, me, target);
              damage=(int)me->query_skill("wudu-goufa",1)
                    +(int)me->query_skill("qianzhu-wandushou",1)
                    +(int)me->query_skill("wudu-shengong",1);
              if(damage > 5900 ) damage = 5900;
		target->receive_wound( "qi",damage);
             }
	} 
       else {
		msg = HIG "可是$n早有准备，一个懒驴打滚，堪堪躲过了这一招。\n" NOR;
	       message_vision(msg, me, target);
	}

	msg = HIM "只见$N从怀中，拿出一大包不知道是什么东西的药粉，一把撒向$n的周身!\n";

	if( random( (int)me->query("combat_exp",1))
          > target->query("combat_exp")/3  ) {
		msg += HIR"$n没有防范，全身上下被撒了一个正着！\n" NOR;
            target->receive_damage( "qi",damage*5);
            target->receive_wound( "qi",damage);
            target->apply_condition(du[random(sizeof(du))], 15);
            target->apply_condition(du[random(sizeof(du))], 15);
            target->apply_condition(du[random(sizeof(du))], 15);
            target->apply_condition(du[random(sizeof(du))], 15);
            target->apply_condition(du[random(sizeof(du))], 15);

            target->start_busy(1 + random(3));
		message_combatd(msg, me, target);
		COMBAT_D->report_status(target);
	} else {
		msg += "$p急提内力奋力一震，将$N撒出的毒粉卸在了身旁!\n" NOR;
		message_combatd(msg, me, target);
	}
	return 1;
}
