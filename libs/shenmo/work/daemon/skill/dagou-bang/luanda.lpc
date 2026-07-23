// sanqing.c 一剑化三清

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>


inherit F_SSERVER;
 
int perform(object me, object target)
{
        object weapon, ob;
        string msg, string1;
        int count;
 	if( !target ) target = offensive_target(me);

	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("「乱打」只能在战斗中使用。\n");
 
	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "staff")
			return notify_fail("你使用的武器不对。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "staff")
			return notify_fail("你使用的武器不对。\n");

        if( (int)me->query("neili") < 300 )
                return notify_fail("你的真气不够！\n");

        if( (int)me->query_skill("dagou-bang",1) < 80 )
                return notify_fail("你的你的打狗棒法不够娴熟，不会使用「乱打」！\n");

        if (me->query_skill("huntian-qigong", 1)<70)
                return notify_fail("你的本门内功火候未到，！\n");

        msg = YEL "$N心中一急,没头没脑的向前面打了出去,但正是打狗棒法的精要之所在！\n" NOR;
        msg+= HIR"$N怒喝一声，横过"+ weapon->name()+HIG"一搭，借势跃起，人未至，棒先到，凌虚下击，连施三下杀手！\n" NOR;
        message_vision(msg, me);

        me->add_temp("apply/attack", (int)me->query_skill("dagou-bang",1));
        me->add_temp("apply/damage", (int)me->query_skill("dagou-bang",1)/2);
       msg = WHT  "$N转过"+ weapon->name()+HIG"，刷刷刷连进三棒，棒法快捷无伦，都是打狗棒法中的杀招！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
if ( (int)me->query_skill("dagou-bang",1) > 120 )
{
       msg = WHT  "连进三棒！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi", random(me->query_skill("dagou-bang",1)));
}
        msg = HIC  "$N突然飞出"+ weapon->name()+HIG"，迎面劈向$n，这棒连戳三下，竟在霎时之间分点$p胸口三处大穴！" NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
if ( (int)me->query_skill("dagou-bang",1) > 220 )
{
       msg = HIC  "连戳三下！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
target->receive_wound("qi", random(me->query_skill("dagou-bang",1)));
}

        msg = RED "$N横棒挥出，变守为攻，发挥出打狗棒法中的攻手，连进了三记杀招！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
if ( (int)me->query_skill("dagou-bang",1) > 299 )
{
       msg = RED  "三记杀招！" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
if ( (int)me->query_skill("dagou-bang",1) > 350  && me->query_skill_mapped("force") == "huntian-qigong")
{

        msg = RED "第一招 $N横棒挥出，使出了封字决！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = RED "第二招 $N横棒挥出，使出了转字决！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = RED "第三招 $N横棒挥出，使出了拌字决！！" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
}
target->receive_wound("qi", random(me->query_skill("dagou-bang",1)));
}



        me->add_temp("apply/attack", - (int)me->query_skill("dagou-bang",1));
        me->add_temp("apply/damage", - (int)me->query_skill("dagou-bang",1)/2);
        me->add("neili", -300);
        me->start_busy(2);

        return 1;
}

