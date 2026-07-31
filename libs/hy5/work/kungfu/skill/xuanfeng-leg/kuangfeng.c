// kuangfeng.c  狂风绝技

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;
 
int perform(object me, object target)
{
	object weapon, ob;
        string msg;
int extra;
if( !target ) target = offensive_target(me);
if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("「狂风绝技」只能在战斗中使用。\n");
 
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("「狂风绝技」开始时不能拿着兵器！\n");

	if( (int)me->query("neili") < 500 )
		return notify_fail("你的真气不够！\n");

	if( (int)me->query_skill("bibo-shengong",1) < 50 )
		return notify_fail("你的碧波神功不够！\n");
        if (me->query_skill_mapped("unarmed") != "xuanfeng-leg")
                return notify_fail("你没有激发旋风扫叶腿，难以施展。\n");
	if( (int)me->query_skill("luoying-zhang",1) < 100 ||
	    me->query_skill("xuanfeng-leg",1) < 100)
		return notify_fail("你的腿掌功夫还不到家，无法使用狂风绝技！\n");

	extra = me->query_skill("xuanfeng-leg",1) / 10;
	extra += me->query_skill("luoying-zhang",1) /20;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", 900);
	msg = YEL "$N使出桃花岛绝技「狂风绝技」，身法陡然加快！" NOR;
if (!target->is_busy() && random(6)==0 ) target->start_busy(2);

	message_vision(msg, me, target);                
	msg =  YEL  "$N聚力于左掌，右腿一脚跟着踢出！" NOR;
        	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = CYN  "人影中，$N翻身而起，左掌大力得挥向$n！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL  "$N见$n门户大开，暗运内力，双腿连环踢向$n！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = CYN  "$N越战越勇，周围骤起一阵旋风，使得$n看不清方向！" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = YEL "$N如星光乍现，右掌略带悠然之色轻拍$n！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	msg = CYN "$N长啸一声，面如赤发，忽然转到$n身后，反手又是一掌！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);	
	me->add_temp("apply/damage", -900);

	me->add("neili", -200);
        me->start_busy(2);

        return 1;
}

