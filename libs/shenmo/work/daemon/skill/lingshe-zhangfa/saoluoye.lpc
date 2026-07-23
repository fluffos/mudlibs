#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
	int extra;
	object weapon,ob;
	if(me->is_busy())
		return notify_fail("你现在没空！！\n");
	extra = me->query_skill("lingshe-zhangfa",1);
        if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("「狂风扫落叶」只能在战斗中使用。\n");
 
	if (!objectp(weapon = me->query_temp("weapon"))
	|| (string)weapon->query("skill_type") != "staff")
            return notify_fail("你使用的武器不对。\n");
       
	 if( (int)me->query("neili") < 1200 )
                return notify_fail("你的真气不够！\n");

	if( (int)me->query_skill("hamagong", 1) < 100 )
		return notify_fail("你的蛤蟆功不够娴熟.\n");

        if( extra < 200 )
                return notify_fail("你的灵蛇杖法火候不够，无法使用「狂风扫落叶」！\n");

        if( (int)me->query_skill("force",1) < 180 )
                return notify_fail("你的内功修为不够，无法使用「狂风扫落叶」！\n");
	me->add_temp("apply/attack",(extra/3));
	me->add_temp("apply/damage",(extra/2));
	weapon = me->query_temp("weapon");

        msg = HIY "$N跳出数丈外，突然一声暴喝：“------ 狂 ----- 风 ----- 扫 ----- 落 ----- 叶 ----- ！！！”" NOR;
	         message_vision(msg, me, target);                
	 msg =  YEL  "$N身形加快，所到之处，狂风四起！" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg =  YEL  "$N突如起来的从狂风中闪出，对着$n胸前就是一杖！" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "$N御杖回身，立于$n身侧，反手一劈！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "$N借力打力，一个纵身，居高临下，当头又是一杖！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "人在半空，$N化虚为掌，化实为杖，朝$n点刺过去！" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL "$N持杖乱舞，密不透风，使$n渐渐感到透不过气来！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg = YEL "$N见有机可乘，一杖接着一杖，招招致命！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	 msg = YEL "$N聚起天地之灵气，手中的"+ weapon->name() +"卷起千层大浪朝$n挥去！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        me->add_temp("apply/attack",-(extra/3));
	 me->add_temp("apply/damage",-(extra/2));
if (extra > 250
&&  random(me->query("combat_exp")) > (int)target->query("combat_exp")/3 )
{
	 msg = RED "蛇毒" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	target->apply_condition("snake_poison",10);
	 msg = RED "蟾蜍毒" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	target->apply_condition("chanchu_poison",10);
	 msg = RED "七修蛇毒" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	target->apply_condition("qx_snake_poison",20);
}
        me->add("neili", -500);
        me->start_busy(4);

        return 1;
}

