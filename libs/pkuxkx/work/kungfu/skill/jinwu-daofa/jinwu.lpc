#include <ansi.h>
#include <combat.h>
inherit F_SSERVER;
#define Menpai "雪山派"

int perform(object me, object target)
{
        string msg;
        int extra;
        object weapon;

        extra = me->query_skill("jinwu-daofa",1);

        if( !target ) target = offensive_target(me);
        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("［金乌融雪］只能对战斗中的对手使用。\n");
        weapon = me->query_temp("weapon");
        if (!(weapon = me->query_temp("weapon")) || weapon->query("skill_type") != "blade"
           || me->query_skill_mapped("blade") != "jinwu-daofa")
                return notify_fail("你现在没法使用「金乌融雪」！\n");

        if ((int)me->query_skill("jinwu-daofa",1) < 120) 
                return notify_fail("你的金乌刀法还不够纯熟！\n");
        if ((int)me->query_skill("xueshan-neigong", 1) < 120)
                return notify_fail("你的雪山内功功力太浅，使不出「金乌融雪」。\n");                
        if ((int)me->query("max_neili") < 1200)
                return notify_fail("你的内力修为太浅，使不出「金乌融雪」。\n");
        if ((int)me->query("neili") < extra/2)
                return notify_fail("你的内力不够，使不出「金乌融雪」。\n");
    	if( me->query("family/family_name")!=Menpai && me->query("chushi/last_family")!=Menpai 
        	&& !(me->query("tqt/old_family") && member_array(Menpai,me->query("tqt/old_family"))!=-1)
        	&& me->query_skill_mapped("force") != "xueshan-neigong" )
            	return notify_fail("你真气运转方式不对，使不出「金乌融雪」。\n");                

        me->add("neili", -extra/2);
        me->start_perform(5,"「金乌融雪」");
        msg = HIY  "$N使出金乌刀法中的［金乌融雪］，一招连环三式，手中的"+ weapon->name()+ HIY"闪电般向$n攻出！\n" NOR;
        message_vision(msg,me,target);

        me->add_temp("apply/damage", extra/5);       
        me->add_temp("apply/strength", extra/5);
        me->add_temp("apply/attack", extra/5); 
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_REGULAR);        
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_REGULAR);       
        COMBAT_D->do_attack(me,target, me->query_temp("weapon"), TYPE_REGULAR);
        me->add_temp("apply/damage", -extra/5);
        me->add_temp("apply/strength", -extra/5);
        me->add_temp("apply/attack", -extra/5); 
        if ((int)me->query("neili") < 0)  me->set("neili", 0);
        me->start_busy(2+random(3));
   
        return 1;
}

