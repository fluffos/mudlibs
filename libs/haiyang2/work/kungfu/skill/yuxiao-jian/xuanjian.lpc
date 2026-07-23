// jianzhang.c  
#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

#include "/kungfu/skill/eff_msg.h"
inherit F_SSERVER;

int perform(object me, object target)
{
	object weapon, ob;
        string msg, string1;
        int count,damage,p;
int extra;
  if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("只能在战斗中使用。\n");

        if (!objectp(weapon = me->query_temp("weapon"))
        || (string)weapon->query("skill_type") != "sword")
            return notify_fail("你使用的武器不对。\n");

	if(me->is_busy())
		return notify_fail("你现在没空！！\n");

	if( (int)me->query("neili") < 2000  ) 
		return notify_fail("你的内力不够。\n");

	if( (int)me->query("neili") < me->query("max_neili")/7+200 ) 
		return notify_fail("你的内力不够。\n");

       if( !wizardp(me) &&(int)me->query_skill("yuxiao-jian", 1) < 500 )
		return notify_fail("你的本门外功不够!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("tanzhi-shentong", 1) < 500 )
		return notify_fail("你的本门外功不够高!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("bibo-shengong", 1) < 500 )
		return notify_fail("你的本门内功不够高!不能贯通使用！\n");

	if(!wizardp(me) && (int)me->query_skill("jiuyin-zhengong", 1) )
		return notify_fail("你的杂学太多，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/flag"))
		return notify_fail("你的江湖经验还不够，无法对本门武功贯通使用！\n");

        if (!wizardp(me) && !me->query("guard/ok"))
		return notify_fail("你还没有通过华山论剑! 无法对本门武功贯通使用！\n");

        if ( !wizardp(me) && me->query_skill_mapped("force") != "bibo-shengong")
                return notify_fail("不使用本门内功，如何使用本门绝学!\n");


        msg = HBWHT "$N贯通桃花岛武学，使出了桃花岛的绝学之精髓！\n" NOR;
	me->add("neili", -me->query("max_neili")/7);
        message_vision(msg, me, target);          

	extra = me->query_skill("yuxiao-jian",1) / 20;
	extra += me->query_skill("bibo-shengong",1) /10;

	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra*2);
if (random(3)==0) target->start_busy(3);
	msg = YEL "$N剑掌交叉，使出桃花岛绝技「狂风绝技」，身法陡然加快！" NOR;
	message_vision(msg, me, target);                
	msg =  YEL  "$N聚力于左掌，右腿一脚跟着踢出！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("bibo-shengong",1)));
        msg = CYN  "人影中，$N翻身而起，左掌大力得挥向$n！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("bibo-shengong",1)));
        msg = YEL  "$N见$n门户大开，暗运内力，双腿连环踢向$n！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("bibo-shengong",1)));
        msg = CYN  "$N越战越勇，周围骤起一阵旋风，使得$n看不清方向！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("bibo-shengong",1)));
        msg = YEL "$N如星光乍现，右掌略带悠然之色轻拍$n！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("bibo-shengong",1)));
	msg = CYN "$N长啸一声，面如赤发，忽然转到$n身后，反手又是一掌！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("bibo-shengong",1)));
	me->add_temp("apply/attack", -extra);	
	me->add_temp("apply/damage", -extra*2);

if ( me->query_skill("yuxiao-jian",1) >230)
{
        msg = HIG 
HIG"$N一声清啸，剑发琴音，深吸一口气，剑附内力，一式「天外清音」，"+weapon->name()
+"闪动不止，剑影如夜幕般扑向$n。\n"NOR;

	extra = me->query_skill("yuxiao-jian",1) / 5;
	extra += me->query_skill("bibo-shengong",1) /5;
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", 2*extra);

       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi",random((int)me->query_skill("bibo-shengong",1)));
	me->add_temp("apply/attack", -extra);	
	me->add_temp("apply/damage", -2*extra);
	me->add("neili", -150);

}

    msg = HIG "$N默运落英心法，使出落英神掌「玄」字诀，从半空中撒出一片掌影逼向$n。\n"NOR;

	if (random(me->query("combat_exp")) > (int)target->query("combat_exp") / 3) 
    {

        damage = (int)me->query_skill("bibo-shengong", 1); 
        damage = damage + random(damage);

        target->receive_damage("qi", damage*2);
        target->receive_wound("qi", damage/2);

        if ( damage < 40 ) msg += HIY"结果$N受到$n的内力反震，虽然击中$N，自己却闷哼一声向后退了两步。\n"NOR;
        else if( damage < 80 ) msg += RED"结果$N被$n以内力反震，胸口有如受到一记重锤，连退了五六步！\n"NOR;
        else msg += HIR"$n茫然不知所措，结果被$N一掌击中前胸，$n眼前一黑，被击飞出两丈许！！！\n"NOR;
	message_combatd(msg, me, target);
	COMBAT_D->report_status(target);
    } else
    {
        msg += HIG"可是$p看破了$P的企图，早就闪在了一边。\n"NOR;
	message_combatd(msg, me, target);
    }
	msg = CYN "$N双手一前一后，缓缓伸出，中指突地一弹，两道劲风汇成一股，“咝咝”有声，直袭$n前胸。\n";

	damage = (int)me->query_skill("tanzhi-shentong", 1) + (int)me->query_skill("bibo-shengong", 1) + 500;
	damage += random(damage / 2);
	if (random(me->query("combat_exp")) > (int)target->query("combat_exp") / 3) {
		msg += "$n躲闪不及，“噗”地一声，被指劲击中前胸！\n";
		target->receive_damage("qi", damage*5);
		target->receive_wound("qi", damage / 3);
                p = (int)target->query("qi") * 100 / (int)target->query("max_qi");
		msg += RED "$n胸口一阵巨痛，大叫倒地！\n" ;
	} 
	else if (random(me->query("combat_exp")) > (int)target->query("combat_exp") * 2 / 3) {
		msg += "$n向旁边一闪，让过了劲风，没想到这股指劲竟然有回力，从$n背后倒转回来，正刺中$p的后背。\n";
		target->receive_damage("qi", damage *3);
		target->receive_wound("qi", damage / 9);
                p = (int)target->query("qi") * 100 / (int)target->query("max_qi");
		msg += RED "$n觉的胸口有点痛！\n" ;
	}
	else {
		msg += "$n向旁边一闪，让过了劲风，却忽然发觉这股指劲竟然有回力，匆忙中只好一个前扑才堪堪躲过，模样狼狈之极。\n" NOR;
	}
	message_vision(msg, me, target);

	me->start_busy(4);
	return 1;
}
