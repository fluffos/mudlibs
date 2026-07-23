#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
int perform(object me, object target)
{
        string dodskill,msg;
        int extra;
        int tmp;
         extra = me->query_skill("qidao",1);
        if ( extra < 250) return notify_fail("你的棋道还不够纯熟！\n");
                
        dodskill = (string) me->query_skill_mapped("dodge");

    if( (int)me->query_skill("xuantian-wuji", 1) < 150 )
	return notify_fail("你的本门内功还未练成，不能使用！\n");

    if( (int)me->query("neili") < 600 )
    return notify_fail("你的内力不够。\n");
                
        
        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［大雪崩型定式］只能对战斗中的对手使用。\n");

        tmp=tmp/2;       
        if (extra> 200) extra=200;
        me->add_temp("apply/attack",extra);
        me->add_temp("apply/damage",extra*3);
    msg = HIW "\n\n$N大喝一声，双指如风，赫然使出『--大雪崩型定式--』!!\n$N的指风如五色光芒忽如蝶翼般片片飞向$n"+HIW"袭来！\n" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIR  "●一子解双征○\n" NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIM  "●二子之头式○\n" NOR;
          COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIG  "●三大难解式○\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIM  "●四角穿心式○\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIC  "●五六飞攻式○\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = CYN  "●六子沿边式○\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIY  "●七死八活式○\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
    msg = HIY  "●八卦太级式○\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);



        msg = HIC "\n$N"+HIG"双指连环 六子沿边活也输，左右同形适其中，隐隐有霸者之意！\n" NOR;
		msg += HIW "忽听得空中棋子飞舞之声大作，如黄龙周虎，黄莺扑蝶一般。\n\n"NOR;
        message_vision(msg, me);
 if (random((int)target->query("combat_exp")) < (int)me->query("combat_exp")) {
            message_vision(HIR"一阵棋子落地的声音后，$N"+HIR"身上多了几个血洞。\n"NOR, target); 
			target->receive_wound("qi", me->query_skill("qidao",1)*5+800);
            target->start_busy(3);
}            
        me->add_temp("apply/attack",-extra);
        me->add_temp("apply/damage",-extra*3);

me->add("neili",-380);
                me->start_busy(3);
        return 1;
}   
