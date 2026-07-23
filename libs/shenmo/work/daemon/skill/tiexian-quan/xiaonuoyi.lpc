#include <ansi.h>

#include <combat.h>

inherit F_SSERVER;

object *enemy = ({});
int perform(object me, object target1,object target2)

{

        int extra;

	object weapon;

	if(me->is_busy())

		return notify_fail("你现在没空！！\n");

	if( (int)me->query_skill("tiexian-quan", 1) < 150 )
		return notify_fail("你的此项武功还不到家。\n");

	if( (int)me->query_skill("unarmed") < 60 ||

	    me->query_skill_mapped("unarmed") != "tiexian-quan")

		return notify_fail(HIW "你的「铁线拳」还不到家，无法使用「小挪移」！\n"NOR);

	enemy=me->query_enemy();

        if (sizeof(enemy)<2) return notify_fail("你必须同时和两个以上的敌手战斗才能使用小挪移！\n");

        if( !target1 && target2) return notify_fail("你必须同时指定两个对手\n");

        if( !target2 && target1) return notify_fail("你必须同时指定两个对手\n");

	if(!target1 && !target2)

        {

           target1=enemy[0];

           target2=enemy[1];

         }

        if( !target1 || !target2

	||	!target1->is_character() || !target2->is_character()

	||	!me->is_fighting(target1) || !me->is_fighting(target2))

		return notify_fail(HIW "［小挪移］只能对战斗中的对手使用。\n"NOR);

	if (me->query("neili")<=350) return notify_fail(HIW "你的内力不足，无法带动敌人攻势！\n"NOR);

        me->add("neili",-300);

        message_vision(HIR "\n$N使出浣花剑派的不传之秘「小挪移」\n\n"NOR,me);

        me->start_busy(2);

        weapon = target1->query_temp("weapon");

//        extra = me->query_skill("tiexian-quan",1) + (int)me->query_skill("unarmed", 1);

        if( random(me->query("combat_exp")) >(int)target1->query("combat_exp")/3 )
//        if ((me->query("combat_exp")*random(10))>target1->query("combat_exp"))

        {

          message_vision(HIY "$N伸手带动$n的攻势，使之攻向"+target2->name()+"！\n" NOR,me,target1);

          COMBAT_D->do_attack(target1,target2, weapon);  

          COMBAT_D->do_attack(target2,target1, weapon);  

 	  COMBAT_D->do_attack(target1,target2, weapon);  

          COMBAT_D->do_attack(target2,target1, weapon);

          target1->receive_damage("qi",0,me);

          target1->start_busy(2);

        }

        else

        {

          message_vision(HIR "但$n看破$N的意图，趁势发动攻击！\n"NOR,me,target1);

          COMBAT_D->do_attack(target1,me,weapon);

        }

        weapon = target2->query_temp("weapon");

        if( random(me->query("combat_exp")) >(int)target2->query("combat_exp")/3 )
//        if (random(me->query("combat_exp")*(extra/30+1))>target2->query("combat_exp"))

        {

          message_vision(HIY "$N伸手带动$n的攻势，使之攻向"+target1->name()+"！\n" NOR,me,target2);

          COMBAT_D->do_attack(target2,target1, weapon);  

          target2->receive_damage("qi",0,me);

          target2->start_busy(2);

        }

        else

        {

          message_vision(HIR "但$n看破$N的意图，趁势发动攻击！\n"NOR,me,target2);

          COMBAT_D->do_attack(target2,me,weapon);

        }

     	return 1;

}

