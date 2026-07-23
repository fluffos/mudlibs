// ning@fengyun
#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
	string msg;
	int extra;
	object weapon;
        extra = me->query_skill("six-sword",1);
       if ( extra < 50) return notify_fail("你的六阴追魂剑法还不够纯熟！\n");

        if((int)me->query("neili") < 500 )
                return notify_fail("你现在内力不足，不能使用！\n");
                weapon = me->query_temp("weapon");
        if (!weapon || weapon->query("skill_type") != "sword"       )
                return notify_fail("你手里没有剑，无法使用！\n");                
	if( !target ) target = offensive_target(me);
	if( !target
	||	!target->is_character()
	||	!me->is_fighting(target) )
                return notify_fail("［连环剑］只能对战斗中的对手使用。\n");
	weapon = me->query_temp("weapon");
msg = HIR "$N剧烈地抖动着手中的"+ weapon->name() + HIR"一次向$n连续攻出『六』『阴』『追』『魂』四连剑！！\n\n" NOR;
	message_vision(msg,me,target);
if (extra>200) extra=200;
        me->add_temp("apply/damage",extra);
        me->add_temp("apply/attack",extra);
        msg = ""+ weapon->name()+ "" + HIW"象一条银蛇一般直刺向$n！"NOR;
	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = ""+ weapon->name()+ "" + HIY"化作一片金光平消向$n！"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = ""+ weapon->name()+ "" + HIC"忽隐忽现反撩向$n！"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = ""+ weapon->name()+ "" + HIG"犹如失去控制一般横扫向$n！"NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add_temp("apply/damage",-extra);
        me->add_temp("apply/attack",-extra);
        me->start_busy(2);
	return 1;
}
