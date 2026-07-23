#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        object weapon;
        extra = me->query_skill("six-sword",1);
        if ( extra < 150) return notify_fail("你的六阴追魂剑法还不够纯熟！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［海渊八剑］只能对战斗中的对手使用。\n");
        weapon = me->query_temp("weapon");
        if((int)me->query("neili") < 500 )
                return notify_fail("你现在内力不足，不能使用！\n");
                weapon = me->query_temp("weapon");
        if (!weapon || weapon->query("skill_type") != "sword"       )
                return notify_fail("你手里没有剑，无法使用！\n");                 
        msg = HIY  "$N使出海渊剑法中的［海渊八剑］，一招连环八剑齐出，手中的"+ weapon->name()+  "闪电般向$n攻出洪水剑！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "大愚剑！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

        msg = HIC  "伤心剑！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIM  "大龙剑！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = MAG  "不破剑！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "杀人剑！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "无敌剑！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg); 
        msg = HIY  "大乐剑！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
msg = HIG "\n$N一剑挥出 剑光一闪即没，归于$N掌中，登时风停树止，鸟寂林息，刚才的一切气 
象似乎只是一场幻梦，荡然无存。" ;

if(random(2)==0)
{
	 target->start_busy(2);
	target->add("jing",-extra);
target->add("eff_jing",-extra);
}	
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->add("neili",-380);
        me->start_busy(3);
        return 1;
}