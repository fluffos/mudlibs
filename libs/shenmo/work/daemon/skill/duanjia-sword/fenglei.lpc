//风雷 fenglei.c 

#include <ansi.h>
#include <skill.h>
#include <weapon.h>
#include <combat.h>

inherit F_SSERVER;

//#include "/kungfu/skill/eff_msg.h";

int perform(object me, object target)
{
	object weapon, ob;
        mapping prepare;
        string msg;
       int i;
i = (int)me->query_skill("duanjia-sword", 1)  /5;
 
 

        weapon = me->query_temp("weapon");
       
	 if( !target ) target = offensive_target(me);

	if( !me->is_fighting() )
		return notify_fail("「风雷四击」只能在战斗中使用。\n");
 
	if (!weapon || weapon->query("skill_type") != "sword"
       || me->query_skill_mapped("sword") != "duanjia-sword")
      return notify_fail("手中无剑,你怎么使得出「风雷四击」！\n");

    if( (int)me->query("neili") < 500 )
		return notify_fail("你的真气不够！\n");
         
	if( (int)me->query_skill("kurong-changong", 1) < 70 )
		return notify_fail("你的枯荣禅功修为不够高。\n");

	if( (int)me->query_skill("duanjia-sword",1) < 150 ||
	    me->query_skill_mapped("sword") != "duanjia-sword")
		return notify_fail("你的段家剑法还不到家，无法使用「风雷四击」绝技！\n");

 message_vision(BLU"\n $N长笑一声，剑交左手，蹂身而上，施展「风雷四击」绝技,试图快速击伤$n \n"NOR, me,target);
      COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
	me->add("neili",-300); 
      me->add("jing",-30); 
    me->add_temp("apply/attack", 80);
    me->add_temp("apply/dodge", i*2);
	me->add_temp("apply/damage", i);
	 msg =  HIY  "$N握剑直上，对着$n就是一剑！\n" NOR;
	        COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "$N脚踩流星步，错步而前，恍惚之间已到$n面前！\n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
        msg = HIY  "$N立身而起，一鹤冲天，一招[风火雷电]闪电般劈向$n！ \n" NOR;
               COMBAT_D->do_attack(me,target, me->query_temp("weapon"),TYPE_REGULAR,msg);
       me->start_busy(2);
      me->add_temp("apply/dodge", -i*2);
    me->add_temp("apply/attack", -80);
    me->add_temp("apply/damage", -i); 

           return 1;
}
