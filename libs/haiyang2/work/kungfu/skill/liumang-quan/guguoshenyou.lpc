#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string msg;
        int extra;
        if(me->is_busy())
                return notify_fail("你现在没空！！\n");
        extra = me->query_skill("liumang-quan",1);
	if ( extra < 50) return notify_fail("你的流氓神拳还不够纯熟！\n");
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［故国神游］只能对战斗中的对手使用。\n");

    if( (int)me->query("neili", 1) < 600 )
		return notify_fail("你现在内力不足，不能使用！\n");	
	if (me->query_temp("weapon") || me->query_temp("secondary_weapon"))
		return notify_fail("这个武功只能空手使用。\n");		
extra=extra/3;
if (extra> 200) extra=200;
        me->add_temp("apply/damage",extra);
        me->add_temp("apply/attack",extra);

        msg = HIY  "$N仰天长笑，使出了小重山掌的［故国神游］，一股浩然正气直冲霄汉！\n" NOR;
        message_vision(msg,me,target);
        msg = HIR  "故" NOR;
                msg+= "\n$N运足内劲，双掌齐出，直取$n的$l。";
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIW  "      国" NOR;
                msg+= "\n$N右臂如环般圈住$n的手臂，左手毫不客气的一拳击向$p。";
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIM  "            神" NOR;
                msg+= "\n$N出手如电，转眼间双掌已经出现在$n的面前！";
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIB  "                  游" NOR;
                msg+= "\n$N身形一折，凌空下击，$n简直都不知该如何躲避！";
if (random(3)==0) target->start_busy(2);
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        me->start_busy(2);
        me->add_temp("apply/damage",-extra);
        me->add_temp("apply/attack",-extra);
        return 1;
}    
