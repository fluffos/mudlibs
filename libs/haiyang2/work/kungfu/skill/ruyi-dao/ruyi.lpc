//ruyi.c 如意连环刀

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

void remove_effect(object me, int a_amount, int d_amount);

inherit F_SSERVER;
int perform(object me, object target)
{
        object weapon,ob;
        int skill;
	int extra;
        string msg;

        if( !target ) target = offensive_target(me);

        if( !target
        ||      !target->is_character()
        ||      !me->is_fighting(target) )
                return notify_fail("「如意连环刀」只能在战斗中使用。\n");

	if (!objectp(weapon = me->query_temp("weapon"))
		|| (string)weapon->query("skill_type") != "blade")
                return notify_fail("「如意连环刀」必须用刀才能施展。\n");

        if( (int)me->query_skill("ruyi-dao", 1) < 60 )
                return notify_fail("你的「如意刀法」不够娴熟，不会使用「如意连环刀」。\n");

        if( (int)me->query_skill("beiming-shengong", 1) < 60 )
                return notify_fail("你的「北冥神功」不够娴熟，不会使用「如意连环刀」。\n");

        if( (int)me->query("neili") < 400  ) 
                return notify_fail("你的内力不够。\n");

        skill = me->query_skill("ruyi-dao");
	extra = me->query_skill("ruyi-dao",1) / 20;
	extra += me->query_skill("ruyi-dao",1) /20;
me->set_temp("ruyi");
	me->add_temp("apply/attack", extra);	
	me->add_temp("apply/damage", extra);
        msg = HIY "$N一声长笑，只觉世事如意，豪气满胸，哪管什么是非荣辱，反手一刀砍出！\n"NOR;
        me->add("neili", -200);
        
       	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	        msg = HIB"$N刀风过处，意犹未尽，反手又是一刀！\n"NOR;
       
       	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIR"$N身随刀转，顺手又是一刀！\n"NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

if( (int)me->query_skill("ruyi-dao", 1) > 200 )
{
        msg = HIG"$N身随刀转，顺手再是一刀！\n"NOR;
       	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIC"$N身随刀转，顺手最后一刀！\n"NOR;
       COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

}
        msg = HIW"$N身形再转，如意一刀又回转回来！\n"NOR;
             	COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);

       me->start_busy(2);
me->delete_temp("ruyi");
	me->add_temp("apply/attack", -extra);
	me->add_temp("apply/damage", -extra);
        return 1;
}
