#include <ansi.h>
#include <combat.h>

inherit F_SSERVER;
int perform(object me, object target)
{
	string dodskill,msg;
	int extra,tmp;
	object weapon;
       if( !target ) target = offensive_target(me);
       if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
		return notify_fail("[相思无用]只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
	extra = me->query_skill("duanjia-sword",1);
	if ( extra < 300) return notify_fail("你的[段家剑法]还不够纯熟！\n");

        if (!objectp(weapon) || weapon->query("skill_type") != "sword")
                return notify_fail("你手中无剑，如何使得出哀牢山剑意？\n");
		
        if ((int)me->query_skill("kurong-changong",1) < 180)
            return notify_fail("你的枯荣禅功太低。\n");
        if ((int)me->query_skill("duanjia-sword", 1) < 180)
		return notify_fail("你的段家剑火候太浅。\n");    
        if ((int)me->query_skill("jinyu-quan", 1) < 180)
		return notify_fail("你的金玉拳火候太浅。\n");
        if ((int)me->query_skill("wuluo-zhang", 1) < 180)
		return notify_fail("你的五罗轻烟掌火候太浅。\n");
        if ((int)me->query_skill("feifeng-whip", 1) < 180)
		return notify_fail("你的飞凤鞭火候太浅。\n");

        if (me->query("neili") <= 500)
                return notify_fail("你的内力不够！\n");
 if (extra> 200) extra=200;
 	
        me->add_temp("apply/attack", extra); 
	me->add_temp("apply/damage", extra);
       msg =  HIG  "$N发挥出段家剑法中的最高境界［相思无用］，眼前突然闪过一条倩影，手中的"+ weapon->name()+"化作五彩长虹闪电般的划向$n！" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg =  HIW "倩影一现，消失了．．．．\n" NOR;
       message_vision(msg,me,target);
       msg =  HIW "$N突然手中又一亮！" + HIG "\n相思无用第一式：日色欲尽花含烟！" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg =  HIW "剑光消失，$N突然手中又一亮！" + HIC "\n相思无用第二式：月明欲素愁不眠！" NOR; 
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg =  HIW "剑光消失，$N突然手中又一亮！" + HIY "\n相思无用第三式：赵瑟初停凤凰柱！" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg =  HIW "剑光消失，$N突然手中又一亮！" + HIR "\n相思无用第四式：蜀琴欲奏鸳鸯弦！" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg =  HIW "剑光消失，$N突然手中又一亮！" + HIW "\n相思无用第五式：此曲有意无人传！" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg =  HIW "剑光消失，$N突然手中又一亮！" + HIB "\n相思无用第六式：愿随春风寄燕然！" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg =  HIW "剑光消失，$N突然手中又一亮！" + HIC "\n相思无用第七式：忆君迢迢隔青天！" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg =  HIW "剑光消失，$N突然手中又一亮！" + HIM "\n相思无用第八式：昔时横波目，今作流泪泉！" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       msg =  HIW "剑光消失，$N突然手中又一亮！ "+ HIB "\n相思无用最后一式：不信妾肠断，归来看取明镜前！" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add_temp("apply/attack", -extra);	
        me->add_temp("apply/damage", -extra);
	me->add("neili",-500);
        me->start_busy(5);
	return 1;
}
