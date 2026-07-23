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
                return notify_fail("［天下八剑］只能对战斗中的对手使用。\n");
        weapon = me->query_temp("weapon");
        if((int)me->query("neili") < 500 )
                return notify_fail("你现在内力不足，不能使用！\n");
                weapon = me->query_temp("weapon");
        if (!weapon || weapon->query("skill_type") != "sword"       )
                return notify_fail("你手里没有剑，无法使用！\n");         
        
        msg = HIY  "$N"HIY"使出大内剑法中的［天下八剑］，一招连环八剑齐出，手中的"+ weapon->name()+  HIY"闪电般向$n攻出独孤剑！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "飞仙剑！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC  "寒天剑！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIM  "段家剑！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = MAG  "三才剑！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR  "杀人剑！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "左手剑！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg); 
        msg = HIY  "浣花剑！" NOR;
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

      msg = HIC "$N一剑挥出，如夕阳，又如烈日，如彩虹，又如乌云，如动又静，如虚又实，
如在左，又在右，如在前，又在後，如快又慢，如空又实。 \n"NOR;
if(random(2)==0)
{
	 target->start_busy(2);
	target->add("qi",-extra*5);
target->add("eff_qi",-extra*3);
}	
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);



        me->add("neili",-380);
        me->start_busy(3);
        return 1;
}
